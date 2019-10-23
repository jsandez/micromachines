cmake_minimum_required(VERSION 3.10.2)

# Subdirectorios 3rd-party que se compilan sin flags
#add_subdirectory(SDL2)
add_subdirectory(3rd-party/Box2D)

# Subdirectorios propios
set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Werror -pedantic")

include_directories(${CMAKE_SOURCE_DIR})
add_subdirectory(servidor)

add_executable(main main.cpp)
target_link_libraries(main Box2D Servidor)
