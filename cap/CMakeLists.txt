# How to use with mingw: (Windows)
#   cmake -S . -B build -G "MinGW Makefiles"
#   cd build
#   mingw32-make

# How to use with clang: (Linux and MacOS)
#   cmake -S . -B build
#   cd build
#   make

# Minimum CMake version
cmake_minimum_required(VERSION 3.10)
cmake_policy(SET CMP0167 OLD)

# Project name and version
project(
    CAP
    VERSION 0.1
    LANGUAGES CXX
)

# Specify the C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

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

# Create the main executable for the server
add_executable(server ${SERVER_SOURCES})

# Link libraries to the server executable
target_link_libraries(server ${Boost_LIBRARIES} jsoncpp)

# Google Test configuration
# Download and install Google Test if not available
include(FetchContent)
FetchContent_Declare(
    googletest
    URL https://github.com/google/googletest/archive/refs/heads/main.zip
    DOWNLOAD_EXTRACT_TIMESTAMP true # Explicitly set the extraction timestamp behavior
)
# Prevent Google Test from overriding our compiler/linker options
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)
