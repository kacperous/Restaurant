#include "model/Vehicle.h"
using namespace std;
string Vehicle::getPlateNumber() const {
    return plateNumber;
}
int Vehicle::getBasePrice() const {
    return basePrice;
}
bool Vehicle::getRented() const {
    return rented;
}
void Vehicle::setPlateNumber(const std::string &NrPlate) {
    if(!NrPlate.empty()){
        plateNumber=NrPlate;
    }
}
void Vehicle::setBasePrice(const int &Price) {
    basePrice=Price;
}
void Vehicle::setRented(const bool &isRented){
    rented=isRented;
}
void Vehicle::getInfo() const {
    cout<<"Number plate: "<<plateNumber<<", price: "<<basePrice<<", is rented: "<<rented;
}
double Vehicle::getActualRentalPrice() const {
    return basePrice;
}