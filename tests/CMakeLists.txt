
project(Tests)

add_executable(Tests)
target_link_libraries(Tests PRIVATE DrkEngine)

target_sources(Tests
  PRIVATE
    src/Main.cpp
    src/Tests.cpp
    src/TestUtils.cpp
)

set_target_properties(Tests
  PROPERTIES
    CXX_STANDARD 17
    CXX_STANDARD_REQUIRED ON
)

target_compile_options(Tests
  PRIVATE
    -Wall
    -Wextra
)

set(OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin")
set_target_properties(Tests DrkEngine
  PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY "${OUTPUT_DIRECTORY}"
    LIBRARY_OUTPUT_DIRECTORY "${OUTPUT_DIRECTORY}/lib"
    ARCHIVE_OUTPUT_DIRECTORY "${OUTPUT_DIRECTORY}/lib"
)
