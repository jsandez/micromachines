cmake_minimum_required(VERSION 3.10.2)

# Subdirectorios 3rd-party que se compilan sin flags
add_subdirectory(3rd-party/Box2D)
#add_subdirectory(3rd-party/lua)


# Subdirectorios propios
set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Werror -pedantic")

include_directories(${CMAKE_SOURCE_DIR})
include_directories(${CMAKE_SOURCE_DIR}/includes/3rd-party)

add_subdirectory(servidor)
add_subdirectory(cliente)

add_executable(Servidor servidor/main_servidor.cpp)
target_link_libraries(Servidor ServidorCMake Box2D)

add_executable(Cliente cliente/main_cliente.cpp)

#Para FFMPEG
include_directories(${PROJECT_SOURCE_DIR})
set (FFMPEG_DIRS
        $ENV{FFMPEG_DIR}
        $ENV{FFMPEG_DIR}/libavcodec
        $ENV{FFMPEG_DIR}/libavdevice
        $ENV{FFMPEG_DIR}/libavfilter
        $ENV{FFMPEG_DIR}/libavformat
        $ENV{FFMPEG_DIR}/libavutil
        $ENV{FFMPEG_DIR}/libavswresample
        $ENV{FFMPEG_DIR}/libswscale
        )

include_directories(${FFMPEG_DIRS})
#include_directories(${CMAKE_BINARY_DIR})
link_directories(${FFMPEG_DIRS})

set (FFMPEG_LIBRARIES
    libavcodec
    libavformat
    libavutil
    libavswresample
    libswscale
)

target_link_libraries(Cliente ClienteCMake SDL2 SDL2_image SDL2_mixer SDL2_ttf lua5.3 avutil avformat avcodec swscale swresample)
# ¿-lz -lm ?????

INSTALL(TARGETS Servidor DESTINATION ${RUTA_INSTALACION})
INSTALL(TARGETS Cliente DESTINATION ${RUTA_INSTALACION})
