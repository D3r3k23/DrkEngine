
cmake_minimum_required(VERSION 3.16)
project(DrkEngine)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

add_library(DrkEngine STATIC)
target_include_directories(DrkEngine PUBLIC inc)
add_subdirectory(src)

set_target_properties(DrkEngine
  PROPERTIES
    CXX_STANDARD 17
    CXX_STANDARD_REQUIRED ON
)

target_compile_options(DrkEngine
  PRIVATE
    -Wall
    -Wextra
)

if(${CMAKE_BUILD_TYPE} STREQUAL Debug)
    target_compile_definitions(DrkEngine
      PUBLIC
        DRK_DEBUG
    )
endif()

option(BUILD_TESTS "Build unit tests" OFF)
if (${BUILD_TESTS})
    add_subdirectory(tests)
endif()
