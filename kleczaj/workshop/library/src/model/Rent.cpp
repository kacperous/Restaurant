#include "model/Rent.h"
#include "model/Client.h"
#include <boost/date_time.hpp>
namespace pt=boost::posix_time;
namespace gr = boost::gregorian;
Rent::Rent(int id, ClientPtr client, VehiclePtr vehicle,pt::ptime beginTime,pt::ptime endTime){
    this->id=id;
    this->client=client;
    this->vehicle=vehicle;
    this->beginTime=beginTime;
    this->endTime=endTime;
    vehicle->setRented(true);
}

int Rent::getId() const {
    return id;
}

const ClientPtr& Rent::getClient() const {
    return client;
}

const VehiclePtr& Rent::getVehicle() const {
    return vehicle;
}

string Rent::getInfo() const {
    return "id: " + to_string(id) + ", client: " + client->getFirstName() + ", vehicle: " + vehicle->getPlateNumber();
}
int Rent::getRentDays() const {
    if (endTime == pt::not_a_date_time) {
        return 0;
    } else {
        pt::time_duration duration = endTime - beginTime;
        int totalSeconds = duration.total_seconds();
        int days = totalSeconds / (24 * 3600); // Liczba sekund w jednym dniu
        if (totalSeconds % (24 * 3600) > 0) {
            days += 1;
        }
        return days;
    }
}
int Rent::getRentCost() const {
    int days= Rent::getRentDays();
    int price= vehicle->getBasePrice();
    return days*price;
}
pt::ptime Rent::endRent(){
    if (beginTime > pt::ptime(gr::date(1970, 1, 1))) {
        endTime = pt::second_clock::local_time();
        vehicle->setRented(false);
        client->removeRent();
    }
    return endTime;
}
pt::ptime Rent::getBeginTime() const{
    return beginTime;
}
pt::ptime Rent::getEndTime() const{
    return endTime;
}
