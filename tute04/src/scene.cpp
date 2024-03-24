WeChat: cstutorcs
QQ: 749389476
Email: tutorcs@163.com
#include "scene.hpp"
#include "texture_2d.hpp"


namespace scene {
    void draw(const node_t *node,  glm::mat4 view_projection, GLint mvp_loc) {
        // TODO: implement this function
        view_projection = glm::translate(view_projection, node->translation);
        view_projection = glm::rotate(view_projection, node->rotation.x, glm::vec3{1,0,0});
        view_projection = glm::rotate(view_projection, node->rotation.y, glm::vec3{0,1,0});
        view_projection = glm::rotate(view_projection, node->rotation.z, glm::vec3{0,0,1});
        view_projection = glm::scale(view_projection, node->scale);
        glUniformMatrix4fv(mvp_loc, 1, GL_FALSE, glm::value_ptr(view_projection));
        texture_2d::bind(node->texture);
        static_mesh::draw(node->mesh);
        for(auto && child : node->children) {
            draw(child, view_projection, mvp_loc);
        }
    }

    void destroy(const node_t &node) {
        static_mesh::destroy(node.mesh);
        texture_2d::destroy(node.texture);
    }

}
