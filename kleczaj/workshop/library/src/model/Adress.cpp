#include "model/Adress.h"
using namespace std;

string Adress::getInfo() const {
    return "city: "+city+", street: "+street+", numer: "+number;
}
string Adress::getCity() const {
    return city;
}
string Adress::getStreet() const {
    return street;
}
string Adress::getNumber() const {
    return number;
}
void Adress::setCity(const std::string &cty) {
    if(!cty.empty()){
        city=cty;
    }
}
void Adress::setStreet(const std::string &str) {
    if(!str.empty()){
        city=str;
    }
}
void Adress::setNumber(const std::string &nr) {
    if(!nr.empty()){
        city=nr;
    }
}