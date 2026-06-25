#pragma once

#include<vector>
#include"Server.h"

//stores and manages every backend server known to load balancer
class ServerManager {
private:
	//dynamic list of backend server
	std::vector<Server> servers;

public:
	//add a backend
	void addServer(const Server& server);
	//remove backend by port
	void removeServer(int port);
	//print all backend server
	void listServers() const;
	//number of servers
	int getServerCount() const;
	//find server
	Server* findServer(int port);
	//check dupliate
	bool serverExists(int port) const;

};