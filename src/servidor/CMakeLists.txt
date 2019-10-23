cmake_minimum_required(VERSION 3.13.4)

project(Servidor)

set(SOURCES
  ${PROJECT_SOURCE_DIR}/modelo/MiClase.cpp
  ${PROJECT_SOURCE_DIR}/modelo/Rueda.cpp
)

include_directories(${CMAKE_SOURCE_DIR})
add_library(${PROJECT_NAME} STATIC ${SOURCES})