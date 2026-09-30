cmake_minimum_required(VERSION 3.20)

project(CppLab)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(value_categories
    advanced_cpp/01_value_categories/main.cpp
)

add_executable(copy_move
    advanced_cpp/02_copy_move/main.cpp
)

add_executable(rule_of_3_5_0
    advanced_cpp/03_rule_of_3_5_0/main.cpp
)