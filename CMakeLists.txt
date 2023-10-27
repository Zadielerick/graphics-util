cmake_minimum_required(VERSION 3.22)

project(
  graphics-utils
  VERSION 0.1
  LANGUAGES CXX)

add_executable(gbmRender main.cpp)

target_link_libraries(gbmRender PRIVATE gbm GLESv2 EGL)
