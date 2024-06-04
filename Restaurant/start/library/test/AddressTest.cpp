#include <boost/test/unit_test.hpp>
#include "model/Adress.h"
#include "model/typedefs.h"

using namespace std;

namespace btt = boost::test_tools;

BOOST_AUTO_TEST_SUITE(ADDRESS_TEST)
    BOOST_AUTO_TEST_CASE(TEST_ADDRESS) {
        AddressPtr address = make_shared<Address>("Lodz", "Piotrkowska", "1");
        BOOST_TEST(address->getCity() == "Lodz");
        BOOST_TEST(address->getStreet() == "Piotrkowska");
        BOOST_TEST(address->getNumber() == "1");
    }
BOOST_AUTO_TEST_SUITE_END()