#include "../../include/model/Rent.h"
#include "../../include/model/Client.h"  // Include the full definition of Client
#include "../../include/typedefs.h"
typedef std::shared_ptr<Client> ClientPtr;
typedef std::shared_ptr<Vehicle> VehiclePtr;

Rent::Rent(int id, std::shared_ptr<Client> client, std::shared_ptr<Vehicle> vehicle)
        : id(id), client(client), vehicle(vehicle) {}

int Rent::getId() const {
    return id;
}

ClientPtr Rent::getClient() const {
    return client;
}

VehiclePtr Rent::getVehicle() const {
    return vehicle;
}

std::string Rent::getInfo() const {
    return "Rent ID: " + std::to_string(id) + ", Client Info: " + client->getInfo() + ", Vehicle Info: " + vehicle->getInfo();
}