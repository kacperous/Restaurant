#ifndef RESTAURANT_RESERVATIONREPOSITORIES_H
#define RESTAURANT_RESERVATIONREPOSITORIES_H
#include <vector>
#include <functional>
#include "model/Reservation.h"
#include "model/typedefs.h"

using ReservationPtr = std::shared_ptr<Reservation>;
using ReservationPredicate = std::function<bool(ReservationPtr)>;

class ReservationRepository {
public:
    void addReservation(ReservationPtr reservation);
    ReservationPtr getReservation(size_t index) const;
    void removeReservation(ReservationPtr reservation);
    std::vector<ReservationPtr> findBy(ReservationPredicate predicate) const;

private:
    std::vector<ReservationPtr> reservations;
};
#endif //RESTAURANT_RESERVATIONREPOSITORIES_H
