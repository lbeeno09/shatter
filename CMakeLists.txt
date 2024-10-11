cmake_minimum_required(VERSION 3.10)

# Project name
project(cpp_lib_template VERSION 1.0)

# C++ Standard
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)

add_subdirectory(src)

enable_testing()
add_subdirectory(test)