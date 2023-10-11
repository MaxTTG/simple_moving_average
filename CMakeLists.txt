cmake_minimum_required(VERSION 3.26)
project(sma_test_task)

set(CMAKE_CXX_STANDARD 23)

set(SOURCE_FILES main.cpp)
add_executable(sma_test_task ${SOURCE_FILES})

add_subdirectory(smalib)
include_directories(smalib)

target_link_libraries(sma_test_task smalib_lib)
