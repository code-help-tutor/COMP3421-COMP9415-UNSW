WeChat: cstutorcs
QQ: 749389476
Email: tutorcs@163.com
#include <cstdlib>
#include <iostream>
#include <vector>

#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>

#include <chicken3421/chicken3421.hpp>

struct vertex_t {
    glm::vec3 pos;
};

struct mesh_t {
    GLuint vao;
    GLuint vbo;
    std::vector<vertex_t> vertices;
};

const int SCR_WIDTH = 800;
const int SCR_HEIGHT = 600;

const char *WIN_TITLE = "Hello Triangle";
const char *VERT_PATH = "res/shaders/shader.vert";
const char *FRAG_PATH = "res/shaders/shader.frag";

namespace {
    /**
     *
     * Creates a new window with the given width, height, and title.
     *
     * @param width: Screen width in pixels
     * @param height: Screen height in pixels
     * @param title: The title for the window
     * @return A valid GLFWwindow pointer or null if window creation failed
     */
    GLFWwindow *make_window(int width, int height, const std::string &title) {
        glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
        glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
        glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    #ifdef _APPLE_
        glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
    #endif
        auto window = glfwCreateWindow(width, height, title.data(), nullptr, nullptr);
        return window;
    }

    /**
     *
     * Given a valid GLFWwindow pointer, makes this window's OpenGL context current and loads the Glad function pointers into it
     *
     * @param win: A valid GLFWwindow pointer
     * @return True if there was no error, false if there was.
     */
    bool make_opengl_context(GLFWwindow *win) {
        glfwMakeContextCurrent(win);

        const GLADloadproc proc_address_fn = (GLADloadproc)glfwGetProcAddress;

        return gladLoadGLLoader(proc_address_fn);
    }

    /**
     *
     * Reads in the shader source code in `path` and creates a new shader object of type `shader-type`
     *
     * @param path: filesystem path to the shader
     * @param shader_type: one of GL_VERTEX_SHADER, GL_FRAGMENT_SHADER
     * @return A handle to the new shader object
     */
    GLuint make_shader(const std::string &path, GLenum shader_type) {
        const std::string shader_src = chicken3421::read_file(path);
        const char *src_arr = shader_src.data();

        GLuint shader = glCreateShader(shader_type);
        glShaderSource(shader, 1, &src_arr, nullptr);

        glCompileShader(shader);
        return shader;
    }


    /**
     *
     * Creates a new program with the given shaders.
     *
     * @param shader_ids: A list of the shaders to attach and link.
     * @return A handle to the program object
     */
    GLuint make_program(const std::vector<GLuint> &shader_ids) {
        GLuint program = glCreateProgram();

        for (const GLuint &shader : shader_ids) {
            glAttachShader(program, shader);
        }
        glLinkProgram(program);
        return program;
    }


    /**
     *
     * Cleans up a shader object and releases the resources
     *
     * @param shader: The shader to delete
     */
    void delete_shader(GLuint shader) {
        glDeleteShader(shader);
    }


    /**
     *
     * Creates a triangle mesh and sets up the corresponding VAO and VBO objects needed to render.
     *
     * @return A struct containing the vertices, a handle to the VAO object, and a handle to the VBO object
     */
    mesh_t make_mesh() {
        std::vector<vertex_t> verts = {
            {{0.0F, 0.0F, 0.0F}},
            {{1.0F, 0.0F, 0.0F}}, 
            {{0.0F, 1.0F, 0.0F}},
         };

        GLuint vbo;
        glGenBuffers(1, &vbo);

        GLuint vao;
        glGenVertexArrays(1, &vao);

        glBindVertexArray(vao);
        glBindBuffer(GL_ARRAY_BUFFER, vbo);

        glBufferData(GL_ARRAY_BUFFER, static_cast<GLintptr>(verts.size() * sizeof(vertex_t)), &verts[0], 
        GL_STATIC_DRAW);

        glEnableVertexAttribArray(0);
        glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(vertex_t), nullptr);

        return {.vao = vao, .vbo = vbo, .vertices = std::move(verts)};
    }


    /**
     *
     * The rendering function.
     * Draws the mesh as GL_TRIANGLES with the given rendering program `program`.
     *
     * @param mesh: The given mesh to draw
     * @param program: The rendering program to use
     */
    void render(const mesh_t &mesh, GLuint program) {
        glClearColor(0.2f, 0.2f, 0.3f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        glUseProgram(program);

        glBindVertexArray(mesh.vao);
        glDrawArrays(GL_TRIANGLES, 0, static_cast<GLint>(mesh.vertices.size()));
        glBindVertexArray(0);
    }
}


int main() {
    // TODO: Step 1
    auto success = glfwInit();
    if (!success) {
        std::cerr << "Could not initialise GLFW.\n";
        glfwTerminate();
        return EXIT_FAILURE;
    }

    // TODO: Step 2
    auto window = make_window(SCR_WIDTH, SCR_HEIGHT, WIN_TITLE);
    if (!window) {
        std::cerr << "Failed to create GLFW window.\n";
        glfwTerminate();
        return EXIT_FAILURE;
    }

    // TODO: Step 3
    success = make_opengl_context(window);
    if (!success) {
        std::cerr << "Failed to load OpenGL with Glad.\n";
        glfwTerminate();
        return EXIT_FAILURE;
    }

    // TODO: Step 4
    const auto shaders = std::vector<GLuint>{
            make_shader(VERT_PATH, GL_VERTEX_SHADER),
            make_shader(FRAG_PATH, GL_FRAGMENT_SHADER)
    };

    // TODO: Step 5
    const auto render_program = make_program(shaders);

    // TODO: Step 5.5
    delete_shader(shaders[0]);
    delete_shader(shaders[1]);

    // TODO: Step 6
    auto mesh = make_mesh();

    while (!glfwWindowShouldClose(window)) {
        glfwPollEvents();

        // TODO: Step 7
        render(mesh, render_program);

        glfwSwapBuffers(window);
    }

    glfwTerminate();

    return EXIT_SUCCESS;
}
