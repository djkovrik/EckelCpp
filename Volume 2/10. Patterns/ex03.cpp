/*
Using SingletonPattern.cpp as a starting point, create
a class that manages a fixed number of its own objects.
Assume the objects are database connections and you only
have a license to use a fixed quantity of these at any one time.
*/

#include <iostream>

class ConnectionsManager {
	static ConnectionsManager s;
	static int connections_counter;
	int connections_limit;
	ConnectionsManager(int x) : connections_limit(x) { }
	ConnectionsManager& operator=(ConnectionsManager&);
	ConnectionsManager(const ConnectionsManager&);

public:
	static ConnectionsManager& instance() { return s; }
	void connected()    {
		std::cout << "Connection " << ++connections_counter << " has been established.\n";;
	}
	void disconnected() {
		std::cout << "Connection " << connections_counter-- << " has been closed.\n";;
	}
	bool is_connect_allowed() { return connections_counter < connections_limit; }
};

ConnectionsManager ConnectionsManager::s(3);
int ConnectionsManager::connections_counter = 0;

int main() {

	ConnectionsManager& manager = ConnectionsManager::instance();

	for (int i = 1; i < 10; i++) {

		if ( manager.is_connect_allowed() )
			manager.connected();
		else {
			std::cout << "Connections limit!\n";
			break;
		}
	}

	manager.disconnected();
	manager.connected();

return 0;
}
