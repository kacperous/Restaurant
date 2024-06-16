#ifndef CLIENTMANAGER_H
#define CLIENTMANAGER_H

#include <vector>
#include <memory>
#include <stdexcept>
#include "model/Client.h"
#include "model/Reservation.h"
#include "repositories/ClientRepositories.h"

class ClientManager {
public:
    explicit ClientManager(ClientRepository &repository) : repository(repository) {}

    std::vector<ReservationPtr> getClientReservations(ClientPtr client, const std::vector<ReservationPtr>& reservations) const;
    bool checkClient(ClientPtr client) const;

private:
    ClientRepository &repository;
};

// Define exceptions directly in the header
class ClientManagerException : public std::runtime_error {
public:
    explicit ClientManagerException(const std::string &message) : std::runtime_error(message) {}
};

class ClientNotFoundException : public ClientManagerException {
public:
    explicit ClientNotFoundException(const std::string &message) : ClientManagerException("Client not found: " + message) {}
};

#endif // CLIENTMANAGER_H
