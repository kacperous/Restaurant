#ifndef RESTAURANT_CLIENTTYPE_H
#define RESTAURANT_CLIENTTYPE_H
#include "Client.h"

class ClientType{
public:
    ClientType();

    virtual ~ClientType() {}

    std::string getInfo() const;
    virtual double getDiscount() const =0;
    virtual std::string getTypeInfo() const =0;
    virtual bool vipTable() const =0;
};
#endif //RESTAURANT_CLIENTTYPE_H
