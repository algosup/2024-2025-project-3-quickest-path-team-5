# How to use with mingw: (Windows)
#   cmake -S . -B build -G "MinGW Makefiles"
#   cd build
#   mingw32-make

# How to use with clang: (Linux and MacOS)
#   cmake -S . -B build
#   cd build
#   make

cmake_minimum_required(VERSION 3.30)

set(CMAKE_CXX_COMPILER "clang++")

project(
  CAP
  VERSION 0.1
  LANGUAGES CXX
)

find_package(Threads REQUIRED)

add_executable(tests
  src/data_struct/graph.cpp
  src/data_struct/node.cpp
  src/data_struct/edge.cpp
  test/test.cc
  ../googletest/googletest/src/gtest-all.cc
)

target_include_directories(tests
  PRIVATE
    "${CMAKE_CURRENT_SOURCE_DIR}/src/data_struct"
    "${CMAKE_CURRENT_SOURCE_DIR}/../googletest/googletest/include"
    "${CMAKE_CURRENT_SOURCE_DIR}/../googletest/googletest"
    "${CMAKE_CURRENT_SOURCE_DIR}/test"
)

target_link_libraries(tests
  PRIVATE
    Threads::Threads
)

target_compile_options(tests
  PRIVATE
    -Wall -Wextra -pedantic -g -O2
)

set_target_properties(tests
  PROPERTIES
    CXX_STANDARD 17
    CXX_EXTENSIONS OFF
    RUNTIME_OUTPUT_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/bin"
)

add_executable(cap
    src/cap.cpp
    src/io/csv_reader.cpp
    src/data_struct/graph.cpp
    src/data_struct/node.cpp
    src/data_struct/edge.cpp
)

target_include_directories(cap
  PRIVATE
    "${CMAKE_CURRENT_SOURCE_DIR}/src"
    "${CMAKE_CURRENT_SOURCE_DIR}/src/io"
    "${CMAKE_CURRENT_SOURCE_DIR}/src/data_struct"
)

target_link_libraries(cap
  PRIVATE
    Threads::Threads
)

target_compile_options(cap
  PRIVATE
    -Wall -Wextra -pedantic -g -O2
)

set_target_properties(cap
  PROPERTIES
  CXX_STANDARD 17
  CXX_EXTENSIONS OFF
  RUNTIME_OUTPUT_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/bin"
)