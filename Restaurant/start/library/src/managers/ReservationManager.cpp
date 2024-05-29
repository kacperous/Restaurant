#include "managers/ReservationManager.h"

std::vector<ReservationPtr> ReservationManager::createReservation(ReservationPtr reservation, std::vector<std::shared_ptr<Client>> clients) {
    std::vector<ReservationPtr> reservations;
    for (auto& client : clients) {
        ReservationPtr newReservation = std::make_shared<Reservation>(reservation->getReservationId(), reservation->getDate(), client, reservation->getTable());
        repository.addReservation(newReservation);
        reservations.push_back(newReservation);
    }
    return reservations;
}

int ReservationManager::countReservation() const {
    return repository.findBy([](ReservationPtr) {
        return true;
    }).size();
}