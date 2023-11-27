# Interface surface implementations
if(SURFACE_TYPE STREQUAL "GLFW")
    add_library(glfwSurfaceLib GLFWConcreteSurface.cpp)
    target_include_directories(glfwSurfaceLib PRIVATE ${PROJECT_SOURCE_DIR})
else(SURFACE_TYPE STREQUAL "GBM")
    add_library(gbmSurfaceLib GBMConcreteSurface.cpp)
    target_include_directories(gbmSurfaceLib PRIVATE ${PROJECT_SOURCE_DIR})
endif()

# Example programs
add_subdirectory(simple-clear)
