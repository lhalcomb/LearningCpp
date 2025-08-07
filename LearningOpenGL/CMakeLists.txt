cmake_minimum_required(VERSION 3.10)
project(LearningOpenGL)

set(CMAKE_CXX_STANDARD 17)

# GLFW: Assume installed with Homebrew (or manually add its include/lib paths)
find_package(PkgConfig REQUIRED)
pkg_search_module(GLFW REQUIRED glfw3)

include_directories(/opt/homebrew/include)
link_directories(/opt/homebrew/lib)

# Add glad and your source files
add_executable(LearningOpenGL
    src/GLWindow.cpp
    #src/HelloTriangle.cpp
    #src/multipleTriangles.cpp
    src/glad.c
)

# Include paths
target_include_directories(LearningOpenGL
    PRIVATE
    include         # for glad
    ${GLFW_INCLUDE_DIRS}
)

# Link GLFW and OpenGL framework on macOS
target_link_libraries(LearningOpenGL
    "-framework OpenGL"
    glfw
)
