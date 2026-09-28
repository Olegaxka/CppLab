cmake_minimum_required(VERSION 3.20)

project(CppLab)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(copy_move
    advanced_cpp/02_copy_move/main.cpp
)