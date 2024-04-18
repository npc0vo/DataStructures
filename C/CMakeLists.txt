cmake_minimum_required(VERSION 3.27)
project(C CXX)
set(CMAKE_C_STANDARD 11)



add_executable(5_17 educoderOJ/5_17.cpp)
add_executable(3_9 educoderOJ/3_9.cpp)
add_executable(5_2 educoderOJ/5_2.cpp)
add_executable(C1_1 educoderOJ/C1_1.cpp
        educoderOJ/linearList.h)
add_executable(3_10 educoderOJ/3_10.cpp
        LinkList/SingleLinkList.h)

add_executable(C1_2 educoderOJ/C1_2.cpp
        educoderOJ/slink.h)
add_executable(C1_3 educoderOJ/C1_3.cpp
        educoderOJ/tree.h)
add_executable(C2_1 educoderOJ/C2_1.cpp)
add_executable(HelloWorld HelloWorld.cpp)
add_executable(SingleLinkList LinkList/SingleLinkList.cpp
        LinkList/SingleLinkList.h)
add_executable(DoubleLinkedList LinkList/DoubleLinkedList.cpp
        LinkList/DoubleLinkedList.h)
add_executable(CircularLinkedList LinkList/CircularLinkedList.cpp
        LinkList/CircularLinkedList.h)
add_executable(stack Stack/LinkedStack.cpp Stack/LinkedStack.h
        Stack/ArrayStack.h)
add_executable(sequentialQueue queue/sequentialQueue.cpp
        queue/sequentialQueue.h)