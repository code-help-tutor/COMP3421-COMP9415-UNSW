WeChat: cstutorcs
QQ: 749389476
Email: tutorcs@163.com
cmake_minimum_required(VERSION 3.12)

project("COMP3421 Tutorial 02")

set(CMAKE_CXX_STANDARD 17)

list(APPEND CMAKE_MODULE_PATH ${PROJECT_SOURCE_DIR}/cmake)

# If I was better at CMake I would make this nicer
if (NOT (EXISTS ${PROJECT_SOURCE_DIR}/lib))
    message(STATUS "Dependencies not found. Please run fetch_deps.sh [-G Ninja] from the project root and reconfigure")
endif()

find_package(glad REQUIRED HINTS ${PROJECT_SOURCE_DIR}/lib)
find_package(glfw3 REQUIRED HINTS ${PROJECT_SOURCE_DIR}/lib)
find_package(glm REQUIRED HINTS ${PROJECT_SOURCE_DIR}/lib)
find_package(stb REQUIRED HINTS ${PROJECT_SOURCE_DIR}/lib)
find_package(tinyobjloader REQUIRED HINTS ${PROJECT_SOURCE_DIR}/lib)
find_package(chicken3421 REQUIRED HINTS ${PROJECT_SOURCE_DIR}/lib)

set(COMMON_LIBS glad::glad glm::glm glfw stb chicken3421)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/bin)

include(copy_resources)
copy_resources(${CMAKE_CURRENT_LIST_DIR}/res ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/res)


# In bigger projects a dedicated CMakeLists.txt would be in the `src` folder that does this
add_executable(week02_simple_texture)
target_include_directories(week02_simple_texture PUBLIC include)
target_sources(week02_simple_texture PRIVATE ${PROJECT_SOURCE_DIR}/src/simple_texture.cpp)
target_link_libraries(week02_simple_texture PUBLIC ${COMMON_LIBS})

add_executable(week02_simple_transforms)
target_include_directories(week02_simple_transforms PUBLIC include)
target_sources(week02_simple_transforms PRIVATE ${PROJECT_SOURCE_DIR}/src/simple_transforms.cpp)
target_link_libraries(week02_simple_transforms PUBLIC ${COMMON_LIBS})


