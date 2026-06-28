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

bool SocketServer::bindSocket() {
	serverAddress.sin_family = AF_INET;
	serverAddress.sin_port = htons(PORT);
	if (inet_pton(AF_INET, "127.0.0.1", &serverAddress.sin_addr) != 1)
	{
		std::cout << "Invalid IP Address\n";
		return false;
	}
	if (bind(serverSocket, (sockaddr*)&serverAddress, sizeof(serverAddress)) == SOCKET_ERROR) {
		std::cout << "Bind Failed\n";
		return false;
	}
	std::cout << "Socket Bound Successfullly\n";
	return true;
}

bool SocketServer::startListening() {
	if(listen(serverSocket,SOMAXCONN)==SOCKET_ERROR){
		std::cout << "Listen Failed\n";
		return false;
	}
	std::cout << "Listening for incoming connections...\n";
	return true;
}

bool SocketServer::acceptClient() {
	std::cout<<"Waiting for client connection...\n";

	clientSocket = accept(serverSocket, nullptr, nullptr);
	if(clientSocket == INVALID_SOCKET){
		std::cout << "Accept Failed\n";
		return false;
	}
	std::cout << " Client connected successfully\n";
	return true;
}