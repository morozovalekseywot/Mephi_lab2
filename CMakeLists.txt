cmake_minimum_required(VERSION 3.17)
project(Cstring)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_FLAGS_RELEASE "-Ox")

add_executable(Cstring main.cpp Cstring.hpp Linked_List.hpp Dynamic_array.hpp Linked_List.cpp Dynamic_array.cpp
         Array_Sequence.hpp Cstring.hpp Linked_List_Sequence.hpp)