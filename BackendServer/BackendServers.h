#pragma once

#include<WinSock2.h>
#include<ws2tcpip.h>
#define _WINSOCK_DEPRECATED_NO_WARNINGS
#include<iostream>
#include<string>


#pragma comment(lib, "ws2_32.lib")

class BackendServer {
private:
	//stores information about thewindoes ntworking liobrarry after initilization
	WSADATA wsaData;
	//listening socket for the server
	SOCKET serverSocket;
	//socket for the client connection
	SOCKET clientSocket;
	//structure to hold the server address information
	sockaddr_in serverAddress;
	// a port
	unsigned short port;
	std::string serverName;

public:
	BackendServer(unsigned short port, std::string name);

	bool intialize();
	bool createSocket();
	bool bindSocket();
	bool startListening();

	bool acceptClient();
	bool receiveData();
	bool sendData(const char* message);

	bool handleClient();

	void cleanup();

}; 
