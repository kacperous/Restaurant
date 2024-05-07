//
// Created by student on 07.05.24.
//
#ifndef CARRENTAL_CAR_H
#define CARRENTAL_CAR_H
#include "MotorVehicle.h"

enum SegmentType  {A,B,C,D,E};

class Car : public MotorVehicle{
    SegmentType Segment;
public:
    Car(string NrPlate,int Price,bool isRented,int engineDisplacement,SegmentType Segment);
    double getActualRentalPrice() const override;
    void getInfo() const override;

};
#endif //CARRENTAL_CAR_H
