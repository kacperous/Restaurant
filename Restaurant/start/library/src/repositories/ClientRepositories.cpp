#include "../../include/repositories/ClientRepositories.h"
#include <algorithm>
#include "model/typedefs.h"
void ClientRepository::addClient(ClientPtr client) {
    clients.push_back(client);
}

void ClientRepository::removeClient(ClientPtr client) {
    clients.erase(std::remove(clients.begin(), clients.end(), client), clients.end());
}

std::vector<ClientPtr> ClientRepository::findBy(ClientPredicate predicate) const {
    std::vector<ClientPtr> result;
    for (ClientPtr client : clients) {
        if (predicate(client)) {
            result.push_back(client);
        }
    }
    return result;
}
