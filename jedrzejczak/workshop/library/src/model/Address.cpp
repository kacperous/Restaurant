#include "../../include/model/Address.h"
using namespace std;

void Address::setCity(const std::string &city) {
    if (!city.empty()) {
        this->city = city;
    }
}
void Address::setStreet(const std::string &street) {
    if (!city.empty()) {
        this->street = street;
    }
}
void Address::setNumber(const std::string &number) {
    if (!city.empty()) {
        this->number = number;
    }
}
string Address::getCity() const
{
    return city;
}
string Address::getStreet() const
{
    return street;
}
string Address::getNumber() const
{
    return number;
}
string Address::getInfo() const
{
    cout<<"City: "<<city<<", Street: "<<street<<", Number: "<<number<<endl;
}