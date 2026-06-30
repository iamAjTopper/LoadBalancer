#pragma once

#include<winsock2.h>
#include<ws2tcpip.h>
#include<iostream>

#pragma comment(lib, "Ws2_32.lib")

class SocketClient {
private:
	WSADATA wsaData;
	SOCKET clientSocket;
	sockaddr_in serverAddress;
public:
	SocketClient();

	bool intialize();
	bool createSocket();
	bool connectToServer();

	bool sendData(const char* message);
	bool receiveData();

	void cleanup();
};
