cmake_minimum_required(VERSION 3.10.2)

project(Micromachines)

# seteo de flags compartidos por todos los subproyectos
set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -O3 -std=c++11 -pthread")

include_directories(includes/servidor)

add_subdirectory(src)
