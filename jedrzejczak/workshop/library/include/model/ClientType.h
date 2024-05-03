
#ifndef CARRENTAL_CLIENTTYPE_H
#define CARRENTAL_CLIENTTYPE_H
#include <string>
#include "Client.h"

class ClientType : public Client {
public:
    ClientType(const string &firstName, const string &lastName, const string &personalID, Address *address);

    virtual ~ClientType() {}
    virtual int getMaxVehicles() const = 0;
    virtual double applyDiscount(double price) const = 0;
    virtual std::string getInfo() const = 0;

    string getTypeInfo() const;
};

#endif //CARRENTAL_CLIENTTYPE_H
