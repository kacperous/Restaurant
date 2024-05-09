cmake_minimum_required(VERSION 3.4)

project(Program)

# Dodanie katalogu z bibliotekami
include_directories(../library/include)

# Zdefiniowanie pliku wykonywalnego
add_executable(Program src/main.cpp)

# Linkowanie z biblioteką, jeśli jest wymagane
target_link_libraries(Program Library)

