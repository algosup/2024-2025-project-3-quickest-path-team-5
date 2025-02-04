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
  VERSION 0.2
  LANGUAGES CXX
)

find_package(Threads REQUIRED)

add_executable(tests
  src/data_struct/graph.cpp
  src/data_struct/node.cpp
  src/data_struct/edge.cpp
  src/api/api.cpp
  test/test.cc
  ../googletest/googletest/src/gtest-all.cc
)

target_include_directories(tests
  PRIVATE
    "${CMAKE_CURRENT_SOURCE_DIR}/src/data_struct"
    "${CMAKE_CURRENT_SOURCE_DIR}/src/api"
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
  -Wall -Wextra -pedantic -g -Ofast -ffast-math
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
    src/api/api.cpp
)

target_include_directories(cap
  PRIVATE
    "${CMAKE_CURRENT_SOURCE_DIR}/src"
    "${CMAKE_CURRENT_SOURCE_DIR}/src/io"
    "${CMAKE_CURRENT_SOURCE_DIR}/src/api"
    "${CMAKE_CURRENT_SOURCE_DIR}/src/data_struct"
)

target_link_libraries(cap
  PRIVATE
    Threads::Threads
)

target_compile_options(cap
  PRIVATE
  -Wall -Wextra -pedantic -g -O3
)

set_target_properties(cap
  PROPERTIES
  CXX_STANDARD 17
  CXX_EXTENSIONS OFF
  RUNTIME_OUTPUT_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/bin"
)

# Add Boost and JSONCPP (dependencies for Crow)
find_package(Boost REQUIRED)
find_package(PkgConfig REQUIRED)
pkg_check_modules(JSONCPP REQUIRED jsoncpp)

# Include directories
include_directories(${Boost_INCLUDE_DIRS} ${JSONCPP_INCLUDE_DIRS} include)

# Add library search path for jsoncpp (if necessary)
link_directories(/opt/homebrew/lib)

# Source files for the API
set(SERVER_SOURCES
    src/api/api.cpp
    src/cap.cpp
)
