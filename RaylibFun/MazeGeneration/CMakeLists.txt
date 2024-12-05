cmake_minimum_required(VERSION 3.10)
project(MazeGeneration)

# Specify the C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Manually set the SDK path if needed
set(CMAKE_OSX_SYSROOT /Applications/Xcode.app/Contents/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX15.sdk)

# Add include directories specific to macOS
include_directories(/opt/homebrew/Cellar/raylib/5.0/include/)

# Add link directories specific to macOS
link_directories(/opt/homebrew/Cellar/raylib/5.0/lib)

# Define the executable
add_executable(MazeGeneration 
    src/main.cpp
    Components/Cell.cpp
)

# Link libraries (raylib in this case)
target_link_libraries(MazeGeneration raylib)