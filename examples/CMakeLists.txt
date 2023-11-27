# Interface surface implementations
if(SURFACE_TYPE STREQUAL "GLFW")
    add_library(glfwSurfaceLib GLFWConcreteSurface.cpp)
    target_link_libraries(glfwSurfaceLib glfw GLESv2 EGL)
else(SURFACE_TYPE STREQUAL "GBM")
    add_library(gbmSurfaceLib GBMConcreteSurface.cpp)
endif()

# Add examples include/ directory
include_directories(include)

# Example programs
add_subdirectory(simple-clear)
