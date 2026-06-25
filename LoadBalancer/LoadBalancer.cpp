#include <iostream>
#include "ServerManager.h"

int main()
{
    ServerManager manager;

    manager.addServer(Server("127.0.0.1", 8081));
    manager.addServer(Server("127.0.0.1", 8082));
    manager.addServer(Server("127.0.0.1", 8083));

    // Duplicate
    manager.addServer(Server("127.0.0.1", 8081));

    manager.listServers();

    std::cout
        << "\nTotal Servers : "
        << manager.getServerCount()
        << "\n";

    Server* backend = manager.findServer(8082);

    if (backend != nullptr)
    {
        std::cout
            << "\nFound server:\n";

        backend->incrementActiveConnections();
        backend->incrementActiveConnections();

        backend->printInfo();
    }

    manager.removeServer(8083);

    manager.listServers();

    std::cout<< "\nTotal Servers : "<< manager.getServerCount()<< "\n";
}