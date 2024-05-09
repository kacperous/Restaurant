//
// Created by student on 08.05.24.
//

#ifndef CARRENTAL_VEHICLEREPOSITORY_H
#define CARRENTAL_VEHICLEREPOSITORY_H
#include "model/Vehicle.h"
#include "model/typedefs.h"
#include <algorithm>
#include <vector>
class VehicleRepository{
    vector<VehiclePtr> vehicles;
public:
    VehiclePtr get(size_t index) const {        //size_t to typ danych sluzacy do przechowywyania rozmiaru tablic lub kolejnych danych jest to alias do: unsigned int,long, long long
        if(index< vehicles.size())      //sprawdza ile jest klientow i czy przypadkiem nie pytamy o klienta ktorego nie ma, jezeli jest to zwraca jego wskaznik
            return vehicles[index];
        else
            return nullptr;             //jezeli nie ma tego klienta zwraca wskaznik na nic
    }
    void add(VehiclePtr vehicle){
        if(vehicle!= nullptr){
            vehicles.push_back(vehicle);
        }
    }
    void remove(VehiclePtr vehicle){
        vehicles.erase(std::remove(vehicles.begin(), vehicles.end(), vehicle), vehicles.end());
    }
    string raport(){
        string raportString = " ";
        for(VehiclePtr vehicle : vehicles){
            raportString=raportString+vehicle->toString();
        }
        return raportString;
    }
    size_t size(){
        return vehicles.size();
    }
    vector<VehiclePtr> findBy(VehiclePredicate &predicate) const {
        vector<VehiclePtr> found;
        for (unsigned int i = 0; i < vehicles.size(); i++) {
            VehiclePtr vehicle = get(i);
            if (vehicle != nullptr && predicate(vehicle)) {
                found.push_back(vehicle);
            }
        }
        return found;
    }

    vector<VehiclePtr> findAll() const {
        return vehicles; // Zwraca kopię wektora vehicles
    }
};
#endif //CARRENTAL_VEHICLEREPOSITORY_H
