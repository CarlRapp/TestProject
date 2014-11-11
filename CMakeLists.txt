# Minimum required CMake version
cmake_minimum_required(VERSION 2.8 FATAL_ERROR)

# Project name
project("LekProjekt")

# Include directory
include_directories("${CMAKE_CURRENT_SOURCE_DIR}/External/include")

# Create executable
file(GLOB SRC_FILES
     ${CMAKE_CURRENT_SOURCE_DIR}/src/*.h
     ${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp)
	 
add_compile_options(-std=c++11)
add_executable(LekProjekt ${SRC_FILES})

if (UNIX)
	set(CMAKE_CXX_FLAGS_DEBUG 	"${CMAKE_CXX_FLAGS_DEBUG} -g -Wno-ignored-attributes -Wno-deprecated -Wno-shift-op-parentheses -fexceptions")
	set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} -Wall -O4")
	set(CMAKE_LINKER 			"/usr/bin/llvm-ld")
	set(CMAKE_CXX_COMPILER 		"/usr/bin/g++")
	set(CMAKE_C_COMPILER 		"/usr/bin/gcc")


	# Link libraries
	file(GLOB LINUX_SHARED_LIBRARIES
	     ${CMAKE_CURRENT_SOURCE_DIR}/External/lib/*.so)
	target_link_libraries(LekProjekt
			      ${LINUX_SHARED_LIBRARIES})
endif()



