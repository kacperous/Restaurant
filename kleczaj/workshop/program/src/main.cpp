#include <iostream>
#include "model/Client.h"
#include "model/Adress.h"
#include "model/Vehicle.h"
#include "model/Rent.h"

using namespace std;

int main() {
    // Tworzenie adresów
    Adress *a1 = new Adress("lodz","piotrkowska","15");
    Adress *a2 = new Adress("lodddddddz","piotrsssssskowska","1522222");

    // Tworzenie klientów
    Client c1("Jan", "Kowalski", "1", a1);
    Client *c2 = new Client("Wojtek", "Szczesny", "2", a2);

    // Tworzenie pojazdu
    Vehicle *w1 = new Vehicle("TSK40251", 213, true);

    // Tworzenie wypożyczenia i dodawanie go do klienta
    Rent *rent1= new Rent(1,c2,w1);
    c1.addRent(rent1);

    // Wyświetlanie informacji
    cout << c1.getInfo() << endl;
    cout << c2->getInfo() << endl;
    cout << a1->getInfo() << endl;
    cout << a2->getInfo() << endl;
    w1->getInfo();
    cout << endl;
    cout << "Current rents for " << c1.getFirstName() << ": " << endl;
    const vector<Rent*>& currentRents = c1.getCurrentRents();
    for (const Rent* rent : currentRents) {
       cout << rent->getInfo() << endl;
    }

    // Usuwanie obiektów
    delete c2;
    delete a1;
    delete a2;
    delete w1;

    return 0;
}
