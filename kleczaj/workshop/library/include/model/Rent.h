#pragma once
#include <iostream>
#include "model/Vehicle.h"
#include <boost/date_time.hpp>
namespace pt=boost::posix_time;
using namespace std;
class Client;
class Rent {
    int id;
    Client *client;
    Vehicle *vehicle;
    pt::ptime beginTime;
    pt::ptime endTime;
    int rentCost;

public:
    Rent(int id,Client* client, Vehicle *vehicle,pt::ptime beginTime,pt::ptime endTime);
    string getInfo() const;
    const Client* getClient() const;
    const Vehicle* getVehicle() const;
    int getId() const;
    int getRentCost() const;
    pt::ptime endRent();
    int getRentDays() const;
    pt::ptime getBeginTime() const;
    pt::ptime getEndTime() const;
};
