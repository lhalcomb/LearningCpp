# Shared CMakeLists.txt

cmake_minimum_required(VERSION 3.10)
project(CppSpaceInvaders)

# Specify the C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Define the executable and list source files
add_executable(CppSpaceInvaders
    src/main.cpp
    components/game.cpp
    components/spaceship.cpp
    components/laser.cpp
    components/colors.cpp
    components/block.cpp
    components/obstacle.cpp
    components/alien.cpp
    components/mysteryship.cpp
    Font/monogram.ttf
)

# Include platform-specific configurations
if(APPLE)
    include(${CMAKE_SOURCE_DIR}/CMakeLists_mac.txt)
elseif(WIN32)
    include(${CMAKE_SOURCE_DIR}/CMakeLists_win.txt)
endif()
