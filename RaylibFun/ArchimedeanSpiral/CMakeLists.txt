cmake_minimum_required(VERSION 3.10)
project(ArchimedianSpiral)

# Specify the C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Add include directories
include_directories(/opt/homebrew/Cellar/raylib/5.0/include)

# Add link directories
link_directories(/opt/homebrew/Cellar/raylib/5.0/lib)

# Define the executable
add_executable(ArchimedianSpiral
    main.cpp
)

# Link libraries
target_link_libraries(ArchimedianSpiral raylib)