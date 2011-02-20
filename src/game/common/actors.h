#ifndef GAME_ACTORS_H
#define GAME_ACTORS_H

#include <game/common/system.h>
#include <game/common/replicated_system.h>

#include <utils/vec.h>
#include <vector>

typedef int ActorId;

class Actors : public ReplicatedSystem {
public:
  ~Actors();

  // System stuff
  void init(const class Portal &interfaces);
  void render();

  // Replicated system
  void onTick(class Client *client);
  void onReceive(NetPacketType type, const class Packet &packet);
  
  // Misc
  class Tank *tank(int id) const;
  class Tank *intersectingTank(const vec2 &start, const vec2 &end, float radius, ActorId ignore, vec2 &hitpos);

  
private:
  typedef std::vector<class Tank *> TankVector;

  class Graphics *graphics;
  class WindowManager *wm;
  class Texture *tankBase;
  class Texture *tankTurret;
  
  TankVector tanks;
  double lastUpdate;
};

#endif // !GAME_ACTORS_H
