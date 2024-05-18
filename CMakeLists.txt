cmake_minimum_required(VERSION 3.10)
project(BlastEngine)

set(CMAKE_CXX_STANDARD 11)

# Add GLAD
add_library(glad libs/GLAD/src/glad.c)
include_directories(libs/GLAD/include)

# Add GLFW
add_subdirectory(libs/GLFW)
include_directories(libs/GLFW/include)

# Include directories for BlastEngine
include_directories(include/blast)

# Add the executable
add_executable(BlastEngine src/main.cpp src/particle.cpp)

# Link libraries
target_link_libraries(BlastEngine glfw glad)
