WeChat: cstutorcs
QQ: 749389476
Email: tutorcs@163.com
// C++20 has a standard `pi` value, but we're not using C++20...
#define _USE_MATH_DEFINES
#include <cmath>

#include <cstdlib>
#include <string>

#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <glm/glm.hpp>

// These are very useful headers when working with GLM types
#include <glm/ext/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include <stb/stb_image.h>

#include <chicken3421/chicken3421.hpp>

/* Start helpers */

struct image_t {
    int width;
    int height;
    int n_channels;
    void *data;
};

image_t load_image(const std::string &filename) {
    image_t img; // NOLINT(cppcoreguidelines-pro-type-member-init)

    stbi_set_flip_vertically_on_load(true);
    img.data = stbi_load(filename.data(), &img.width, &img.height, &img.n_channels, 0);

    chicken3421::expect(img.data, "Could not read " + filename);

    return img;
}

void delete_image(image_t &img) {
    stbi_image_free(img.data);

    img.data = nullptr;
    img.width = 0;
    img.height = 0;
    img.n_channels = 0;
}

GLuint make_texture(const image_t &tex_img) {
    GLint format = tex_img.n_channels == 3 ? GL_RGB : GL_RGBA; // assuming that if not 3 channels then 4

    GLuint tex;
    glGenTextures(1, &tex);

    glBindTexture(GL_TEXTURE_2D, tex);
    glTexImage2D(GL_TEXTURE_2D, 0, format, tex_img.width, tex_img.height, 0, format, GL_UNSIGNED_BYTE, tex_img.data);

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_MIRRORED_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_MIRRORED_REPEAT);

    glBindTexture(GL_TEXTURE_2D, 0);

    return tex;
}

void delete_texture(GLuint tex) {
    glDeleteTextures(1, &tex);
}

GLint get_uniform_location(GLuint program, const std::string &name) {
    GLint loc = glGetUniformLocation(program, name.data());
    chicken3421::expect(loc != -1, "No uniform variable named: " + name + "in program: " + std::to_string(loc));
    return loc;
}

/* End Helpers */


struct circle_t {
    GLuint vao = 0;
    GLuint vbo = 0;
    GLsizeiptr n_verts = 0;

    std::vector<glm::vec4> positions;
    std::vector<glm::vec2> tcs;

    // TODO: Add transformational stuff here
    glm::mat4 translate = glm::mat4{1};
    glm::mat4 rotate = glm::mat4{1};
    glm::mat4 scale = glm::mat4{1};


};

/**
 *
 * A Circle is drawn as a triangle fan.
 * The first point is the center, and every point thereafter is on the perimeter of the circle.
 *
 * @param cx: center's x coordinate
 * @param cy: center's y coordinate
 * @param r: radius
 * @param detail: how many sides the circle approximation should have
 * @return: a circle mesh
 */
circle_t make_circle(float cx, float cy, float r, int detail = 32) {
    circle_t c;

    c.positions.emplace_back(cx, cy, 0, 1);
    c.tcs.emplace_back(0.5f, 0.5f);
    c.n_verts++;

    float slice = 2 * M_PI/detail;
    for (int i = 0; i <= detail; ++i) {
        float theta = i * slice;
        float x = cx + r * std::cos(theta);
        float y = cy + r * std::sin(theta);

        float tx = (x/r + 1) * 0.5f;
        float ty = (y/r + 1) * 0.5f;

        c.positions.emplace_back(x, y, 0, 1);
        c.tcs.emplace_back(tx, ty);
        c.n_verts++;
    }

    glGenVertexArrays(1, &c.vao);
    glGenBuffers(1, &c.vbo);

    glBindVertexArray(c.vao);
    glBindBuffer(GL_ARRAY_BUFFER, c.vbo);

    glBufferData(GL_ARRAY_BUFFER, c.n_verts * (sizeof(glm::vec4) + sizeof(glm::vec2)), nullptr, GL_STATIC_DRAW);

    glBufferSubData(GL_ARRAY_BUFFER, 0, c.n_verts * sizeof(glm::vec4), c.positions.data());
    glBufferSubData(GL_ARRAY_BUFFER, c.n_verts * sizeof(glm::vec4), c.n_verts * sizeof(glm::vec2), c.tcs.data());

    glVertexAttribPointer(0, 4, GL_FLOAT, GL_FALSE, 0, nullptr);
    glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 0, (const GLvoid *)(c.n_verts * sizeof(glm::vec4)));

    glEnableVertexAttribArray(0);
    glEnableVertexAttribArray(1);

    glBindVertexArray(0);
    glBindBuffer(GL_ARRAY_BUFFER, 0);

    return c;
}

void delete_circle(circle_t &c) {
    c.positions.clear();
    c.tcs.clear();
    glDeleteBuffers(1, &c.vbo);
    glDeleteVertexArrays(1, &c.vao);
}


// TODO: fill these in
void on_key_press(GLFWwindow *win, int key, int scancode, int action, int mods) {
    auto mesh = (circle_t * )glfwGetWindowUserPointer(win);
    switch (key) {
        case GLFW_KEY_W:
            mesh->translate = glm::translate(mesh->translate, glm::vec3{0, 0.1, 0});
            break;
        case GLFW_KEY_S:
            mesh->translate = glm::translate(mesh->translate, glm::vec3{0, -0.1, 0});
            break;
        case GLFW_KEY_A:
            mesh->translate = glm::translate(mesh->translate, glm::vec3{-0.1, 0, 0});
            break;
        case GLFW_KEY_D:
            mesh->translate = glm::translate(mesh->translate, glm::vec3{0.1, 0, 0});
            break;
        case GLFW_KEY_Q:
            mesh->rotate = glm::rotate(mesh->rotate, glm::radians(10.0f), glm::vec3{0, 0, 1});
            break;
        case GLFW_KEY_E:
            mesh->rotate = glm::rotate(mesh->rotate, glm::radians(-10.0f), glm::vec3{0, 0, 1});
            break;
        default:
            break;

    }
}

void on_mouse_scroll(GLFWwindow *win, double dx, double dy) {
    auto mesh = (circle_t * ) glfwGetWindowUserPointer(win);
    auto scale = dy < 0 ? 0.9 : 1.1;
    mesh->scale = glm::scale(mesh->scale, glm::vec3{scale, scale, 0});
}

void on_mouse_click(GLFWwindow *win, int button, int action, int mods) {
    auto mesh = (circle_t *)glfwGetWindowUserPointer(win);
    mesh->translate = glm::mat4{1};
    mesh->rotate = glm::mat4{1};
    mesh->scale = glm::mat4{1};
}


int main() {
    // set-up
    GLFWwindow *win = chicken3421::make_opengl_window(800, 800, "Simple Transforms");

    GLuint vs = chicken3421::make_shader("res/shaders/simple_transforms/vert.glsl", GL_VERTEX_SHADER);
    GLuint fs = chicken3421::make_shader("res/shaders/simple_transforms/frag.glsl", GL_FRAGMENT_SHADER);
    GLuint program = chicken3421::make_program(vs, fs);
    image_t emoji = load_image("res/img/emoji512.png");
    GLuint tex = make_texture(emoji);

    circle_t mesh = make_circle(0, 0, 0.5);

    // TODO: callback set-up
    glfwSetWindowUserPointer(win, &mesh);
    glfwSetKeyCallback(win, on_key_press);
    glfwSetScrollCallback(win, on_mouse_scroll);
    glfwSetMouseButtonCallback(win, on_mouse_click);

    while(!glfwWindowShouldClose(win)) {
        glfwPollEvents();

        glUseProgram(program);
        glBindVertexArray(mesh.vao);
        glBindBuffer(GL_ARRAY_BUFFER, mesh.vbo);
        glBindTexture(GL_TEXTURE_2D, tex);

        glClear(GL_COLOR_BUFFER_BIT);
        glClearColor(0, 0, 1, 1);

        glUniformMatrix4fv(glGetUniformLocation(program, "transform"), 1, GL_FALSE, glm::value_ptr(mesh.translate * mesh.scale * mesh.rotate));

        glDrawArrays(GL_TRIANGLE_FAN, 0, mesh.n_verts);

        glBindVertexArray(0);
        glBindBuffer(GL_ARRAY_BUFFER, 0);
        glBindTexture(GL_TEXTURE_2D, 0);
        glUseProgram(0);

        glfwSwapBuffers(win);
    }


    // Tear-down
    delete_circle(mesh);
    delete_texture(tex);
    delete_image(emoji);
    chicken3421::delete_program(program);
    chicken3421::delete_shader(fs);
    chicken3421::delete_shader(vs);
    glfwDestroyWindow(win);

    return EXIT_SUCCESS;
}