
project(Tests)

add_executable(Tests Main.cpp Tests.cpp)
target_link_libraries(Tests PRIVATE DrkEngine)
target_include_directories(Tests PRIVATE ${PROJECT_SOURCE_DIR}/inc)

set(OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin")
set_target_properties(Tests DrkEngine
  PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY "${OUTPUT_DIRECTORY}"
    LIBRARY_OUTPUT_DIRECTORY "${OUTPUT_DIRECTORY}/lib"
    ARCHIVE_OUTPUT_DIRECTORY "${OUTPUT_DIRECTORY}/lib"
)
