#ifndef RESTAURANT_CLIENTREPOSITORIES_H
#define RESTAURANT_CLIENTREPOSITORIES_H
#include <vector>
#include <functional>
#include "model/Client.h"

using ClientPredicate = std::function<bool(Client*)>;

class ClientRepository {
public:
    void addClient(Client* client);
    void removeClient(Client* client);
    std::vector<Client*> findBy(ClientPredicate predicate) const;

private:
    std::vector<Client*> clients;
};

#endif //RESTAURANT_CLIENTREPOSITORIES_H
