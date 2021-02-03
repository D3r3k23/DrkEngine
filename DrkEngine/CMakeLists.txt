add_library(DrkEngine)
add_subdirectory(src)

target_include_directories(
  DrkEngine
    PUBLIC
    "${PROJECT_SOURCE_DIR}/DrkEngine/include"
)

if(${CMAKE_BUILD_TYPE} STREQUAL Debug)
    target_compile_definitions(
      DrkEngine
      PRIVATE
        DRK_EN_LOGGING
        DRK_EN_ASSERTS
    )
else()
    target_compile_definitions(
      DrkEngine
      PRIVATE
        DRK_EN_ASSERTS
    )
endif()