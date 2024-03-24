WeChat: cstutorcs
QQ: 749389476
Email: tutorcs@163.com
#ifndef COMP3421_TUTORIAL_07_PRIMITIVES_HPP
#define COMP3421_TUTORIAL_07_PRIMITIVES_HPP

#include <glad/glad.h>

#include <string>
#include <vector>

using index_t = GLuint;
const GLenum index_type = GL_UNSIGNED_INT;

struct mesh_t {
    GLuint vao;
    GLuint vbo;
    GLuint ibo;
    std::size_t nverts;
};

struct material_t {
    GLuint diff_map;
};

struct model_t {
    mesh_t mesh;
    material_t material;
};

struct material_param_t {
    std::string diff_map_path;
};

struct volume_param_t {
    float width = 1;
    float height = 1;
    float depth = 1;
};

struct sphere_param_t {
    int slices = 16;
    int stacks = 16;
};

struct torus_param_t {
    float inner_r = 0.f;
    float outer_r = 1.f;
    int lod = 16;
};

// TODO: modify this
model_t make_volume(const volume_param_t &geo_params, const material_param_t &mat_params);

// TODO: modify this
model_t make_sphere(const sphere_param_t &geo_params, const material_param_t &mat_params);

// TODO: modify this
model_t make_torus(const torus_param_t &geo_params, const material_param_t &mat_params);


#endif //COMP3421_TUTORIAL_07_PRIMITIVES_HPP
