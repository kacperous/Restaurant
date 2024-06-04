#include "managers/TableManager.h"

bool TableManager::checkTable(Table* table) const {
    return table != nullptr;
}

int TableManager::countChildren() const {
    auto children = repository.findBy([](Table* table) {
        return table->getIsVipTable();
    });
    return children.size();
}
