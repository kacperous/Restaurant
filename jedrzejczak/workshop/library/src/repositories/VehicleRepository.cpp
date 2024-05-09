#include "repositories/VehicleRepository.h"
#include <sstream>
#include <algorithm>

void VehicleRepository::add(std::shared_ptr<Vehicle> vehicle) {
    if (vehicle) {
        vehicles.push_back(vehicle);
    }
}

void VehicleRepository::remove(std::shared_ptr<Vehicle> vehicle) {
    auto it = std::remove_if(vehicles.begin(), vehicles.end(),
                             [&vehicle](const std::shared_ptr<Vehicle>& v) { return v == vehicle; });
    vehicles.erase(it, vehicles.end());
}

std::shared_ptr<Vehicle> VehicleRepository::get(int index) const {
    if (index >= 0 && index < vehicles.size()) {
        return vehicles[index];
    }
    return nullptr;
}

std::string VehicleRepository::report() const {
    std::ostringstream oss;
    for (auto& vehicle : vehicles) {
        oss << vehicle->getInfo() << "\n";
    }
    return oss.str();
}

size_t VehicleRepository::size() const {
    return vehicles.size();
}

std::vector<std::shared_ptr<Vehicle>> VehicleRepository::findAll() const {
    return vehicles;
}
