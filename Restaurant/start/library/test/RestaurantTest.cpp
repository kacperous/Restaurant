#include <boost/test/unit_test.hpp>
#include "model/Adress.h"
#include "model/typedefs.h"
#include "model/ClientType.h"
#include "model/Default.h"
#include "model/Table.h"
#include "model/Reservation.h"
#include "model/Restaurant.h"

using namespace std;

namespace btt = boost::test_tools;

BOOST_AUTO_TEST_SUITE(RESTAURANT_TEST)
    BOOST_AUTO_TEST_CASE(TEST_RESTAURANT){
        AddressPtr address_restaurant = make_shared<Address>("Lodz", "Piotrkowska", "1");
        RestaurantPtr McDonald = make_shared<Restaurant>("McDonald",address_restaurant);
        TablePtr table = make_shared<Table>(1,5,false,false);
        TablePtr table2 = make_shared<Table>(2,3,false,true);
        TablePtr table3 = make_shared<Table>(3,7,true,false);
        TablePtr table4 = make_shared<Table>(4,2,true,true);
        McDonald->addTable(table);
        McDonald->addTable(table2);
        McDonald->addTable(table3);
        BOOST_TEST(McDonald->getName() == "McDonald");
        BOOST_TEST(McDonald->getAddress() == address_restaurant);
        const std::vector<TablePtr>& actualTables = McDonald->getTables();
        BOOST_REQUIRE_EQUAL(actualTables.size(), 3);
        McDonald->addTable(table4);
        BOOST_REQUIRE_EQUAL(actualTables.size(), 4);
        ClientTypePtr regularClientType = std::make_shared<Default>();
        AddressPtr address1 = make_shared<Address>("Lodz", "Piotrkowska", "1");
        ClientPtr client1 = make_shared<Client>(1,"Stefan","Kowalski",675345532,address1,regularClientType);
        std::tm date2 = {};
        date2.tm_year = 2024 - 1900;
        date2.tm_mon = 0;  // 0 to styczen
        date2.tm_mday = 30;
        date2.tm_hour = 10;
        date2.tm_min = 15;
        date2.tm_sec = 29;
        const std::vector<ReservationPtr>& actualReservations = McDonald->getReservations();
        BOOST_REQUIRE_EQUAL(actualReservations.size(), 0);
        ReservationPtr reservation1 = make_shared<Reservation>(1, date2, client1, table);
        ReservationPtr reservation2 = make_shared<Reservation>(2, date2, client1, table2);
        McDonald->addReservation(reservation1);
        McDonald->addReservation(reservation2);
        BOOST_REQUIRE_EQUAL(actualReservations.size(), 2);
        ReservationPtr reservation3 = make_shared<Reservation>(3, date2, client1, table4);
        McDonald->addReservation(reservation3);
        BOOST_REQUIRE_EQUAL(actualReservations.size(), 3);
    }
BOOST_AUTO_TEST_SUITE_END()