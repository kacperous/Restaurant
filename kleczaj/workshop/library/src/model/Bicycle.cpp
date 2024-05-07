//
// Created by student on 07.05.24.
//
#include "model/Bicycle.h"
Bicycle::Bicycle(std::string NrPlate, int Price, bool isRented): Vehicle(NrPlate,Price,isRented) {}
double Bicycle::getActualRentalPrice() const {
    return basePrice;
}
void Bicycle::getInfo() const {
    Vehicle::getInfo();
}
