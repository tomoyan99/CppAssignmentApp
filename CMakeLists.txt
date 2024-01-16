cmake_minimum_required(VERSION 3.25)
project(CppAssignmentApp)

set(CMAKE_CXX_STANDARD 14)
set(EXECUTABLE_OUTPUT_PATH ../dist)

add_subdirectory(lib)
add_subdirectory(src)