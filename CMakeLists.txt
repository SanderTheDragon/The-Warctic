cmake_minimum_required (VERSION 3.7)
project (Warctic VERSION 1.0.1 LANGUAGES CXX)

find_package (OGRE 2.0)

if (NOT OGRE_FOUND)
    message (STATUS "Building OGRE 2")
    set (OGRE_BUILD_SAMPLES2 0)
    add_subdirectory ("${CMAKE_CURRENT_SOURCE_DIR}/external/OGRE")
endif ()



set(CMAKE_CXX_STANDARD 17)

set (SRC "${CMAKE_CURRENT_SOURCE_DIR}/src")
set (SOURCES
    "${SRC}/Main.cpp")
set (HEADERS
    )



if (NOT OGRE_FOUND)
    include_directories ("${CMAKE_CURRENT_BINARY_DIR}/external/OGRE/include/")
    include_directories ("${CMAKE_CURRENT_SOURCE_DIR}/external/OGRE/OgreMain/include/")
    include_directories ("${CMAKE_CURRENT_SOURCE_DIR}/external/OGRE/RenderSystems/GL3Plus/include/")
else ()
    include_directories (${OGRE_INCLUDE_DIRECTORIES})
endif ()

add_executable (${PROJECT_NAME} ${SOURCES} ${HEADERS})
if (NOT OGRE_FOUND)
    target_link_libraries (${PROJECT_NAME} OgreMain RenderSystem_GL3Plus)
else ()
    target_link_libraries (${PROJECT_NAME} ${OGRE_LIBRARIES})
endif ()
