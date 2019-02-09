cmake_minimum_required(VERSION 3.11)
project(simple_c)

set(CMAKE_CXX_STANDARD 14)

add_subdirectory(utils)

add_executable(simple_c
        hello.cpp)
target_link_libraries(${PROJECT_NAME} Utils)
