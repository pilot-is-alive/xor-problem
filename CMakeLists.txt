cmake_minimum_required(VERSION 3.15)

project(XorProblem VERSION 0.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(xor src/main.cpp)

target_include_directories(xor PRIVATE include)