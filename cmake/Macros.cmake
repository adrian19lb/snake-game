include(CMakeParseArguments)

macro(snake_add_library target)
    cmake_parse_arguments(THIS "STATIC" "" "SOURCES" ${ARGN})
    
    if(NOT "${THIS_UNPARSED_ARGUMENTS}" STREQUAL "")
        message(FATAL_ERROR "Extra unparsed arguments when calling snake_add_library: ${THIS_UNPARSED_ARGUMENTS}")
    endif()

    if(THIS_STATIC)
        add_library(${target} STATIC ${SOURCES})
    else()
        add_library(${target} STATIC ${SOURCES})
    endif()


    set_target_properties(${target} 
        PROPERTIES LINKER_LANGUAGE CXX
        VERSION ${PROJECT_VERSION}
        SOVERSION ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    )

    target_include_directories(${target}
        PUBLIC $<BUILD_INTERFACE:${PROJECT_SOURCE_DIR}/include>
               $<INSTALL_INTERFACE:include/snake>
        PRIVATE ${PROJECT_SOURCE_DIR}/src)

    target_compile_features(${target} PUBLIC cxx_std_17)
    
    install(TARGETS ${target} EXPORT "SnakeConfig"
        ARCHIVE  DESTINATION ${CMAKE_INSTALL_LIBDIR}
        LIBRARY  DESTINATION ${CMAKE_INSTALL_LIBDIR}
        RUNTIME  DESTINATION ${CMAKE_INSTALL_BINDIR}
    )
    
    install(DIRECTORY ${PROJECT_SOURCE_DIR}/include DESTINATION ${CMAKE_INSTALL_INCLUDEDIR})

endmacro()
