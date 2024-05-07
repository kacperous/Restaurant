#ifndef RENT_H
#define RENT_H

#include "Vehicle.h"  // Assume this is correctly defined
class Client;  // Forward declaration of Client

class Rent {
private:
    int id;
    Client* client;
    Vehicle* vehicle;

public:
    Rent(int id, Client* client, Vehicle* vehicle);
    int getId() const;
    Client* getClient() const;
    Vehicle* getVehicle() const;
    std::string getInfo() const;
};

#endif // RENT_H
