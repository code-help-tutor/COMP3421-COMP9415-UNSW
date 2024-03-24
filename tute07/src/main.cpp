WeChat: cstutorcs
QQ: 749389476
Email: tutorcs@163.com
#include <cstdlib>
#include <chrono>
#include <thread>
#include <iostream>

#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <chicken3421/chicken3421.hpp>

#include <tute07/memes.hpp>
#include <tute07/scene.hpp>
#include <tute07/renderer.hpp>

struct {
    int WIDTH = 1280;
    int HEIGHT = 720;
    const char *TITLE = "Tutorial 07";
    float ASPECT = (float) WIDTH / (float) HEIGHT;
} win_opts;

/**
 * Returns the difference in time between when this function was previously called and this call.
 * @return A float representing the difference between function calls in seconds.
 */
float time_delta();

/**
 * Returns the current time in seconds.
 * @return Returns the current time in seconds.
 */
float time_now();


/**
 * TODO: complete this
 *
 * @param sun The direction vector to modify
 * @param win The window whose input to poll
 * @param dt Delta Time (not to be confused with Break Time)
 */
void update_sunlight(glm::vec3 &sun, GLFWwindow *win, float dt);

int main() {
    GLFWwindow *win = marcify(chicken3421::make_opengl_window(win_opts.WIDTH, win_opts.HEIGHT, win_opts.TITLE));
    glfwSetInputMode(win, GLFW_CURSOR, GLFW_CURSOR_DISABLED);


    scene_t scene = make_scene();
    renderer_t renderer = make_renderer(glm::perspective(glm::pi<float>() / 3, win_opts.ASPECT, 0.1f, 100.f));

    while (!glfwWindowShouldClose(win)) {
        float dt = time_delta();

        update_camera(scene.cam, win, dt);

        render(renderer, scene);

        glfwSwapBuffers(win);
        glfwPollEvents();

        // not entirely correct as a frame limiter, but close enough
        // it would be more correct if we knew how much time this frame took to render
        // and calculated the distance to the next "ideal" time to render and only slept that long
        // the current way just always sleeps for 16.67ms, so in theory we'd drop frames
        std::this_thread::sleep_for(std::chrono::duration<float, std::milli>(1000.f / 60));
    }

    // deleting the whole window also removes the opengl context, freeing all our memory in one fell swoop.
    chicken3421::delete_opengl_window(win);

    return EXIT_SUCCESS;
}

float time_delta() {
    static float then = time_now();
    float now = time_now();
    float dt = now - then;
    then = now;
    return dt;
}

float time_now() {
    return (float) glfwGetTime();
}