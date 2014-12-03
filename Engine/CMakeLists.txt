cmake_minimum_required (VERSION 2.8)
project (Engine)

set (PROJECT_INCLUDE_DIR ${PROJECT_SOURCE_DIR}/include)
set (PROJECT_SOURCE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/src)

set (Engine_SRCS
    ${PROJECT_SOURCE_DIR}/Entity.cpp
    ${PROJECT_SOURCE_DIR}/Image.cpp
    ${PROJECT_SOURCE_DIR}/SDL/SDLGraphics.cpp
    ${PROJECT_SOURCE_DIR}/Window.cpp
    ${PROJECT_SOURCE_DIR}/EventSystem.cpp
    ${PROJECT_SOURCE_DIR}/ImageDraw.cpp
    ${PROJECT_SOURCE_DIR}/SDL/SDLWindow.cpp
    ${PROJECT_SOURCE_DIR}/_Errors.cpp
    ${PROJECT_SOURCE_DIR}/Graphics.cpp
    ${PROJECT_SOURCE_DIR}/SDL/SDLEventsSystem.cpp
    ${PROJECT_SOURCE_DIR}/SubSystem.cpp
    ${PROJECT_SOURCE_DIR}/_Selector.cpp
    ${PROJECT_SOURCE_DIR}/SDL/SDLImage.cpp)

add_library (${PROJECT_NAME} STATIC ${Engine_SRCS})



add_definitions(
  -g
  -std=c++11
  -DSDL2
  -DENGAPI_EXPORT)

include_directories (${PROJECT_INCLUDE_DIR})

set (CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} ${CMAKE_SOURCE_DIR}/CMake)

find_package (SDL2 REQUIRED)
include_directories (${SDL2_INCLUDE_DIR})
target_link_libraries (Engine ${SDL2_LIBRARY})

find_package (SDL2_image REQUIRED)
include_directories (${SDL2_image_INCLUDE_DIRS})
target_link_libraries (Engine ${SDL2_image_LIBRARIES})

set (${PROJECT_NAME}_INCLUDE_DIR ${PROJECT_INCLUDE_DIR} CACHE INTERNAL "${PROJECT_NAME}: Definitions" FORCE)
