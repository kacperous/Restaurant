#include "managers/ClientManager.h"

std::vector<ReservationPtr> ClientManager::getClientReservations(ClientPtr client, const std::vector<ReservationPtr>& reservations) const {
    try {
        checkClient(client); // Validate the client first

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
    } catch (const ClientNotFoundException& e) {
        // Handle the exception as needed, possibly log it and rethrow or return a default value
        // Here we're simply rethrowing it
        throw;
    }
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
