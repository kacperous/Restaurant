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

bool Table::GetisReserved() const {
    return isReserved;
}

void Table::setIsReserved(bool IsReserved) {
    Table::isReserved = IsReserved;
}

bool Table::GetisVipTable() const {
    return isVipTable;
}

void Table::setIsVipTable(bool IsVipTable) {
    Table::isVipTable = IsVipTable;
}
