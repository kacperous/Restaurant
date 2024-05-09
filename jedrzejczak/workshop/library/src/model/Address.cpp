#include "../../include/model/Address.h"
#include <iostream>
using namespace std;

void Address::setCity(const string &city) {
    if (!city.empty()) {
        this->city = city;
    }
}
void Address::setStreet(const string &street) {
    if (!street.empty()) {
        this->street = street;
    }
}
void Address::setNumber(const string &number) {
    if (!number.empty()) {
        this->number = number;
    }
}
string Address::getCity() const {
    return city;
}
string Address::getStreet() const {
    return street;
}
string Address::getNumber() const {
    return number;
}
string Address::getInfo() const {
    return "City: " + city + ", Street: " + street + ", Number: " + number;
}

Address::Address() {

}

