cmake_minimum_required(VERSION 3.22)

project(
  graphics-utils
  VERSION 0.1
  LANGUAGES CXX)

# Default SURFACE_TYPE is GLFW
# Other supported SURFACE_TYPES:
#   - GBM
if(NOT SURFACE_TYPE)
    set(SURFACE_TYPE GLFW)
endif()

# Library directory
add_subdirectory(lib)

# Examples directory
add_subdirectory(examples)
