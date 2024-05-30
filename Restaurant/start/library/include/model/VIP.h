#ifndef RESTAURANT_VIP_H
#define RESTAURANT_VIP_H
#include "ClientType.h"
class VIP:public ClientType{
public:
    ~VIP() override;

    double getDiscount() const override;
    std::string getTypeInfo() const override;
    bool vipTable() const override;
};
#endif //RESTAURANT_VIP_H
