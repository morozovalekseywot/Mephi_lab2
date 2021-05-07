cmake_minimum_required(VERSION 3.17)
project(Cstring)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_FLAGS_RELEASE "-O3")

add_executable(Cstring main.cpp Sequence.hpp Linked_List.hpp Dynamic_array.hpp
        Array_Sequence.hpp Sequence.hpp Linked_List_Sequence.hpp Cstring.hpp)