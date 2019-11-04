cmake_minimum_required(VERSION 3.10.2)
project (ffmepg)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -D__STDC_CONSTANT_MACROS")
set(CMAKE_CXX_LINK_FLAGS "-lavutil -lavformat -lavcodec -lz -lswscale -lswresample -lm")

#Include folders
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
include_directories(${CMAKE_BINARY_DIR})

link_directories(${FFMPEG_DIRS})


#Here we add our source files
set (SOURCES
 ${PROJECT_SOURCE_DIR}/example/Area.cpp
  ${PROJECT_SOURCE_DIR}/example/SdlException.cpp
   ${PROJECT_SOURCE_DIR}/example/SdlTexture.cpp
    ${PROJECT_SOURCE_DIR}/example/SdlWindow.cpp
 ${PROJECT_SOURCE_DIR}/common/output_stream.cpp
 ${PROJECT_SOURCE_DIR}/common/codec.cpp
 ${PROJECT_SOURCE_DIR}/common/frame.cpp
 ${PROJECT_SOURCE_DIR}/common/output_format.cpp
 ${PROJECT_SOURCE_DIR}/video/output_video.cpp
 ${PROJECT_SOURCE_DIR}/video/video_codec.cpp
 )

set (FFMPEG_LIBRARIES
  libavcodec
  libavformat
  libavutil
  libavswresample
  libswscale
 )


add_library(${PROJECT_NAME} STATIC ${SOURCES})

target_compile_features(${PROJECT_NAME} PUBLIC cxx_std_11)

add_executable(example ${SOURCES})

target_link_libraries(example libffmepg.a)
