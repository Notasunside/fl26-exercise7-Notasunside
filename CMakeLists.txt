cmake_minimum_required(VERSION 3.10)

project(treap_exercise)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(clientcode clientcode.cpp treap.cpp)
add_executable(unit_test unit_test.cpp treap.cpp)