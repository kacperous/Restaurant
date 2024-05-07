cmake_minimum_required(VERSION 3.10)
project(jedrzejczak)

# Dodanie podkatalogów, które zawierają własne pliki CMakeLists.txt
add_subdirectory(library)
add_subdirectory(program)

