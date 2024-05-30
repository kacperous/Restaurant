#include <iostream>
#include <memory>
#include <vector>
#include "model/Restaurant.h"
#include "model/Reservation.h"
#include "model/Client.h"
#include "model/Adress.h"
#include "model/Table.h"
#include "model/ClientType.h"
#include "model/Default.h"
#include "model/VIP.h"
#include "managers/ReservationManager.h"
#include "managers/ClientManager.h"

using namespace std;

int main() {
    // Create Address
    AddressPtr address = std::make_shared<Address>("City", "Main St", "123");

    // Create Client Types
    ClientTypePtr regularClientType = std::make_shared<Default>();
    ClientTypePtr vipClientType = std::make_shared<VIP>();

    // Create Clients
    ClientPtr client1 = std::make_shared<Client>(1, "John", "Doe", 123456789, address, regularClientType);
    ClientPtr client2 = std::make_shared<Client>(2, "Jane", "Smith", 987654321, address, vipClientType);

    // Create Tables
    TablePtr table1 = std::make_shared<Table>(1, 4, false, false);
    TablePtr table2 = std::make_shared<Table>(2, 6, false, true);

    // Create Restaurant
    Restaurant restaurant("Good Eats", address);
    restaurant.addTable(table1);
    restaurant.addTable(table2);

    std::cout << restaurant.getInfo() << std::endl;
    restaurant.showTables();

    // Create Reservations
    std::tm date = {};
    date.tm_year = 2024 - 1900;
    date.tm_mon = 4;  // May (months are 0-based)
    date.tm_mday = 29;
    date.tm_hour = 18;
    date.tm_min = 30;
    date.tm_sec = 0;

    ReservationPtr reservation1 = std::make_shared<Reservation>(1, date, client1, table1);
    ReservationPtr reservation2 = std::make_shared<Reservation>(2, date, client2, table2);

    restaurant.addReservation(reservation1);
    restaurant.addReservation(reservation2);

    restaurant.showReservations();

    // Client Manager
    ClientManager clientManager;
    std::vector<ReservationPtr> reservations = {reservation1, reservation2};

    auto client1Reservations = clientManager.getClientReservations(client1, reservations);
    std::cout << "Reservations for client1:\n";
    for (auto& res : client1Reservations) {
        std::cout << res->getInfo() << std::endl;
    }

    bool clientExists = clientManager.checkClient(client1);
    std::cout << "Client1 exists: " << clientExists << std::endl;

    // Reservation Manager
    ReservationManager reservationManager;
    std::vector<ClientPtr> clients = {client1, client2};
    auto newReservations = reservationManager.createReservation(reservation1, clients);
    for (const auto& res : newReservations) {
        std::cout << res->getInfo() << std::endl;
    }

    std::cout << "Total Reservations: " << reservationManager.countReservation() << std::endl;

    return 0;
}
