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
  ${CMAKE_SOURCE_DIR}/src/common/RecibidorEventos.cpp
  ${CMAKE_SOURCE_DIR}/src/common/EnviadorEventos.cpp
  ${CMAKE_SOURCE_DIR}/src/common/eventos/Evento.cpp
  ${CMAKE_SOURCE_DIR}/src/common/eventos/EventoCrearPartida.cpp
  ${CMAKE_SOURCE_DIR}/src/common/eventos/EventoDesconexion.cpp
  ${CMAKE_SOURCE_DIR}/src/common/eventos/EventoAcelerar.cpp
  ${CMAKE_SOURCE_DIR}/src/common/eventos/EventoFactory.cpp
  ${CMAKE_SOURCE_DIR}/src/common/red/SocketTCP.cpp
  ${CMAKE_SOURCE_DIR}/src/common/red/Protocolo.cpp
  ${CMAKE_SOURCE_DIR}/src/common/excepciones/EventoDesconocidoError.cpp
)

include_directories(${CMAKE_SOURCE_DIR})
add_library(${PROJECT_NAME} STATIC ${SOURCES})
