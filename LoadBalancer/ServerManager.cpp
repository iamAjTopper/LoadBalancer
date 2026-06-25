#include<iostream>
#include"ServerManager.h"

//add a backend server to the list and duplicate check
void ServerManager::addServer(const Server& server) {
	if (serverExists(server.getPort())) {
		std::cout << "Server already exist.\n";
		return;
	}
	servers.push_back(server);

	std::cout << "Server added successfully.\n";
}

//removae backend
void ServerManager::removeServer(int port) {
	for (auto it = servers.begin(); it != servers.end(); ++it) {
		if (it->getPort() == port) {
			servers.erase(it);
			std::cout << "Server removed\n";
		}
	}
	std::cout << "Server not found\n";
}

//print every backend
void ServerManager::listServers() const {
	std::cout << "\n===========Server List===========\n";

	for (const auto& server : servers) {
		server.printInfo();
	}
}

//total backend coubnt
int ServerManager::getServerCount() const {
	return servers.size();
}

//find servwer by port
Server* ServerManager::findServer(int port) {
	for (auto& server : servers) {
		if (server.getPort() == port) {
			return &server;
		}
	}
	return nullptr;
}

//checks duplicate ports
bool ServerManager::serverExists(int port) const {
	for (const auto& server : servers) {
		if (server.getPort() == port) {
			return true;
		}
	}
	return false;
}
