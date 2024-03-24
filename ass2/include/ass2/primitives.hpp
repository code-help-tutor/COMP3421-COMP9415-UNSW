WeChat: cstutorcs
QQ: 749389476
Email: tutorcs@163.com
#ifndef COMP3421_ASS2_PRIMITIVES_HPP
#define COMP3421_ASS2_PRIMITIVES_HPP

#include <glad/glad.h>

#include <glm/ext.hpp>

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
    glm::vec3 diffuse;
    glm::vec3 specular;
    glm::vec3 emissive;
    float shininess;
    GLuint diff_map;
    GLuint spec_map;
};

struct model_t {
    mesh_t mesh;
    material_t material;
};

struct material_param_t {
    std::string diff_map_path;
    std::string spec_map_path;

    glm::vec3 diffuse = glm::vec3(1, 1, 1);
    glm::vec3 specular = glm::vec3(1, 1, 1);
    glm::vec3 emissive = glm::vec3(0, 0, 0);
    float shininess = 16;
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


model_t make_volume(const volume_param_t &geo_params, const material_param_t &mat_params);

model_t make_sphere(const sphere_param_t &geo_params, const material_param_t &mat_params);



#endif 