WeChat: cstutorcs
QQ: 749389476
Email: tutorcs@163.com
#include <iostream>

#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include <glm/ext.hpp>

#include <chicken3421/chicken3421.hpp>

#include "texture_2d.hpp"
#include "shapes.hpp"
#include "scene.hpp"
#include "euler_camera.hpp"
#include "memes.hpp"

const int SCR_WIDTH = 1280;
const int SCR_HEIGHT = 720;

const char *WIN_TITLE = "Tutorial 04";
const char *VERT_PATH = "res/shaders/shader.vert";
const char *FRAG_PATH = "res/shaders/shader.frag";
const char *SUN_TEXTURE_PATH = "res/textures/sun.jpg";
const char *EARTH_TEXTURE_PATH = "res/textures/earth.jpg";
const char *MARS_TEXTURE_PATH = "res/textures/mars.jpg";
const char *MOON_TEXTURE_PATH = "res/textures/moon.jpg";
const char *CLOUDS_TEXTURE_PATH = "res/textures/clouds.png";

namespace {
    double time_delta() {
        static double then = glfwGetTime();
        double now = glfwGetTime();
        double dt = now - then;
        then = now;
        return dt;
    }
}

int main() {
    chicken3421::enable_debug_output();
    GLFWwindow *window = marcify(chicken3421::make_opengl_window(SCR_WIDTH, SCR_HEIGHT, WIN_TITLE));
    glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);

    // make the render program
    auto vs = chicken3421::make_shader(VERT_PATH, GL_VERTEX_SHADER);
    auto fs = chicken3421::make_shader(FRAG_PATH, GL_FRAGMENT_SHADER);
    auto render_program = chicken3421::make_program(vs, fs);
    chicken3421::delete_shader(vs);
    chicken3421::delete_shader(fs);

    // TODO: create scene nodes here

    auto solar_system = scene::node_t{};

    auto sun = scene::node_t{
        shapes::make_sphere(1),
        texture_2d::init(SUN_TEXTURE_PATH)
    };

    auto earth = scene::node_t{
        shapes::make_sphere(0.4),
        texture_2d::init(EARTH_TEXTURE_PATH),
        glm::vec3{3,0,0},
    };

    auto clouds = scene::node_t{
        shapes::make_sphere(0.4),
        texture_2d::init(CLOUDS_TEXTURE_PATH),
    };
    clouds.scale = glm::vec3{1.1};

    auto mars = scene::node_t{
        shapes::make_sphere(0.3),
        texture_2d::init(MARS_TEXTURE_PATH),
        glm::vec3{-4,0,0},
    };

    auto moon = scene::node_t{
        shapes::make_sphere(0.4),
        texture_2d::init(MOON_TEXTURE_PATH),
        glm::vec3{1,0,0}, // move 1 based on coord of earth
    };
    moon.scale = (glm::vec3(0.6));

    solar_system.children.push_back(&sun);
    solar_system.children.push_back(&earth);
    solar_system.children.push_back(&mars);
    earth.children.push_back(&moon);
    earth.children.push_back(&clouds);

    GLint mvp_loc = chicken3421::get_uniform_location(render_program, "uMVP");
    glm::mat4 proj = glm::perspective(glm::radians(60.0), (double) SCR_WIDTH / (double) SCR_HEIGHT, 0.1, 50.0);
    auto cam = euler_camera::make_camera(glm::vec3(0, 0, 5), glm::vec3(0));

    glEnable(GL_DEPTH_TEST);
    glEnable(GL_CULL_FACE);
    // TODO: add blending here
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);


    glUseProgram(render_program);
    while (!glfwWindowShouldClose(window)) {
        auto dt = (float) time_delta();

        glClearColor(0.0, 0.0, 0.0, 1.0);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        euler_camera::update_camera(cam, window, dt);

        // TODO: add your animations here
        sun.rotation.y += glm::radians(50.0f) * dt;
        earth.rotation.y += glm::radians(80.0f) * dt;

        // TODO: draw your scene here
        scene::draw(&solar_system, proj * euler_camera::get_view(cam), mvp_loc);

        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    // TODO: destroy scene nodes here (tute optional)
    chicken3421::delete_program(render_program);
    glfwTerminate();
    return EXIT_SUCCESS;
}
