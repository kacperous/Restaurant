#include "model/Client.h"

Client::Client() : firstName("Unknown"), lastName("Unknown"), personalID("Unknown") {
    std::cout << "Default Client constructor called" << std::endl;
}

Client::Client(const std::string &firstName, const std::string &lastName, const std::string &personalID)
        : firstName(firstName), lastName(lastName), personalID(personalID) {
    std::cout << "Parameterized Client constructor for " << firstName << " " << lastName << " called" << std::endl;
}

Client::~Client() {
    std::cout << "Client destructor for " << firstName << " " << lastName << " called" << std::endl;
}

std::string Client::getFirstName() const {
    return firstName;
}

std::string Client::getLastName() const {
    return lastName;
}

std::string Client::getPersonalID() const {
    return personalID;
}

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

std::string Client::getInfo() const {
    std::string info = "Client: " + firstName + " " + lastName + " PESEL: " + personalID;
    return info;
}
