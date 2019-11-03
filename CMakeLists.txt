cmake_minimum_required(VERSION 3.8)

include(GNUInstallDirs)

project(ssnake
        VERSION 1.0.0
        DESCRIPTION "Snake game"
        LANGUAGES CXX 
)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

add_subdirectory(src)

#Add unit tests to build
option(PACKAGE_TESTS "Build the tests" ON)
if (PACKAGE_TESTS)
    enable_testing()
    add_subdirectory(tests)
endif()

