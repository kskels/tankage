#ifndef GAME_GAMESERVER_H
#define GAME_GAMESERVER_H

#include <game/common/system.h>

class GameServer : public System {
public:
  ~GameServer();
  
  void init(const class Portal &interfaces);
  void update();
  
private:
  void onConnect(class Client *client);
  void onDisconnect(class Client *client);
  void onReceive(class Packet *packet);

  class Host *_host;
};


#endif // !GAME_GAMESERVER_H
