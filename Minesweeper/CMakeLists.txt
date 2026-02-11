
cmake_minimum_required(VERSION 3.10)
project(Minesweeper LANGUAGES CXX)

#=======================================================================
set(CMAKE_CXX STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

#=======================================================================
set(CMAKE_DISABLE_IN_SOURCE_BUILD ON)
set(CMAKE_DISABLE_SOURCE_CHANGES ON)
if("${CMAKE_SOURCE_DIR}" STREQUAL "${CMAKE_BINARY_DIR}")
    message(SEND_ERROR "Nie buduj w katalogu źródłowym!")
endif()

#======================================================================
# Debug/Release
#======================================================================
set(CMAKE_BUILD_TYPE Debug)

set(CMAKE_CXX_FLAGS_DEBUG_INIT "-Wall -Wextra -pedantic -g")
set(CMAKE_CXX_FLAGS_RELEASE_INIT "-02 -Wall")

#=======================================================================
# Struktura katalogów projektu
#=======================================================================
set(INCLUDE_DIR "${PROJECT_SOURCE_DIR}/include")
set(SOURCE_DIR "${PROJECT_SOURCE_DIR}/src")

include_directories(${INCLUDE_DIR})

file(GLOB SOURCES "${SOURCE_DIR}/*.cpp")
#=======================================================================
add_executable(${PROJECT_NAME} Main.cpp ${SOURCES})

#=======================================================================
target_compile_options(${PROJECT_NAME} PRIVATE -Wall -Wextra -Wpedantic)