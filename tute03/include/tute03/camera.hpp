WeChat: cstutorcs
QQ: 749389476
Email: tutorcs@163.com
#ifndef COMP3421_TUTORIAL_03_CAMERA_HPP
#define COMP3421_TUTORIAL_03_CAMERA_HPP

#include <GLFW/glfw3.h>
#include <glm/glm.hpp>

// struct camera_t {
//    // TODO part 2: add whatever you need to make this work.
//    glm::vec3 pos;
//     glm::vec3 front;
//     glm::vec3 up;

//     float pitch;
//     float yaw;

// };

// // TODO: Part 2. Add whatever you need to make this work.
// camera_t make_camera(glm::vec3 pos, glm::vec3 front, glm::vec3 up = {0,1,0});

struct camera_t {
    glm::vec3 pos;
    glm::vec3 front;
    glm::vec3 upv;

    float pitch;
    float yaw;
};

camera_t make_camera(glm::vec3 e, glm::vec3 t, glm::vec3 up = { 0, 1, 0});

void on_mouse_move(GLFWwindow *win, double x, double y);

void update_camera(camera_t &cam, GLFWwindow *window, float dt);

glm::mat4 get_view(const camera_t &cam);


#endif //COMP3421_TUTORIAL_03_CAMERA_HPP
