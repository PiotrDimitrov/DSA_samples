cmake_minimum_required(VERSION 3.27)
project(DSA_samples)

set(CMAKE_CXX_STANDARD 17)

add_executable(DSA_samples main.cpp
        header.h
        Data_Structures/myVector.h
        Data_Structures/myLinkedList.h
)
