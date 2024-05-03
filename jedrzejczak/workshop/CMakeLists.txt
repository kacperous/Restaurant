cmake_minimum_required(VERSION 3.10) # Używamy najnowszej wymaganej wersji

project(workshop)

# Włączenie testowania
enable_testing()

# Ustawienie standardu C++17
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Dodatkowe flagi kompilatora dla debugowania
set(CMAKE_BUILD_TYPE Debug)
set(CMAKE_CXX_FLAGS_DEBUG "-g3 -gdwarf-4 -Wall -Wpedantic -Wextra")

# Dodanie podprojektów
add_subdirectory(library)
add_subdirectory(program)

