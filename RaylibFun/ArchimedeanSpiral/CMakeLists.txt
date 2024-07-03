# Shared CMakeLists.txt

cmake_minimum_required(VERSION 3.10)
project(ArchimedianSpiral)

# Specify the C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Define the executable and link libraries
add_executable(ArchimedianSpiral main.cpp)

# Include platform-specific configurations
if(APPLE)
    include(${CMAKE_SOURCE_DIR}/CMakeLists_mac.txt)
elseif(WIN32)
    include(${CMAKE_SOURCE_DIR}/CMakeLists_win.txt)
endif()
