//
// Created by student on 08.05.24.
//

#ifndef CARRENTAL_RENTREPOSITORY_H
#define CARRENTAL_RENTREPOSITORY_H
#include "model/Rent.h"
#include "model/typedefs.h"
#include <algorithm>
#include <vector>
class RentRepository{
        vector<RentPtr> rents;
        public:
        RentPtr get(size_t index) const{        //size_t to typ danych sluzacy do przechowywyania rozmiaru tablic lub kolejnych danych jest to alias do: unsigned int,long, long long
            if(index< rents.size())      //sprawdza ile jest klientow i czy przypadkiem nie pytamy o klienta ktorego nie ma, jezeli jest to zwraca jego wskaznik
                return rents[index];
            else
                return nullptr;             //jezeli nie ma tego klienta zwraca wskaznik na nic
        }
        void add(RentPtr rent){
            if(rent!= nullptr){
                rents.push_back(rent);
            }
        }
        void remove(RentPtr rent){
            rents.erase(std::remove(rents.begin(), rents.end(), rent), rents.end());
        }
        string raport(){
            string raportString = "";
            for(RentPtr rent : rents){
                raportString=raportString+rent->toString();
            }
            return raportString;
        }
        size_t size(){
            return rents.size();
        }
    vector<RentPtr> findBy(RentPredicate &predicate) const {
        vector<RentPtr> found;
        for (unsigned int i = 0; i < rents.size(); i++) {
            RentPtr rent = get(i);
            if (rent != nullptr && predicate(rent)) {
                found.push_back(rent);
            }
        }
        return found;
    }

    vector<RentPtr> findAll() const {
        return rents; // Zwraca kopię wektora vehicles
    }
};

#endif //CARRENTAL_RENTREPOSITORY_H
