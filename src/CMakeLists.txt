cmake_minimum_required(VERSION 3.13.4)

add_subdirectory(3rd-party/Box2D)
#add_subdirectory(SDL2)
add_executable(main main.cpp)
target_link_libraries(main Box2D)
