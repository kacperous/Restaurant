//
// Created by student on 07.05.24.
//
#ifndef CARRENTAL_MOTORVEHICLE_H
#define CARRENTAL_MOTORVEHICLE_H
#include "Vehicle.h"
//pojazd spalinowy
class MotorVehicle : public Vehicle{
    int engineDisplacement;
public:
    MotorVehicle (string NrPlate,int Price,bool isRented,int engineDisplacement);
    double getActualRentalPrice() const override;
    void getInfo() const override;
};

#endif //CARRENTAL_MOTORVEHICLE_H
