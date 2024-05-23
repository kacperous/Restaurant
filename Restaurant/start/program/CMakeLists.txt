enable_testing()

cmake_minimum_required(VERSION 3.4)

set(SOURCE_FILES src/main.cpp)

add_executable(Program ${SOURCE_FILES})

target_link_libraries(Program Library)

target_include_directories(Program PUBLIC "${CMAKE_SOURCE_DIR}/../library/include/model")
target_include_directories(Program PUBLIC include)