cmake_minimum_required(VERSION 3.19)

project(DrkEngine)

option(DRK_ENGINE_BUILD_TESTS, "Build tests", OFF)
option(DRK_ENGINE_BUILD_CONSOLE_CHESS, "Build ConsoleChess application", OFF)

# Set PLATFORM
if(${CMAKE_SYSTEM_NAME} STREQUAL Windows)
    set(DRK_ENGINE_PLATFORM Windows)
elseif(${CMAKE_SYSTEM_NAME} STREQUAL Linux)
    set(DRK_ENGINE_PLATFORM Linux)
else()
    message("Error: Unsupported platform")
    return()
endif()

# Set BUILD_CONFIG
if(${CMAKE_BUILD_TYPE} STREQUAL Debug)
    set(DRK_ENGINE_BUILD_CONFIG Debug)
elseif((${CMAKE_BUILD_TYPE} STREQUAL Release) OR (${CMAKE_BUILD_TYPE} STREQUAL RelWithDebInfo))
    set(DRK_ENGINE_BUILD_CONFIG Release)
else()
    message("CMAKE_BUILD_TYPE not set")
    set(DRK_ENGINE_BUILD_CONFIG Debug)
endif()

set_property(CXX_STANDARD 20)
set_property(CXX_STANDARD_REQUIRED ON)

###################################
add_library(DrkEngine STATIC)
add_subdirectory(include)
add_subdirectory(src)
add_subdirectory(lib)
###################################

if(${DRK_ENGINE_BUILD_CONFIG} STREQUAL Debug)
    target_compile_definitions(DrkEngine PUBLIC DRK_BUILD_CONFIG_DEBUG)
endif()

if(${DRK_ENGINE_BUILD_TESTS})
    add_subdirectory(test)
endif()

if(${DRK_ENGINE_BUILD_CONSOLE_CHESS})
    add_subdirectory(ConsoleChess)
endif()
