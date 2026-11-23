cmake_minimum_required(VERSION 3.16)
project(lab2_variant5 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fsanitize=address -g")

add_library(string_lib src/string.cpp)
target_include_directories(string_lib PUBLIC include)

add_executable(lab2_main src/main.cpp)
target_link_libraries(lab2_main PRIVATE string_lib)

include(FetchContent)
FetchContent_Declare(
    googletest
    URL https://github.com/google/googletest/archive/refs/tags/v1.14.0.zip
    DOWNLOAD_EXTRACT_TIMESTAMP TRUE
)
FetchContent_MakeAvailable(googletest)

add_executable(lab2_tests tests/test.cpp)
target_link_libraries(lab2_tests PRIVATE string_lib gtest_main)
