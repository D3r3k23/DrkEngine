if (${CMAKE_BUILD_TYPE} == Debug)
    target_compile_definitions(DrkEngine
      PRIVATE
        EN_LOGGING
        EN_ASSERT)
endif()
    
add_library(DrkEngine)
add_subdirectory(src)
