#ifndef CLIENT_H
#define CLIENT_H

#include <string>
#include <vector>
#include <memory>
#include "Address.h"
#include "Rent.h"

class Client {
private:
    std::string firstName;
    std::string lastName;
    std::string personalID;
    std::shared_ptr<Address> address;
    std::vector<std::shared_ptr<Rent>> rents;

public:
    // Konstruktory
    Client(const std::string& firstName, const std::string& lastName, const std::string& personalID);
    Client(const std::string& firstName, const std::string& lastName, const std::string& personalID, std::shared_ptr<Address> address);
    Client(); // Domyślny konstruktor

    // Destruktor
    ~Client();

    // Gettery
    std::string getFirstName() const;
    std::string getLastName() const;
    std::string getPersonalID() const;
    std::shared_ptr<Address> getAddress() const;

    // Settery
    void setFirstName(const std::string& firstName);
    void setLastName(const std::string& lastName);
    void setPersonalID(const std::string& personalID);
    void setAddress(std::shared_ptr<Address> newAddress);

    // Metody zarządzania wypożyczeniami
    void addRent(std::shared_ptr<Rent> rent);
    void removeRent(std::shared_ptr<Rent> rent);
    std::vector<std::shared_ptr<Rent>> getCurrentRents() const;

    // Inne metody
    std::string getInfo() const;
};

#endif // CLIENT_H
