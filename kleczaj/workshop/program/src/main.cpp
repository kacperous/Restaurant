#include <iostream>
#include "model/Client.h"
#include "model/Adress.h"
#include "model/Vehicle.h"
#include "model/Rent.h"
#include "model/Bicycle.h"
#include "StorageContainer.h"

using namespace std;

int main() {
    // Tworzenie adresów
    AdressPtr a1= make_shared<Adress>("lodz","piotrkowska","15");
    AdressPtr a2= make_shared<Adress>("lodddddddz","piotrsssssskowska","1522222");
    ClientType *clientType=new Silver();
    ClientType *clientType1= new Gold();

    // Tworzenie klientów
    ClientPtr c1=make_shared<Client>("Jan", "Kowalski", "1", a1,clientType);
    ClientPtr c2=make_shared<Client>("Wojtek", "Szczesny", "2", a2,clientType1);

    // Tworzenie pojazdu
    VehiclePtr w1=make_shared<Vehicle>("TSK40251", 213, true);

    // Tworzenie wypożyczenia i dodawanie go do klienta
    //Rent *rent1= new Rent(1,c2,w1);
    //c1.addRent(rent1);

    // Wyświetlanie informacji
    cout << c1->getInfo() << endl;
    cout << c2->getInfo() << endl;
    cout << a1->getInfo() << endl;
    cout << a2->getInfo() << endl;
    w1->getInfo();
    cout << endl;
    cout << "Current rents for " << c1->getFirstName() << ": " << endl;
    const vector<RentPtr>& currentRents = c1->getCurrentRents();
    for (RentPtr rent : currentRents) {
        cout << rent->getInfo() << endl;
    }
    //cout<<rent1->getRentDays()<<endl;
    //cout<<rent1->getRentCost()<<endl;
    //rent1->endRent();

    ClientPtr client=make_shared<Client>("Marian", "Kucyk", "12",a1,clientType);
    VehiclePtr vehicle=make_shared<Vehicle>("WSZ23131", 760, false);

    // Przypadek 2: Wypożyczenie trwające dokładnie 1 minutę
    pt::ptime beginTime2 = pt::second_clock::local_time();
    pt::ptime endTime2 = beginTime2 + pt::minutes(1);
    RentPtr rent2=make_shared<Rent>(2, client, vehicle, beginTime2, endTime2);
    std::cout << "Rent days for rent2: " << rent2->getRentDays() << std::endl;

    // Przypadek 3: Wypożyczenie trwające 23 godziny i 59 minut
    pt::ptime beginTime3 = pt::second_clock::local_time();
    pt::ptime endTime3 = beginTime3 + pt::hours(23) + pt::minutes(59);
    RentPtr rent3=make_shared<Rent>(3, client, vehicle, beginTime3, endTime3);
    std::cout << "Rent days for rent3: " << rent3->getRentDays() << std::endl;

    pt::ptime beginTime4 = pt::second_clock::local_time();
    pt::ptime endTime4 = beginTime4 + pt::hours(49) + pt::minutes(59);
    RentPtr rent4=make_shared<Rent>(4, client, vehicle, beginTime4, endTime4);
    std::cout << "Rent days for rent3: " << rent4->getRentDays() << std::endl;

    StorageContainer storageContainer;
    ClientRepository clientRepository= storageContainer.getClientRepository();
    VehicleRepository vehicleRepository = storageContainer.getVehicleRepository();
    RentRepository rentRepository = storageContainer.getRentRepository();
    cout<<endl<<endl;
    cout<<clientRepository.raport();
    clientRepository.add(client);
    cout<<clientRepository.raport();
    cout<<endl<<endl;
    cout<<vehicleRepository.raport();
    vehicleRepository.add(w1);
    cout<<vehicleRepository.raport();
    cout<<endl<<endl;
    cout<<rentRepository.raport();
    rentRepository.add(rent2);
    cout<<rentRepository.raport();
    cout<<endl<<endl;
    Bicycle bicycle("tsk2421",450,1);
    if(bicycle.getActualRentalPrice() == 450){
        cout<<"1- zaliczone";
    }
    else
        cout<<"blad";
    return 0;
}
