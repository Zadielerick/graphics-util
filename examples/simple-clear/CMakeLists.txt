add_executable(simpleClearExample simple-clear.cpp)

if(SURFACE_TYPE STREQUAL "GLFW")
    message("GLFW Surface used")
    target_link_libraries(simpleClearExample glfwSurfaceLib)
endif()
