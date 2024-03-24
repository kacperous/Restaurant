#include <boost/test/unit_test.hpp>
#include "model/Client.h"

/**
 * @brief Test suite for the Client class.
 */
BOOST_AUTO_TEST_SUITE(TestSuiteClient)

/**
 * @brief Test case for the setFirstName method of the Client class.
 *
 * This test case checks the behavior of the setFirstName method.
 */
    BOOST_AUTO_TEST_CASE(SetFirstNameTest) {
        // Pozytywny test - ustaw nowe imię
        Client client("Jan", "Kowalski", "1");
        client.setFirstName("Adam");
        BOOST_CHECK_EQUAL(client.getFirstName(), "Adam");

        // Negatywny test - próba ustawienia pustego imienia
        client.setFirstName("");
        BOOST_CHECK_EQUAL(client.getFirstName(), "Adam"); // Sprawdzamy, czy imię pozostało niezmienione
    }

/**
 * @brief Test case for the setLastName method of the Client class.
 *
 * This test case checks the behavior of the setLastName method.
 */
    BOOST_AUTO_TEST_CASE(SetLastNameTest) {
        // Pozytywny test - ustaw nowe nazwisko
        Client client("Jan", "Kowalski", "1");
        client.setLastName("Nowak");
        BOOST_CHECK_EQUAL(client.getLastName(), "Nowak");

        // Negatywny test - próba ustawienia pustego nazwiska
        client.setLastName("");
        BOOST_CHECK_EQUAL(client.getLastName(), "Nowak"); // Sprawdzamy, czy nazwisko pozostało niezmienione
    }

BOOST_AUTO_TEST_SUITE_END()






