#include <boost/test/unit_test.hpp>
#include "../include/model/Client.h"

BOOST_AUTO_TEST_SUITE(ClientSuite)

// Przykładowy test konstruktora Client
    BOOST_AUTO_TEST_CASE(TestClientConstructor) {
        Client c("Jan", "Kowalski", "12345678901"); // Użycie konstruktora z trzema argumentami
        BOOST_CHECK_EQUAL(c.getFirstName(), "Jan");
        BOOST_CHECK_EQUAL(c.getLastName(), "Kowalski");
        BOOST_CHECK_EQUAL(c.getPersonalID(), "12345678901");
    }


BOOST_AUTO_TEST_SUITE_END()
