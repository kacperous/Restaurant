#pragma once
#include <iostream>
#include "model/Vehicle.h"

using namespace std;
class Client;
class Rent {
    int id;
    const Client* client;
    const Vehicle* vehicle;

public:
    Rent(int id, const Client* client, const Vehicle* vehicle);
    string getInfo() const;
    const Client* getClient() const;
    const Vehicle* getVehicle() const;
    int getId() const;
};
