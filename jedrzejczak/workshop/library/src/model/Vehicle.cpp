#include "../../include/model/Vehicle.h"

Vehicle::Vehicle(const std::string& plateNumber, unsigned int basePrice, bool rented)
        : plateNumber(plateNumber), basePrice(basePrice), rented(rented) {}

std::string Vehicle::getPlateNumber() const {
    return plateNumber;
}

unsigned int Vehicle::getBasePrice() const {
    return basePrice;
}

bool Vehicle::getRented() const {
    return rented;
}

void Vehicle::setPlateNumber(const std::string& newPlateNumber) {
    if (plateNumber != newPlateNumber) {
        plateNumber = newPlateNumber;
    }
}

void Vehicle::setBasePrice(unsigned int newBasePrice) {
    if (basePrice != newBasePrice) {
        basePrice = newBasePrice;
    }
}

void Vehicle::setRented(bool newRented) {
    if (rented != newRented) {
        rented = newRented;
    }
}

std::string Vehicle::getInfo() const {
    return "Plate Number: " + plateNumber + ", Base Price: " + std::to_string(basePrice);
}

std::string Vehicle::getActualRentalPrice() const {
    return "Actual Rental Price: " + std::to_string(basePrice);
}
