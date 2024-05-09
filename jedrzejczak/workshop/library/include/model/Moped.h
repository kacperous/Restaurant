#ifndef CARRENTAL_MOPED_H
#define CARRENTAL_MOPED_H
#include "MotorVehicle.h"

using namespace std;
class Moped : public MotorVehicle{
private:

public:
    Moped(const std::string& plateNumber, unsigned int basePrice, bool rented,int engineDisplacement);

    std::string getActualRentalPrice() const ;
    std::string getInfo() const ;
};

#endif //CARRENTAL_MOPED_H
