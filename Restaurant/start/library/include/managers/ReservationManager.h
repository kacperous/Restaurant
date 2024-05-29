#ifndef RESTAURANT_RESERVATIONMANAGER_H
#define RESTAURANT_RESERVATIONMANAGER_H
#include "../repositories/ReservationRepositories.h"
#include "../model/typedefs.h"

class ReservationManager {
public:
    std::vector<ReservationPtr> createReservation(ReservationPtr reservation, std::vector<std::shared_ptr<Client>> clients);
    int countReservation() const;

private:
    ReservationRepository repository;
};
#endif //RESTAURANT_RESERVATIONMANAGER_H
