# Minimum CMake version
cmake_minimum_required(VERSION 3.10)
cmake_policy(SET CMP0167 OLD)

# Project name and version
project(RestAPI VERSION 1.0)

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
set(SOURCES
    src/api/api.cpp
    src/cap.cpp
)

# Create the main executable
add_executable(server ${SOURCES})

# Link libraries to the executable
target_link_libraries(server ${Boost_LIBRARIES} jsoncpp)