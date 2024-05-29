#include "managers/ClientManager.h"

std::vector<ReservationPtr> ClientManager::getClientReservations(ClientPtr client, const std::vector<ReservationPtr>& reservations) const {
    std::vector<ReservationPtr> clientReservations;
    for (ReservationPtr reservation : reservations) {
        if (reservation->getClient() == client) {
            clientReservations.push_back(reservation);
        }
    }
    return clientReservations;
}

bool ClientManager::checkClient(ClientPtr  client) const {
    auto foundClients = repository.findBy([client](ClientPtr  c) {
        return c == client;
    });
    return !foundClients.empty();
}