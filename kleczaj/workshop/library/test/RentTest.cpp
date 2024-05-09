#include <boost/test/unit_test.hpp>
#include "model/Rent.h"
#include "model/Client.h"
#include "model/Vehicle.h"
#include "model/Adress.h"

using namespace std;

struct TestSuiteRentFixture{
    const int id = 1;
    ClientType *type= new Default();
    AdressPtr a1=make_shared<Adress>("London", "Accacia Avenue", "22");
    ClientPtr c1=make_shared<Client>("Marian","Kucyk","12",a1,type);
    VehiclePtr w1=make_shared<Vehicle>("WSZ23131",760,false);

    ~TestSuiteRentFixture(){

    }
};

BOOST_FIXTURE_TEST_SUITE(TestSuiteRent, TestSuiteRentFixture)
/*
    BOOST_AUTO_TEST_CASE(ParameterConstrutorTest) {
        Rent w(id,c1,w1);
        BOOST_TEST(id == w.getId());
        BOOST_TEST(c1 == w.getClient());
        BOOST_TEST(w1 == w.getVehicle());
    }
    */
    BOOST_AUTO_TEST_CASE(NoRentTest)
    {
        pt::ptime beginTime;
        pt::ptime endTime;
        Rent r(1, c1, w1,beginTime,endTime);
        BOOST_CHECK_EQUAL(r.getRentDays(),0);
    }

    BOOST_AUTO_TEST_CASE(OneMinuteRentTest)
    {
        // Tworzymy wypożyczenie trwające dokładnie 1 minutę
        pt::ptime beginTime = pt::second_clock::local_time();
        pt::ptime endTime = pt::second_clock::local_time() + pt::minutes(1);
        Rent r(2, c1, w1,beginTime,endTime);
        BOOST_CHECK_EQUAL(r.getRentDays(), 1);
    }

    BOOST_AUTO_TEST_CASE(TwentyThreeHoursFiftyNineMinutesRentTest)
    {
        // Tworzymy wypożyczenie trwające 23 godziny i 59 minut
        pt::ptime beginTime = pt::second_clock::local_time();
        pt::ptime endTime = beginTime + pt::hours(23) + pt::minutes(59);
        Rent r(3, c1, w1,beginTime,endTime);
        BOOST_CHECK_EQUAL(r.getRentDays(), 1);
    }

    BOOST_AUTO_TEST_CASE(TwentyFourHoursRentTest)
    {
        // Tworzymy wypożyczenie trwające dokładnie 24 godziny
        pt::ptime beginTime = pt::second_clock::local_time();
        pt::ptime endTime = beginTime + pt::hours(24);
        Rent r(4, c1, w1,beginTime,endTime);
        BOOST_CHECK_EQUAL(r.getRentDays(), 1);
    }

    BOOST_AUTO_TEST_CASE(TwentyFourHoursOneMinuteRentTest)
    {
        // Tworzymy wypożyczenie trwające 24 godziny i 1 minutę
        pt::ptime beginTime = pt::second_clock::local_time();
        pt::ptime endTime = beginTime + pt::hours(24) + pt::minutes(1);
        Rent r(5, c1, w1,beginTime,endTime);
        BOOST_CHECK_EQUAL(r.getRentDays(), 2);
    }

    BOOST_AUTO_TEST_CASE(FortyEightHoursRentTest)
    {
        // Tworzymy wypożyczenie trwające 48 godzin
        pt::ptime beginTime = pt::second_clock::local_time();
        pt::ptime endTime = beginTime + pt::hours(48);
        Rent r(6, c1, w1,beginTime,endTime);
        BOOST_CHECK_EQUAL(r.getRentDays(), 2);
    }

    BOOST_AUTO_TEST_CASE(EndedRentTest)
    {
        // Wypożyczenie zakończone
        pt::ptime beginTime = pt::second_clock::local_time();
        pt::ptime endTime = beginTime; // Wypożyczenie zakończone w tym samym momencie rozpoczęcia
        Rent r(7, c1, w1,beginTime,endTime);
        BOOST_CHECK_EQUAL(r.getRentDays(), 0);
    }
BOOST_AUTO_TEST_SUITE_END()
