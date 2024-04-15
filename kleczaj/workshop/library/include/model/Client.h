#pragma once
#include "model/Rent.h"
#include <iostream>
#include "model/Adress.h"
#include <vector>
using namespace std;
class Client{
    string firstName;
    string lastName;
    string personalID;
    Adress *adress;
    vector<Rent*> currentRents;
public:
    Client(string fName, string lName, string ID, Adress *addr) : firstName(fName), lastName(lName), personalID(ID), adress(addr){
    }
    ~Client(){
        for (Rent* rent : currentRents) {
            delete rent;
        }
    }
    string getFirstName() const;
    void setFirstName(const string& fName);
    string getLastName() const;
    void setLastName(const string& lName);
    string getPersonalID() const;
    void setPersonalID(const string& ID);
    string getInfo();
    Adress *getAdress() const;
    void setAdress(Adress *adr);
    void addRent(Rent* newRent);
    const vector<Rent*>& getCurrentRents() const;
private:
    void printDiagnostic(string message);
};
