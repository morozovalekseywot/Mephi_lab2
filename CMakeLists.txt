cmake_minimum_required(VERSION 3.17)
project(Cstring)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_FLAGS_RELEASE "-Ox")

add_executable(Cstring main.cpp Cstring.hpp Cstring.cpp Linked_List.hpp Dynamic_array.h Linked_List.cpp)