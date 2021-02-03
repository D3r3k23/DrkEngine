option(Debug "Debug" OFF)

cmake_minimum_required(VERSION 3.16)
project(DrkEngine)

if(Debug == ON)
    set(CMAKE_BUILD_TYPE Debug)
else()
    set(CMAKE_BUILD_TYPE Release)
endif()

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall")

add_subdirectory(DrkEngine)
add_subdirectory(ConsoleChess)
