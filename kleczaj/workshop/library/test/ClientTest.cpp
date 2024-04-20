#include <boost/test/unit_test.hpp>
#include "model/Client.h"
#include "model/Adress.h"

BOOST_AUTO_TEST_SUITE(TestSuiteClient)

    BOOST_AUTO_TEST_CASE(SetFirstNameTest) {
        // Pozytywny test - ustaw nowe imię
        Adress a1("lodz","gdzies","5");
        Client client("Jan", "Kowalski", "1",&a1);
        client.setFirstName("Adam");
        BOOST_CHECK_EQUAL(client.getFirstName(), "Adam");

        // Negatywny test - próba ustawienia pustego imienia
        client.setFirstName("");
        BOOST_CHECK_EQUAL(client.getFirstName(), "Adam"); // Sprawdzamy, czy imię pozostało niezmienione
    }

    BOOST_AUTO_TEST_CASE(SetLastNameTest) {
        // Pozytywny test - ustaw nowe nazwisko
        Adress a1("lodz","gdzies","5");
        Client client("Jan", "Kowalski", "1",&a1);
        client.setLastName("Nowak");
        BOOST_CHECK_EQUAL(client.getLastName(), "Nowak");

        // Negatywny test - próba ustawienia pustego nazwiska
        client.setLastName("");
        BOOST_CHECK_EQUAL(client.getLastName(), "Nowak"); // Sprawdzamy, czy nazwisko pozostało niezmienione
    }

BOOST_AUTO_TEST_SUITE_END()


