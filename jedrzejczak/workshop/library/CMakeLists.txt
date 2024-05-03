cmake_minimum_required(VERSION 3.10)

project(Library)

# Znalezienie Boost
find_package(Boost 1.60.0 COMPONENTS unit_test_framework REQUIRED)

# Określenie plików źródłowych dla biblioteki
set(SOURCE_FILES src/model/Client.cpp include/model/Client.h
        src/model/Address.cpp
        include/model/Vehicle.h
        src/model/Vehicle.cpp
        src/model/Rent.cpp
        include/model/Rent.h
)

# Utworzenie biblioteki 'Library'
add_library(Library STATIC ${SOURCE_FILES})

target_include_directories(Library PUBLIC include)

# Określenie plików testowych
set(SOURCE_TEST_FILES test/master.cpp test/ClientTest.cpp)
add_executable(LibraryTester ${SOURCE_TEST_FILES})
target_link_libraries(LibraryTester Library ${Boost_UNIT_TEST_FRAMEWORK_LIBRARY})

# Dodanie testów
add_test(NAME LibraryTest COMMAND LibraryTester)

