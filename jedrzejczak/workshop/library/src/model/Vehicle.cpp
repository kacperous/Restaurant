#include "../../include/model/Vehicle.h"

Vehicle::Vehicle(const std::string& plateNumber, unsigned int basePrice)
        : plateNumber(plateNumber), basePrice(basePrice) {}

std::string Vehicle::getPlateNumber() const {
    return plateNumber;
}

unsigned int Vehicle::getBasePrice() const {
    return basePrice;
}

void Vehicle::setPlateNumber(const std::string& plateNumber) {
    this->plateNumber = plateNumber;
}

void Vehicle::setBasePrice(unsigned int basePrice) {
    this->basePrice = basePrice;
}

std::string Vehicle::getInfo() const {
    return "Plate Number: " + plateNumber + ", Base Price: " + std::to_string(basePrice);
}
