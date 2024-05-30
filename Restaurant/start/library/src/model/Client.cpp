#include "model/Client.h"
Client::Client(int personalId, const std::string &firstName, const std::string &lastName, int phoneNumber,
               const AddressPtr &address, const ClientTypePtr &clientType) : personalID(personalId),
                                                                             firstName(firstName), lastName(lastName),
                                                                             phoneNumber(phoneNumber), address(address),
                                                                             clientType(clientType) {}
Client::~Client() {

}

int Client::getPersonalId() const {
    return personalID;
}

void Client::setPersonalId(int personalId) {
    personalID = personalId;
}

const std::string &Client::getFirstName() const {
    return firstName;
}

void Client::setFirstName(const std::string &newFirstName) {
    Client::firstName = newFirstName;
}

const std::string &Client::getLastName() const {
    return lastName;
}

void Client::setLastName(const std::string &newLastName) {
    Client::lastName = newLastName;
}

int Client::getPhoneNumber() const {
    return phoneNumber;
}

void Client::setPhoneNumber(int newPhoneNumber) {
    Client::phoneNumber = newPhoneNumber;
}

const AddressPtr &Client::getAddress() const {
    return address;
}

void Client::setAddress(const AddressPtr &newAddress) {
    Client::address = newAddress;
}

const ClientTypePtr &Client::getClientType() const {
    return clientType;
}

void Client::setClientType(const ClientTypePtr &newClientType) {
    Client::clientType = newClientType;
}
std::string Client::getInfo() const {
    return "Client ID: " + std::to_string(personalID) +
           ", Name: " + firstName + " " + lastName +
           ", Phone: " + std::to_string(phoneNumber) +
           ", Address: " + (address ? address->getInfo() : "None") +
           ", Client Type: " + (clientType ? clientType->getInfo() : "None");
}


