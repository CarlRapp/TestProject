# Minimum required CMake version
cmake_minimum_required(VERSION 2.8 FATAL_ERROR)

# Project name
project("LekProjekt")

# Include directory
include_directories("${CMAKE_CURRENT_SOURCE_DIR}/External/include")

# Include directory
file(RELATIVE_PATH IncludeDirectoryRelative ${CMAKE_CURRENT_SOURCE_DIR}/External/include/)
get_filename_component(IncludeDirectoryAbsolute ${IncludeDirectoryRelative} ABSOLUTE)

# Library directory
file(RELATIVE_PATH LibraryDirectoryRelative ${CMAKE_CURRENT_SOURCE_DIR}/External/include/)
get_filename_component(LibraryDirectoryAbsolute ${LibraryDirectoryRelative} ABSOLUTE)

# Create executable
file(GLOB SRC_FILES
     ${CMAKE_CURRENT_SOURCE_DIR}/src/*.h
     ${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp)
	 
add_compile_options(-std=c++11)
add_executable(LekProjekt ${SRC_FILES})

find_path(SDL2Include SDL2/SDL.h
	PATHS ${IncludeDirectoryAbsolute})
set(SDL2Includes ${SDL2IncludeDirectory})
find_library(SDL2Library
	NAMES SDL2 SDL2main
	PATHS ${LibraryDirectoryAbsolute})
set(SDL2Libraries ${SDL2Library})

if (UNIX)
	# Link libraries
	file(GLOB LINUX_SHARED_LIBRARIES
	     ${CMAKE_CURRENT_SOURCE_DIR}/External/lib/x86/*.so)
	target_link_libraries(LekProjekt
			      ${LINUX_SHARED_LIBRARIES})
endif()



