// Restaurant.cpp
#include "model/Restaurant.h"
#include <algorithm>
#include <iostream>

Restaurant::Restaurant(const std::string& name, AddressPtr address)
        : name(name), address(address) {}

std::string Restaurant::getName() const {
    return name;
}

AddressPtr Restaurant::getAddress() const {
    return address;
}

std::string Restaurant::getInfo() const {
    return "Restaurant: " + name + ", Address: " + (address ? address->getInfo() : "None");
}

void Restaurant::addTable(TablePtr table) {
    tables.push_back(table);
}

void Restaurant::showTables() const {
    for (const auto& table : tables) {
        std::cout << table->getInfo() << std::endl;
    }
}

void Restaurant::removeTable(TablePtr table) {
    tables.erase(std::remove(tables.begin(), tables.end(), table), tables.end());
}

void Restaurant::addReservation(ReservationPtr reservation) {
    reservations.push_back(reservation);
}

void Restaurant::showReservations() const {
    for (const auto& reservation : reservations) {
        std::cout << reservation->getInfo() << std::endl;
    }
}

void Restaurant::removeReservation(ReservationPtr reservation) {
    reservations.erase(std::remove(reservations.begin(), reservations.end(), reservation), reservations.end());
}
