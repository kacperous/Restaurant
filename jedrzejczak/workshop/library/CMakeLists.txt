cmake_minimum_required(VERSION 3.10)
project(Library)

# Znalezienie Boost
find_package(Boost 1.60.0 COMPONENTS unit_test_framework REQUIRED)

# Określenie plików źródłowych dla biblioteki
set(SOURCE_FILES
        src/model/Client.cpp
        src/model/Address.cpp
        src/model/Vehicle.cpp
        src/model/Rent.cpp
        src/model/Bicycle.cpp
        src/model/MotorVehicle.cpp
        src/model/Moped.cpp
        src/model/ClientType.cpp
        src/repositories/ClientRepository.cpp
        src/repositories/RentRepository.cpp
        src/repositories/VehicleRepository.cpp
        src/StorageContainer.cpp
        test/AddressTest.cpp
        test/RentTest.cpp
        test/VehicleTest.cpp
)

# Utworzenie biblioteki 'Library'
add_library(Library STATIC ${SOURCE_FILES})
target_include_directories(Library PUBLIC include)

# Określenie plików testowych
set(SOURCE_TEST_FILES test/master.cpp test/ClientTest.cpp)
add_executable(LibraryTester ${SOURCE_TEST_FILES})
target_link_libraries(LibraryTester Library ${Boost_UNIT_TEST_FRAMEWORK_LIBRARY})

# Dodanie testów
enable_testing()
add_test(NAME LibraryTest COMMAND LibraryTester)

# Include directory for the library
target_include_directories(Library PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)
