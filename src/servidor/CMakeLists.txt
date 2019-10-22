cmake_minimum_required(VERSION 3.13.4)

project(Servidor)

set(SOURCES
  ${PROJECT_SOURCE_DIR}/src/MiClase.cpp
)

include_directories(${CMAKE_SOURCE_DIR}/includes/servidor)
add_library(${PROJECT_NAME} STATIC ${SOURCES})