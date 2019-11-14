cmake_minimum_required(VERSION 3.10.2)

project(ServidorCMake)

set(SOURCES
  ${PROJECT_SOURCE_DIR}/utils/ConfigServidor.cpp
  ${PROJECT_SOURCE_DIR}/red/SocketTCPServidor.cpp

  ${PROJECT_SOURCE_DIR}/Servidor.cpp
  ${PROJECT_SOURCE_DIR}/HiloAceptador.cpp
  ${PROJECT_SOURCE_DIR}/DistribuidorEventos.cpp  
  ${PROJECT_SOURCE_DIR}/SalaDeEspera.cpp
  ${PROJECT_SOURCE_DIR}/CoordinadorPartidas.cpp
  ${PROJECT_SOURCE_DIR}/Partida.cpp
  ${PROJECT_SOURCE_DIR}/Jugador.cpp
  ${PROJECT_SOURCE_DIR}/modelo/Mundo.cpp
  ${PROJECT_SOURCE_DIR}/modelo/Identificable.cpp
  ${PROJECT_SOURCE_DIR}/modelo/superficies/Superficie.cpp
  ${PROJECT_SOURCE_DIR}/modelo/entidades/Vehiculo.cpp
  ${PROJECT_SOURCE_DIR}/modelo/superficies/NoSuperficie.cpp
  ${PROJECT_SOURCE_DIR}/modelo/superficies/SuperficieArena.cpp
  ${PROJECT_SOURCE_DIR}/modelo/superficies/SuperficiePista.cpp
  ${PROJECT_SOURCE_DIR}/modelo/superficies/SuperficieTierra.cpp
  ${PROJECT_SOURCE_DIR}/modelo/superficies/SuperficieFactory.cpp
  ${PROJECT_SOURCE_DIR}/modelo/fisicas/Fisicas.cpp
  ${PROJECT_SOURCE_DIR}/modelo/movimiento/Posicion.cpp
  
  ${CMAKE_SOURCE_DIR}/src/common/Hilo.cpp
  ${CMAKE_SOURCE_DIR}/src/common/Conversor.cpp
  ${CMAKE_SOURCE_DIR}/src/common/Cronometro.cpp
  ${CMAKE_SOURCE_DIR}/src/common/Handler.cpp
  ${CMAKE_SOURCE_DIR}/src/common/RecibidorEventos.cpp
  ${CMAKE_SOURCE_DIR}/src/common/EnviadorEventos.cpp
  ${CMAKE_SOURCE_DIR}/src/common/Tile.cpp
  ${CMAKE_SOURCE_DIR}/src/common/eventos/Evento.cpp
  ${CMAKE_SOURCE_DIR}/src/common/eventos/EventoCrearPartida.cpp
  ${CMAKE_SOURCE_DIR}/src/common/eventos/EventoIDJugador.cpp
  ${CMAKE_SOURCE_DIR}/src/common/eventos/EventoPartidaAgregada.cpp
  ${CMAKE_SOURCE_DIR}/src/common/eventos/EventoUnirseAPartida.cpp
  ${CMAKE_SOURCE_DIR}/src/common/eventos/EventoIniciarPartida.cpp
  ${CMAKE_SOURCE_DIR}/src/common/eventos/EventoDesconexion.cpp
  ${CMAKE_SOURCE_DIR}/src/common/eventos/EventoAcelerar.cpp
  ${CMAKE_SOURCE_DIR}/src/common/eventos/EventoFactory.cpp
  ${CMAKE_SOURCE_DIR}/src/common/red/SocketTCP.cpp
  ${CMAKE_SOURCE_DIR}/src/common/red/Protocolo.cpp
  ${CMAKE_SOURCE_DIR}/src/common/excepciones/EventoDesconocidoError.cpp
)

include_directories(${CMAKE_SOURCE_DIR})
include_directories(${CMAKE_SOURCE_DIR}/includes/3rd-party)
add_library(${PROJECT_NAME} STATIC ${SOURCES})
