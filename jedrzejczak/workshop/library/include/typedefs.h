#ifndef TYPEDEFS_H
#define TYPEDEFS_H


class Vehicle;
class Bicycle;
class MotorVehicle;
class Moped;
class Car;
class Client;
class ClientType;

// Typedefs for pointer types
typedef std::shared_ptr<Client> ClientPtr;
typedef std::shared_ptr<Vehicle> VehiclePtr;
typedef Bicycle* BicyclePtr;
typedef MotorVehicle* MotorVehiclePtr;
typedef Moped* MopedPtr;
typedef Car* CarPtr;
typedef ClientType* ClientTypePtr;

#endif // TYPEDEFS_H
