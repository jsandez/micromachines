cmake_minimum_required(VERSION 3.10.2)

set(RUTA_INSTALACION "$ENV{HOME}/micromachines" CACHE INTERNAL "")

project(Micromachines)

# seteo de flags compartidos por todos los subproyectos
set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -O3 -std=c++11 -pthread -D__STDC_CONSTANT_MACROS")

include_directories(includes/servidor)

add_subdirectory(src)

INSTALL(DIRECTORY config DESTINATION ${RUTA_INSTALACION})
INSTALL(DIRECTORY assets DESTINATION ${RUTA_INSTALACION})
INSTALL(FILES extras/supresiones_valgrind/minimal.supp DESTINATION ${RUTA_INSTALACION})
