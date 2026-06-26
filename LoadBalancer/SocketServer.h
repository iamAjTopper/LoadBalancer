#pragma once

#include<WinSock2.h>
#include<ws2tcpip.h>
#include<iostream>

#pragma comment(lib, "ws2_32.lib")

class SocketServer {
private:
	//stores information about thewindoes ntworking liobrarry after initilization
	WSADATA wsaData;
	//listening socket for the server
	SOCKET serverSocket;
	//structure to hold the server address information
	sockaddr_in serverAddress;
public:
	SocketServer();
	bool intialize();

};