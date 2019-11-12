cmake_minimum_required(VERSION 3.10.2)

project(ClienteCMake)

set(SOURCES
  ${PROJECT_SOURCE_DIR}/utils/ConfigCliente.cpp
  ${PROJECT_SOURCE_DIR}/red/SocketTCPCliente.cpp
  ${PROJECT_SOURCE_DIR}/excepciones/SDLException.cpp
  
  ${PROJECT_SOURCE_DIR}/Cliente.cpp
  ${PROJECT_SOURCE_DIR}/HiloDibujador.cpp
  ${PROJECT_SOURCE_DIR}/GUI/eventos/EventoGUIClick.cpp
  ${PROJECT_SOURCE_DIR}/GUI/eventos/EventoGUIKeyDown.cpp
  ${PROJECT_SOURCE_DIR}/GUI/Area.cpp
  ${PROJECT_SOURCE_DIR}/GUI/Renderizador.cpp
  ${PROJECT_SOURCE_DIR}/GUI/Textura.cpp
  ${PROJECT_SOURCE_DIR}/GUI/Animacion.cpp
  ${PROJECT_SOURCE_DIR}/GUI/AnimacionFactory.cpp
  ${PROJECT_SOURCE_DIR}/GUI/Ventana.cpp
  ${PROJECT_SOURCE_DIR}/GUI/escenas/Escena.cpp
  ${PROJECT_SOURCE_DIR}/GUI/escenas/EscenaMenu.cpp
  ${PROJECT_SOURCE_DIR}/GUI/escenas/EscenaSala.cpp

  ${CMAKE_SOURCE_DIR}/src/common/Hilo.cpp
  ${CMAKE_SOURCE_DIR}/src/common/RecibidorEventos.cpp
  ${CMAKE_SOURCE_DIR}/src/common/EnviadorEventos.cpp
  ${CMAKE_SOURCE_DIR}/src/common/eventos/Evento.cpp
  ${CMAKE_SOURCE_DIR}/src/common/eventos/EventoCrearPartida.cpp
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
add_library(${PROJECT_NAME} STATIC ${SOURCES})
target_link_libraries(ClienteCMake)
