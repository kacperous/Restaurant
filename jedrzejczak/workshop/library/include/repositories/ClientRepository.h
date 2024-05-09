//
// Created by student on 04.05.24.
//

#ifndef CARRENTAL_CLIENTREPOSITORY_H
#define CARRENTAL_CLIENTREPOSITORY_H
#include <vector>
#include <string>
#include <memory>
#include "model/Client.h"

class ClientRepository {
public:
    ClientRepository();
    ~ClientRepository();

    void add(std::shared_ptr<Client> client);
    void remove(std::shared_ptr<Client> client);
    std::shared_ptr<Client> get(int index) const;
    std::string report() const;
    size_t size() const;
    std::vector<std::shared_ptr<Client>> findAll() const;

private:
    std::vector<std::shared_ptr<Client>> clients;
};

#endif //CARRENTAL_CLIENTREPOSITORY_H
