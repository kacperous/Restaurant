#ifndef CARRENTAL_BICYCLE_H
#define CARRENTAL_BICYCLE_H

#include "Vehicle.h"

using namespace std;
class Bicycle : public Vehicle{
private:

public:
    Bicycle(const std::string& plateNumber, unsigned int basePrice, bool rented);

    std::string getActualRentalPrice() const ;
    std::string getInfo() const ;
};

#endif //CARRENTAL_BICYCLE_H
