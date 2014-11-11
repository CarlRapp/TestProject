# Minimum required CMake version
cmake_minimum_required(VERSION 2.8 FATAL_ERROR)

# Project name
project("sdl2-test")

# Include directory
include_directories("${CMAKE_CURRENT_SOURCE_DIR}/External/include")

# Create executable
file(GLOB SRC_FILES
     ${CMAKE_CURRENT_SOURCE_DIR}/src/*.h
     ${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp)
add_executable(sdl2-test ${SRC_FILES})

if (UNIX)
	# Link libraries
	file(GLOB LINUX_SHARED_LIBRARIES
	     ${CMAKE_CURRENT_SOURCE_DIR}/External/lib/*.so)
	target_link_libraries(sdl2-test
			      ${LINUX_SHARED_LIBRARIES})
endif()