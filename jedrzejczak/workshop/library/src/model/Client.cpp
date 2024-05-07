#include "model/Client.h"
#include "model/Rent.h"
#include <iostream>
#include <algorithm>

// Konstruktor z parametrami inicjalizuje pola klasy
Client::Client(const std::string &firstName, const std::string &lastName, const std::string &personalID, Address* address)
        : firstName(firstName), lastName(lastName), personalID(personalID), address(address) {
    if (!address) {
        throw std::invalid_argument("Address pointer cannot be null");
    }
    std::cout << "Parameterized Client constructor for " << firstName << " " << lastName << " called" << std::endl;
}

// Destruktor
Client::~Client() {
    std::cout << "Client destructor for " << firstName << " " << lastName << " called" << std::endl;
    // Przykład: Jeśli klasa Client zarządza pamięcią wskaźnika `address`, tutaj należałoby ją zwolnić
    // delete address;
}

// Gettery
std::string Client::getFirstName() const {
    return firstName;
}

std::string Client::getLastName() const {
    return lastName;
}

std::string Client::getPersonalID() const {
    return personalID;
}

const Address* Client::getAddress() const {
    return address;
}

// Settery
void Client::setFirstName(const std::string &firstName) {
    if (!firstName.empty()) {
        this->firstName = firstName;
    }
}

void Client::setLastName(const std::string &lastName) {
    if (!lastName.empty()) {
        this->lastName = lastName;
    }
}

void Client::setPersonalID(const std::string &personalID) {
    if (!personalID.empty()) {
        this->personalID = personalID;
    }
}

void Client::setAddress(Address* address) {
    if (address == nullptr) {
        throw std::invalid_argument("Address pointer cannot be null");
    }
    this->address = address;
}

// Metoda do dodawania wypożyczenia
void Client::addRent(Rent* rent) {
    if (rent != nullptr) {
        currentRents.push_back(rent);
    }
}

// Metoda do usuwania wypożyczenia
void Client::removeRent(Rent* rent) {
    auto it = std::remove(currentRents.begin(), currentRents.end(), rent);
    currentRents.erase(it, currentRents.end());
}

// Metoda zwracająca wektor aktualnych wypożyczeń
const std::vector<Rent*>& Client::getCurrentRents() const {
    return currentRents;
}

// Metoda zwracająca informacje o kliencie
std::string Client::getInfo() const {
    std::string info = "Client: " + firstName + " " + lastName + " PESEL: " + personalID;
    // Dodatkowe informacje z adresu, jeśli jest potrzebne
    if (address != nullptr) {
        // Załóżmy, że Address ma metodę toString()
        // info += " Address: " + address->toString();
    }
    return info;
}
