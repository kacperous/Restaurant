//
// Created by student on 07.05.24.
//
#include "model/MotorVehicle.h"
MotorVehicle::MotorVehicle(std::string NrPlate, int Price, bool isRented, int engineDisplacement): Vehicle(NrPlate,Price,isRented),engineDisplacement(engineDisplacement){}
double MotorVehicle::getActualRentalPrice() const {
    if(engineDisplacement<=1000){
        return basePrice*1.0;
    }
    else if(engineDisplacement>1000 and engineDisplacement<=2000){
        return basePrice*(1.0+0.5*(engineDisplacement-1000)/1000);
    }
    else
        return basePrice*1.5;
}
void MotorVehicle::getInfo() const {
    cout<<"pojemnosc silnika: "<<engineDisplacement<<" ";
    Vehicle::getInfo();
}