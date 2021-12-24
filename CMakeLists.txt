cmake_minimum_required(VERSION 3.21)
project(task7)

set(CMAKE_CXX_STANDARD 14)
add_library(Utils AndrewContainerUtils.cpp AndrewContainerUtils.h)
add_library(HashTable HashTable.cpp HashTable.h HashTableTest.cpp)
add_library(BinaryTree BinaryTree.cpp BinaryTree.h BinaryTreeTest.cpp)

add_executable(task7 main.cpp)
target_link_libraries(HashTable Utils)
target_link_libraries(BinaryTree Utils)
target_link_libraries(task7 BinaryTree HashTable Utils)
