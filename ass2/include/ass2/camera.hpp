WeChat: cstutorcs
QQ: 749389476
Email: tutorcs@163.com
#ifndef COMP3421_ASS2_CAMERA_HPP
#define COMP3421_ASS2_CAMERA_HPP

#include <glm/glm.hpp>
#include <GLFW/glfw3.h>


struct camera_t {
    glm::vec3 pos;

    float yaw;
    float pitch;
};


camera_t make_camera(glm::vec3 pos, glm::vec3 target);


void delete_camera(camera_t &c);


void update_camera(camera_t &cam, GLFWwindow *window, float dt);


glm::mat4 get_view(const camera_t &cam);

#endif 