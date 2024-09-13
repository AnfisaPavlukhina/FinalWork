cmake_minimum_required(VERSION 3.4)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

project(mainfile)
option(BUILD_MAIN "Build main.cpp" OFF)
option(BUILD_TESTS "Build tests" OFF)
include_directories(${CMAKE_CURRENT_SOURCE_DIR})
add_library(function STATIC ${CMAKE_CURRENT_SOURCE_DIR}/function.cpp)

if (BUILD_MAIN)
    add_executable(main ${CMAKE_CURRENT_SOURCE_DIR}/task.cpp)
    target_link_libraries(main function)
    install(TARGETS main RUNTIME DESTINATION bin)
endif()

if (BUILD_TESTS)
    enable_testing()
    add_executable(testing ${CMAKE_CURRENT_SOURCE_DIR}/tests/test_all.cpp)
    target_link_libraries(testing gtest_main gtest function)
    include(GoogleTest)
    gtest_discover_tests(testing)
endif()
