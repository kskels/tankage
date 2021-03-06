#ifndef GAME_PARTICLES_H
#define GAME_PARTICLES_H

#include <utils/vec.h>
#include <utils/color.h>
#include <vector>

class Particle {
public:
  Particle();
  
  bool update(double dt);
  
  vec2 pos;
  color4 color;
  double ttd;
};

class ParticleGroup {
public:
  ParticleGroup(class Texture *texture);

  void render(double dt, class Graphics *gfx);
  void addParticle(const Particle &particle);
  
private:
  typedef std::vector<Particle> ParticleList;
  
  class Texture *texture;
  ParticleList particles;
};

class Particles {
public:
  Particles(const class Portal &modules);
    
  void render();
  ParticleGroup *group(class Texture *texture);
  
private:
  typedef std::vector<std::pair<Texture *, ParticleGroup *> > GroupList;
  
  class Graphics *gfx;
  class WindowManager *wm;
  GroupList groups;
  double lastUpdate;
};

#endif // !GAME_PARTICLES_H
