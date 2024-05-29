#ifndef RESTAURANT_TABLE_H
#define RESTAURANT_TABLE_H
#include <string>
class Table{
public:
    std::string getInfo();
    void setAvailability();

    int getTableId() const;

    void setTableId(int tableId);

    int getTableSize() const;

    void setTableSize(int tableSize);

    bool isReserved1() const;

    void setIsReserved(bool isReserved);

    bool isVipTable1() const;

    void setIsVipTable(bool isVipTable);

    virtual ~Table();

    Table(int tableId, int tableSize, bool isReserved, bool isVipTable);

private:
    int tableID;
    int tableSize;
    bool isReserved;
    bool isVipTable;
};
#endif //RESTAURANT_TABLE_H
