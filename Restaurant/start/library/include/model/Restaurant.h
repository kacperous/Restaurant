#ifndef RESTAURANT_RESTAURANT_H
#define RESTAURANT_RESTAURANT_H
#include <string>
#include <vector>
#include "Adress.h"
#include "Table.h"
#include "Reservation.h"
#include <algorithm>

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

    virtual ~Restaurant();
    void setName(const std::string &newName);
    void setAddress(const AddressPtr &newAddress);
    const std::vector<TablePtr> &getTables() const;
    void setTables(const std::vector<TablePtr> &newTables);
    const std::vector<ReservationPtr> &getReservations() const;
    void setReservations(const std::vector<ReservationPtr> &newReservations);

    TablePtr findTableBySize(int size);
    void modifyReservation(int reservationId,tm date,ClientPtr client, TablePtr table);

private:
    std::string name;
    AddressPtr address;
    std::vector<TablePtr> tables;
    std::vector<ReservationPtr> reservations;
};

#endif //RESTAURANT_RESTAURANT_H
