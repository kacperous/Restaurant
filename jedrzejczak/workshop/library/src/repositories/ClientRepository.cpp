#include "repositories//ClientRepository.h"
#include <sstream>
#include <algorithm>
int remove(vector<shared_ptr<Client>>::iterator iterator, vector<shared_ptr<Client>>::iterator iterator1,
           shared_ptr<Client> sharedPtr);

ClientRepository::ClientRepository() {
    // Możliwa inicjalizacja, jeśli potrzebna
}

ClientRepository::~ClientRepository() {
    // Destruktor nie musi nic robić, shared_ptr automatycznie zarządza pamięcią
}

void ClientRepository::add(std::shared_ptr<Client> client) {
    if (client) {
        clients.push_back(client);
    }
}

void ClientRepository::remove(std::shared_ptr<Client> client) {
    if (client) {
        auto iter = std::remove(clients.begin(), clients.end(), client); // Używaj std::remove
        clients.erase(iter, clients.end());
    }
}

int remove(vector<shared_ptr<Client>>::iterator iterator, vector<shared_ptr<Client>>::iterator iterator1,
           shared_ptr<Client> sharedPtr) {
    return 0;
}

std::shared_ptr<Client> ClientRepository::get(int index) const {
    if (index >= 0 && index < clients.size()) {
        return clients[index];
    }
    return nullptr;
}

std::string ClientRepository::report() const {
    std::ostringstream stream;
    for (const auto& client : clients) {
        stream << client->getInfo() << "\n";
    }
    return stream.str();
}

size_t ClientRepository::size() const {
    return clients.size();
}

std::vector<std::shared_ptr<Client>> ClientRepository::findAll() const {
    return clients; // Zwraca kopię wektora wskaźników
}