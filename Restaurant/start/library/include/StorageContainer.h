#ifndef RESTAURANT_STORAGECONTAINER_H
#define RESTAURANT_STORAGECONTAINER_H
#include "repositories/ClientRepositories.h"
#include "repositories/ReservationRepositories.h"
#include "repositories/RestaurantRepositories.h"
#include "repositories/TableRepositories.h"
#include "model/Restaurant.h"
#include "model/VIP.h"
#include "model/Default.h"

class StorageContainer{
private:
    ClientRepository clientRepository;
    ReservationRepository reservationRepository;
    RestaurantRepository restaurantRepository;
    TableRepository tableRepository;
public:
    StorageContainer(){
        initializeTestData();
    }


    const ClientRepository &getClientRepository() const;
    const ReservationRepository &getReservationRepository() const;
    const TableRepository &getTableRepository() const;
    const RestaurantRepository &getRestaurantRepository() const;
private:
    void initializeTestData();
};
#endif //RESTAURANT_STORAGECONTAINER_H