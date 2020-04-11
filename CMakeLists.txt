cmake_minimum_required(VERSION 3.15)
project(ancestor_tree)

set(CMAKE_CXX_STANDARD 14)

add_executable(ancestor_tree main.cpp Demo.cpp TestCounter.cpp doctest.h FamilyTree.cpp FamilyTree.hpp Test.cpp)