//
// Created by student on 04.05.24.
//

#ifndef CARRENTAL_VEHICLEREPOSITORY_H
#define CARRENTAL_VEHICLEREPOSITORY_H
#include <vector>
#include <memory>
#include "model/Vehicle.h"

class VehicleRepository {
public:
    void add(std::shared_ptr<Vehicle> vehicle);
    void remove(std::shared_ptr<Vehicle> vehicle);
    std::shared_ptr<Vehicle> get(int index) const;
    std::string report() const;
    size_t size() const;
    std::vector<std::shared_ptr<Vehicle>> findAll() const;

private:
    std::vector<std::shared_ptr<Vehicle>> vehicles;
};

#endif //CARRENTAL_VEHICLEREPOSITORY_H
