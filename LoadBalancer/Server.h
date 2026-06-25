#pragma once

#include<string>

class Server {
private:
	//IP addreess of the backend server
	std::string host;
	//port on whihc bakcend listens
	int port;
	//whethr the backend is alive
	bool healthy;
	//current ative lient onnections to the backend serve
	int activeConnections;
	
public:
	//comstructor to initialize the server with host and port
	Server(std::string host, int port);
	//getter methods to access the private members
	std::string getHost() const;
	int getPort() const;

	bool isHealthy() const;
	//setter method to set the health status of the server
	void setHealthy(bool healthy);
	//getter method to get the number of active connections
	int getActiveConnections() const;
	void incrementActiveConnections();
	void decrementActiveConnections();

	void printInfo() const;
	
};