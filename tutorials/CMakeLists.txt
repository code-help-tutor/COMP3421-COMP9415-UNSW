WeChat: cstutorcs
QQ: 749389476
Email: tutorcs@163.com
cmake_minimum_required(VERSION 3.12)

project("COMP3421 Tutorials")

# C++ settings.
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_EXTENSIONS Off)
set(CMAKE_CXX_STANDARD_REQUIRED On)

# Artifact tree
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/bin)

# Our own custom CMake modules
list(APPEND CMAKE_MODULE_PATH ${PROJECT_SOURCE_DIR}/cmake)
include (copy_resources)

# 3rd and 1st party dependencies
add_subdirectory(lib)
set(COMMON_LIBS glfw glm glad stb chicken3421)

# Actual tutorial materials
add_subdirectory(week01)
add_subdirectory(week02)
#add_subdirectory(week03)
#add_subdirectory(week04)
#add_subdirectory(week05)
#add_subdirectory(week07)
#add_subdirectory(week08)
#add_subdirectory(week09)
#add_subdirectory(week10)