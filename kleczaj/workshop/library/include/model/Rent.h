#pragma once
#include <iostream>
#include "model/Vehicle.h"
#include "model/Client.h"
#include <boost/date_time.hpp>
#include "typedefs.h"
namespace pt=boost::posix_time;
using namespace std;
class Rent {
    int id;
    ClientPtr client;
    VehiclePtr vehicle;
    pt::ptime beginTime;
    pt::ptime endTime;
    int rentCost;

public:
    Rent(int id,ClientPtr client, VehiclePtr vehicle,pt::ptime beginTime,pt::ptime endTime);
    ~Rent(){};
    string getInfo() const;
    const ClientPtr& getClient() const;
    const VehiclePtr& getVehicle() const;
    int getId() const;
    int getRentCost() const;
    pt::ptime endRent();
    int getRentDays() const;
    pt::ptime getBeginTime() const;
    pt::ptime getEndTime() const;
    string toString() const {
        return to_string(id);
    }
};
