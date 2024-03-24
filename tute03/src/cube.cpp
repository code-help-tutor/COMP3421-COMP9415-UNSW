WeChat: cstutorcs
QQ: 749389476
Email: tutorcs@163.com
// #include <tute03/cube.hpp>
// #include <chicken3421/chicken3421.hpp>

// cube_t make_cube() {
// 	cube_t cube{};
// 	// 8 vertices with their respective colours
//     	std::vector<vertex_t> verts = {
//             {{-1, -1,  1, 1},    {1, 1, 0, 1}}, // 
//             {{ 1, -1,  1, 1},    {0, 1, 0, 1}},
//             {{ 1, -1, -1, 1},    {0, 1, 1, 1}},
//             {{-1, -1, -1, 1},    {1, 1, 1, 1}},

//             {{-1,  1,  1, 1},    {1, 0, 0, 1}},
//             {{ 1,  1,  1, 1},    {0, 0, 0, 1}},
//             {{ 1,  1, -1, 1},    {0, 0, 1, 1}},
//             {{-1,  1, -1, 1},    {1, 0, 1, 1}},

// 	};

// 	// 6 faces * 2 triangles * 3 verts per triangle = 36 indices
//     	std::vector<GLuint> indices = {
//             0, 1, 2,
//             0, 2, 3,

//             4, 0, 5,
//             5, 0, 1,

//             1, 2, 6,
//             1, 6, 5,

//             3, 0, 4,
//             3, 4, 7,

//             4, 5, 6,
//             4, 6, 7,

//             3, 2, 6,
//             3, 6, 7
//     	};
	
// 	cube.vao = chicken3421::make_vao();
// 	glBindVertexArray(cube.vao);

// 	cube.vbo = chicken3421::make_buffer();
// 	glBindBuffer(GL_ARRAY_BUFFER, cube.vbo);
// 	glBufferData(GL_ARRAY_BUFFER, sizeof(vertex_t) * verts.size(), verts.data(), GL_STATIC_DRAW);

// 	cube.indices = indices;

// 	cube.ebo = chicken3421::make_buffer();
// 	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, cube.ebo);
// 	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(GLuint) * indices.size(), indices.data(), GL_STATIC_DRAW);

// 	glVertexAttribPointer(0, 4, GL_FLOAT, GL_FALSE, sizeof(vertex_t), (void *) offsetof(vertex_t, pos));
//     	glVertexAttribPointer(1, 4, GL_FLOAT, GL_FALSE, sizeof(vertex_t), (void *) offsetof(vertex_t, color));

// 	glEnableVertexAttribArray(0);
//     	glEnableVertexAttribArray(1);



// 	return cube;

// }

#include <glm/ext.hpp>

#include <chicken3421/chicken3421.hpp>

#include <tute03/cube.hpp>


cube_t make_cube() {
    // 8 vertices with their respective colours
    std::vector<vertex_t> verts = {
            {{-1, -1,  1, 1},    {1, 1, 0, 1}},
            {{ 1, -1,  1, 1},    {0, 1, 0, 1}},
            {{ 1, -1, -1, 1},    {0, 1, 1, 1}},
            {{-1, -1, -1, 1},    {1, 1, 1, 1}},

            {{-1,  1,  1, 1},    {1, 0, 0, 1}},
            {{ 1,  1,  1, 1},    {0, 0, 0, 1}},
            {{ 1,  1, -1, 1},    {0, 0, 1, 1}},
            {{-1,  1, -1, 1},    {1, 0, 1, 1}},
    };

    // 6 faces * 2 triangles * 3 verts per triangle = 36 indices
    std::vector<GLuint> indices = {
            0, 1, 2,
            0, 2, 3,

            4, 0, 5,
            5, 0, 1,

            1, 2, 6,
            1, 6, 5,

            3, 0, 4,
            3, 4, 7,

            4, 5, 6,
            4, 6, 7,

            3, 2, 6,
            3, 6, 7
    };

    GLuint vao = chicken3421::make_vao();
    glBindVertexArray(vao);

    GLuint vbo = chicken3421::make_buffer();
    glBindBuffer(GL_ARRAY_BUFFER, vbo);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertex_t) * verts.size(), verts.data(), GL_STATIC_DRAW);

    GLuint ebo = chicken3421::make_buffer();
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ebo);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(GLuint) * indices.size(), indices.data(), GL_STATIC_DRAW);

    glVertexAttribPointer(0, 4, GL_FLOAT, GL_FALSE, sizeof(vertex_t), (void *) offsetof(vertex_t, pos));
    glVertexAttribPointer(1, 4, GL_FLOAT, GL_FALSE, sizeof(vertex_t), (void *) offsetof(vertex_t, color));

    glEnableVertexAttribArray(0);
    glEnableVertexAttribArray(1);

    return cube_t{ vao, vbo, ebo, verts, indices, glm::identity<glm::mat4>() };
}

void delete_cube(cube_t &c) {
    chicken3421::delete_buffer(c.ebo);
    chicken3421::delete_buffer(c.vbo);
    chicken3421::delete_vao(c.vao);

    c.ebo = c.vbo = c.vao = 0;
    c.indices.clear();
    c.vertices.clear();
}
