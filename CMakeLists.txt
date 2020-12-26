cmake_minimum_required(VERSION 3.17)
project(AutocompleteCPP)

set(CMAKE_CXX_STANDARD 20)

add_executable(AutocompleteCPP main.cpp prefix_trees.cpp autocomplete_engines.cpp support.cpp)