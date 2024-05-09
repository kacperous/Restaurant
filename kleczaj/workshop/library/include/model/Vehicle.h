#pragma once
#include <iostream>
#include "typedefs.h"
using namespace std;
class Vehicle{
    string plateNumber;
    bool rented;
protected:
    int basePrice;
public:
    Vehicle(string NrPlate,int Price, bool isRented){
        plateNumber=NrPlate;
        basePrice=Price;
        rented=isRented;
    }
    virtual ~Vehicle(){
    }
    string getPlateNumber() const;
    void setPlateNumber(const string &NrPlate);
    int getBasePrice() const;
    void setBasePrice(const int &Price);
    bool getRented() const;
    void setRented(const bool &isRented);
    virtual void getInfo() const;
    virtual double getActualRentalPrice() const;
};
