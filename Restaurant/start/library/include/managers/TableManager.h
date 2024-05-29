#ifndef RESTAURANT_TABLEMANAGER_H
#define RESTAURANT_TABLEMANAGER_H
#include "../repositories/TableRepositories.h"

class TableManager {
public:
    bool checkTable(Table* table) const;
    int countChildren() const;

private:
    TableRepository repository;
};
#endif //RESTAURANT_TABLEMANAGER_H
