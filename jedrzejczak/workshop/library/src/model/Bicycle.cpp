#include "model/Bicycle.h"
using namespace std;

Bicycle::Bicycle(const string& plateNumber, unsigned int basePrice, bool rented)
        : Vehicle(plateNumber, basePrice, rented) {}

string Bicycle::getActualRentalPrice() const {
    return "ActualRentalPrice: " + to_string(getBasePrice() * 0.85); // 15% taniej
}


string Bicycle::getInfo() const {
    return "Bicycle - " + Vehicle::getInfo(); // Dodaje etykietę "Bicycle" do istniejącej informacji
}
