WeChat: cstutorcs
QQ: 749389476
Email: tutorcs@163.com
#include <tute07/scene.hpp>

// TODO: add something here?
scene_t make_scene() {
    camera_t cam = make_camera({ 0, 1.1f, -5 }, { 0, 0, 0 });

    node_t cube = {
            node_t::CUBE,
            make_volume({ 1, 1, 1 }, { "res/textures/volume/bricks.jpg" }),
            glm::translate(glm::mat4(1), { 0, 1.1f, 0 }),
            { }
    };

    node_t sphere = {
            node_t::SPHERE,
            make_sphere({ 16, 16 }, { "res/textures/sphere/gold.jpg" }),
            glm::translate(glm::mat4(1), { -2.5, 1.1f, 0 }),
            { }
    };

    node_t torus = {
            node_t::TORUS,
            make_torus({ 0.5f, 1.f, 32 }, { "res/textures/torus/marble.jpg" }),
            glm::translate(glm::mat4(1), { 2.5f, 1.1f, 0 })
            * glm::rotate(glm::mat4(1), glm::pi<float>() / 2, { 0, 1, 0 })
            * glm::rotate(glm::mat4(1), glm::pi<float>() / 2, { 0, 0, 1 }),
            { }
    };

    node_t ground = {
            node_t::GROUND,
            make_volume({ 100, 0, 100 }, { "res/textures/ground/grass.jpg" }),
            glm::mat4(1),
            { cube, sphere, torus }
    };

    return scene_t{ cam, ground };
}