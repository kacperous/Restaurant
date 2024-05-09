#ifndef CARRENTAL_TYPEDEFS_H
#define CARRENTAL_TYPEDEFS_H
#include <memory>

class Vehicle;
class Rent;
class Client;
class Adress;

typedef std::shared_ptr<Vehicle> VehiclePtr;
typedef std::shared_ptr<Rent> RentPtr;
typedef std::shared_ptr<Adress> AdressPtr;
typedef std::shared_ptr<Client> ClientPtr;

typedef bool (*ClientPredicate)(ClientPtr);
typedef bool (*VehiclePredicate)(VehiclePtr);
typedef bool (*RentPredicate)(RentPtr);

#endif
