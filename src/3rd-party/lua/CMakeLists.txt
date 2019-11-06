cmake_minimum_required(VERSION 3.1)

project(lua)

set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -O3 -std=c++11")


set(SOURCES ${CMAKE_CURRENT_SOURCE_DIR}/lua/main.cpp /home/micromachines/includes/3rd-party/Lua/sol-master/sol.hpp)

add_executable(${PROJECT_NAME} ${SOURCES})


target_include_directories(${PROJECT_NAME} PRIVATE $ENV{HOME}/micromachines/includes/3rd-party/Lua/lua-5.3.3)


target_compile_features(${PROJECT_NAME} PUBLIC cxx_std_11)


