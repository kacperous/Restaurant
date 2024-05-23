#ifndef RESTAURANT_DEFAULT_H
#define RESTAURANT_DEFAULT_H
#include "ClientType.h"

class Default:public ClientType{
public:
    ~Default() override;


    double getDiscount() const override;
    std::string getTypeInfo() const override;
    bool vipTable() const override;
};
#endif //RESTAURANT_DEFAULT_H
