#ifndef RESTAURANT_CLIENTMANAGER_H
#define RESTAURANT_CLIENTMANAGER_H
#include "repositories/ClientRepositories.h"
#include "model/Reservation.h"

class ClientManager {
public:
    std::vector<ReservationPtr> getClientReservations(ClientPtr client, const std::vector<ReservationPtr>& reservations) const;
    bool checkClient(ClientPtr client) const;

private:
    ClientRepository repository;
};
#endif //RESTAURANT_CLIENTMANAGER_H
