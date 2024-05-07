#include "model/Rent.h"
#include "model/Client.h"  // Include the full definition of Client

Rent::Rent(int id, Client* client, Vehicle* vehicle)
        : id(id), client(client), vehicle(vehicle) {}

int Rent::getId() const {
    return id;
}

Client* Rent::getClient() const {
    return client;
}

Vehicle* Rent::getVehicle() const {
    return vehicle;
}

std::string Rent::getInfo() const {
    return "Rent ID: " + std::to_string(id) + ", Client Info: " + client->getInfo() + ", Vehicle Info: " + vehicle->getInfo();
}
