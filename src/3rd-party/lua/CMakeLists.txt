cmake_minimum_required(VERSION 2.6)
project(lua_interprete)

find_package(Lua REQUIRED)

message("Variables:\n")
message("LUA_FOUND: ${LUA_FOUND}")
message("LUA_LIBRARIES: ${LUA_INCLUDE_DIR}")
message("LUA_INCLUDE_DIR: ${LUA_INCLUDE_DIR}")
message("LUA_VERSION_STRING: ${LUA_VERSION_STRING}")
message("LUA_VERSION_MAJOR: ${LUA_VERSION_MAJOR}")
message("LUA_VERSION_MINOR: ${LUA_VERSION_MINOR}")
message("LUA_VERSION_PATCH: ${LUA_VERSION_PATCH}")

include_directories(${LUA_INCLUDE_DIR})

set(SOURCES
  ${PROJECT_SOURCE_DIR}/lua/lua/LuaInterprete.cpp
}

add_library(${PROJECT_NAME} STATIC ${SOURCES})

target_compile_features(${PROJECT_NAME} PUBLIC cxx_std_11)

install(DIRECTORY ${CMAKE_SOURCE_DIR}/includes/3rd-party/lua/lua_scripts DESTINATION ${CMAKE_BINARY_DIR})
