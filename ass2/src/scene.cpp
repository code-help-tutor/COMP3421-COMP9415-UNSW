WeChat: cstutorcs
QQ: 749389476
Email: tutorcs@163.com
#include <ass2/scene.hpp>

scene_t make_scene() {
    camera_t cam = make_camera({ 0, 1.1f, -5 }, { 0, 0, 0 });

    node_t cube = {
            node_t::CUBE,
            make_volume(
                    { 1, 1, 1 },
                    { "res/textures/volume/bricks_diff.jpg", "res/textures/volume/bricks_spec.jpg" }
            ),
            glm::translate(glm::mat4(1), { 0, 1.1f, 0 }),
            { }
    };

    node_t earth = {
            node_t::SPHERE,
            make_sphere(
                    { 16, 16 },
                    { "res/textures/earth.jpg", "res/textures/sphere/gold_spec.jpg" }
            ),
            glm::translate(glm::mat4(1), { -2.0f, 2.1f, 0 }),
            { }
    };

    node_t sphere = {
            node_t::SPHERE,
            make_sphere(
                    { 16, 16 },
                    { "res/textures/sphere/gold_diff.jpg", "res/textures/sphere/gold_spec.jpg" }
            ),
            glm::translate(glm::mat4(1), { 5.0f, 2.1f, 0 }),
            { earth}
    };


    material_param_t mtl_light_mesh;
    mtl_light_mesh.emissive = glm::vec3(1, 1, 1);
    node_t light_mesh = {
            node_t::LIGHT_MESH,
            make_sphere(
                    { 4, 4 },
                    mtl_light_mesh
            ),
            glm::translate(glm::mat4(1), { 0, 5, 0 })
            * glm::scale(glm::mat4(1), { 0.1, 0.1, 0.1 }),
            { }
    };

    node_t ground = {
            node_t::GROUND,
            make_volume(
                    { 100, 0, 100 },
                    { "res/textures/ground/grass_diff.jpg", "res/textures/ground/grass_spec.jpg" }
            ),
            glm::mat4(1),
            { cube, sphere, light_mesh }
    };

    point_light_t light = {
            glm::vec3{ 0, 5, 0 },
            glm::vec3{ 1, 0.95, 0.9 },
            0.3
    };

    return scene_t{ cam, light, ground };
}
