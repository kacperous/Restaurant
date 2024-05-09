#ifndef CARRENTAL_DIAMOND_H
#define CARRENTAL_DIAMOND_H
#include "ClientType.h"

class Diamond : public ClientType {
public:
    int getMaxVehicles() const override { return 10; }
    double applyDiscount(double price) const override {
        if (price <= 125) return price * 0.90;
        else if (price <= 250) return price * 0.80;
        else if (price <= 500) return price * 0.70;
        else return price * 0.60;
    }
    std::string getInfo() const override { return "Diamond"; }
};
#endif //CARRENTAL_DIAMOND_H
