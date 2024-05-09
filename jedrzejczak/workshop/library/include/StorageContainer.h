//
// Created by student on 04.05.24.
//

#ifndef CARRENTAL_STORAGECONTAINER_H
#define CARRENTAL_STORAGECONTAINER_H
#include "repositories/ClientRepository.h"
#include "repositories/RentRepository.h"
#include "repositories/VehicleRepository.h"

class StorageContainer {
public:
    StorageContainer();
    ~StorageContainer();

    ClientRepository& getClientRepository();
    VehicleRepository& getVehicleRepository();
    RentRepository& getRentRepository();

private:
    ClientRepository clientRepository;
    VehicleRepository vehicleRepository;
    RentRepository rentRepository;

    void initializeTestData();
};

#endif //CARRENTAL_STORAGECONTAINER_H
