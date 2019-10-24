cmake_minimum_required(VERSION 3.10.2)

# Subdirectorios 3rd-party que se compilan sin flags
#add_subdirectory(SDL2)
add_subdirectory(3rd-party/Box2D)
add_subdirectory(3rd-party/yaml-cpp)

# Subdirectorios propios
set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Werror -pedantic")

include_directories(${CMAKE_SOURCE_DIR})
add_subdirectory(servidor)

add_executable(Servidor servidor/main_servidor.cpp)
target_link_libraries(Servidor ServidorCMake Box2D yaml-cpp)

INSTALL(TARGETS Servidor DESTINATION ${RUTA_INSTALACION})