cmake_minimum_required (VERSION 3.7)
project (Warctic VERSION 0.0.1 LANGUAGES CXX)
set (Warctic_VERSION_SUFFIX "alpha")

if (UNIX AND NOT APPLE AND NOT CYGWIN)
    set (Warctic_VERSION_PLATFORM "Linux")
    add_definitions ("-DLINUX=1")
elseif (UNIX AND APPLE)
    set (Warctic_VERSION_PLATFORM "Mac")
    add_definitions ("-DMAC=1")
elseif (WIN32 OR MINGW OR MSYS OR CYGWIN)
    set (Warctic_VERSION_PLATFORM "Windows")
    add_definitions ("-DWINDOWS=1")
else ()
    set (Warctic_VERSION_PLATFORM "Unknown")
endif ()

find_package (OGRE 2.0)
find_package (SDL2)

include (ExternalProject)
if (NOT OGRE_FOUND)
    message (STATUS "Building OGRE 2")
    ExternalProject_Add (OGRE
        DOWNLOAD_COMMAND git submodule init "${CMAKE_CURRENT_SOURCE_DIR}/external/OGRE"
        UPDATE_COMMAND git submodule update --remote --progress --force "${CMAKE_CURRENT_SOURCE_DIR}/external/OGRE"
        SOURCE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/external/OGRE"
        CMAKE_ARGS "-DOGRE_BUILD_SAMPLES2=0" "-DCMAKE_INSTALL_PREFIX=${CMAKE_BINARY_DIR}/external"
        BUILD_IN_SOURCE 1)

    set (OGRE_PLUGIN_PATH "${CMAKE_CURRENT_BINARY_DIR}/external/lib/OGRE")
else ()
    set (OGRE_PLUGIN_PATH "${OGRE_PLUGIN_DIR_REL}")
endif ()

if (NOT SDL2_FOUND)
    message (STATUS "Building SDL2")
    ExternalProject_Add (SDL2
        DOWNLOAD_COMMAND git submodule init "${CMAKE_CURRENT_SOURCE_DIR}/external/SDL2"
        UPDATE_COMMAND git submodule update --remote --progress --force "${CMAKE_CURRENT_SOURCE_DIR}/external/SDL"
        SOURCE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/external/SDL2"
        CONFIGURE_COMMAND "${CMAKE_CURRENT_SOURCE_DIR}/external/SDL2/./configure" "--prefix=${CMAKE_BINARY_DIR}/external"
        BUILD_IN_SOURCE 1)
    ExternalProject_Add_Step (SDL2 autogen
        DEPENDEES update
        DEPENDERS configure
        WORKING_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/external/SDL2"
        COMMAND "./autogen.sh")
endif ()



set(CMAKE_CXX_STANDARD 17)

set (SRC "${CMAKE_CURRENT_SOURCE_DIR}/src")
configure_file ("${CMAKE_CURRENT_SOURCE_DIR}/cmake/Config.hpp.in" "${SRC}/Config.hpp")

set (SOURCES
    "${SRC}/Engine.cpp"
    "${SRC}/GameWindow.cpp"
    "${SRC}/Input.cpp"
    "${SRC}/Main.cpp")
set (HEADERS
    "${SRC}/Config.hpp"
    "${SRC}/Engine.hpp"
    "${SRC}/GameWindow.hpp"
    "${SRC}/Input.hpp"
    "${SRC}/Log.hpp"
    "${SRC}/Macro.hpp")



if (NOT OGRE_FOUND)
    include_directories ("${CMAKE_CURRENT_BINARY_DIR}/external/include/OGRE")
else ()
    include_directories (${OGRE_INCLUDE_DIRECTORIES})
endif ()

if (NOT SDL2_FOUND)
    include_directories ("${CMAKE_CURRENT_BINARY_DIR}/external/include")
else ()
    include_directories (${SDL2_INCLUDE_DIRECTORIES})
endif ()



add_executable (${PROJECT_NAME} ${SOURCES} ${HEADERS})

if (NOT OGRE_FOUND)
    find_library (OGRE_LIBRARIES "OgreMain" "${CMAKE_CURRENT_BINARY_DIR}/external/lib")
endif ()
target_link_libraries (${PROJECT_NAME} ${OGRE_LIBRARIES})

if (NOT SDL2_FOUND)
    link_directories ("${CMAKE_CURRENT_BINARY_DIR}/external/lib")
    target_link_libraries (${PROJECT_NAME} "-lSDL2 -lSDL2main")
else ()
    target_link_libraries (${PROJECT_NAME} ${SDL2_LIBRARIES})
endif ()
