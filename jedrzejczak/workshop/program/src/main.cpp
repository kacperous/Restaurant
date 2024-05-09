#include <iostream>
#include <memory>
#include "../../library/include/model/Address.h"
#include "../../library/include/model/Vehicle.h"
#include "../../library/include/model/Rent.h"
#include "../../library/include/model/Client.h"
#include "../../library/include/typedefs.h"

int main() {
    try {
        // Utworzenie adresu klienta
        auto clientAddress = std::make_shared<Address>("Kraków, Floriańska 15");

        // Utworzenie klienta
        auto client1 = std::make_shared<Client>("Jan", "Kowalski", "12345678901", clientAddress);

        // Utworzenie pojazdu
        auto vehicle1 = std::make_shared<Vehicle>("DW12345", 150, true);

        // Utworzenie wypożyczenia
        auto rent1 = std::make_shared<Rent>(1, client1, vehicle1);

        // Dodanie wypożyczenia do klienta
        client1->addRent(rent1);
        std::cout << "Wypożyczenie dodane. Informacje: " << rent1->getInfo() << std::endl;

        // Usunięcie wypożyczenia
        client1->removeRent(rent1);
        std::cout << "Po usunięciu wypożyczenia, liczba wypożyczeń klienta: " << client1->getCurrentRents().size() << std::endl;
    } catch (const std::exception& e) {
        std::cerr << "Wystąpił wyjątek: " << e.what() << std::endl;
        return 1; // Zwróć błąd
    }

    return 0; // Zakończ program sukcesem
}