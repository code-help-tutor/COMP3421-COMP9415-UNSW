WeChat: cstutorcs
QQ: 749389476
Email: tutorcs@163.com
// C++17 doesn't have std::pi
#define _USE_MATH_DEFINES
#include <cmath>

#include <cstdlib>
#include <chrono>

#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <chicken3421/chicken3421.hpp>

int main() {
    GLFWwindow *win = chicken3421::make_opengl_window(1280, 720, "Assignment 1");

    while (!glfwWindowShouldClose(win)) {
        using namespace std::chrono;
        long long now = time_point_cast<milliseconds>(system_clock::now()).time_since_epoch().count();

        glfwPollEvents();

        glClear(GL_COLOR_BUFFER_BIT);
        glClearColor(std::cos(now/1000), std::sin(now/1000), std::cos(now/1000), 1);

        glfwSwapBuffers(win);
    }


    return EXIT_SUCCESS;
}