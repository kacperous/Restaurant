#include "repositories/TableRepositories.h"
#include <algorithm>

void TableRepository::addTable(Table* table) {
    tables.push_back(table);
}

Table* TableRepository::getTable(size_t index) const {
    if (index < tables.size()) {
        return tables[index];
    }
    return nullptr;
}

void TableRepository::removeTable(Table* table) {
    tables.erase(std::remove(tables.begin(), tables.end(), table), tables.end());
}

std::vector<Table*> TableRepository::findBy(TablePredicate predicate) const {
    std::vector<Table*> result;
    for (Table* table : tables) {
        if (predicate(table)) {
            result.push_back(table);
        }
    }
    return result;
}
