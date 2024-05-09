//
// Created by student on 04.05.24.
//

#ifndef CARRENTAL_RENTREPOSITORY_H
#define CARRENTAL_RENTREPOSITORY_H
#include <vector>
#include <memory>
#include "model/Rent.h"

class RentRepository {
public:
    void add(std::shared_ptr<Rent> rent);
    void remove(std::shared_ptr<Rent> rent);
    std::shared_ptr<Rent> get(int index) const;
    std::string report() const;
    size_t size() const;
    std::vector<std::shared_ptr<Rent>> findAll() const;

private:
    std::vector<std::shared_ptr<Rent>> rents;
};
#endif //CARRENTAL_RENTREPOSITORY_H
