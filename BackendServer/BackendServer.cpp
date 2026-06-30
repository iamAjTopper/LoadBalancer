#include <iostream>
#include"BackendServers.h"

int main() {
	BackendServer backend(9001, "Backend 1");

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