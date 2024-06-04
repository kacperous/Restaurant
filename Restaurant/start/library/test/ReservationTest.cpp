#include <boost/test/unit_test.hpp>
#include "model/Adress.h"
#include "model/typedefs.h"
#include "model/ClientType.h"
#include "model/Default.h"
#include "model/Table.h"
#include "model/Reservation.h"
#include <ctime>

using namespace std;

namespace btt = boost::test_tools;

BOOST_AUTO_TEST_SUITE(RESERVATION_TEST)
    bool compareDates(const std::tm& lhs, const std::tm& rhs) {
        return lhs.tm_year == rhs.tm_year &&
               lhs.tm_mon == rhs.tm_mon &&
               lhs.tm_mday == rhs.tm_mday &&
               lhs.tm_hour == rhs.tm_hour &&
               lhs.tm_min == rhs.tm_min &&
               lhs.tm_sec == rhs.tm_sec;
    }
    BOOST_AUTO_TEST_CASE(TEST_RESERVATION){
        AddressPtr address1 = make_shared<Address>("Lodz", "Piotrkowska", "1");
        ClientTypePtr regularClientType = std::make_shared<Default>();
        ClientPtr client1 = make_shared<Client>(1,"Stefan","Kowalski",675345532,address1,regularClientType);
        TablePtr table1 = make_shared<Table>(1,5,false,false);
        std::tm date = {};
        date.tm_year = 2024 - 1900;
        date.tm_mon = 4;  // 0 to styczen
        date.tm_mday = 29;
        date.tm_hour = 18;
        date.tm_min = 30;
        date.tm_sec = 0;
        ReservationPtr reservation1 = make_shared<Reservation>(1, date, client1, table1);
        BOOST_TEST(reservation1->getReservationId() == 1);
        BOOST_TEST(compareDates(reservation1->getDate(), date));
        BOOST_TEST(reservation1->getClient() == client1);
        BOOST_TEST(reservation1->getTable() == table1);
        std::tm date2 = {};
        date2.tm_year = 2024 - 1900;
        date2.tm_mon = 0;  // 0 to styczen
        date2.tm_mday = 30;
        date2.tm_hour = 10;
        date2.tm_min = 15;
        date2.tm_sec = 29;
        ReservationPtr reservation2 = make_shared<Reservation>(1, date2, client1, table1);
        BOOST_TEST(reservation2->getReservationId() == 1);
        BOOST_TEST(compareDates(reservation2->getDate(), date2));
        BOOST_TEST(reservation2->getClient() == client1);
        BOOST_TEST(reservation2->getTable() == table1);
    }
BOOST_AUTO_TEST_SUITE_END()