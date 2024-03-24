WeChat: cstutorcs
QQ: 749389476
Email: tutorcs@163.com
#ifndef COMP3421_ASS2_SCENE_HPP
#define COMP3421_ASS2_SCENE_HPP

#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include <glm/ext.hpp>

#include <vector>
#include <ass2/camera.hpp>
#include <ass2/light.hpp>
#include <ass2/primitives.hpp>

struct node_t {
    /**
     * The different types of models in our scene.
     */
    enum {
        CUBE,
        SPHERE,
        GROUND,
        LIGHT_MESH
    } kind;
    model_t obj;
    glm::mat4 transform;
    std::vector<node_t> children;
};

struct scene_t {
    camera_t cam;

    point_light_t point_light;

    node_t root;
};

scene_t make_scene();

#endif 
