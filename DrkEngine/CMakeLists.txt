if(${CMAKE_BUILD_TYPE} == Debug)
    target_compile_definitions(DrkEngine
      PRIVATE
        DRK_LOG
        DRK_ASSERT
    )
endif()
    
add_library(DrkEngine)
add_subdirectory(src)
