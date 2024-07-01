cmake_minimum_required(VERSION 3.27)
project(DSA_samples)

set(CMAKE_CXX_STANDARD 17)

add_executable(DSA_samples main.cpp
        header.h
        Data_Structures/myVector.h
        Data_Structures/myLinkedList.h
        Data_Structures/interfaces.h
        Data_Structures/myLinkedListTwo.h
        Data_Structures/myStack.h
        Data_Structures/myQueue.h
        Data_Structures/myPriorityQueue.h
        Data_Structures/myBinaryTree.h
)
