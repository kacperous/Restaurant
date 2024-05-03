#pragma once
#include <iostream>
using namespace std;
class Vehicle{
    string plateNumber;
    int basePrice;
    bool rented;
public:
    Vehicle(string NrPlate,int Price, bool isRented){
        plateNumber=NrPlate;
        basePrice=Price;
        rented=isRented;
    }
    ~Vehicle(){
    }
    string getPlateNumber() const;
    void setPlateNumber(const string &NrPlate);
    int getBasePrice() const;
    void setBasePrice(const int &Price);
    bool getRented() const;
    void setRented(const bool &isRented);
    void getInfo();
};
