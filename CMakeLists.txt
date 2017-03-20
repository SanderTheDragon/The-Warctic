cmake_minimum_required (VERSION 3.8) #3.8 Is the first to support C++17

#Do not allow build in the base directory
if (CMAKE_BINARY_DIR STREQUAL CMAKE_SOURCE_DIR)
	message (FATAL_ERROR "Please build in another directory, like ./build")
endif ()

#Warning for spaces in build path
if (CMAKE_BINARY_DIR MATCHES " ")
	message (WARNING "Your directory has spaces, this could cause issues when building")
endif ()

project (warctic)

find_package (OpenGL 3.3 REQUIRED)  #OpenGL has to be 3.3 or higher
find_package (glfw3 3.0 REQUIRED)   #GLFW has to be 3.0 or higher
find_package (GLEW 2.0 REQUIRED)    #GLEW has to be 2.0 or higher
find_package (glm REQUIRED)         #GLM can be any version

#No cmake module for minizip :(
#find_package (minizip 1.0 REQUIRED) #minizip has to be 1.0 or higher

set (CMAKE_CXX_STANDARD 17) #Use C++17, required mostly for <filesystem>
set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall") #Enable all warnings

#Version info, for Config.hpp.in
set (VERSION_MAJOR 0)
set (VERSION_MINOR 1)
set (VERSION_BUILD 1)
add_definitions (-DUNSTABLE)

#Platform info
if (CMAKE_HOST_UNIX AND NOT CMAKE_HOST_APPLE) #All Unix systems that are not Apple are now Linux
	add_definitions(-DLIN)
endif ()

if (CMAKE_HOST_WIN32)
	add_definitions(-DWIN)
endif ()

if (CMAKE_HOST_APPLE)
	add_definitions(-DMAC)
endif ()

#Architecture info
if(CMAKE_SIZEOF_VOID_P EQUAL 8)
	add_definitions(-DX64)
else()
	add_definitions(-DX86)
endif() 

configure_file ("src/Config.hpp.in" "${CMAKE_SOURCE_DIR}/src/Config.hpp") #Configure the config

include_directories ("src/") #Use src/ as header directory

file (GLOB_RECURSE SOURCES "src/*.cpp") #Use all cpp files as source

add_executable (warctic ${SOURCES}) #Build all cpp files
target_link_libraries (warctic "-lstdc++ -lGL -lglfw -lGLEW -lminizip") #Link everything together
