#include <iostream>
#include "model/Client.h"

int main() {
    // Dynamically allocated client #1
    Client *client1 = new Client("Jan", "Kowalski", "12345678901");
    std::cout << client1->getInfo() << std::endl;

    // Deleting dynamically allocated client #1
    delete client1;

    // Dynamically allocated client #2
    Client *client2 = new Client("Anna", "Nowak", "09876543210");
    std::cout << client2->getInfo() << std::endl;

    // Deleting dynamically allocated client #2
    delete client2;

    return 0;
}
