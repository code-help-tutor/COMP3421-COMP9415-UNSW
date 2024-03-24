WeChat: cstutorcs
QQ: 749389476
Email: tutorcs@163.com
#include "../include/static_mesh.hpp"

#include <vector>
#include <iostream>

namespace static_mesh {
    mesh_t init(const mesh_template_t &mesh_template) {
        mesh_t mesh;
        mesh.indices_count = (GLsizei) mesh_template.indices.size();

        glGenVertexArrays(1, &mesh.vao);
        glGenBuffers(1, &mesh.vbo);
        glGenBuffers(1, &mesh.ebo);

        glBindVertexArray(mesh.vao);
        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, mesh.ebo);
        glBufferData(GL_ELEMENT_ARRAY_BUFFER, // target
                     (GLsizeiptr) (mesh_template.indices.size() * sizeof(GLuint)), // num bytes in the data
                     &mesh_template.indices[0], // pointer to the actual data
                     GL_STATIC_DRAW);

        std::vector<float> data;

        for (auto i = size_t{0}; i < mesh_template.positions.size(); ++i) {
            data.push_back(mesh_template.positions[i].x);
            data.push_back(mesh_template.positions[i].y);
            data.push_back(mesh_template.positions[i].z);
        }

        for (auto i = size_t{0}; i < mesh_template.colors.size(); ++i) {
            data.push_back(mesh_template.colors[i].x);
            data.push_back(mesh_template.colors[i].y);
            data.push_back(mesh_template.colors[i].z);
        }

        for (auto i = size_t{0}; i < mesh_template.tex_coords.size(); ++i) {
            data.push_back(mesh_template.tex_coords[i].x);
            data.push_back(mesh_template.tex_coords[i].y);
        }

        // set the GL_ARRAY_BUFFER state to be our mesh.vbo handle
        glBindBuffer(GL_ARRAY_BUFFER, mesh.vbo);
        // create and allocate the actually buffer object in gpu memory for whatever handle is currently
        // bound to GL_ARRAY_BUFFER
        glBufferData(GL_ARRAY_BUFFER, // target
                     (GLsizeiptr) (data.size() * sizeof(float)), // num bytes in the data
                     &data[0], // pointer to the actual data
                     GL_STATIC_DRAW // optimisation hint for frequency of access and nature of access
        );

        glEnableVertexAttribArray(0); // enable attribute to be used for drawing

        glVertexAttribPointer(0, // the layout location this attribute can be found in vertex shader
                              3, // number of components in one attribute
                              GL_FLOAT, // type of each component
                              GL_FALSE, // normalise? - don't normalise the data to -1..1
                              0, // stride - byte offset between same attributes
                              nullptr // offset in bytes to first component of this attribute in the buffer
        );

        GLuint attrib_index = 1;
        size_t offset = mesh_template.positions.size() * sizeof(glm::vec3);

        if (!mesh_template.colors.empty()) {
            glEnableVertexAttribArray(attrib_index);
            glVertexAttribPointer(attrib_index, 3, GL_FLOAT, GL_FALSE, 0, (void *) offset);
            ++attrib_index;
            offset += mesh_template.colors.size() * sizeof(glm::vec3);
        }

        if (!mesh_template.tex_coords.empty()) {
            glEnableVertexAttribArray(attrib_index);
            glVertexAttribPointer(attrib_index, 2, GL_FLOAT, GL_FALSE, 0, (void *) offset);
//            ++attrib_index;
//            offset += mesh_template.tex_coords.size() * sizeof(glm::vec2);
        }

        // unbind the vertex array object so not to accidentally add more info to the vao state
        glBindVertexArray(0);

        return mesh;
    }

    void draw(const mesh_t &mesh, GLenum draw_mode) {
        glBindVertexArray(mesh.vao);
        glDrawElements(draw_mode, mesh.indices_count, GL_UNSIGNED_INT, nullptr);
        glBindVertexArray(0);
    }

    void destroy(const mesh_t &mesh) {
        glDeleteVertexArrays(1, &mesh.vao);
        glDeleteBuffers(1, &mesh.vbo);
        glDeleteBuffers(1, &mesh.ebo);
    }
}
