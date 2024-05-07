#ifndef CLIENT_H
#define CLIENT_H

#include <string>
#include <vector>
#include "Address.h"
#include "Rent.h"  // Ensure this is only a forward declaration if there's a circular dependency

class Client {
private:
    std::string firstName;
    std::string lastName;
    std::string personalID;
    Address* address;
    std::vector<Rent*> currentRents;

public:
    Client(const std::string &firstName, const std::string &lastName, const std::string &personalID, Address* address);
    ~Client();

    std::string getFirstName() const;
    std::string getLastName() const;
    std::string getPersonalID() const;
    const Address* getAddress() const;

    void setFirstName(const std::string &firstName);
    void setLastName(const std::string &lastName);
    void setPersonalID(const std::string &personalID);
    void setAddress(Address* address);

    void addRent(Rent* rent);
    void removeRent(Rent* rent);
    const std::vector<Rent*>& getCurrentRents() const;

    std::string getInfo() const;
};

#endif // CLIENT_H
