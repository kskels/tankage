#include <game/common/projectile.h>
#include <game/common/system.h>
#include <game/common/snails.h>
#include <game/common/tank.h>
#include <game/common/items.h>
#include <game/client/particles.h>

#include <engine/graphics.h>
#include <engine/texture.h>

#include <utils/vec.h>
#include <utils/rect.h>
#include <cmath>

Projectile::Projectile(class ParticleGroup *partGroup,
                       class Snail *shooter, class Texture *tex,
                       const SystemContext *ctx, const vec2 &pos)
  : partGroup(partGroup)
  , shooter(shooter)
  , tex(tex)
  , ctx(ctx)
  , pos(pos)
{
  sinceEmit = 0.0;
  /*
    group = ctx->particles()->group(particle_texture);
    group->addParticle(pos);
  */

}

bool Projectile::update(double dt) {
  const vec2 prevPos = pos;
  pos += vel * dt;
  sinceEmit += dt;
  
  vec2 hitPos;
  Snail *hit = ctx->snails()->intersectingSnails(prevPos, pos, 1.0f, shooter, hitPos);
  if (hit) {
    hit->takeDamage(hitPos, 10.0f);
    return false;
  }

  Item *hitItem = ctx->items()->intersectingItem(prevPos, pos, 1.0f, hitPos);
  if (hitItem) {
    if (hitItem->takeDamage(hitPos, 10.0f, shooter)) {  // FIXME: takeDamage -> DISINTEGRATE, IGNORE, REFLECT
      return false;
    }

    // If reflect: emitter.addMidpoint()
  }

  if (sinceEmit > 0.01) {
    Particle particle;
    particle.pos = pos;
    particle.ttd = 0.2;
    partGroup->addParticle(particle);
    sinceEmit = 0.0;
  }
  
  // update effect
  // partGroup->emitParticle(Particle(blabla));
//  emitter.setPosition(pos);
  if (pos.x - 64.0f > 800.0f || pos.x + 64.0f < 0.0f)
    return false;
  if (pos.y - 64.0f > 800.0f || pos.y + 64.0f < 0.0f)
    return false;
  
  return true;
}

void Projectile::render(Graphics *gfx) {
  gfx->setBlend(Graphics::BLEND_ALPHA);
  gfx->enableTextures();
  tex->bind();

  vec2 dir = normalized(vel);
  gfx->drawQuad(rect(pos, 32, 32), degrees(dir)); // FIXME: get rid of hardcoded sizes

}

void Projectile::setVel(const vec2 &vel) {
  this->vel = vel;
}

