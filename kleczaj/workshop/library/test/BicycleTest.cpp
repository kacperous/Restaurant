//
// Created by student on 07.05.24.
//
#include <boost/test/unit_test.hpp>
#include "model/Bicycle.h"

BOOST_AUTO_TEST_CASE(bicycle_rental_price_test){
    Bicycle bicycle("TSK23532",450,0);
    BOOST_CHECK_EQUAL(bicycle.getActualRentalPrice(),450);
}