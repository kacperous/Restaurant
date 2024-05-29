#ifndef RESTAURANT_TABLEREPOSITORIES_H
#define RESTAURANT_TABLEREPOSITORIES_H
#include <vector>
#include <functional>
#include "../model/Table.h"

using TablePredicate = std::function<bool(Table*)>;

class TableRepository {
public:
    void addTable(Table* table);
    Table* getTable(size_t index) const;
    void removeTable(Table* table);
    std::vector<Table*> findBy(TablePredicate predicate) const;

private:
    std::vector<Table*> tables;
};
#endif //RESTAURANT_TABLEREPOSITORIES_H
