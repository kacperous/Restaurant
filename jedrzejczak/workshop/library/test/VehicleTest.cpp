#include <boost/test/unit_test.hpp>
#include "../include/model/Vehicle.h"

BOOST_AUTO_TEST_SUITE(VehicleSuite)

// Test konstruktora klasy Vehicle
    BOOST_AUTO_TEST_CASE(TestVehicleConstructor) {
        Vehicle vehicle("DW12345", 150, true);

        BOOST_CHECK_EQUAL(vehicle.getPlateNumber(), "DW12345");
        BOOST_CHECK_EQUAL(vehicle.getBasePrice(), 150);
        BOOST_CHECK(vehicle.getRented());
    }

// Test metody setRented i getRented
    BOOST_AUTO_TEST_CASE(TestVehicleRentalStatus) {
        Vehicle vehicle("KR6789A", 100, false);

        // Sprawdzenie początkowego stanu wynajmu
        BOOST_CHECK(!vehicle.getRented());

        // Zmiana stanu wynajmu i sprawdzenie
        vehicle.setRented(true);
        BOOST_CHECK(vehicle.getRented());
    }


    BOOST_AUTO_TEST_CASE(TestVehicleRentalPriceCalculation) {
        Vehicle vehicle("GD4567Z", 250, true);


        std::string expectedPrice = "Actual Rental Price: " + std::to_string(250);
        BOOST_CHECK_EQUAL(vehicle.getActualRentalPrice(), expectedPrice);
    }



BOOST_AUTO_TEST_SUITE_END()
