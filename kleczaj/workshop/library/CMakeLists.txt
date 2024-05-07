# Włączenie testów powoduje pojawienie się celu test w Makefiles
enable_testing()

cmake_minimum_required(VERSION 3.4)
project(Library)

set(SOURCE_FILES
    src/model/Client.cpp
    include/model/Client.h
        include/model/Adress.h
        src/model/Adress.cpp
        test/AdressTest.cpp
        include/model/Vehicle.h
        src/model/Vehicle.cpp
        include/model/Rent.h
        src/model/Rent.cpp
        include/model/typedefs.h
        include/model/typedefs.h
        include/model/Bicycle.h
        include/model/MotorVehicle.h
        include/model/Moped.h
        include/model/Car.h
        src/model/Bicycle.cpp
        src/model/MotorVehicle.cpp
        src/model/Moped.cpp
        src/model/Car.cpp
        include/model/ClientType.h
)

# Utwórz bibliotekę typu STATIC, SHARED albo MODULE ze wskazanych źródeł
add_library(Library ${SOURCE_FILES})

target_include_directories(Library PUBLIC include)

find_package(Boost 1.60.0 COMPONENTS "unit_test_framework" REQUIRED)

include_directories(
    ${CMAKE_CURRENT_SOURCE_DIR}/include
    ${Boost_INCLUDE_DIRS}
)

set(SOURCE_TEST_FILES
    ${CMAKE_CURRENT_SOURCE_DIR}/test/master.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/test/ClientTest.cpp
        test/VehicleTest.cpp
        test/RentTest.cpp
        test/BicycleTest.cpp
        test/MopedTest.cpp
        test/CarTest.cpp

)
add_executable(LibraryTester ${SOURCE_TEST_FILES})

target_link_libraries(LibraryTester
    Library
    ${Boost_UNIT_TEST_FRAMEWORK_LIBRARY}
)

add_test(LibraryTest LibraryTester
    --report_level=detailed
    --log_level=all
    --color_output=yes
)
add_custom_target(check ${CMAKE_COMMAND} -E env CTEST_OUTPUT_ON_FAILURE=1 BOOST_TEST_LOG_LEVEL=all
        ${CMAKE_CTEST_COMMAND} -C $<CONFIGURATION> --verbose
        WORKING_DIRECTORY ${CMAKE_BINARY_DIR})
