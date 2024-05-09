#include "model/Client.h"
#include <iostream>
#include <algorithm>

// Konstruktor z parametrami inicjalizuje pola klasy
Client::Client(const std::string& firstName, const std::string& lastName, const std::string& personalID)
        : firstName(firstName), lastName(lastName), personalID(personalID) {
    std::cout << "Parameterized Client constructor called for " << firstName << " " << lastName << std::endl;
}

Client::Client(const std::string& firstName, const std::string& lastName, const std::string& personalID, std::shared_ptr<Address> address)
        : firstName(firstName), lastName(lastName), personalID(personalID), address(address) {
    if (!address) {
        throw std::invalid_argument("Address pointer cannot be null");
    }
    std::cout << "Parameterized Client constructor with address called for " << firstName << " " << lastName << std::endl;
}

// Domyślny konstruktor
Client::Client() {
    std::cout << "Default constructor for Client called" << std::endl;
}

// Destruktor
Client::~Client() {
    std::cout << "Client destructor called for " << firstName << " " << lastName << std::endl;
}

// Implementacja getterów i setterów
std::string Client::getFirstName() const { return firstName; }
std::string Client::getLastName() const { return lastName; }
std::string Client::getPersonalID() const { return personalID; }
std::shared_ptr<Address> Client::getAddress() const { return address; }

void Client::setFirstName(const std::string& firstName) { this->firstName = firstName; }
void Client::setLastName(const std::string& lastName) { this->lastName = lastName; }
void Client::setPersonalID(const std::string& personalID) { this->personalID = personalID; }
void Client::setAddress(std::shared_ptr<Address> newAddress) {
    if (!newAddress) {
        throw std::invalid_argument("Address pointer cannot be null");
    }
    this->address = newAddress;
}

// Metody zarządzania wypożyczeniami
void Client::addRent(std::shared_ptr<Rent> rent) {
    if (rent) {
        rents.push_back(rent);
    }
}

void Client::removeRent(std::shared_ptr<Rent> rent) {
    rents.erase(std::remove(rents.begin(), rents.end(), rent), rents.end());
}

std::vector<std::shared_ptr<Rent>> Client::getCurrentRents() const {
    return rents;
}

// Metoda zwracająca informacje o kliencie
std::string Client::getInfo() const {
    std::string info = "Client: " + firstName + " " + lastName + " PESEL: " + personalID;
    if (address) {
        info += " Address: [Address details here]";
    }
    return info;
}
