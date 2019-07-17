cmake_minimum_required(VERSION 3.10)
project(BrushProblem)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_BUILD_TYPE Debug)

add_executable(BrushProblem main.cpp)

add_subdirectory(leetcode)
add_subdirectory(nowcoder)
add_subdirectory(template)
add_subdirectory(CCF)
add_subdirectory(openjudge)
add_subdirectory(collects)