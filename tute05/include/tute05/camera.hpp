WeChat: cstutorcs
QQ: 749389476
Email: tutorcs@163.com
#ifndef COMP3421_TUTORIAL_05_CAMERA_HPP
#define COMP3421_TUTORIAL_05_CAMERA_HPP


#include <glm/glm.hpp>
#include <GLFW/glfw3.h>

/**
 * A classic Euler-angle camera
 * Quite unremarkable
 */
struct camera_t {
    glm::vec3 pos;

    float yaw;
    float pitch;
};

/**
 * Create a new camera at pos looking toward target
 *
 * @param pos The position of the camera
 * @param target What the camera is looking at
 * @return A new camera positioned at position, looking at target.
 */
camera_t make_camera(glm::vec3 pos, glm::vec3 target);

/**
 * Destroys the camera "c".
 *
 * Does nothing since camera_t is a trivial type and holds no resources
 *
 * @param c The camera to destroy.
 */
void delete_camera(camera_t &c);

/**
 * Update the position and/or target based on user input.
 *
 * The position is modified by WASD in the usual FPS manner.
 * Where the camera is looking is modified by moving the mouse.
 *
 * @param cam The camera to update
 * @param window The active window that is receiving user input
 * @param dt How much time has passed since the last frame was drawn
 */
void update_camera(camera_t &cam, GLFWwindow *window, float dt);

/**
 * Get the view matrix of this camera.
 *
 * The view matrix is an inverse transform that takes points in world space and moves them into the camera's space.
 * Effectively, moves the world "into" the camera's eye.
 *
 * @param cam The camera whose view we're interested in.
 * @return A 4x4 matrix that moves world-space coordinates into camera-space
 */
glm::mat4 get_view(const camera_t &cam);


#endif // COMP3421_TUTORIAL_05_CAMERA_HPP