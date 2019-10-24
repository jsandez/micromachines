cmake_minimum_required(VERSION 3.10.2)

project(ServidorCMake)

set(SOURCES
  ${CMAKE_SOURCE_DIR}/src/servidor/utils/ConfigServidor.cpp
  ${PROJECT_SOURCE_DIR}/Servidor.cpp
)

include_directories(${CMAKE_SOURCE_DIR})
add_library(${PROJECT_NAME} STATIC ${SOURCES})
