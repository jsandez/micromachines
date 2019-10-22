cmake_minimum_required(VERSION 3.13.4)

project(Micromachines)

# seteo de flags
#set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -O3 -std=c++11 -Wall -Werror -pedantic -pthread")

include_directories(includes/servidor)

add_subdirectory(src)
