#include "../../include/model/Vehicle.h"

Vehicle::Vehicle(const std::string& plateNumber, unsigned int basePrice,bool rented)
        : plateNumber(plateNumber), basePrice(basePrice), rented(rented){}

std::string Vehicle::getPlateNumber() const {
    return plateNumber;
}

unsigned int Vehicle::getBasePrice() const {
    return basePrice;
}
bool Vehicle::getRented() const {
    return rented;
}
void Vehicle::setPlateNumber(const std::string& plateNumber) {
    this->plateNumber = plateNumber;
}

void Vehicle::setBasePrice(unsigned int basePrice) {
    this->basePrice = basePrice;
}
void Vehicle::setRented(bool rented){
    this->rented=rented;
}

string Vehicle::getInfo() const {
    return "Plate Number: " + plateNumber + ", Base Price: " + std::to_string(basePrice);
}
string Vehicle::getActualRentalPrice() const{
    return "ActualRentalPrice: " + to_string(basePrice);
}
