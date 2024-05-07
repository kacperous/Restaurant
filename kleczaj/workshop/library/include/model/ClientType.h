//
// Created by student on 07.05.24.
//

#ifndef CARRENTAL_CLIENTTYPE_H
#define CARRENTAL_CLIENTTYPE_H
#include "Client.h"
class ClientType{
public:
    virtual ~ClientType(){}
    virtual int getMaxVehicles() const =0;
    virtual double applyDiscount(double price) const =0;
    virtual void getInfo() const =0;
};
class Default : public ClientType{
    int getMaxVehicles() const override {return 1; }
    double applyDiscount(double price) const override {return price;}
    void getInfo() const override {cout<<"Default";}
};
class Bronze : public ClientType{
    int getMaxVehicles() const override {return 2; }
    double applyDiscount(double price) const override {return price-3;}
    void getInfo() const override {cout<<"Bronze";}
};
class Silver : public ClientType{
    int getMaxVehicles() const override {return 3; }
    double applyDiscount(double price) const override {return price-6;}
    void getInfo() const override {cout<<"Silver";}
};
class Gold : public ClientType{
    int getMaxVehicles() const override {return 4; }
    double applyDiscount(double price) const override {return price-(price*0.05);}
    void getInfo() const override {cout<<"Gold";}
};
class Platinium : public ClientType{
    int getMaxVehicles() const override {return 5; }
    double applyDiscount(double price) const override {return price-(price*0.10);}
    void getInfo() const override {cout<<"Platinium";}
};
class Diamond : public ClientType{
    int getMaxVehicles() const override {return 10; }
    double applyDiscount(double price) const override {
        if(price>0 and price<=125){
            return price-(price*0.10);
        }
        else if(price>125 and price<=250){
            return price-(price*0.20);
        }
        else if(price>250 and price<=500){
            return price-(price*0.30);
        }
        else
            return price-(price*0.40)
    ;}
    void getInfo() const override {cout<<"Diamond";}
};

#endif //CARRENTAL_CLIENTTYPE_H
