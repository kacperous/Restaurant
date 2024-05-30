#include <iomanip>
#include "model/Reservation.h"
#include "model/Client.h"
#include "model/Table.h"

Reservation::Reservation(int reservationId, const tm &date, const ClientPtr &client, const TablePtr &table)
        : reservationID(reservationId), date(date), client(client), table(table) {}

Reservation::~Reservation() {

}

int Reservation::getReservationId() const {
    return reservationID;
}

void Reservation::setReservationId(int reservationId) {
    reservationID = reservationId;
}

const tm &Reservation::getDate() const {
    return date;
}

void Reservation::setDate(const tm &Date) {
    Reservation::date = Date;
}

const ClientPtr &Reservation::getClient() const {
    return client;
}

void Reservation::setClient(const ClientPtr &Client) {
    Reservation::client = Client;
}

const TablePtr &Reservation::getTable() const {
    return table;
}

void Reservation::setTable(const TablePtr &Table) {
    Reservation::table = Table;
}
std::string Reservation::getInfo() const{
    std::ostringstream oss;
    oss << "ReservationId: " << reservationID
        << ", Date: " << std::put_time(&date, "%Y-%m-%d %H:%M:%S")
        << ", Client: " << (client ? client->getInfo() : "None")
        << ", Table: " << (table ? table->getInfo() : "None");
    return oss.str();
}