cmake_minimum_required (VERSION 3.6)

project (warctic)

set (CMAKE_BINARY_DIR "./build")
set (EXECUTABLE_OUTPUT_PATH "${CMAKE_BINARY_DIR}")

set (CMAKE_CXX_STANDARD 11)

add_custom_target (resource COMMAND "./resource.sh")

set (VERSION_MAJOR 0)
set (VERSION_MINOR 1)
set (VERSION_BUILD 1)
add_definitions(-DUNSTABLE)

if (CMAKE_HOST_UNIX AND NOT CMAKE_HOST_APPLE)
add_definitions(-DLIN)
endif ()

if (CMAKE_HOST_WIN32)
add_definitions(-DWIN)
endif ()

if (CMAKE_HOST_APPLE)
add_definitions(-DMAC)
endif ()

if(CMAKE_SIZEOF_VOID_P EQUAL 8)
add_definitions(-DX64)
else()
add_definitions(-DX86)
endif() 

configure_file ("src/Config.hpp.in" "src/Config.hpp")

include_directories ("src/")
include_directories ("src/")

file (GLOB_RECURSE SOURCES "src/*.cpp")

add_executable (warctic ${SOURCES})

target_link_libraries (warctic "-lstdc++ -lSDL2 -lSDL2_mixer -lSDL2_ttf -lGL")

add_dependencies (warctic resource)
