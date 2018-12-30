cmake_minimum_required(VERSION 3.12)
project(test_glfw)

set(CMAKE_CXX_STANDARD 11)

add_executable(test_glfw main.cpp glad.c Shader.h camera.h objLoader.cpp objLoader.h)
target_link_libraries(test_glfw glfw3)