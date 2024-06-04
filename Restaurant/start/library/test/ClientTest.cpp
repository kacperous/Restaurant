#include <boost/test/unit_test.hpp>
#include "model/Adress.h"
#include "model/typedefs.h"
#include "model/ClientType.h"
#include "model/VIP.h"
#include "model/Default.h"

using namespace std;

namespace btt = boost::test_tools;

BOOST_AUTO_TEST_SUITE(CLIENT_TEST)
    BOOST_AUTO_TEST_CASE(TEST_CLIENT){
        AddressPtr address1 = make_shared<Address>("Lodz", "Piotrkowska", "1");
        AddressPtr address2 = make_shared<Address>("Warszawa", "Zlote Tarasy", "2");
        ClientTypePtr regularClientType = std::make_shared<Default>();
        ClientTypePtr vipClientType = std::make_shared<VIP>();
        ClientPtr client1 = make_shared<Client>(1,"Stefan","Kowalski",675345532,address1,regularClientType);
        ClientPtr client2 = make_shared<Client>(2,"Marian","Stefanski",321567428,address2,vipClientType);
        BOOST_TEST(client1->getPersonalId() ==1);
        BOOST_TEST(client1->getFirstName() == "Stefan");
        BOOST_TEST(client1->getLastName() == "Kowalski");
        BOOST_TEST(client1->getPhoneNumber() == 675345532);
        BOOST_TEST(client1->getAddress() == address1);
        BOOST_TEST(client1->getClientType() == regularClientType);

        BOOST_TEST(client2->getPersonalId() ==2);
        BOOST_TEST(client2->getFirstName() == "Marian");
        BOOST_TEST(client2->getLastName() == "Stefanski");
        BOOST_TEST(client2->getPhoneNumber() == 321567428);
        BOOST_TEST(client2->getAddress() == address2);
        BOOST_TEST(client2->getClientType() == vipClientType);
    }
BOOST_AUTO_TEST_SUITE_END()


