#include "managers/ClientManager.h"

std::vector<ReservationPtr> ClientManager::getClientReservations(ClientPtr client, const std::vector<ReservationPtr>& reservations) const {
    if (!client) {
        throw ClientNotFoundException("Client pointer is null.");
    }

    std::vector<ReservationPtr> clientReservations;
    for (const auto& reservation : reservations) {
        if (reservation->getClient() == client) {
            clientReservations.push_back(reservation);
        }
    }

    if (clientReservations.empty()) {
        throw ClientNotFoundException("No reservations found for the given client.");
    }

    return clientReservations;
}

bool ClientManager::checkClient(ClientPtr client) const {
    if (!client) {
        throw ClientNotFoundException("Client pointer is null.");
    }

    auto foundClients = repository.findBy([client](ClientPtr c) {
        return c == client;
    });

    if (foundClients.empty()) {
        throw ClientNotFoundException("Client not found in the repository.");
    }

    return true;
}
