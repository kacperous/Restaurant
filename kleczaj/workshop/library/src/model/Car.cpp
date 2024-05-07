//
// Created by student on 07.05.24.
//
#include "model/Car.h"
Car::Car(std::string NrPlate, int Price, bool isRented, int engineDisplacement, SegmentType Segment): MotorVehicle(NrPlate,Price,isRented,engineDisplacement), Segment(Segment) {}
double Car::getActualRentalPrice() const {
    double price = MotorVehicle::getActualRentalPrice();
    switch (Segment) {
        case SegmentType::A:
            return price*1.0;
        case SegmentType::B:
            return price*1.1;
        case SegmentType::C:
            return price*1.2;
        case SegmentType::D:
            return price*1.3;
        case SegmentType::E:
            return price*1.5;
    }
    return price;
}
void Car::getInfo() const {
    cout<<"segment: "<<Segment;
    MotorVehicle::getInfo();
}