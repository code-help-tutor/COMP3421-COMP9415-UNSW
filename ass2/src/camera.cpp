WeChat: cstutorcs
QQ: 749389476
Email: tutorcs@163.com
#include <glm/glm.hpp>
#include <glm/ext.hpp>

#include <ass2/camera.hpp>

namespace {
    const float CAMERA_SPEED = 10.f;
    const float INVERT_X = -1.f;
    const float INVERT_Y = 1.f;

    glm::vec3 sidev(float p, float y) {
        auto cy = std::cos(y);
        auto sy = std::sin(y);

        return glm::normalize(glm::vec3{ cy, 0, -sy });
    }

    glm::vec3 upv(float p, float y) {
        auto cp = std::cos(p);
        auto cy = std::cos(y);
        auto sp = std::sin(p);
        auto sy = std::sin(y);

        return glm::normalize(glm::vec3{ -sp * sy, cp, -cy * sp });
    }

    glm::vec3 frontv(float p, float y) {
        auto cp = std::cos(p);
        auto cy = std::cos(y);
        auto sp = std::sin(p);
        auto sy = std::sin(y);

        return glm::normalize(glm::vec3{ cp * sy, sp, cy * cp });
    }

    void update_cam_angles(camera_t &cam, GLFWwindow *win, float dt) {
        glm::dvec2 ms_pos;
        glfwGetCursorPos(win, &ms_pos[0], &ms_pos[1]);

        static glm::vec2 prev_pos = ms_pos;

        glm::vec2 delta = glm::radians(glm::vec2(ms_pos) - prev_pos);

        prev_pos = ms_pos;

        cam.yaw += INVERT_X * 1/CAMERA_SPEED * delta.x;
        cam.pitch += INVERT_Y * 1/CAMERA_SPEED * delta.y;
    }

    void update_cam_pos(camera_t &cam, GLFWwindow *win, float dt) {
        auto front = -frontv(cam.pitch, cam.yaw);
        auto right = sidev(cam.pitch, cam.yaw);
        float step = dt * CAMERA_SPEED;

        if (glfwGetKey(win, GLFW_KEY_W) == GLFW_PRESS) {
            cam.pos += front * step;
        }
        if (glfwGetKey(win, GLFW_KEY_S) == GLFW_PRESS) {
            cam.pos -= front * step;
        }
        if (glfwGetKey(win, GLFW_KEY_D) == GLFW_PRESS) {
            cam.pos += right * step;
        }
        if (glfwGetKey(win, GLFW_KEY_A) == GLFW_PRESS) {
            cam.pos -= right * step;
        }
    }

}

camera_t make_camera(glm::vec3 pos, glm::vec3 target) {
    glm::vec3 front = glm::normalize(target - pos);

    // calculate the yaw and pitch from the front vector
    // pretty sure there's a bug here
    float yaw = -std::atan2(front.x, -front.z);
    float pitch = -std::asin(front.y);

    return { pos, yaw, pitch };
}

void delete_camera(camera_t &c) {
    // nothing to do as this is a trivially destructible type
    (void)c;
}


void update_camera(camera_t &cam, GLFWwindow *window, float dt) {
    update_cam_angles(cam, window, dt);
    update_cam_pos(cam, window, dt);
}

glm::mat4 get_view(const camera_t &cam) {
    auto s = sidev(cam.pitch, cam.yaw);
    auto u = upv(cam.pitch, cam.yaw);
    auto f = frontv(cam.pitch, cam.yaw);
    auto o = glm::vec3(-glm::dot(cam.pos, s), -glm::dot(cam.pos, u), -glm::dot(cam.pos, f));
    auto view = glm::mat4{
            s.x, u.x, f.x, 0,
            s.y, u.y, f.y, 0,
            s.z, u.z, f.z, 0,
            o.x, o.y, o.z, 1
    };

    return view;
}
