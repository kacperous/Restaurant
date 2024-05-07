#include "model/ClientType.h"

ClientType::ClientType(const std::string &firstName, const std::string &lastName, const std::string &personalID, Address* address)
        : Client(firstName, lastName, personalID, address) {
    // Możesz tutaj dodać więcej logiki inicjalizacyjnej
}

std::string ClientType::getTypeInfo() const {
    // Zwraca informacje specyficzne dla typu klienta
    return "Type Info: Base Client Type";
}

