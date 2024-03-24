WeChat: cstutorcs
QQ: 749389476
Email: tutorcs@163.com
#ifndef COMP3421_TUTORIAL_08_RENDERER_HPP
#define COMP3421_TUTORIAL_08_RENDERER_HPP

#include <glad/glad.h>
#include <glm/ext.hpp>

#include <tute08/primitives.hpp>
#include <tute08/scene.hpp>

/**
 * A simple bag of all the OpenGL rendering bits we've used up until now.
 */
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

/**
 * Initialise our renderer.
 *
 * Inside of this we can load shaders, grab uniform locations, etc.
 * Of course, if we have different shaders, it is conceivable we would have different capabilities enabled/disabled too.
 * Whatever doesn't change can be initialised here, then.
 *
 * @param projection The projection matrix to use (almost always a perspective transform)
 * @return The renderer.
 */
renderer_t make_renderer(const glm::mat4 &projection);

/**
 * Draws the current node "m".
 *
 * @param renderer The rendering context gotten from make_renderer()
 * @param p The Projection matrix
 * @param v The view matrix
 * @param m The model matrix
 * @param model The model to draw.
 */
void draw(const renderer_t &renderer, const glm::mat4 &p, const glm::mat4 &v, const glm::mat4 &m, const model_t &model);

/**
 * Renders the current scene specified by scene.
 *
 * Starting at the root of the scenegraph, this function will "recursively" descend the scenegraph and draw all nodes.
 * Nothing is modified except the OpenGL context.
 *
 * @param renderer the rendering context gotten from make_renderer()
 * @param scene the scene to draw.
 */
void render(const renderer_t &renderer, const scene_t &scene);

#endif //COMP3421_TUTORIAL_08_RENDERER_HPP
