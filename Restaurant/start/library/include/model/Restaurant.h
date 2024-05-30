#ifndef RESTAURANT_RESTAURANT_H
#define RESTAURANT_RESTAURANT_H
#include <string>
#include <vector>
#include "Adress.h"
#include "Table.h"
#include "Reservation.h"


class Restaurant {
public:
    Restaurant(const std::string& name, AddressPtr address);

    std::string getName() const;
    AddressPtr getAddress() const;
    std::string getInfo() const;

    void addTable(TablePtr table);
    void showTables() const;
    void removeTable(TablePtr table);

    void addReservation(ReservationPtr reservation);
    void showReservations() const;
    void removeReservation(ReservationPtr reservation);

private:
    std::string name;
    AddressPtr address;
    std::vector<TablePtr> tables;
    std::vector<ReservationPtr> reservations;
};

#endif //RESTAURANT_RESTAURANT_H
