#ifndef VEHICLE_H
#define VEHICLE_H

#include <string>

class Vehicle {
private:
    std::string plateNumber;
    unsigned int basePrice;

public:
    Vehicle(const std::string& plateNumber, unsigned int basePrice);

    std::string getPlateNumber() const;
    unsigned int getBasePrice() const;

    void setPlateNumber(const std::string& plateNumber);
    void setBasePrice(unsigned int basePrice);

    std::string getInfo() const;
};

#endif // VEHICLE_H
