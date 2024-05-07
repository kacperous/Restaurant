//
// Created by student on 07.05.24.
//
#include <boost/test/unit_test.hpp>
#include "model/Moped.h"
#include "model/Moped.h"
BOOST_AUTO_TEST_CASE(moped_rental_price_test){
    Moped moped("El13414",1000,1,1000);
    BOOST_CHECK_EQUAL(moped.getActualRentalPrice(),1000);
    Moped moped1("El13414",1000,1,1500);
    BOOST_CHECK_EQUAL(moped1.getActualRentalPrice(),1250);
    Moped moped2("El13414",1000,1,2000);
    BOOST_CHECK_EQUAL(moped2.getActualRentalPrice(),1500);
    Moped moped3("El13414",1000,1,3000);
    BOOST_CHECK_EQUAL(moped3.getActualRentalPrice(),1500);
}