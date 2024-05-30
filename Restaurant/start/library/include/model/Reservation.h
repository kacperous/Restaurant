#ifndef RESTAURANT_RESERVATION_H
#define RESTAURANT_RESERVATION_H
#include <iostream>
#include <ctime>
#include "typedefs.h"
class Reservation
{
public:
    Reservation(int reservationId, const tm &date, const ClientPtr &client, const TablePtr &table);
    std::string getInfo() const;
    virtual ~Reservation();

    int getReservationId() const;

    void setReservationId(int reservationId);

    const tm &getDate() const;

    void setDate(const tm &date);

    const ClientPtr &getClient() const;

    void setClient(const ClientPtr &client);

    const TablePtr &getTable() const;

    void setTable(const TablePtr &table);

private:
    int reservationID;
    std::tm date;
    ClientPtr client;
    TablePtr table;

};
#endif //RESTAURANT_RESERVATION_H
