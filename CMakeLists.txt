# Minimum required CMake version
cmake_minimum_required(VERSION 2.8 FATAL_ERROR)

# Project name
project("Test")

# Include directory
include_directories("${CMAKE_CURRENT_SOURCE_DIR}/External/include")
 
# Create executable
file(GLOB SRC_FILES
     ${CMAKE_CURRENT_SOURCE_DIR}/src/*.h
     ${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp)
add_executable(test ${SRC_FILES})

#set(CMAKE_SHARED_LINKER_FLAGS "${CMAKE_STATIC_LINKER_FLAGS} -Wl,-rpath,-Bstatic")

if (UNIX)
        # Link libraries
        file(GLOB LINUX_SHARED_LIBRARIES
             ${CMAKE_CURRENT_SOURCE_DIR}/External/lib/x86/libSDL2.so)
        target_link_libraries(test
                              ${LINUX_SHARED_LIBRARIES})
elseif (WIN32)
	# Link libraries
        file(GLOB WINDOWS_SHARED_LIBRARIES
             ${CMAKE_CURRENT_SOURCE_DIR}/External/lib/x86/*.lib)
        target_link_libraries(test
                              ${WINDOWS_SHARED_LIBRARIES}
							  OpenGL32)
endif()