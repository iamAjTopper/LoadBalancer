#include"Server.h"
#include<iostream>

Server::Server(std::string host, int port) : host(host), port(port), healthy(true), activeConnections(0) {};

//return server ip
std::string Server::getHost() const {
	return host;
}

//return server port
int Server::getPort() const {
	return port;
}
//return whetere the backend is ghealthy
bool Server::isHealthy() const {
	return healthy;
}

//return numbert of active connections
int Server::getActiveConnections() const {
	return activeConnections;
}

//update health status
void Server::setHealthy(bool status) {
	healthy = status;
}

//called qwhenever a ne request is routed to the backend
void Server::incrementActiveConnections() {
	activeConnections++;
}

//called when a request is completed and the connection is closed
void Server::decrementActiveConnections() {
	if (activeConnections > 0) {
		activeConnections--;
	}
}

void Server::printInfo() const {
	std::cout << "------------------------------\n";

	std::cout << "Host: " << host << "\n";
	std::cout << "Port: " << port << "\n";
	std::cout << "Healthy";
	if (healthy) {
		std::cout << "Yes\n";
	}
	else {
		std::cout << "No\n";
	}

	std::cout << "Active Connections: " << activeConnections << "\n";
	std::cout << "------------------------------\n";
}