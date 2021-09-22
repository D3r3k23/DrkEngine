cmake_minimum_required(VERSION 3.16)

if (NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE Release)
endif()
message("${CMAKE_BUILD_TYPE} build.")

project(DrkEngine)

add_library(DrkEngine STATIC)
target_include_directories(DrkEngine
  INTERFACE
    include
  PRIVATE
    src
)
add_subdirectory(src)

set_target_properties(DrkEngine
  PROPERTIES
    CXX_STANDARD 20
    CXX_STANDARD_REQUIRED ON
)

target_compile_options(DrkEngine
  PRIVATE
    -Wall
)

if(${CMAKE_BUILD_TYPE} STREQUAL Debug)
    target_compile_definitions(DrkEngine
      PUBLIC
        DRK_DEBUG
    )
endif()

option(BUILD_TESTS "Build unit tests" OFF)
if (${BUILD_TESTS})
    add_subdirectory(test)
endif()
