#ifndef RESTAURANT_CLIENT_H
#define RESTAURANT_CLIENT_H
#include <string>
#include "ClientType.h"
#include "Adress.h"
#include "typedefs.h"
class Client{
    int personalID;
    std::string firstName;
    std::string lastName;
    int phoneNumber;
    AddressPtr address;
    ClientTypePtr clientType;
public:
    Client(int personalId, const std::string &firstName, const std::string &lastName, int phoneNumber,
           const AddressPtr &address, const ClientTypePtr &clientType);
    virtual ~Client();
    int getPersonalId() const;
    void setPersonalId(int personalId);
    const std::string &getFirstName() const;
    void setFirstName(const std::string &newFirstName);
    const std::string &getLastName() const;
    void setLastName(const std::string &newLastName);
    int getPhoneNumber() const;
    void setPhoneNumber(int newPhoneNumber);
    const AddressPtr &getAddress() const;
    void setAddress(const AddressPtr &newAddress);
    const ClientTypePtr &getClientType() const;
    void setClientType(const ClientTypePtr &newClientType);


    std::string getInfo() const;
};
#endif //RESTAURANT_CLIENT_H
