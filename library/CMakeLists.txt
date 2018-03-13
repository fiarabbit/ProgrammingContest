cmake_minimum_required(VERSION 3.9)
project(library)

set(CMAKE_CXX_STANDARD 14)

add_library(library SimpleDirectedGraph.cpp SimpleDirectedGraph.h)