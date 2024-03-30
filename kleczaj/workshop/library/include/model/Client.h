#pragma once
#include <iostream>
#include "model/Adress.h"
using namespace std;
class Client{
private:
    string firstName;
    string lastName;
    string personalID;
    Adress *adress;
public:
    Client(string fName, string lName, string ID, Adress *addr) : firstName(fName), lastName(lName), personalID(ID), adress(addr){
    }
    ~Client(){
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
private:
    void printDiagnostic(string message);
};