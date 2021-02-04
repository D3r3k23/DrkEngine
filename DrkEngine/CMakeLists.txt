add_library(DrkEngine STATIC)

target_include_directories(DrkEngine PUBLIC inc)
add_subdirectory(src)

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