#include <iostream>
#include "model/Client.h"
#include "model/Adress.h"
#include "model/Vehicle.h"
#include "model/Rent.h"
#include "model/Bicycle.h"

using namespace std;

int main() {
    // Tworzenie adresów
    Adress *a1 = new Adress("lodz","piotrkowska","15");
    Adress *a2 = new Adress("lodddddddz","piotrsssssskowska","1522222");
    ClientType *clientType=new Silver();
    ClientType *clientType1= new Gold();

    // Tworzenie klientów
    Client c1("Jan", "Kowalski", "1", a1,clientType);
    Client *c2 = new Client("Wojtek", "Szczesny", "2", a2,clientType1);

    // Tworzenie pojazdu
    Vehicle *w1 = new Vehicle("TSK40251", 213, true);

    // Tworzenie wypożyczenia i dodawanie go do klienta
    //Rent *rent1= new Rent(1,c2,w1);
    //c1.addRent(rent1);

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
    //cout<<rent1->getRentDays()<<endl;
    //cout<<rent1->getRentCost()<<endl;
    //rent1->endRent();

    Client* client = new Client("Marian", "Kucyk", "12", new Adress("London", "Accacia Avenue", "22"),clientType);
    Vehicle* vehicle = new Vehicle("WSZ23131", 760, false);

    // Przypadek 2: Wypożyczenie trwające dokładnie 1 minutę
    pt::ptime beginTime2 = pt::second_clock::local_time();
    pt::ptime endTime2 = beginTime2 + pt::minutes(1);
    Rent *rent2= new Rent(2, client, vehicle, beginTime2, endTime2);
    std::cout << "Rent days for rent2: " << rent2->getRentDays() << std::endl;

    // Przypadek 3: Wypożyczenie trwające 23 godziny i 59 minut
    pt::ptime beginTime3 = pt::second_clock::local_time();
    pt::ptime endTime3 = beginTime3 + pt::hours(23) + pt::minutes(59);
    Rent rent3(3, client, vehicle, beginTime3, endTime3);
    std::cout << "Rent days for rent3: " << rent3.getRentDays() << std::endl;

    pt::ptime beginTime4 = pt::second_clock::local_time();
    pt::ptime endTime4 = beginTime4 + pt::hours(49) + pt::minutes(59);
    Rent rent4(4, client, vehicle, beginTime4, endTime4);
    std::cout << "Rent days for rent3: " << rent4.getRentDays() << std::endl;

    // Usuwanie obiektów
    delete c2;
    delete a1;
    delete a2;
    delete w1;

    Bicycle bicycle("tsk2421",450,1);
    if(bicycle.getActualRentalPrice() == 450){
        cout<<"1- zaliczone";
    }
    else
        cout<<"blad";
    return 0;
}
