cmake_minimum_required(VERSION 3.5 FATAL_ERROR)
project(Containers LANGUAGES C)

set(CMAKE_C_STANDARD 99)
set(CMAKE_C_EXTENSIONS OFF)
set(CMAKE_C_STANDARD_REQUIRED ON)

include(GNUInstallDirs)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY
	${CMAKE_BINARY_DIR}/${CMAKE_INSTALL_LIBDIR})
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY
	${CMAKE_BINARY_DIR}/${CMAKE_INSTALL_LIBDIR})
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY
	${CMAKE_BINARY_DIR}/${CMAKE_INSTALL_BINDIR})

# Project targets and sources
add_subdirectory(src)

# Test targets and sources
add_subdirectory(test)

enable_testing()