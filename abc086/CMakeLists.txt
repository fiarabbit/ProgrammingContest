cmake_minimum_required(VERSION 3.9)
get_filename_component(dirname ${CMAKE_CURRENT_SOURCE_DIR} NAME)

project(${dirname} CXX)

set(CMAKE_CXX_FLAGS "-std=gnu++1y -O2")
set(BOOST_ROOT "c:\\boost_1_60_0")
set(Boost_USE_MULTITHREADED OFF)
set(Boost_USE_STATIC_LIBS ON)

find_package(Boost)
message(STATUS ${Boost_INCLUDE_DIRS})

include_directories(${Boost_INCLUDE_DIRS})

file(GLOB cpps *.cpp)

foreach(cpp ${cpps})
    get_filename_component(filename ${cpp} NAME)
    string(REPLACE ".cpp" ".out" executable ${filename})
    add_executable(${executable} ${filename})
    message(STATUS ${executable} ${filename})
endforeach(cpp cpps)
