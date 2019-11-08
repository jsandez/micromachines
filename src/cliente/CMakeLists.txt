cmake_minimum_required(VERSION 3.10.2)

project(ClienteCMake)

set(SOURCES
  ${PROJECT_SOURCE_DIR}/utils/ConfigCliente.cpp
  ${PROJECT_SOURCE_DIR}/red/SocketTCPCliente.cpp
  ${PROJECT_SOURCE_DIR}/excepciones/SDLException.cpp
  
  ${PROJECT_SOURCE_DIR}/Cliente.cpp
  ${PROJECT_SOURCE_DIR}/Renderizador.cpp
  ${PROJECT_SOURCE_DIR}/Textura.cpp
  ${PROJECT_SOURCE_DIR}/Ventana.cpp
)

include_directories(${CMAKE_SOURCE_DIR})
add_library(${PROJECT_NAME} STATIC ${SOURCES})
target_link_libraries(ClienteCMake Qt5::Widgets)
