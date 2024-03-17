#include <iostream>
#include "Client.h"

Client::Client() {
    std::cout << "Konstruktor bezparametrowy został wywołany." << std::endl;
}

Client::~Client() {
    std::cout << "Destruktor został wywołany." << std::endl;
}

