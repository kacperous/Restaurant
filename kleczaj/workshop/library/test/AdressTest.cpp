#include <boost/test/unit_test.hpp>
#include "model/Client.h"
#include "model/Adress.h"

struct TestSuiteClientFixture {
    const std::string testFirstName = "Jon";
    const std::string testLastName = "Arbuckle";
    const std::string testPersonalID = "0123456789";
    ClientType *clientType;
    Adress *testaddress1;
    Adress *testaddress2;

    TestSuiteClientFixture() {
        testaddress1 = new Adress("London", "Accacia Avenue", "22");
        testaddress2 = new Adress("London", "Rue Morgue", "13");
    }

    ~TestSuiteClientFixture() {
        delete testaddress1;
        delete testaddress2;
    }

};

BOOST_FIXTURE_TEST_SUITE(TestSuiteClient, TestSuiteClientFixture)

    BOOST_AUTO_TEST_CASE(ParameterConstrutorTest) {

        Client c(testFirstName, testLastName, testPersonalID, testaddress1,clientType);
        BOOST_TEST(testFirstName == c.getFirstName());
        BOOST_TEST(testLastName == c.getLastName());
        BOOST_TEST(testPersonalID == c.getPersonalID());
        BOOST_TEST(testaddress1 == c.getAdress());
    }

BOOST_AUTO_TEST_SUITE_END()