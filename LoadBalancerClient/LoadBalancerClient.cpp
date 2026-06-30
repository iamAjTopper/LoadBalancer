#include "SocketClient.h"

int main() {
	SocketClient client;

	if(!client.intialize()){
		return 1;
	}

	if(!client.createSocket()){
		return 1;
	}

	if (!client.connectToServer()) {
		return 1;
	}

	client.sendData("Hello Server");
	client.receiveData();

	system("pause");

	client.cleanup();

	return 0;
}