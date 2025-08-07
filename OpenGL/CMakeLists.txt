cmake_minimum_required(VERSION 3.10)
project(OpenGL)

set(CMAKE_CXX_STANDARD 11)

include_directories(/opt/homebrew/include)
link_directories(/opt/homebrew/lib)

find_package(OpenGL REQUIRED)

add_executable(OpenGL test.cpp)

target_link_libraries(OpenGL
    ${OPENGL_LIBRARIES}
    glfw
    GLEW
)
# This CMakeLists.txt file is for a simple OpenGL project using GLFW and GLEW.