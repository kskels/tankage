#include "tank_renderer.h"
#include <game/server/tank.h>
#include <iostream>
#include <game/client/gameclient.h>
#include <engine/portal.h>
#include <engine/graphics.h>

TankRenderer::TankRenderer(class GameClient *client, class Portal &services)
  : _client(client)
{
  _gfx = services.requestInterface<Graphics>();
}

void TankRenderer::addSnapshot(const Snapshot<Tank::State> &snapshot) {
  prev = current;
  current = snapshot;
}

void TankRenderer::render() {  
  // Note: there's also another case where a tank can dissappear and then appear again
  //       in the snapshots; when they go out of the visible area
  
  TankSnapshot::const_iterator it = current.begin(), it_e = current.end();
  for (; it != it_e; ++it) {
    TankSnapshot::const_iterator it_prev = prev.find(it->id);
    Tank::State state;
    if (it_prev != prev.end() && _client->lerpRemote()) {
      state = lerp(*it_prev, *it, _client->deltaTime()); // FIXME: lerping base_dir is bad
    }
    else {
      // it just started existing! or remote entity smoothing is turned off
      state = *it;
    }

    renderTank(state);
  }
}

void TankRenderer::renderTank(const Tank::State &state) {
  _gfx->setColor(color4(0.0f, 0.0f, 1.0f, 1.0f));
  _gfx->disableTextures();
  _gfx->drawQuad(rect(state.pos, 16, 16), state.base_dir);
  
}