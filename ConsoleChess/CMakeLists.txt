add_subdirectory(src)

target_include_directories(
  ConsoleChess
    PUBLIC
    "${PROJECT_SOURCE_DIR}/ConsoleChess/include"
)