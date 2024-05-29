#ifndef RESTAURANT_CLIENTREPOSITORIES_H
#define RESTAURANT_CLIENTREPOSITORIES_H
#include <vector>
#include <functional>
#include "model/Client.h"
#include "model/typedefs.h"

using ClientPredicate = std::function<bool(ClientPtr)>;

class ClientRepository {
public:
    void addClient(ClientPtr client);
    void removeClient(ClientPtr client);
    std::vector<ClientPtr> findBy(ClientPredicate predicate) const;

private:
    std::vector<ClientPtr> clients;
};

#endif //RESTAURANT_CLIENTREPOSITORIES_H
