//
// Created by student on 07.05.24.
//
#include "model/Moped.h"
Moped::Moped(std::string NrPlate, int Price, bool isRented, int engineDisplacement): MotorVehicle(NrPlate,Price,isRented,engineDisplacement) {}
double Moped::getActualRentalPrice() const {
    double price = MotorVehicle::getActualRentalPrice();
    return price;
}
void Moped::getInfo() const {
    MotorVehicle::getInfo();
}