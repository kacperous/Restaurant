#include "Client.h"
#include <iostream>
#include <sstream>

Client::Client(std::string firstName, std::string lastName, std::string personalID)
    : firstName(firstName), lastName(lastName), personalID(personalID) {
    std::cout << "Konstruktor parametrowy został wywołany: " << getInfo() << std::endl;
}

Client::~Client() {
    std::cout << "Destruktor został wywołany: " << getInfo() << std::endl;
}

std::string Client::getInfo() const {
    std::stringstream info;
    info << "Klasa: Client, Imię: " << firstName << ", Nazwisko: " << lastName << ", PESEL: " << personalID;
    return info.str();
}

std::string Client::getFirstName() const { return firstName; }
std::string Client::getLastName() const { return lastName; }
std::string Client::getPersonalID() const { return personalID; }

void Client::setFirstName(const std::string& fName) {
    if (!fName.empty()) {
        firstName = fName;
    }
}

void Client::setLastName(const std::string& lName) {
    if (!lName.empty()) {
        lastName = lName;
    }
}

void Client::setPersonalID(const std::string& pID) {
    if (!pID.empty()) {
        personalID = pID;
    }
}

