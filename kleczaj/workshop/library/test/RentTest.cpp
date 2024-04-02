#include <boost/test/unit_test.hpp>
#include "model/Rent.h"
#include "model/Client.h"
#include "model/Vehicle.h"
#include "model/Adress.h"
using namespace std;

struct TestSuiteRentFixture{
    const int id = 1;
    Client* c1;
    Vehicle* w1;

    TestSuiteRentFixture(){
        Adress *a1 = new Adress("London", "Accacia Avenue", "22");
        Client *c1= new Client("Marian","Kucyk","12",a1);
        Vehicle *w1 = new Vehicle("WSZ23131",760,false);
    };
    ~TestSuiteRentFixture(){
        //delete a1;
        delete c1;
        delete w1; }
};
BOOST_FIXTURE_TEST_SUITE(TestSuiteVehicle, TestSuiteRentFixture)

    BOOST_AUTO_TEST_CASE(ParameterConstrutorTest) {
        Rent w(id,c1,w1);
        BOOST_TEST(id == w.getId());
        BOOST_TEST(c1 == w.getClient());
        BOOST_TEST(w1 == w.getVehicle());
    }

BOOST_AUTO_TEST_SUITE_END()
