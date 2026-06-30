#pragma once

#include <vector>
#include "Server.h"

class LoadBalancer {
private:
	std::vector<Server> backends;

public:
	void addBackend(const Server& server);

	void listBackend() const;
};