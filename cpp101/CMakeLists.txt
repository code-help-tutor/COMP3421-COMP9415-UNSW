WeChat: cstutorcs
QQ: 749389476
Email: tutorcs@163.com
cmake_minimum_required(VERSION 3.12)

project(cpp101)

set(CMAKE_CXX_STANDARD 17)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY bin)

add_executable(cpp101)
target_include_directories(cpp101 PUBLIC include)
target_sources(cpp101 PRIVATE src/main.cpp)