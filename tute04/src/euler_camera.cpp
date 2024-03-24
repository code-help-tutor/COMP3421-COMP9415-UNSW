WeChat: cstutorcs
QQ: 749389476
Email: tutorcs@163.com
#include <glm/glm.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <iostream>
#include <euler_camera.hpp>

namespace euler_camera {
    const float CAMERA_SPEED = 5.0;
    const float MOUSE_SENSITIVITY = 10.0;
    
    camera_t make_camera(glm::vec3 pos, glm::vec3 target) {
        glm::vec3 front = glm::normalize(target - pos);
        // calculate the yaw and pitch from the front vector
        float yaw = glm::degrees(std::atan2(front.x, -front.z));
        float pitch = glm::degrees(std::asin(front.y));
        return {pos, yaw, pitch};
    }

    glm::mat4 get_view(const camera_t &cam) {
        // calculate the rotated coordinate frame
        glm::mat4 yawed = glm::rotate(glm::mat4(1.0), -glm::radians(cam.yaw), glm::vec3(0, 1, 0));
        glm::mat4 pitched = glm::rotate(glm::mat4(1.0), glm::radians(cam.pitch), glm::vec3(1, 0, 0));
        // transpose for inverted transformation
        glm::mat4 view = glm::transpose(yawed * pitched);
        view *= glm::translate(glm::mat4(1.0), -cam.pos);
        return view;
    }

    void update_cam_angles(camera_t &cam, GLFWwindow *win, float dt) {
        double mx, my;
        glfwGetCursorPos(win, &mx, &my);
        static glm::vec2 mouse_prev = {mx, my};
        glm::vec2 mouse_pos = {mx, my};

        glm::vec2 offset = MOUSE_SENSITIVITY * dt * (mouse_pos - mouse_prev);
        offset.y *= -1; // reversed since y-coordinates range from bottom to top
        mouse_prev = mouse_pos;

        cam.yaw += offset.x;
        cam.pitch += offset.y;

        if(cam.pitch > float{89.0}) {
            cam.pitch = float{89.0};
        } else if(cam.pitch < float{-89.0}) {
            cam.pitch = float{-89.0};
        }
    }

    void update_camera(camera_t &cam, GLFWwindow *window, float dt) {
        update_cam_angles(cam, window, dt);
        float step = dt * CAMERA_SPEED;
        glm::mat4 trans = glm::translate(glm::mat4(1.0), -cam.pos);
        trans *= glm::rotate(glm::mat4(1.0), -glm::radians(cam.yaw), glm::vec3(0, 1, 0));
        trans *= glm::rotate(glm::mat4(1.0), glm::radians(cam.pitch), glm::vec3(1, 0, 0));

        auto front = glm::vec3(-trans[2]);
        auto right = glm::vec3(trans[0]);
        auto up = glm::vec3(trans[1]);

        if (glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS) {
            cam.pos += front * step;
        }
        if (glfwGetKey(window, GLFW_KEY_S) == GLFW_PRESS) {
            cam.pos += front * -step;
        }
        if (glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS) {
            cam.pos += right * -step;
        }
        if (glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS) {
            cam.pos += right * step;
        }
        if (glfwGetKey(window, GLFW_KEY_R) == GLFW_PRESS) {
            cam.pos += up * step;
        }
        if (glfwGetKey(window, GLFW_KEY_F) == GLFW_PRESS) {
            cam.pos += up * -step;
        }
    }
}
