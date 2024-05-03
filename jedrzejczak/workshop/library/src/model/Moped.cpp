#include "model/Moped.h"
#include "model/Vehicle.h"
using namespace std;

Moped::Moped(const string& plateNumber, unsigned int basePrice, bool rented,int engineDisplacement)
        : MotorVehicle(plateNumber, basePrice, rented,engineDisplacement) {}

string Moped::getActualRentalPrice() const {
    return "ActualRentalPrice: " + to_string(getBasePrice() * 0.85); // 15% taniej
}


string Moped::getInfo() const {
    return "Bicycle - " + Vehicle::getInfo(); // Dodaje etykietę "Bicycle" do istniejącej informacji
}