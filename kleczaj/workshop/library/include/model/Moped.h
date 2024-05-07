//
// Created by student on 07.05.24.
//

#ifndef CARRENTAL_MOPED_H
#define CARRENTAL_MOPED_H
#include "MotorVehicle.h"
//motorower
class Moped : public MotorVehicle{
public:
    Moped(string NrPlate,int Price,bool isRented,int engineDisplacement);
    double getActualRentalPrice() const override;
    void getInfo() const override;
};
#endif //CARRENTAL_MOPED_H
