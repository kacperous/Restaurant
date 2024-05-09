#include "model/ClientType.h"

ClientType::ClientType(const std::string& firstName, const std::string& lastName, const std::string& personalID, Address* address) {
    std::shared_ptr<Address> addressPtr(address); // Bezpieczne tworzenie shared_ptr z surowego wskaźnika
    Client client(firstName, lastName, personalID, addressPtr);

}
std::string ClientType::getTypeInfo() const {
    // Zwraca informacje specyficzne dla typu klienta
    return "Type Info: Base Client Type";
};

