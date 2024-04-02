#include "model/Rent.h"
#include "model/Client.h"

Rent::Rent(int id, const Client* client, const Vehicle* vehicle) : id(id), client(client), vehicle(vehicle) {}

int Rent::getId() const {
    return id;
}

const Client* Rent::getClient() const {
    return client;
}

const Vehicle* Rent::getVehicle() const {
    return vehicle;
}

string Rent::getInfo() const {
    return "id: " + to_string(id) + ", client: " + client->getFirstName() + ", vehicle: " + vehicle->getPlateNumber();
}
