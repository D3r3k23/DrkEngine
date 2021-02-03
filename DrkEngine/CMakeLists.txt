if(${CMAKE_BUILD_TYPE} == Debug)
    target_compile_definitions(DrkEngine
      PRIVATE
        DRK_EN_LOGGING
        DRK_EN_ASSERTS
    )
endif()
    
add_library(DrkEngine)
add_subdirectory(src)
