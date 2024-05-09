//
// Created by student on 08.05.24.
//

#ifndef CARRENTAL_STORAGECONTAINER_H
#define CARRENTAL_STORAGECONTAINER_H
#include "repositories/ClientRepository.h"
#include "repositories/RentRepository.h"
#include "repositories/VehicleRepository.h"
#include "model/Client.h"
#include "model/Adress.h"
#include "model/Vehicle.h"
#include "model/Rent.h"
#include "model/typedefs.h"
class StorageContainer{
    ClientRepository clientRepository;
    VehicleRepository vehicleRepository;
    RentRepository rentRepository;
public:
    StorageContainer(){
        initializeTestData();
    }
    ClientRepository& getClientRepository() {
        return clientRepository;
    }

    VehicleRepository& getVehicleRepository() {
        return vehicleRepository;
    }

    RentRepository& getRentRepository() {
        return rentRepository;
    }
private:
    void initializeTestData() {
        auto adress= make_shared<Adress>("Skarzysko-Kamienna","Politechniczna","2");
        ClientType *gold= new Gold();
        auto client= make_shared < Client> ("kacper", "kleczaj", "1", adress, gold);
        auto vehicle = make_shared<Vehicle>("TSK24151",500,1);
        pt::ptime beginTime = pt::second_clock::local_time();
        pt::ptime endTime = beginTime + pt::minutes(1);
        auto rent = make_shared<Rent>(1,client,vehicle,beginTime,endTime);
        clientRepository.add(client);
        vehicleRepository.add(vehicle);
        rentRepository.add(rent);
    }
};

#endif //CARRENTAL_STORAGECONTAINER_H
