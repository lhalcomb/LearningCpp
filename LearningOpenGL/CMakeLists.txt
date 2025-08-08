cmake_minimum_required(VERSION 3.10)
project(LearningOpenGL)

set(CMAKE_CXX_STANDARD 17)

# Find GLFW
find_package(PkgConfig REQUIRED)
pkg_search_module(GLFW REQUIRED glfw3)

# Include directories
include_directories(
    include
    include/glad
    ${GLFW_INCLUDE_DIRS}
    /opt/homebrew/include            
)

# Link directories
link_directories(
    /opt/homebrew/lib
)

# Core source files reused by all examples
set(CORE_SOURCES
    src/glad.c
    src/core/Window.cpp
    src/core/Shader.cpp
)

# Function to create an example executable
function(add_example name)
    add_executable(${name}
        src/main/${name}.cpp
        ${CORE_SOURCES}
    )
    target_include_directories(${name} PRIVATE include)
    target_link_libraries(${name}
        "-framework OpenGL"
        glfw
    )
endfunction()

# Add individual examples
add_example(WindowExecute)
add_example(GLWindow)
add_example(HelloTriangle)
add_example(MultipleTriangles)
add_example(RefHelloTriangle)
