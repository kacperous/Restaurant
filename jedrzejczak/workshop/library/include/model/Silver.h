#ifndef CARRENTAL_SILVER_H
#define CARRENTAL_SILVER_H
#include "ClientType.h"

class Silver : public ClientType {
public:
    int getMaxVehicles() const override { return 3; }
    double applyDiscount(double price) const override { return price - 6; }
    std::string getInfo() const override { return "Silver"; }
};
#endif //CARRENTAL_SILVER_H
