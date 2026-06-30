#include"SocketClient.h"

SocketClient::SocketClient() {
	clientSocket = INVALID_SOCKET;
}

bool SocketClient::intialize() {
	if (WSAStartup(MAKEWORD(2, 2), &wsaData) != 0) {
		std::cout << "WSAStartup failed with error: " << WSAGetLastError() << std::endl;
		return false;
	}
	std::cout << "WinSock initialized successfully." << std::endl;
	return true;
}

bool SocketClient::createSocket() {
	clientSocket = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
	if (clientSocket == INVALID_SOCKET) {
		std::cout << "Socket Creation Failed\n";
		return false;
	}
	std::cout << "Client Socket Created Successfully\n";
	return true;
}

bool SocketClient::connectToServer() {
	serverAddress.sin_family = AF_INET;
	serverAddress.sin_port = htons(9001);

	inet_pton(AF_INET, "127.0.0.1", &serverAddress.sin_addr);

	std::cout << " Connecting to server...\n";
	if (connect(clientSocket, (sockaddr*)&serverAddress, sizeof(serverAddress)) == SOCKET_ERROR){
		std::cout << "Connection to server failed with error: " << WSAGetLastError() << std::endl;
		return false;
	}
	std::cout << "Connected to server successfully.\n";
	return true;
}

bool SocketClient::sendData(const char* message) {
	int bytesSent = send(clientSocket, message, strlen(message), 0);
	
	if(bytesSent == SOCKET_ERROR){
		std::cout << "Send Failed with error: " << WSAGetLastError() << std::endl;
		return false;
	}

	std::cout << "Sent " << bytesSent << " bytes to server.\n";
	return true;
}

bool SocketClient::receiveData() {
	char buffer[1024] = { 0 };

	int bytesReceived = recv(clientSocket, buffer, sizeof(buffer), 0);

	if (bytesReceived == SOCKET_ERROR) {
		std::cout << "Receive Failed\n";
		return false;
	}

	if (bytesReceived == 0) {
		std::cout << "Server Disconnected";
		return false;
	}

	std::cout << "Server says:" << buffer << "\n";

	return true;
}

void SocketClient::cleanup() {
	closesocket(clientSocket);
	WSACleanup();
}