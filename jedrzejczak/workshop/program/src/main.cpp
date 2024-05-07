#include <iostream>
#include "model/Client.h"
#include "model/Address.h"
#include "model/Vehicle.h"
#include "model/Rent.h"

int main() {
    // Tworzenie adresu klienta
    Address* clientAddress = new Address();
    clientAddress->setCity("Kraków");
    clientAddress->setStreet("Floriańska");
    clientAddress->setNumber("15");

    // Tworzenie klienta
    Client* client1 = new Client("Jan", "Kowalski", "12345678901", clientAddress);
    std::cout << client1->getInfo() << std::endl;

    // Tworzenie pojazdu
    Vehicle* vehicle1 = new Vehicle("DW12345", 150,true);
    std::cout << vehicle1->getInfo() << std::endl;

    // Tworzenie wypożyczenia
    Rent* rent1 = new Rent(1, client1, vehicle1);
    client1->addRent(rent1); // Dodanie wypożyczenia do klienta
    std::cout << rent1->getInfo() << std::endl;

    // Usuwanie wypożyczenia
    client1->removeRent(rent1);
    std::cout << "Po usunięciu wypożyczenia, liczba wypożyczeń klienta: " << client1->getCurrentRents().size() << std::endl;

    // Czyszczenie zasobów
    delete rent1;
    delete vehicle1;
    delete client1;
    delete clientAddress;

    return 0;
}
