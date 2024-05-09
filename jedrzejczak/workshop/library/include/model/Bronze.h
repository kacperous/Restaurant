
#ifndef CARRENTAL_BRONZE_H
#define CARRENTAL_BRONZE_H
#include "ClientType.h"

class Bronze : public ClientType {
public:
    int getMaxVehicles() const override { return 2; }
    double applyDiscount(double price) const override { return price - 3; }
    std::string getInfo() const override { return "Bronze"; }
};
#endif //CARRENTAL_BRONZE_H
