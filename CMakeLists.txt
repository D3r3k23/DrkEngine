option(Debug "Debug" OFF)

cmake_minimum_required(VERSION 3.16)
project(DrkEngine)

if(${Debug} STREQUAL ON)
    message("Debug build:")
    set(CMAKE_BUILD_TYPE Debug)
else()
    message("Release build:")
    set(CMAKE_BUILD_TYPE Release)
endif()


set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall")

set(BIN_DIRECTORY "${PROJECT_SOURCE_DIR}/build/bin/${CMAKE_SYSTEM_NAME}/${CMAKE_BUILD_TYPE}")

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${BIN_DIRECTORY}")
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY "${BIN_DIRECTORY}/lib")


add_subdirectory(DrkEngine)

add_executable(ConsoleChess)
add_subdirectory(ConsoleChess)

target_link_libraries(ConsoleChess DrkEngine)
target_include_directories(ConsoleChess PUBLIC "${PROJECT_SOURCE_DIR}/DrkEngine/include")