WeChat: cstutorcs
QQ: 749389476
Email: tutorcs@163.com
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/week01)

copy_resources(${CMAKE_CURRENT_LIST_DIR}/res ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/res)

# In bigger projects a dedicated CMakeLists.txt would be in the `src` folder that does this
add_executable(week01_hello_triangle)
#include_directories(${CMAKE_CURRENT_LIST_DIR}/include)
target_include_directories(week01_hello_triangle PUBLIC include)
target_sources(
	week01_hello_triangle PRIVATE
#	include/EBO.h
#	include/VAO.h
#	include/VBO.h
#	include/header.hpp
	src/EBO.cpp
	src/VAO.cpp
	src/VBO.cpp
	src/header.cpp
	src/shaderClass.cpp
	src/main.cpp
	)
target_link_libraries(week01_hello_triangle PUBLIC ${COMMON_LIBS})

