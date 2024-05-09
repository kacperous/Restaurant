cmake_minimum_required(VERSION 3.10)
project(Workshop)

# Ustawienie standardu C++ na C++14
set(CMAKE_CXX_STANDARD 14)

# Dodanie katalogu z nagłówkami
include_directories(include)

# Dodanie podkatalogów
add_subdirectory(library)
add_subdirectory(program)

# Jeśli potrzebujesz linkować biblioteki z podprojektów
# target_link_libraries(main_library main_program)
