#include "repositories/RentRepository.h"
#include <sstream>
#include <algorithm>

void RentRepository::add(std::shared_ptr<Rent> rent) {
    if (rent) {
        rents.push_back(rent);
    }
}

void RentRepository::remove(std::shared_ptr<Rent> rent) {
    auto it = remove_if(rents.begin(), rents.end(),
                             [&rent](const std::shared_ptr<Rent>& r) { return r == rent; });
    rents.erase(it, rents.end());
}

std::shared_ptr<Rent> RentRepository::get(int index) const {
    if (index >= 0 && index < rents.size()) {
        return rents[index];
    }
    return nullptr;
}

std::string RentRepository::report() const {
    std::ostringstream oss;
    for (auto& rent : rents) {
        oss << rent->getInfo() << "\n";
    }
    return oss.str();
}

size_t RentRepository::size() const {
    return rents.size();
}

std::vector<std::shared_ptr<Rent>> RentRepository::findAll() const {
    return rents;
}
