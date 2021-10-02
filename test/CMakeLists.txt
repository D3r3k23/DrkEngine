cmake_minimum_required(VERSION 3.16)

project(Tests)
add_executable(Tests)

target_link_libraries(Tests PRIVATE DrkEngine)
add_subdirectory(src)

set_target_properties(Tests
  PROPERTIES
    CXX_STANDARD 20
    CXX_STANDARD_REQUIRED ON
)

target_compile_options(Tests     PRIVATE -Wall)
target_compile_options(DrkEngine PRIVATE -Wall)

set(OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin/${CMAKE_BUILD_TYPE})
set_target_properties(Tests DrkEngine
  PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY $<1:${OUTPUT_DIRECTORY}>
    LIBRARY_OUTPUT_DIRECTORY $<1:${OUTPUT_DIRECTORY}/lib>
    ARCHIVE_OUTPUT_DIRECTORY $<1:${OUTPUT_DIRECTORY}/lib>
)
