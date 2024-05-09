#include <boost/test/unit_test.hpp>
#include "model/Client.h"
#include "model/Adress.h"
#include "model/typedefs.h"
#include <memory>

BOOST_AUTO_TEST_SUITE(TestSuiteClient)

    BOOST_AUTO_TEST_CASE(SetLastNameTest) {
        // Pozytywny test - ustaw nowe nazwisko
        ClientType *gold = new Gold();
        auto a1=make_shared<Adress>("lodz","gdzies","5");
        ClientPtr client = make_shared<Client>("Jan", "Kowalski", "1",a1,gold);
        client->setLastName("Nowak");
        client->setFirstName("Adam");
        BOOST_CHECK_EQUAL(client->getFirstName(), "Adam");
        BOOST_CHECK_EQUAL(client->getLastName(), "Nowak");

        // Negatywny test - próba ustawienia pustego nazwiska
        client->setLastName("");
        BOOST_CHECK_EQUAL(client->getLastName(), "Nowak"); // Sprawdzamy, czy nazwisko pozostało niezmienione
    }

BOOST_AUTO_TEST_SUITE_END()


