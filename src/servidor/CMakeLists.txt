cmake_minimum_required(VERSION 3.10.2)

project(ServidorCMake)

set(SOURCES
  ${PROJECT_SOURCE_DIR}/utils/ConfigServidor.cpp
  ${PROJECT_SOURCE_DIR}/Servidor.cpp
  ${PROJECT_SOURCE_DIR}/HiloAceptador.cpp
  ${PROJECT_SOURCE_DIR}/red/SocketTCPServidor.cpp
  ${PROJECT_SOURCE_DIR}/red/SalaDeEspera.cpp
  ${PROJECT_SOURCE_DIR}/red/Jugador.cpp
  
  ${CMAKE_SOURCE_DIR}/src/common/Hilo.cpp
  ${CMAKE_SOURCE_DIR}/src/common/red/SocketTCP.cpp
)

include_directories(${CMAKE_SOURCE_DIR})
add_library(${PROJECT_NAME} STATIC ${SOURCES})
