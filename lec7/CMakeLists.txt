cmake_minimum_required(VERSION 3.1)
project(lec7 C CXX)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(lec7
        port.h
        vintage_port.h port.cpp vintage_port.cpp main.cpp)

