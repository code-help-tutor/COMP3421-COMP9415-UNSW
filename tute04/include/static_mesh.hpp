WeChat: cstutorcs
QQ: 749389476
Email: tutorcs@163.com
#ifndef STATIC_MESH_H
#define STATIC_MESH_H

#include <glad/glad.h>
#include <glm/glm.hpp>
#include <string>
#include <vector>

namespace static_mesh {
    // mesh_t contains only the essential data required to draw the mesh as well as to destroy it
    struct mesh_t {
        GLuint vao = 0;
        GLuint vbo = 0;
        GLuint ebo = 0;
        GLsizei indices_count = 0;
    };

    // mesh_template_t contains potentially mesh attributes - to be used on initialisation only
    struct mesh_template_t {
    public:
        std::vector<glm::vec3> positions;
        std::vector<glm::vec3> colors;
        std::vector<glm::vec2> tex_coords;
        std::vector<GLuint> indices;
    };

    /**
     * Free up all the data used by the mesh
     * @param mesh
     */
    void destroy(mesh_t const &mesh);

    /**
     * Register a buffer with the current OpenGL for the given mesh template
     * @param mesh_template - bloated struct of potential mesh attribute data (to be used on initialisation only)
     * @return
     */
    mesh_t init(mesh_template_t const &mesh_template);

    /**
     * Draw's the mesh using glDrawElements with draw_mode
     * @param mesh
     * @param draw_mode
     */
    void draw(mesh_t const &mesh, GLenum draw_mode = GL_TRIANGLES);
}

#endif
