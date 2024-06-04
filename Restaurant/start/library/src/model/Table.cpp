#include "model/Table.h"

Table::Table(int tableId, int tableSize, bool isReserved, bool isVipTable) : tableID(tableId), tableSize(tableSize),
                                                                             isReserved(isReserved),
                                                                             isVipTable(isVipTable) {}

Table::~Table() {

}

int Table::getTableId() const {
    return tableID;
}

void Table::setTableId(int tableId) {
    tableID = tableId;
}

int Table::getTableSize() const {
    return tableSize;
}

void Table::setTableSize(int TableSize) {
    Table::tableSize = TableSize;
}

bool Table::getIsReserved() const {
    return isReserved;
}

void Table::setIsReserved(bool IsReserved) {
    Table::isReserved = IsReserved;
}

bool Table::getIsVipTable() const {
    return isVipTable;
}

void Table::setIsVipTable(bool IsVipTable) {
    Table::isVipTable = IsVipTable;
}
std::string Table::getInfo() const {
    return "Table ID: " + std::to_string(tableID) +
           ", Size: " + std::to_string(tableSize);
}
