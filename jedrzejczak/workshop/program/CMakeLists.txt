cmake_minimum_required(VERSION 3.4)

project(Program)

# Zbiór plików źródłowych projektu
set(SOURCE_FILES src/main.cpp)

# Zbudowanie programu wykonywalnego
add_executable(Program ${SOURCE_FILES})

# Linkowanie z biblioteką 'Library'
target_link_libraries(Program Library)

# Uwzględnienie katalogu include
target_include_directories(Program PUBLIC "${PROJECT_SOURCE_DIR}/library/include")

