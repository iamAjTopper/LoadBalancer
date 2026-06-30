#include <iostream>
#include "ServerManager.h"
#include"SocketServer.h"

int main()
{
    SocketServer server;
    if (!server.intialize())
        return 1;

    if (!server.createSocket())
        return 1;

    if (!server.bindSocket())
        return 1;

    if (!server.startListening())
        return 1;

    while (true) {
        if (server.acceptClient()){
            if(server.receiveData()) {
                server.sendData("Hello Client");
            }
        }
    }
    return 0;
}