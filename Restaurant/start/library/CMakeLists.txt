enable_testing()

cmake_minimum_required(VERSION 3.4)
project(Restaurant)

set(SOURCE_FILES
        include/model/Restaurant.h
        src/model/Restaurant.cpp
        test/RestaurantTest.cpp
        include/model/Adress.h
        src/model/Adress.cpp
        include/model/Table.h
        src/model/Table.cpp
        src/model/Reservation.cpp
        include/model/Reservation.h
        src/model/Client.cpp
        include/model/Client.h
        include/model/typedefs.h
        include/model/ClientType.h
        src/model/Default.cpp
        include/model/Default.h
        src/model/VIP.cpp
        include/model/VIP.h
        include/StorageContainer.h
        src/StorageContainer.cpp
        src/repositories/RestaurantRepositories.cpp
        include/repositories/RestaurantRepositories.h
        src/repositories/ClientRepositories.cpp
        include/repositories/ClientRepositories.h
        src/repositories/ReservationRepositories.cpp
        include/repositories/ReservationRepositories.h
        src/repositories/TableRepositories.cpp
        include/repositories/TableRepositories.h
        include/managers/TableManager.h
        src/managers/TableManager.cpp
        include/managers/ReservationManager.h
        src/managers/ReservationManager.cpp
        src/managers/ClientManager.cpp
        include/managers/ClientManager.h
)

add_library(Library ${SOURCE_FILES})

target_include_directories(Library PUBLIC include)

find_package(Boost 1.60.0 COMPONENTS "unit_test_framework" REQUIRED)

include_directories(
        ${CMAKE_CURRENT_SOURCE_DIR}/include
        ${Boost_INCLUDE_DIRS}
)

set(SOURCE_TEST_FILES
        ${CMAKE_CURRENT_SOURCE_DIR}/test/master.cpp
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