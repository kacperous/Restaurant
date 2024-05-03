#include <boost/test/unit_test.hpp>
#include "model/Vehicle.h"

using namespace std;

struct TestSuiteVehicleFixture {
    const string testNumberPlate = "WSZ23154";
    const int testPrice = 267;
    const bool testisRented = false;
};

BOOST_FIXTURE_TEST_SUITE(TestSuiteVehicle, TestSuiteVehicleFixture)

    BOOST_AUTO_TEST_CASE(ParameterConstrutorTest) {
        Vehicle w(testNumberPlate, testPrice, testisRented);
        BOOST_TEST(testNumberPlate == w.getPlateNumber());
        BOOST_TEST(testPrice == w.getBasePrice());
        BOOST_TEST(testisRented == w.getRented());
    }

BOOST_AUTO_TEST_SUITE_END()
