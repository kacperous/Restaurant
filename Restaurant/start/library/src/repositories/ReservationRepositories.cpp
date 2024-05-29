#include "../../include/repositories/ReservationRepositories.h"
#include "../../include/model/typedefs.h"
#include <algorithm>

void ReservationRepository::addReservation(ReservationPtr reservation) {
    reservations.push_back(reservation);
}

ReservationPtr ReservationRepository::getReservation(size_t index) const {
    if (index < reservations.size()) {
        return reservations[index];
    }
    return nullptr;
}

void ReservationRepository::removeReservation(ReservationPtr reservation) {
    reservations.erase(std::remove(reservations.begin(), reservations.end(), reservation), reservations.end());
}

std::vector<ReservationPtr> ReservationRepository::findBy(ReservationPredicate predicate) const {
    std::vector<ReservationPtr> result;
    for (ReservationPtr reservation : reservations) {
        if (predicate(reservation)) {
            result.push_back(reservation);
        }
    }
    return result;
}