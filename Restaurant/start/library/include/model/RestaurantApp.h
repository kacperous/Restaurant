#ifndef RESTAURANT_APP_H
#define RESTAURANT_APP_H

#include <vector>
#include <memory>
#include <fstream>
#include <ctime>
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
#include "StorageContainer.h"
#include "managers/TableManager.h"
#include "repositories/TableRepositories.h"

class RestaurantApp {
public:
    RestaurantApp();
    void run();

private:
    void showMenu();
    void addClient();
    void addTable();
    void addReservation();
    void showRestaurantInfo();
    void showReservations();
    void showClientReservations();
    void checkClient();
    void removeTable();
    void removeClient();
    void saveState();
    void loadState();

    AddressPtr address;
    Restaurant restaurant;
    StorageContainer storageContainer;
    ClientManager clientManager; // Adjusted to use the repository
    TableManager tableManager;
    ReservationManager reservationManager;
    ClientRepository clientRepository;
    TableRepository tableRepository;
    ReservationRepository reservationRepository;
    std::vector<ClientPtr> clients;
    std::vector<TablePtr> tables;
    std::vector<ReservationPtr> reservations;
};

#endif // RESTAURANT_APP_H
