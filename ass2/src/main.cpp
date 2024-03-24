WeChat: cstutorcs
QQ: 749389476
Email: tutorcs@163.com
#include <cstdlib>
#include <thread>
#include <chrono>

#include <iostream>
#include <stack>

#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <stb/stb_image.h>
#include <glm/glm.hpp>
#include <glm/ext.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include <chicken3421/chicken3421.hpp>

#include <ass2/memes.hpp>
#include <ass2/scene.hpp>
#include <ass2/renderer.hpp>

struct {
    int WIDTH = 1280;
    int HEIGHT = 720;
    const char *TITLE = "Assignment 02";
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

void update_light(scene_t &scene, GLFWwindow *win, float dt) {
    using namespace glm;

    glm::vec3 &pos = scene.point_light.pos;

    // in degrees
    static glm::vec2 EXTENT = { 170, 10 };
    static float INCREMENT = 25;
    static float curr_angle = 90;

    float change = 0;
    if (glfwGetKey(win, GLFW_KEY_E) == GLFW_PRESS) {
        change = curr_angle >= EXTENT.x ? change : INCREMENT * dt;
    } else if (glfwGetKey(win, GLFW_KEY_Q) == GLFW_PRESS) {
        change = curr_angle <= EXTENT.y ? change : -INCREMENT * dt;
    }

    curr_angle += change;

    pos = rotate(identity<mat4>(), radians(change), { 0, 0, 1 }) * vec4(pos, 1);

    // update light mesh
    std::stack<node_t*> scene_items;
    scene_items.push(&scene.root);
    while (!scene_items.empty()) {
        auto& node = *scene_items.top();
        scene_items.pop();

        if (node.kind == node_t::LIGHT_MESH) {
            node.transform = glm::translate(glm::mat4(1), pos)
                             * glm::scale(glm::mat4(1), { 0.1, 0.1, 0.1 });
        }

        for (node_t &c: node.children) {
            scene_items.push(&c);
        }
    }
}


// // Vertices coordinates
// GLfloat vertices[] =
// { //     COORDINATES     /        COLORS      /   TexCoord  //
// 	-0.5f, 0.0f,  0.5f,     0.83f, 0.70f, 0.44f,	0.0f, 0.0f,
// 	-0.5f, 0.0f, -0.5f,     0.83f, 0.70f, 0.44f,	5.0f, 0.0f,
// 	 0.5f, 0.0f, -0.5f,     0.83f, 0.70f, 0.44f,	0.0f, 0.0f,
// 	 0.5f, 0.0f,  0.5f,     0.83f, 0.70f, 0.44f,	5.0f, 0.0f,
// 	 0.0f, 0.8f,  0.0f,     0.92f, 0.86f, 0.76f,	2.5f, 5.0f
// };

// // Indices for vertices order
// GLuint indices[] =
// {
// 	0, 1, 2,
// 	0, 2, 3,
// 	0, 1, 4,
// 	1, 2, 4,
// 	2, 3, 4,
// 	3, 0, 4
// };


int main() {
    GLFWwindow *win = marcify(chicken3421::make_opengl_window(win_opts.WIDTH, win_opts.HEIGHT, win_opts.TITLE));

    // invisible cursor
    glfwSetInputMode(win, GLFW_CURSOR, GLFW_CURSOR_DISABLED);

    scene_t scene = make_scene();
    renderer_t renderer = make_renderer(glm::perspective(glm::pi<float>() / 3, win_opts.ASPECT, 0.1f, 100.0f));

	
  
	// // create scene nodes here
	// auto ball_system = scene::node_t{};

	// auto ball1 = scene::node_t{
	// 	shapes::make_sphere(1),
	// 	texture_2d::init("res/textures/brick.png")
	// };

	// auto ball2 = scene::node_t{
	// 	shapes::make_sphere(0.7),
	// 	texture_2d::init("res/textures/brick.png"),
	// 	glm::vec3{3,0,0},
	// };

	// auto ball3 = scene::node_t{
	// 	shapes::make_sphere(0.7),
	// 	texture_2d::init("res/textures/brick.png"),
	// 	glm::vec3{1,0,0} // move 1 from coord of ball2
    // };
	// ball3.scale = (glm::vec3(0.5));

	// ball_system.children.push_back(&ball1);
	// ball_system.children.push_back(&ball2);
	// ball2.children.push_back(&ball3);

	// GLint mvp_loc = chicken3421::get_uniform_location(render_program, "uMVP");
    // glm::mat4 proj = glm::perspective(glm::radians(60.0), (double) width / (double) height, 0.1, 50.0);
    // auto cam = euler_camera::make_camera(glm::vec3(0, 0, 5), glm::vec3(0));



    while (!glfwWindowShouldClose(win)) {
        float dt = time_delta();

        // press esc to exit window
        if(glfwGetKey(win, GLFW_KEY_ESCAPE) == GLFW_PRESS)
                glfwSetWindowShouldClose(win, true);

        update_camera(scene.cam, win, dt);
        update_light(scene, win, dt);


        render(renderer, scene);

		

        // // add animations here
        // ball1.rotation.y += glm::radians(50.0f) * dt;
        // ball2.rotation.y += glm::radians(80.0f) * dt;

        

        glfwSwapBuffers(win);
        glfwPollEvents();

    

        

        // not entirely correct as a frame limiter, but close enough
        // it would be more correct if we knew how much time this frame took to render
        // and calculated the distance to the next "ideal" time to render and only slept that long
        // the current way just always sleeps for 16.67ms, so in theory we'd drop frames
        std::this_thread::sleep_for(std::chrono::duration<float, std::milli>(1000.f / 60));
    }
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