
#include <engine/portal.h>
#include <engine/network.h>
#include <cstdlib>
#include <memory>
#include <iostream>

int app_main(Portal &interfaces) {
  Network *net = interfaces.requestInterface<Network>();
  std::auto_ptr<Host> host(net->startHost("0.0.0.0:12345"));

  while (1) {
    host->receive();
    // Fixme: connectingClient -> clientConnecting?
    
    while (Client *newClient = host->connectingClient()) {
      std::cout << "new client! :DD" << std::endl;
    }
    
    while (Client *oldClient = host->disconnectingClient()) {
      std::cout << "client disconnected :(" << std::endl;
    }
    
    while (Packet *newPacket = host->pendingPacket()) {
      delete newPacket;
    }

    // Packet: data() size() resize()
    // PacketBuilder(packet).write(123)
    // PacketReader

    // Is it OK to have a bitfield in the beginning of each packet,
    // saying which subsystems have added stuff in it?
    // The packet is the transport of data between instances of the same
    // subsystem.
    
    
     
  }
  
  return EXIT_SUCCESS;
}
