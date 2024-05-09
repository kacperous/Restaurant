#ifndef RENT_H
#define RENT_H
#include <memory>
#include "Vehicle.h"
#include "../typedefs.h"

class Client;

class Rent {
private:
    Rent(int id, Client *client, Vehicle *vehicle);

    int id;
    shared_ptr<Client> client;
    shared_ptr<Vehicle> vehicle;

public:
    Rent(int id, std::shared_ptr<Client> client, std::shared_ptr<Vehicle> vehicle);
    int getId() const;
    ClientPtr getClient() const;
    VehiclePtr getVehicle() const;
    std::string getInfo() const;
};

#endif // RENT_H
