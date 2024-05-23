#include "model/Adress.h"

Address::Address(const std::string &city, const std::string &street,
                 const std::string &number) : city(city), street(street), number(number) {}

Address::~Address() {
}

const std::string &Address::getCity() const {
    return city;
}

void Address::setCity(const std::string &newCity) {
    Address::city = newCity;
}

const std::string &Address::getStreet() const {
    return street;
}

void Address::setStreet(const std::string &newStreet) {
    Address::street = newStreet;
}

const std::string &Address::getNumber() const {
    return number;
}

void Address::setNumber(const std::string &newNumber) {
    Address::number = newNumber;
}

std::string Address::getInfo() const {
    return "City: " + city + ", Street: " + street + ", Number: " + number;
}

