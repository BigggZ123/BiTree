cmake_minimum_required(VERSION 3.26)
project(BiTree)

set(CMAKE_CXX_STANDARD 17)

add_executable(BiTree main.cpp
        NodeIter.h
        BiTree.h
        CompleteTree.h
        iBiTree.h
        BinarySearchTree.h
        BiTreeContainer.h
)
