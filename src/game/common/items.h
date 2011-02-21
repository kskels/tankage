#ifndef GAME_ITEMS_H
#define GAME_ITEMS_H

#include <game/common/replicated_system.h>
#include <game/common/actors.h>

#include <utils/vec.h>
#include <vector>

class Item {
public:
  virtual ~Item() {}

  Item(const vec2 &pos, float radius);
  
  virtual void render(class Graphics *gfx) =0;
  virtual bool update(double dt) {return true; }
  bool intersects(const vec2 &start, const vec2 &end, float radius, vec2 &hitpos);
  virtual bool takeDamage(const vec2 &pos, float damage, ActorId shooter) =0;
  
protected:
  vec2 pos;
  float radius;
};


class Items : public ReplicatedSystem {
public:
  enum ProjectileType {
    PROJECTILE_BULLET
  };

  Items();
  ~Items();
  void init(const class Portal &interfaces);

  void update();
  void render();
  void spawnProjectile(ProjectileType type,
                       const vec2 &pos,
                       const vec2 &dir,
                       int shooterId);
  Item *intersectingItem(const vec2 &start, const vec2 &end, float radius, vec2 &hitpos);

  void onTick(class Client *client);
  void onReceive(NetPacketType type, const class Packet &packet);
  
private:
  Items(const Items &) {} // private copy ctor
  Items &operator =(const Items &) {return *this; } // private assignment
  
  class WindowManager *wm;
  class Graphics *gfx;
  class Texture *cactusTexture;
  class Texture *bulletTexture;
  class Texture *healthPowerup;
  class Texture *smoke;
  
  double lastGentime;
  double lastUpdate;
  
  typedef std::vector<Item *> ItemVector;
  typedef std::vector<class Projectile *> ProjectileVector;
  
  ItemVector items;
  ProjectileVector projectiles;

  int projectileId;
};

#endif // !GAME_ITEMS_H
