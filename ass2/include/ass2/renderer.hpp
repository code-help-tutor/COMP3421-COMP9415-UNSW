WeChat: cstutorcs
QQ: 749389476
Email: tutorcs@163.com
#ifndef COMP3421_ASS2_RENDERER_HPP
#define COMP3421_ASS2_RENDERER_HPP

#include <glad/glad.h>
#include <glm/ext.hpp>

#include <ass2/primitives.hpp>
#include <ass2/scene.hpp>


struct renderer_t {
    glm::mat4 projection;

    GLuint program;

    // vs uniforms
    GLint p_loc;
    GLint v_loc;
    GLint m_loc;

    // fs uniforms
    GLint light_pos_loc;
    GLint light_color_loc;
    GLint light_attenuation_loc;
    GLint diff_map_loc;
    GLint spec_map_loc;

    GLint diffuse_loc;
    GLint specular_loc;
    GLint emissive_loc;
    GLint shininess_loc;
};


renderer_t make_renderer(const glm::mat4 &projection);


void draw(const renderer_t &renderer, const glm::mat4 &p, const glm::mat4 &v, const glm::mat4 &m, const model_t &model);


void render(const renderer_t &renderer, const scene_t &scene);

#endif 
