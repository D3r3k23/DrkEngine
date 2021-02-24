
cmake_minimum_required(VERSION 3.16)
project(DrkEngine)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall")

add_library(DrkEngine STATIC)
target_include_directories(DrkEngine PUBLIC inc)
add_subdirectory(src)

if(${CMAKE_BUILD_TYPE} STREQUAL Debug)
    target_compile_definitions(DrkEngine
      PRIVATE
        DRK_EN_LOGGING
        DRK_EN_ASSERTS
    )
else()
    target_compile_definitions(DrkEngine
      PRIVATE
        DRK_EN_ASSERTS
    )
endif()

option(BUILD_TESTS "Build unit tests" OFF)
if (${BUILD_TESTS})
    add_subdirectory(tests)
endif()
