#include <boost/test/unit_test.hpp>
#include "../include/model/Address.h"

BOOST_AUTO_TEST_SUITE(AddressSuite)

// Test konstruktora klasy Address
    BOOST_AUTO_TEST_CASE(TestAddressDefaultConstructor) {
        Address address;
        BOOST_CHECK(address.getCity().empty());
        BOOST_CHECK(address.getStreet().empty());
        BOOST_CHECK(address.getNumber().empty());
    }

    BOOST_AUTO_TEST_CASE(TestAddressParameterizedConstructor) {
        Address address("Kraków", "Floriańska", "15");
        BOOST_CHECK_EQUAL(address.getCity(), "Kraków");
        BOOST_CHECK_EQUAL(address.getStreet(), "Floriańska");
        BOOST_CHECK_EQUAL(address.getNumber(), "15");
    }

// Testy setterów i getterów
    BOOST_AUTO_TEST_CASE(TestSettersAndGetters) {
        Address address;
        address.setCity("Warszawa");
        address.setStreet("Marszałkowska");
        address.setNumber("99A");

        BOOST_CHECK_EQUAL(address.getCity(), "Warszawa");
        BOOST_CHECK_EQUAL(address.getStreet(), "Marszałkowska");
        BOOST_CHECK_EQUAL(address.getNumber(), "99A");
    }

// Test metody getInfo
    BOOST_AUTO_TEST_CASE(TestGetInfo) {
        Address address("Warszawa", "Marszałkowska", "99A");
        std::string expected_info = "City: Warszawa, Street: Marszałkowska, Number: 99A";
        BOOST_CHECK_EQUAL(address.getInfo(), expected_info);
    }

BOOST_AUTO_TEST_SUITE_END()
