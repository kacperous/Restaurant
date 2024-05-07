#pragma once
#include "model/Rent.h"
#include <iostream>
#include "model/Adress.h"
#include <vector>
#include "typedefs.h"
#include "ClientType.h"
using namespace std;
class Client {
    string firstName;
    string lastName;
    string personalID;
    AdressPtr adress;
    vector<RentPtr> currentRents;
    ClientType *clientType;
public:
    Client(string fName, string lName, string ID, AdressPtr addr, ClientType *clientType) : firstName(fName), lastName(lName), personalID(ID),
                                                                    adress(addr), clientType(clientType) {
    }
    ~Client() {}
    string getFirstName() const;
    void setFirstName(const string& fName);
    string getLastName() const;
    void setLastName(const string& lName);
    string getPersonalID() const;
    void setPersonalID(const string& ID);
    string getInfo();
    const AdressPtr& getAdress() const;
    void setAdress(AdressPtr adr);
    void addRent(RentPtr newRent);
    void removeRent();
    const vector<RentPtr>& getCurrentRents() const;
    int getMaxVehicles() const;
    double applyDiscount(double price) const;
    void setClientType(ClientType *newClientType);

private:
    void printDiagnostic(string message);
};