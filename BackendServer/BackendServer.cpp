#include <iostream>
#include"BackendServers.h"

int main(int argc, char* argv[]) {

	if (argc != 3) {
		std::cout << "Usage:\n";
		std::cout << "BakendServer.exe <Port> <Name>\n";
		return 1;
	}
	unsigned short port = static_cast<unsigned short>(std::stoi(argv[1]));
	std::string name = argv[2];

	BackendServer backend(port, name);

	if (!backend.intialize())
		return 1;

	if (!backend.createSocket())
		return 1;

	if (!backend.bindSocket())
		return 1;

	if (!backend.startListening())
		return 1;

	while (true) {
		backend.handleClient();
	}
}