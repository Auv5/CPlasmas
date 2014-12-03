cmake_minimum_required (VERSION 2.8)
project (Plasmas)

set (PROJECT_INCLUDE_DIR ${PROJECT_SOURCE_DIR}/include)
set (PROJECT_SOURCE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/src)

set (Plasmas_SRCS
  ${PROJECT_SOURCE_DIR}/Main.cpp
  ${PROJECT_SOURCE_DIR}/BoxEntity.cpp
  ${PROJECT_SOURCE_DIR}/StrawberryEntity.cpp)

add_executable (${PROJECT_NAME} ${Plasmas_SRCS})

add_definitions(
  # Temporary for debugging purposes
  -g
  -std=c++11
  -DSDL2)

include_directories (${PROJECT_INCLUDE_DIR})

set (CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} ${CMAKE_SOURCE_DIR}/CMake)

include_directories (${Engine_INCLUDE_DIR})
target_link_libraries (${PROJECT_NAME} Engine)

find_package (SDL2 REQUIRED)
include_directories (${SDL2_INCLUDE_DIR})
target_link_libraries (Plasmas ${SDL2_LIBRARY})