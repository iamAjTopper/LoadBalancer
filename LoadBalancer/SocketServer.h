#pragma once

#include<WinSock2.h>
#include<ws2tcpip.h>
#define _WINSOCK_DEPRECATED_NO_WARNINGS
#include<iostream>

constexpr unsigned short PORT = 8080;
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
	bool createSocket();
	bool bindSocket();

};