#include <boost/test/unit_test.hpp>
#include "model/typedefs.h"
#include "model/Table.h"


using namespace std;

namespace btt = boost::test_tools;

BOOST_AUTO_TEST_SUITE(TABLE_TEST)
    BOOST_AUTO_TEST_CASE(TEST_TABLE){
        TablePtr table = make_shared<Table>(1,5,false,false);
        TablePtr table2 = make_shared<Table>(2,3,false,true);
        TablePtr table3 = make_shared<Table>(3,7,true,false);
        TablePtr table4 = make_shared<Table>(4,2,true,true);
        BOOST_TEST(table->getTableId() == 1);
        BOOST_TEST(table->getTableSize() == 5);
        BOOST_TEST(table->getIsReserved() == false);
        BOOST_TEST(table->getIsVipTable() == false);
        BOOST_TEST(table2->getTableId() == 2);
        BOOST_TEST(table2->getTableSize() == 3);
        BOOST_TEST(table2->getIsReserved() == false);
        BOOST_TEST(table2->getIsVipTable() == true);
        BOOST_TEST(table3->getTableId() == 3);
        BOOST_TEST(table3->getTableSize() == 7);
        BOOST_TEST(table3->getIsReserved() == true);
        BOOST_TEST(table3->getIsVipTable() == false);
        BOOST_TEST(table4->getTableId() == 4);
        BOOST_TEST(table4->getTableSize() == 2);
        BOOST_TEST(table4->getIsReserved() == true);
        BOOST_TEST(table4->getIsVipTable() == true);
    }
BOOST_AUTO_TEST_SUITE_END()