#include <boost/test/unit_test.hpp>
#include "../include/model/Rent.h"
#include "../include/model/Client.h"
#include "../include/model/Vehicle.h"
#include <memory>

BOOST_AUTO_TEST_SUITE(RentSuite)

// Test konstruktora klasy Rent
    BOOST_AUTO_TEST_CASE(TestRentConstructor) {
        auto client = std::make_shared<Client>("Jan", "Kowalski", "12345678901");
        auto vehicle = std::make_shared<Vehicle>("DW12345", 150, true);
        Rent rent(1, client, vehicle);

        BOOST_CHECK_EQUAL(rent.getId(), 1);
        BOOST_CHECK(rent.getClient() == client);
        BOOST_CHECK(rent.getVehicle() == vehicle);
    }

// Test zarządzania stanem wynajmu
    BOOST_AUTO_TEST_CASE(TestRentState) {
        auto client = std::make_shared<Client>("Anna", "Nowak", "01987654321");
        auto vehicle = std::make_shared<Vehicle>("KR6789A", 100, false);
        Rent rent(2, client, vehicle);

        // Zakładamy, że Vehicle ma metodę `setRented`, która aktualizuje stan wynajmu
        vehicle->setRented(true);
        BOOST_CHECK(vehicle->getRented() == true);

        // Sprawdzenie informacji zwracanych przez Rent
        std::string expected_info = "Rent ID: 2, Client Info: [Client Info], Vehicle Info: [Vehicle Info]";
        BOOST_CHECK_EQUAL(rent.getInfo(), expected_info);
    }

// Test zmiany pojazdu w trakcie wynajmu
    BOOST_AUTO_TEST_CASE(TestChangeVehicle) {
        auto client = std::make_shared<Client>("Mikołaj", "Bęben", "00000000001");
        auto vehicle1 = std::make_shared<Vehicle>("GD4567Z", 250, true);
        auto vehicle2 = std::make_shared<Vehicle>("WE7654P", 300, true);
        Rent rent(3, client, vehicle1);


        BOOST_CHECK(rent.getVehicle() == vehicle2);
    }

BOOST_AUTO_TEST_SUITE_END()
