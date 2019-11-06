cmake_minimum_required(VERSION 3.10.2)

# Subdirectorios 3rd-party que se compilan sin flags
#add_subdirectory(SDL2)
add_subdirectory(3rd-party/Box2D)

# Subdirectorios propios
set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Werror -pedantic")

include_directories(${CMAKE_SOURCE_DIR})
include_directories(${CMAKE_SOURCE_DIR}/includes/3rd-party)

add_subdirectory(servidor)
add_subdirectory(cliente)

add_executable(Servidor servidor/main_servidor.cpp)
target_link_libraries(Servidor ServidorCMake Box2D lua5.3)

add_executable(Cliente cliente/mainMicromachines.cpp)
target_link_libraries(Cliente ClienteCMake SDL2 SDL2_image lua5.3)

INSTALL(TARGETS Servidor DESTINATION ${RUTA_INSTALACION})
INSTALL(TARGETS Cliente DESTINATION ${RUTA_INSTALACION})