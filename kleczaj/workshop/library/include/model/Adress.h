#pragma once
#include <iostream>
#include "typedefs.h"
using namespace std;
class Adress{
    string city;
    string street;
    string number;
public:
    Adress(string cty,string str,string nr) : city(cty),street(str),number(nr){
    }
    ~Adress(){
    }
    string getInfo() const;
    string getCity() const;
    string getStreet() const;
    string getNumber() const;
    void setCity(const string &cty);
    void setStreet(const string &str);
    void setNumber(const string &nr);
};