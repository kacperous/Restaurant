//
// Created by student on 07.05.24.
//
#ifndef CARRENTAL_BICYCLE_H
#define CARRENTAL_BICYCLE_H
#include "Vehicle.h"

class Bicycle : public Vehicle{
public:
    Bicycle(string NrPlate,int Price,bool isRented);
    double  getActualRentalPrice() const override;
    void getInfo() const override;
};

#endif //CARRENTAL_BICYCLE_H
