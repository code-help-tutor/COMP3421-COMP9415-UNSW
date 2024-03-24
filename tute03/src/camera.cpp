WeChat: cstutorcs
QQ: 749389476
Email: tutorcs@163.com
#include <cmath>

#include <glm/ext.hpp>

#include <tute03/camera.hpp>

// camera movement speed in units per second
const float CAMERA_SPEED = 2.5f;

camera_t make_camera(glm::vec3 e, glm::vec3 t, glm::vec3 u) {
    return { e, t - e, u, 0, 0 };
}

// explanation on https://learnopengl.com/Getting-started/Camera
// essentially, take the mouse movement as rotations (yaw and pitch) around the y and x axes respectively
void on_mouse_move(GLFWwindow *win, double x, double y) {
    static float xprev = x;
    static float yprev = y;

    float xoffset = 0.1f * (x - xprev);
    float yoffset = 0.1f * (yprev - y); // reversed since y-coordinates range from bottom to top

    xprev = x;
    yprev = y;

    camera_t *c = (camera_t *) glfwGetWindowUserPointer(win);
    float yaw = c->yaw + xoffset;
    float pitch = c->pitch + yoffset;

    float yaw_r = glm::radians(yaw);
    float pitch_r = glm::radians(pitch);
    c->front = glm::normalize(glm::vec3{
            std::cos(yaw_r) * std::cos(pitch_r),
            std::sin(pitch_r),
            std::sin(yaw_r) * std::cos(pitch_r)
    });

    c->pitch = pitch;
    c->yaw = yaw;
}

// move in the direction we're facing
// or orthogonal to it
void update_camera(camera_t &cam, GLFWwindow *window, float dt) {
    glm::vec3 front = cam.front;
    glm::vec3 right = glm::normalize(glm::cross(front, cam.upv));
    float step = dt * CAMERA_SPEED;

    if (glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS) {
        cam.pos += front * step;
    }
    if (glfwGetKey(window, GLFW_KEY_S) == GLFW_PRESS) {
        cam.pos -= front * step;
    }
    if (glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS) {
        cam.pos += right * step;
    }
    if (glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS) {
        cam.pos -= right * step;
    }
}

// create an orthonormal basis via MATHS
glm::mat4 get_view(const camera_t &cam) {
    const glm::vec3 &e = cam.pos, t = cam.pos + cam.front, up = cam.upv;

    auto f = glm::normalize(e - t);
    auto s = glm::normalize(glm::cross(up, f));
    auto u = glm::normalize(glm::cross(f, s));
    auto o = glm::vec3{ -glm::dot(s, e), -glm::dot(u, e), -glm::dot(f, e) };

    return glm::mat4{
            s.x, u.x, f.x, 0,
            s.y, u.y, f.y, 0,
            s.z, u.z, f.z, 0,
            o.x, o.y, o.z, 1
    };
}
