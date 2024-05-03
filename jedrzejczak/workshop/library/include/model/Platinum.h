//
// Created by student on 03.05.24.
//

#ifndef CARRENTAL_PLATINUM_H
#define CARRENTAL_PLATINUM_H
#include "ClientType.h"

class Platinum : public ClientType {
public:
    int getMaxVehicles() const override { return 5; }
    double applyDiscount(double price) const override { return price * 0.90; } // 10% upust
    std::string getInfo() const override { return "Platinum"; }
};
#endif //CARRENTAL_PLATINUM_H
