#include "LoadBalancers.h"
#include<iostream>

void LoadBalancer::addBackend(const Server& server) {
	backends.push_back(server);
}

void LoadBalancer::listBackend()const {
	std::cout << "\n ===== Registered Backends =====\n\n";
	
	for (const auto& server : backends) {
		std::cout << server.getHost() << ":" << server.getPort() << "\n";
	}

	std::cout << "\nTotal: " << backends.size() << "\n";
}