//
// Created by student on 03.05.24.
//

#ifndef CARRENTAL_DEFAULT_H
#define CARRENTAL_DEFAULT_H
#include "ClientType.h"

class Default : public ClientType {
public:
    int getMaxVehicles() const override { return 1; }
    double applyDiscount(double price) const override { return price; }  // Brak upustu
    std::string getInfo() const override { return "Default"; }
};

#endif //CARRENTAL_DEFAULT_H
