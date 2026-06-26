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
}