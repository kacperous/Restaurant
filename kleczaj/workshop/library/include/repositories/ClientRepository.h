//
// Created by student on 08.05.24.
//

#ifndef CARRENTAL_CLIENTREPOSITORY_H
#define CARRENTAL_CLIENTREPOSITORY_H
#include <vector>
#include <sstream>
#include <algorithm>
#include "model/Client.h"
#include "model/typedefs.h"
using namespace std;

class ClientRepository{
    vector<ClientPtr> clients;
public:
    ClientPtr get(size_t index) const{        //size_t to typ danych sluzacy do przechowywyania rozmiaru tablic lub kolejnych danych jest to alias do: unsigned int,long, long long
        if(index< clients.size())      //sprawdza ile jest klientow i czy przypadkiem nie pytamy o klienta ktorego nie ma, jezeli jest to zwraca jego wskaznik
            return clients[index];
        else
            return nullptr;             //jezeli nie ma tego klienta zwraca wskaznik na nic
    }
    void add(ClientPtr client){
        if(client!= nullptr){
            clients.push_back(client);
        }
    }
    void remove(ClientPtr client){
            clients.erase(std::remove(clients.begin(), clients.end(), client), clients.end());
    }
    string raport(){
        string raportString = "";
        for(ClientPtr client : clients){
            raportString=raportString+client->toString();
        }
        return raportString;
    }
    size_t size(){
        return clients.size();
    }
    vector<ClientPtr> findBy(ClientPredicate &predicate) const {
        vector<ClientPtr> found;
        for (unsigned int i = 0; i < clients.size(); i++) {
            ClientPtr client = get(i);
            if (client != nullptr && predicate(client)) {
                found.push_back(client);
            }
        }
        return found;
    }

    vector<ClientPtr> findAll() const {
        return clients; // Zwraca kopię wektora vehicles
    }
};

#endif //CARRENTAL_CLIENTREPOSITORY_H
