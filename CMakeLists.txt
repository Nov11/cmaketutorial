cmake_minimum_required(VERSION 3.5)
project(cmaketutorial)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp)

# The version number.
set (Tutorial_VERSION_MAJOR 1)
set (Tutorial_VERSION_MINOR 0)
# configure a header file to pass some of the CMake settings
# to the source code
configure_file (
        "${PROJECT_SOURCE_DIR}/TutorialConfig.h.in"
        "${PROJECT_BINARY_DIR}/TutorialConfig.h"
)
# add the binary tree to the search path for include files
# so that we will find TutorialConfig.h
include_directories("${PROJECT_BINARY_DIR}")

# should we use our own math functions?
option (USE_
        "Use custom lib" ON)

if(USE_)
    include_directories ("${PROJECT_SOURCE_DIR}/customlib")
    add_subdirectory (customlib)
    set(LIBS func)
endif(USE_)

add_executable(cmaketutorial ${SOURCE_FILES})
target_link_libraries (cmaketutorial ${LIBS})
enable_testing()
add_test(num1 cmaketutorial  )
set_tests_properties(num1 PROPERTIES
        PASS_REGULAR_EXPRESSION "Hello")