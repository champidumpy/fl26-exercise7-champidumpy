cmake_minimum_required(VERSION 3.10)
project(Exercise7)
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(clientcode
clientcode.cpp
treap.cpp
treap.h
)
add_executable(unit_test
unit_test.cpp
treap.cpp
treap.h
)