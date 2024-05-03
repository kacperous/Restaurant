#ifndef VEHICLE_H
#define VEHICLE_H

#include <string>
using namespace std;

class Vehicle {
private:
    string plateNumber;
    unsigned int basePrice;
    bool rented;

public:
    Vehicle(const string& plateNumber, unsigned int basePrice,bool rented);

    string getPlateNumber() const;
    unsigned int getBasePrice() const;
    bool getRented() const;

    void setPlateNumber(const string& plateNumber);
    void setBasePrice(unsigned int basePrice);
    void setRented(bool rented);

    string getInfo() const;
    string getActualRentalPrice() const;
};

#endif // VEHICLE_H
