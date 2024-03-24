WeChat: cstutorcs
QQ: 749389476
Email: tutorcs@163.com
#ifndef COMP3421_SCENE_OBJECT_HPP
#define COMP3421_SCENE_OBJECT_HPP

#include "static_mesh.hpp"

#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include <glm/ext.hpp>

#include <vector>

namespace scene {
    struct node_t {
        static_mesh::mesh_t mesh;
        GLuint texture = 0;
        glm::vec3 translation = glm::vec3(0.0);
        glm::vec3 rotation = glm::vec3(0.0); // vec3 of euler angles
        glm::vec3 scale = glm::vec3(1.0);
        std::vector<node_t *> children;
    };

    /**
     * Render the given node and its children recursively
     * @param node - the node to render
     * @param parent_mvp - the parent's model view transform
     * @param mvp_loc - the location of the uniform mvp variable in the render program
     */
    void draw(const node_t *node, glm::mat4 view_projection, GLint mvp_loc);

    void destroy(const node_t &node);
}
#endif //COMP3421_SCENE_OBJECT_HPP
