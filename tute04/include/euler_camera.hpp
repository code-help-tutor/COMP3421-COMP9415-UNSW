WeChat: cstutorcs
QQ: 749389476
Email: tutorcs@163.com
#ifndef COMP3421_OPENGL_PRACTICE_EULER_CAMERA_HPP
#define COMP3421_OPENGL_PRACTICE_EULER_CAMERA_HPP

#include <GLFW/glfw3.h>

#include <glm/glm.hpp>
#include <GLFW/glfw3.h>

namespace euler_camera {

    struct camera_t {
        glm::vec3 pos;
        float yaw;
        float pitch;
    };

    /**
     *
     * @param pos - position of the camera
     * @param target - point in word space the camera is looking at
     * @return initialised camera_t struct
     */
    camera_t make_camera(glm::vec3 pos, glm::vec3 target);

    /**
     * Get the view matrix of the camera (aka inverse transformation of cam)
     * @param cam - camera data
     * @return - view matrix
     */
    glm::mat4 get_view(const camera_t &cam);

    /**
     * Update the camera's position on wasd keys as well as the direction the camera's facing based on cursor movement
     * @param cam - cam info
     * @param window - glfw window
     * @param dt - delta time
     */
    void update_camera(camera_t &cam, GLFWwindow *window, float dt);

}

#endif //COMP3421_OPENGL_PRACTICE_EULER_CAMERA_HPP
