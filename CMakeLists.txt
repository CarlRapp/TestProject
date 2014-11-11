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

CMAKE_STATIC_LINKER_FLAGS="-Wl,--whole-archive -lgcc -lgcc_s -Wl,--no-whole-archive"
if (UNIX)
        # Link libraries
        file(GLOB LINUX_STATIC_LIBRARIES
             ${CMAKE_CURRENT_SOURCE_DIR}/External/lib/x86/*.a)
        target_link_libraries(test
                              ${LINUX_STATIC_LIBRARIES}
			      dl
			      X11)
elseif (WIN32)
	# Link libraries
        file(GLOB WINDOWS_SHARED_LIBRARIES
             ${CMAKE_CURRENT_SOURCE_DIR}/External/lib/x86/*.lib)
        target_link_libraries(test
                              ${WINDOWS_SHARED_LIBRARIES}
							  OpenGL32)
endif()