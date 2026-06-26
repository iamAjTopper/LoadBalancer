#include"SocketServer.h"

SocketServer::SocketServer() {
	serverSocket = INVALID_SOCKET;
}

bool SocketServer::intialize() {
	int result = WSAStartup(MAKEWORD(2, 2), &wsaData);
	if (result != 0) {
		std::cout << "WSAStartup Failed\n";
		return false;
	}
	std::cout << "Winsock Initialized\n";
	return true;
}