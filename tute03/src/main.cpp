WeChat: cstutorcs
QQ: 749389476
Email: tutorcs@163.com
// #include <cstdlib>

// #include <glad/glad.h>
// #include <GLFW/glfw3.h>
// #include <stb/stb_image.h>
// #include <glm/ext.hpp>
// #include <glm/glm.hpp>

// #include <chicken3421/chicken3421.hpp>

// // TODO: Part 1
// #include <tute03/cube.hpp>

// // TODO: Part 2
// #include <tute03/camera.hpp>

// const GLfloat width = 1280;
// const GLfloat height = 720;

// int main() {
//     chicken3421::image_t marccoin = chicken3421::load_image("res/img/marccoin.png");
//     GLFWimage favicon = {marccoin.width, marccoin.height, (unsigned char *)marccoin.data};

//     GLFWwindow *win = chicken3421::make_opengl_window(width, height, "Tutorial 03");
//     glfwSetWindowIcon(win, 1, &favicon);


//     // gl stuff
//     GLuint vs = chicken3421::make_shader("res/shaders/vert.glsl", GL_VERTEX_SHADER);
//     GLuint fs = chicken3421::make_shader("res/shaders/frag.glsl", GL_FRAGMENT_SHADER);
//     GLuint prog = chicken3421::make_program(vs, fs);


//     double prev_time = glfwGetTime();

//     // TODO: Fill me in.
//     auto cube = make_cube();
//     auto camera = make_camera({0,0,1}, {0,0,0});
     
//     while(!glfwWindowShouldClose(win)) {
//         glfwPollEvents();

//         // calculate time since previous frame (delta time)
//         double now_time = glfwGetTime();
//         float dt = now_time - prev_time;
//         prev_time = now_time;

//         glUseProgram(prog);

//         glUniformMatrix4fv(chicken3421::get_uniform_location(prog,"transform"), 1, GL_FALSE, glm::value_ptr(glm::lookAt(camera.pos, camera.front + camera.pos, camera.up) * glm::mat4{1}));
//         glClear(GL_COLOR_BUFFER_BIT);
//         glClearColor(0, 0, 0, 1);
//         glDrawElements(GL_TRIANGLES, cube.indices.size(), GL_UNSIGNED_INT, nullptr);

//         glfwSwapBuffers(win);
//     }

//     glfwSetWindowIcon(win, 0, nullptr);
//     chicken3421::delete_image(marccoin);

//     return EXIT_SUCCESS;
// }

#include <cstdlib>

#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include <glm/ext.hpp>

#include <chicken3421/chicken3421.hpp>

#include <tute03/cube.hpp>

#include <tute03/camera.hpp>


int main() {
    chicken3421::image_t marccoin = chicken3421::load_image("res/img/marccoin.png");
    // the rarest form of meme
    GLFWimage favicon = {marccoin.width, marccoin.height, (unsigned char *)marccoin.data};

    GLFWwindow *win = chicken3421::make_opengl_window(1280, 720, "Tutorial 03");
    glfwSetWindowIcon(win, 1, &favicon);

    // gl stuff
    GLuint vs = chicken3421::make_shader("res/shaders/vert.glsl", GL_VERTEX_SHADER);
    GLuint fs = chicken3421::make_shader("res/shaders/frag.glsl", GL_FRAGMENT_SHADER);
    GLuint prog = chicken3421::make_program(vs, fs);
    GLint mvp_loc = chicken3421::get_uniform_location(prog, "mvp");

    // this will be explained in the future
    glm::mat4 proj = glm::perspective(glm::radians(60.f), 16.f/9, 1.f, 20.f);

    cube_t w = make_cube();
    camera_t c = make_camera({0, 0, 5}, {0, 0, 0}); // up is defaulted

    glfwSetWindowUserPointer(win, &c);
    glfwSetInputMode(win, GLFW_CURSOR, GLFW_CURSOR_DISABLED);
    glfwSetCursorPosCallback(win, on_mouse_move);

    double prev_time = glfwGetTime();
    glEnable(GL_DEPTH_TEST);
    while(!glfwWindowShouldClose(win)) {
        glfwPollEvents();

        // calculate time since previous frame (delta time)
        double now_time = glfwGetTime();
        float dt = now_time - prev_time;
        prev_time = now_time;

        update_camera(c, win, dt);

        glUseProgram(prog);

        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        glClearColor(0, 0, 0, 1);

        glUniformMatrix4fv(mvp_loc, 1, GL_FALSE, glm::value_ptr(proj * get_view(c) * w.transform));

        glDrawElements(GL_TRIANGLES, w.indices.size(), GL_UNSIGNED_INT, 0);

        glfwSwapBuffers(win);
    }

    delete_cube(w);
    chicken3421::delete_program(prog);
    chicken3421::delete_shader(fs);
    chicken3421::delete_shader(vs);
    glfwSetWindowIcon(win, 0, nullptr);
    chicken3421::delete_image(marccoin);

    return EXIT_SUCCESS;
}
