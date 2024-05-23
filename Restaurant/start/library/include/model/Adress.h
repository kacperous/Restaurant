#ifndef RESTAURANT_ADRESS_H
#define RESTAURANT_ADRESS_H
#include <string>
class Address{
    std::string city;
    std::string street;
    std::string number;
public:
    Address(const std::string &city, const std::string &street, const std::string &number);
    virtual ~Address();
    const std::string &getCity() const;
    void setCity(const std::string &newCity);
    const std::string &getStreet() const;
    void setStreet(const std::string &newStreet);
    const std::string &getNumber() const;
    void setNumber(const std::string &newNumber);


    std::string getInfo() const;
};
#endif //RESTAURANT_ADRESS_H
