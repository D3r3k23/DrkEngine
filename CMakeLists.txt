
cmake_minimum_required(VERSION 3.16)
project(DrkEngine)

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
