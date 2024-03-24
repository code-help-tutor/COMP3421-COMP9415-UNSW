WeChat: cstutorcs
QQ: 749389476
Email: tutorcs@163.com
#include <thread>
#include <chrono>

#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include <glm/ext.hpp>

#include <chicken3421/chicken3421.hpp>

#include <tute05/animator.hpp>
#include <tute05/camera.hpp>
#include <tute05/memes.hpp>
#include <tute05/renderer.hpp>
#include <tute05/scene.hpp>

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

int main() {
    GLFWwindow *win = marcify(chicken3421::make_opengl_window(1280, 720, "Tutorial 05"));

    // TODO turn this on or off?
    glfwSetInputMode(win, GLFW_CURSOR, GLFW_CURSOR_DISABLED);


    scene_t scene = make_scene();
    animator_t animator = make_animator();
    renderer_t renderer = make_renderer(glm::perspective(glm::pi<double>() / 3, 1280.0 / 720, 0.1, 1000.0));


    while (!glfwWindowShouldClose(win)) {
        float dt = time_delta();

        update_camera(scene.cam, win, dt);
        animate(animator, scene, time_now());
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
    return (float)glfwGetTime();
}