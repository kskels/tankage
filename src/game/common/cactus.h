#ifndef GAME_CACTUS_H
#define GAME_CACTUS_H

#include <game/common/items.h>

class Cactus : public Item {
public:
  Cactus(const class vec2 &pos, class Texture *tex);
  
  void render(class Graphics *gfx);
  bool update(double dt);
  bool takeDamage(const class vec2 &pos, float damage, ActorId shooter);
  
private:
  class Texture *tex;
  float health;
};


#endif // !GAME_CACTUS_H
