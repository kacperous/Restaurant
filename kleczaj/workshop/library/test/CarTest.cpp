//
// Created by student on 07.05.24.
//
#include <boost/test/unit_test.hpp>
#include "model/Car.h"

BOOST_AUTO_TEST_CASE(car_rental_price_test){
    Car car("Tsk231541",1000,1,1000,A);
    BOOST_CHECK_EQUAL(car.getActualRentalPrice(),1000);
    Car car1("Tsk231541",1000,1,1000,B);
    BOOST_CHECK_EQUAL(car1.getActualRentalPrice(),1100);
    Car car2("Tsk231541",1000,1,1000,C);
    BOOST_CHECK_EQUAL(car2.getActualRentalPrice(),1200);
    Car car3("Tsk231541",1000,1,1000,D);
    BOOST_CHECK_EQUAL(car3.getActualRentalPrice(),1300);
    Car car4("Tsk231541",1000,1,1000,E);
    BOOST_CHECK_EQUAL(car4.getActualRentalPrice(),1500);
    Car car5("Tsk231541",1000,1,2000,A);
    BOOST_CHECK_EQUAL(car5.getActualRentalPrice(),1500);
    Car car6("Tsk231541",1000,1,2000,E);
    BOOST_CHECK_EQUAL(car6.getActualRentalPrice(),2250);
}