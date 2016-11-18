cmake_minimum_required(VERSION 3.6)
project(DatabaseAssignment)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp RingBuffer.h DLinkedList.h Stack.h Sequence.h Student.cpp Student.h Faculty.cpp Faculty.h json.hpp PeopleSerializable.cpp PeopleSerializable.h DatabaseController.cpp DatabaseController.h BST.h BinarySearchTree.h KeyValuePair.cpp KeyValuePair.h)
add_executable(DatabaseAssignment ${SOURCE_FILES})