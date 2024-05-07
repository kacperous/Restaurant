
#ifndef CARRENTAL_MOTORVEHICLE_H
#define CARRENTAL_MOTORVEHICLE_H
#include "Vehicle.h"

using namespace std;
class MotorVehicle: public Vehicle{
private:
 int  engineDisplacement;
public:
    MotorVehicle(const string& plateNumber, unsigned int basePrice, bool rented, int engineDisplacement);

    std::string getActualRentalPrice() const ;
    std::string getInfo() const ;
};
#endif //CARRENTAL_MOTORVEHICLE_H
