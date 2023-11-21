include_directories(${graphics-utils_SOURCE_DIR}/include)
add_executable(glfwSimpleClearExample main.cpp)
target_link_libraries(glfwSimpleClearExample PRIVATE GLESv2 EGL glfw)
