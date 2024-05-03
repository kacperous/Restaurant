#include "model/MotorVehicle.h"
using namespace std;
MotorVehicle::MotorVehicle(const string& plateNumber, unsigned int basePrice, bool rented,int engineDisplacement)
        : Vehicle(plateNumber, basePrice, rented) {};
string MotorVehicle::getActualRentalPrice() const {
    return "ActualRentalPrice: " + to_string(getBasePrice() * 0.85); // 15% taniej
}


string MotorVehicle::getInfo() const {
    return "Bicycle - " + Vehicle::getInfo(); // Dodaje etykietę "Bicycle" do istniejącej informacji
}