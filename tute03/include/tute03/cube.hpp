WeChat: cstutorcs
QQ: 749389476
Email: tutorcs@163.com
#ifndef COMP3421_TUTORIAL_03_CUBE_HPP
#define COMP3421_TUTORIAL_03_CUBE_HPP

#include <vector>

#include <glad/glad.h>

#include <glm/glm.hpp>

// struct vertex_t {
//     glm::vec4 pos;
//     glm::vec4 color;
// };

// struct cube_t {
//     GLuint vao;
//     GLuint vbo;
//     GLuint ebo;

//     std::vector<vertex_t> verts;

//     std::vector<GLuint> indices;

//     glm::mat4 transform;

// };

// // TODO: Part 1. Add whatever you need to make this return a renderable cube
// cube_t make_cube();

struct vertex_t {
    glm::vec4 pos;
    glm::vec4 color;
};

struct cube_t {
    GLuint vao;
    GLuint vbo;
    GLuint ebo;

    std::vector<vertex_t> vertices;

    std::vector<GLuint> indices;

    glm::mat4 transform;
};


cube_t make_cube();

void delete_cube(cube_t &c);


#endif //COMP3421_TUTORIAL_03_CUBE_HPP
