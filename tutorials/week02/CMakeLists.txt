WeChat: cstutorcs
QQ: 749389476
Email: tutorcs@163.com
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/week02)

copy_resources(${CMAKE_CURRENT_LIST_DIR}/res ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/res)

include_directories(include)

# In bigger projects a dedicated CMakeLists.txt would be in the `src` folder that does this
#add_executable(hello_triangle)
#target_sources(hello_triangle PRIVATE ${CMAKE_CURRENT_LIST_DIR}/src/main.cpp)
#target_link_libraries(hello_triangle PUBLIC ${COMMON_LIBS})

