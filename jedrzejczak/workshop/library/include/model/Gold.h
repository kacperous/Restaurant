//
// Created by student on 03.05.24.
//

#ifndef CARRENTAL_GOLD_H
#define CARRENTAL_GOLD_H
#include "ClientType.h"

class Gold : public ClientType {
public:
    int getMaxVehicles() const override { return 4; }
    double applyDiscount(double price) const override { return price * 0.95; } // 5% upust
    std::string getInfo() const override { return "Gold"; }
};

#endif //CARRENTAL_GOLD_H
