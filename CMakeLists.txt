cmake_minimum_required(VERSION 3.10)
project(task7)

set(CMAKE_CXX_STANDARD 14)
add_library(Utils AndrewContainerUtils.cpp AndrewContainerUtils.h)
add_library(HashTable HashTable.cpp HashTable.h HashTableTest.cpp)
add_library(BinaryTree BinaryTree.cpp BinaryTree.h BinaryTreeTest.cpp)

FILE(COPY ${CMAKE_CURRENT_SOURCE_DIR}/input.txt
        DESTINATION ${CMAKE_CURRENT_BINARY_DIR})

add_executable(task7 main.cpp)
add_executable(testDataStructures test.cpp)
target_link_libraries(HashTable Utils)
target_link_libraries(BinaryTree Utils)
target_link_libraries(task7 BinaryTree HashTable Utils)
target_link_libraries(testDataStructures BinaryTree HashTable Utils)

