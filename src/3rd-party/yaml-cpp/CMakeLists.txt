cmake_minimum_required(VERSION 3.10.2)

project (yaml-cpp)

set(SOURCES
  ${PROJECT_SOURCE_DIR}/yaml-cpp/binary.cpp
  ${PROJECT_SOURCE_DIR}/yaml-cpp/convert.cpp
  ${PROJECT_SOURCE_DIR}/yaml-cpp/directives.cpp
  ${PROJECT_SOURCE_DIR}/yaml-cpp/emit.cpp
  ${PROJECT_SOURCE_DIR}/yaml-cpp/emitfromevents.cpp
  ${PROJECT_SOURCE_DIR}/yaml-cpp/emitter.cpp
  ${PROJECT_SOURCE_DIR}/yaml-cpp/emitterstate.cpp
  ${PROJECT_SOURCE_DIR}/yaml-cpp/emitterutils.cpp
  ${PROJECT_SOURCE_DIR}/yaml-cpp/exceptions.cpp
  ${PROJECT_SOURCE_DIR}/yaml-cpp/exp.cpp
  ${PROJECT_SOURCE_DIR}/yaml-cpp/memory.cpp
  ${PROJECT_SOURCE_DIR}/yaml-cpp/node.cpp
  ${PROJECT_SOURCE_DIR}/yaml-cpp/nodebuilder.cpp
  ${PROJECT_SOURCE_DIR}/yaml-cpp/node_data.cpp
  ${PROJECT_SOURCE_DIR}/yaml-cpp/nodeevents.cpp
  ${PROJECT_SOURCE_DIR}/yaml-cpp/null.cpp
  ${PROJECT_SOURCE_DIR}/yaml-cpp/ostream_wrapper.cpp
  ${PROJECT_SOURCE_DIR}/yaml-cpp/parse.cpp
  ${PROJECT_SOURCE_DIR}/yaml-cpp/parser.cpp
  ${PROJECT_SOURCE_DIR}/yaml-cpp/regex_yaml.cpp
  ${PROJECT_SOURCE_DIR}/yaml-cpp/scanner.cpp
  ${PROJECT_SOURCE_DIR}/yaml-cpp/scanscalar.cpp
  ${PROJECT_SOURCE_DIR}/yaml-cpp/scantag.cpp
  ${PROJECT_SOURCE_DIR}/yaml-cpp/scantoken.cpp
  ${PROJECT_SOURCE_DIR}/yaml-cpp/simplekey.cpp
  ${PROJECT_SOURCE_DIR}/yaml-cpp/singledocparser.cpp
  ${PROJECT_SOURCE_DIR}/yaml-cpp/stream.cpp
  ${PROJECT_SOURCE_DIR}/yaml-cpp/tag.cpp
)

include_directories(${CMAKE_SOURCE_DIR}/includes/3rd-party/yaml-cpp)
add_library(${PROJECT_NAME} STATIC ${SOURCES})
target_compile_features(${PROJECT_NAME} PUBLIC cxx_std_11)
