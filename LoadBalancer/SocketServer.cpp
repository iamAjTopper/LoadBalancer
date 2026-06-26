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

bool SocketServer::createSocket() {
	serverSocket = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
	if (serverSocket == INVALID_SOCKET) {
		std::cout << "Faield to crteate socket\n";
		return false;
	}
	std::cout << "Socket created successfully\n";
	return true;
}