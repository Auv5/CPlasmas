## Locate the SDL2_image library
# - Try to find SDL2_image
# Once done this will define
#  SDL2_image_FOUND - System has SDL2_image
#  SDL2_image_INCLUDE_DIRS - The SDL2_image include directories
#  SDL2_image_LIBRARIES - The libraries needed to use SDL2_image
#  SDL2_image_DEFINITIONS - Compiler switches required for using SDL2_image

find_package(PkgConfig)
pkg_check_modules(PC_LIBSDL2IMAGE QUIET libSDL2_image-2.0)
set(LIBSDL2_image_DEFINITIONS ${PC_LIBSDL2IMAGE_CFLAGS_OTHER})

find_path(SDL2_image_INCLUDE_DIR SDL2/SDL_image.h
          HINTS ${PC_LIBSDL2IMAGE_INCLUDEDIR} ${PC_LIBSDL2IMAGE_INCLUDE_DIRS}
          PATH_SUFFIXES libSDL2_image )

find_library(SDL2_image_LIBRARY NAMES SDL2_image libSDL2_image
             HINTS ${PC_LIBSDL2IMAGE_LIBDIR} ${PC_LIBSDL2IMAGE_LIBRARY_DIRS} )

set(SDL2_image_LIBRARIES ${SDL2_image_LIBRARY} )
set(SDL2_image_INCLUDE_DIRS ${SDL2_image_INCLUDE_DIR} )

include(FindPackageHandleStandardArgs)
# handle the QUIETLY and REQUIRED arguments and set SDL2_image_FOUND to TRUE
# if all listed variables are TRUE
find_package_handle_standard_args(SDL2_image  DEFAULT_MSG
                                  SDL2_image_LIBRARY SDL2_image_INCLUDE_DIR)

mark_as_advanced(SDL2_image_INCLUDE_DIR SDL2_image_LIBRARY )