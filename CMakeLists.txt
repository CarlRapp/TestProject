# Minimum required CMake version
cmake_minimum_required(VERSION 2.8 FATAL_ERROR)

# Project name
project("LekProjekt")



# Create executable
file(GLOB_RECURSE SRC_FILES
     ${CMAKE_CURRENT_SOURCE_DIR}/src/*.h
     ${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp)
	 
add_compile_options(-std=c++11)
add_executable(LekProjekt ${SRC_FILES})

if (UNIX)
	# Include directory
	include_directories("${CMAKE_CURRENT_SOURCE_DIR}/External/include/LINUX")
	
	# Link libraries
	file(GLOB LINUX_SHARED_LIBRARIES
	     ${CMAKE_CURRENT_SOURCE_DIR}/External/lib/*.so)
	target_link_libraries(LekProjekt
			      ${LINUX_SHARED_LIBRARIES})
elseif (WIN32)
	# Include directory
	include_directories("${CMAKE_CURRENT_SOURCE_DIR}/External/include/WINDOWS")

	# Link libraries
	file(GLOB WINDOWS_SHARED_LIBRARIES
	     ${CMAKE_CURRENT_SOURCE_DIR}/External/lib/*.lib)
	target_link_libraries(LekProjekt
			      ${WINDOWS_SHARED_LIBRARIES})
endif()



