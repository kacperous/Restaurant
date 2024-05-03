#ifndef ADDRESS_H // Jeśli makro ADDRESS_H nie jest zdefiniowane
#define ADDRESS_H // zdefiniuj makro ADDRESS_H

#include <string>
#include <iostream>

class Address
{
private:
    std::string city;
    std::string street;
    std::string number;

public:
    // Tutaj powinny być umieszczone konstruktory, jeśli są potrzebne

    void setCity(const std::string &city);
    void setStreet(const std::string &street);
    void setNumber(const std::string &number);

    std::string getCity() const; // Dodałem const do deklaracji, aby wskazać, że metody te nie modyfikują obiektu
    std::string getStreet() const;
    std::string getNumber() const;

    std::string getInfo() const;
};

#endif // ADDRESS_H
