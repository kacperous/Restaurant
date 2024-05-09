#include "StorageContainer.h"
#include <memory>
#include <iostream>
#include <algorithm>

StorageContainer::StorageContainer() {
    initializeTestData();
}

StorageContainer::~StorageContainer() {

}

ClientRepository& StorageContainer::getClientRepository() {
    return clientRepository;
}

VehicleRepository& StorageContainer::getVehicleRepository() {
    return vehicleRepository;
}

RentRepository& StorageContainer::getRentRepository() {
    return rentRepository;
}

void StorageContainer::initializeTestData() {
    // Tworzenie przykładowych danych dla Client
    auto client1 = std::make_shared<Client>("Jan", "Kowalski", "12345678901", std::make_shared<Address>("Warsaw"));
    auto client2 = std::make_shared<Client>("Anna", "Nowak", "23456789012", std::make_shared<Address>("Krakow"));
    clientRepository.add(client1);
    clientRepository.add(client2);

    // Tworzenie przykładowych danych dla Vehicle
    auto vehicle1 = std::make_shared<Vehicle>("WX1234", 100, false);
    auto vehicle2 = std::make_shared<Vehicle>("WX5678", 150, false);
    vehicleRepository.add(vehicle1);
    vehicleRepository.add(vehicle2);

    // Tworzenie przykładowych danych dla Rent
    auto rent1 = std::make_shared<Rent>(1, client1, vehicle1);
    auto rent2 = std::make_shared<Rent>(2, client2, vehicle2);
    rentRepository.add(rent1);
    rentRepository.add(rent2);
}
