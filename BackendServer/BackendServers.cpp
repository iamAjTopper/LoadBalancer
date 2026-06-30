#include"BackendServers.h"


BackendServer::BackendServer(unsigned short port, std::string name) {
	this->port = port;
	this->serverName = name;

	serverSocket = INVALID_SOCKET;
	clientSocket = INVALID_SOCKET;
}

bool BackendServer::intialize() {
	int result = WSAStartup(MAKEWORD(2, 2), &wsaData);
	if (result != 0) {
		std::cout << "WSAStartup Failed\n";
		return false;
	}
	std::cout << "Winsock Initialized\n";
	return true;
}

bool BackendServer::createSocket() {
	serverSocket = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
	if (serverSocket == INVALID_SOCKET) {
		std::cout << "Faield to crteate socket\n";
		return false;
	}
	std::cout << "Socket created successfully\n";
	return true;
}

bool BackendServer::bindSocket() {
	serverAddress.sin_family = AF_INET;
	serverAddress.sin_port = htons(port);
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

bool BackendServer::startListening() {
	if (listen(serverSocket, SOMAXCONN) == SOCKET_ERROR) {
		std::cout << "Listen Failed\n";
		return false;
	}
	std::cout << "Listening on port " << port << "\n";
	return true;
}

bool BackendServer::acceptClient() {
	std::cout << "Waiting for client connection...\n";

	clientSocket = accept(serverSocket, nullptr, nullptr);
	if (clientSocket == INVALID_SOCKET) {
		std::cout << "Accept Failed\n";
		return false;
	}
	std::cout << " Client connected successfully\n";
	return true;
}

bool BackendServer::receiveData() {
	char buffer[1024] = { 0 };

	int bytesReceived = recv(clientSocket, buffer, sizeof(buffer), 0);
	if (bytesReceived == SOCKET_ERROR) {
		std::cout << "Receive Failed\n";
		return false;
	}

	if (bytesReceived == 0) {
		std::cout << " Client disconnected\n";
		return false;
	}
	std::cout << "Received Data: " << buffer << "\n";
	return true;
}

bool BackendServer::sendData(const char* message) {
	int bytesSent = send(clientSocket, message, strlen(message), 0);
	if (bytesSent == SOCKET_ERROR) {
		std::cout << "Send Failed\n";
		return false;
	}

	std::cout << "Sent " << bytesSent << " bytes to client.\n";
	return true;
}


bool BackendServer::handleClient()
{
	if (!acceptClient())
		return false;

	if (!receiveData())
		return false;

	std::string response = "Hello from " + serverName + " (Port " + std::to_string(port) + ")";

	if (!sendData(response.c_str()))
		return false;

	closesocket(clientSocket);
	clientSocket = INVALID_SOCKET;

	return true;
}


void BackendServer::cleanup() {
	if (clientSocket != INVALID_SOCKET)
		closesocket(clientSocket);
	if (serverSocket != INVALID_SOCKET)
		closesocket(serverSocket);

	WSACleanup();
}