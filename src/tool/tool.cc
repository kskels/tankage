#include <enet/enet.h>

#include <iostream>
#include <cstdlib>
#include <cstdio>

int main(int argc, char *argv[]) {
  const std::string option = argc > 1 ? argv[1] : "";

  if (enet_initialize() != 0) {
	std::cerr << "An error occurred while initializing ENet" << std::endl;
    return EXIT_FAILURE;
  }

  if (option == "server") {
    ENetAddress address;
    ENetHost *server; 


    /* Bind the server to the default localhost.     */
    /* A specific host address can be specified by   */
    /* enet_address_set_host (& address, "x.x.x.x"); */
    address.host = ENET_HOST_ANY;
    /* Bind the server to port 1234. */
    address.port = 9889;

    server = enet_host_create (& address /* the address to bind the server host to */, 
                                 32      /* allow up to 32 clients and/or outgoing connections */,
                                  2      /* allow up to 2 channels to be used, 0 and 1 */,
                                  0      /* assume any amount of incoming bandwidth */,
                                  0      /* assume any amount of outgoing bandwidth */);
    if (!server) {
      std::cerr << "An error occurred while trying to create an ENet server host" << std::endl;
        exit (EXIT_FAILURE);
    }


    ENetEvent event;
    
    /* Wait up to 1000 milliseconds for an event. */
    while (enet_host_service (server, & event, 1000) > 0)
    {
        switch (event.type)
        {
        case ENET_EVENT_TYPE_CONNECT:
            printf ("A new client connected from %x:%u.\n", 
                    event.peer -> address.host,
                    event.peer -> address.port);

            /* Store any relevant client information here. */
            event.peer -> data = (char*)"Client information";

            break;

        case ENET_EVENT_TYPE_RECEIVE:
            printf ("A packet of length %u containing %s was received from %s on channel %u.\n",
                    event.packet -> dataLength,
                    event.packet -> data,
                    event.peer -> data,
                    event.channelID);

            /* Clean up the packet now that we're done using it. */
            enet_packet_destroy (event.packet);
            
            break;
           
        case ENET_EVENT_TYPE_DISCONNECT:
            printf ("%s disconected.\n", event.peer -> data);

            /* Reset the peer's client information. */

            event.peer -> data = NULL;
        }
    } // while
    enet_host_destroy(server);

  } else {
    ENetHost * client;
    client = enet_host_create (NULL /* create a client host */,
                1 /* only allow 1 outgoing connection */,
                2 /* allow up 2 channels to be used, 0 and 1 */,
                57600 / 8 /* 56K modem with 56 Kbps downstream bandwidth */,
                14400 / 8 /* 56K modem with 14 Kbps upstream bandwidth */);
    if (!client) {
      std::cerr << "An error occurred while trying to create an ENet client host" << std::endl;
        exit (EXIT_FAILURE);
    } 
    enet_host_destroy(client);
  }

  atexit (enet_deinitialize);
  return EXIT_SUCCESS;
} 
