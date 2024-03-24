WeChat: cstutorcs
QQ: 749389476
Email: tutorcs@163.com
#include <cstdlib>
#include <iostream>
#include <vector>

#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include <stb/stb_image.h>

#include "shaderClass.h"
#include "VBO.h"
#include "VAO.h"
#include "EBO.h"
#include "header.hpp"

using namespace std;

// const char* vertexShaderSource = "#version 330 core\n"
// "layout (location = 0) in vec3 vert_pos;\n"

// "void main() {\n"
// "    gl_Position = vec4(vert_pos, 1.0f);\n"
// "}\0";

// const char* fragmentShaderSource = "#version 330 core\n"

// "out vec4 FragColor;\n"

// "void main() {\n"
// "    FragColor = vec4(1.0f, 0.0f, 0.0f, 1.0f);\n"
// "}\n\0";


// struct vertex_t {
//     glm::vec3 pos;
// };

// struct mesh_t {
//     GLuint vao;
//     GLuint vbo;
//     std::vector<vertex_t> vertices;
// };

// const int SCR_WIDTH = 800;
// const int SCR_HEIGHT = 600;

// const char *WIN_TITLE = "Hello Triangle";
// const char *VERT_PATH = "res/shaders/shader.vert";
// const char *FRAG_PATH = "res/shaders/shader.frag";

// namespace {
//     /**
//      *
//      * Creates a new window with the given width, height, and title.
//      *
//      * @param width: Screen width in pixels
//      * @param height: Screen height in pixels
//      * @param title: The title for the window
//      * @return A valid GLFWwindow pointer or null if window creation failed
//      */
//     GLFWwindow *make_window(int width, int height, const std::string &title);

//     /**
//      *
//      * Given a valid GLFWwindow pointer, makes this window's OpenGL context current and loads the Glad function pointers into it
//      *
//      * @param win: A valid GLFWwindow pointer
//      * @return True if there was no error, false if there was.
//      */
//     bool make_opengl_context(GLFWwindow *win);

//     /**
//      *
//      * Reads in the shader source code in `path` and creates a new shader object of type `shader-type`
//      *
//      * @param path: filesystem path to the shader
//      * @param shader_type: one of GL_VERTEX_SHADER, GL_FRAGMENT_SHADER
//      * @return A handle to the new shader object
//      */
//     GLuint make_shader(const std::string &path, GLenum shader_type);


//     /**
//      *
//      * Creates a new program with the given shaders.
//      *
//      * @param shader_ids: A list of the shaders to attach and link.
//      * @return A handle to the program object
//      */
//     GLuint make_program(const std::vector<GLuint> &shader_ids);


//     /**
//      *
//      * Cleans up a shader object and releases the resources
//      *
//      * @param shader: The shader to delete
//      */
//     void delete_shader(GLuint shader);


//     /**
//      *
//      * Creates a triangle mesh and sets up the corresponding VAO and VBO objects needed to render.
//      *
//      * @return A struct containing the vertices, a handle to the VAO object, and a handle to the VBO object
//      */
//     mesh_t make_mesh();


//     /**
//      *
//      * The rendering function.
//      * Draws the mesh as GL_TRIANGLES with the given rendering program `program`.
//      *
//      * @param mesh: The given mesh to draw
//      * @param program: The rendering program to use
//      */
//     void render(const mesh_t &mesh, GLuint program);
// }


// int main() {
//     // TODO: Step 1
//     auto success = glfwInit();
//     if (!success) {
//         std::cerr << "Could not initialise GLFW.\n";
//         glfwTerminate();
//         return EXIT_FAILURE;
//     }

//     // TODO: Step 2
//     auto window = make_window(SCR_WIDTH, SCR_HEIGHT, WIN_TITLE);
//     if (!window) {
//         std::cerr << "Failed to create GLFW window.\n";
//         glfwTerminate();
//         return EXIT_FAILURE;
//     }

//     // TODO: Step 3
//     success = make_opengl_context(window);
//     if (!success) {
//         std::cerr << "Failed to load OpenGL with Glad.\n";
//         glfwTerminate();
//         return EXIT_FAILURE;
//     }

//     // TODO: Step 4
//     const auto shaders = std::vector<GLuint>{
//             make_shader(VERT_PATH, GL_VERTEX_SHADER),
//             make_shader(FRAG_PATH, GL_FRAGMENT_SHADER)
//     };

//     // TODO: Step 5
//     const auto render_program = make_program(shaders);

//     // TODO: Step 5.5
//     delete_shader(shaders[0]);
//     delete_shader(shaders[1]);

//     // TODO: Step 6
//     auto mesh = make_mesh();

//     while (!glfwWindowShouldClose(window)) {
//         glfwPollEvents();

//         // TODO: Step 7
//         render(mesh, render_program);

//         glfwSwapBuffers(window);
//     }

//     glfwTerminate();

//     return EXIT_SUCCESS;
// }

int main() {
    glfwInit();
    // Chicken chicken;
    // print();

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR,3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR,3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    GLfloat vertices[] = 
    {
        -0.5f, -0.5f, 0.0f,  1.0f,0.0f, 0.0f, 0.0f,0.0f,
        -0.5f, 0.5f, 0.0f,  0.0f,1.0f, 0.0f,  0.0f,1.0f,
        0.5f, 0.5f, 0.0f,  0.0f,0.0f, 1.0f,  1.0f,1.0f,
        0.5f, -0.5, 0.0f,  1.0f,1.0f, 1.0f,  1.0f,0.0f
        
    };

    GLuint indices[] = {
        0,2,1,
        0,3,2

    };

    GLFWwindow* window = glfwCreateWindow(800, 800, "YoutubeOpenGL", NULL, NULL);
    if (window == NULL) {
        std::cout << "Failed to create GLFW window" << std::endl;
        glfwTerminate();
        return -1;
    }

    glfwMakeContextCurrent(window);

    gladLoadGL();

    glViewport(0,0,800,800);

    Shader shaderProgram("res/shaders/shader.vert", "res/shaders/shader.frag");

    VAO VAO1;
    VAO1.Bind();

    VBO VBO1(vertices, sizeof(vertices));
    EBO EBO1(indices, sizeof(indices));

    VAO1.LinkAttrib(VBO1, 0, 3, GL_FLOAT, 8* sizeof(float), (void*) 0);
    VAO1.LinkAttrib(VBO1, 1, 3, GL_FLOAT, 8* sizeof(float), (void*) (3* sizeof(float)));
    VAO1.LinkAttrib(VBO1, 2, 2, GL_FLOAT, 8* sizeof(float), (void*) (6* sizeof(float)));
    VAO1.Unbind();
    VBO1.Unbind();
    EBO1.Unbind();

    // GLuint vertexShader = glCreateShader(GL_VERTEX_SHADER);
    // glShaderSource(vertexShader, 1, &vertexShaderSource, NULL);
    // glCompileShader(vertexShader);

    // GLuint fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
    // glShaderSource(fragmentShader, 1, &fragmentShaderSource, NULL);
    // glCompileShader(fragmentShader);

    // GLuint shaderProgram = glCreateProgram();

    // glAttachShader(shaderProgram, vertexShader);
    // glAttachShader(shaderProgram, fragmentShader);
    // glLinkProgram(shaderProgram);

    // glDeleteShader(vertexShader);
    // glDeleteShader(fragmentShader);

    // GLuint VAO, VBO, EBO;

    // glGenVertexArrays(1, &VAO);
    // glGenBuffers(1, &VBO);
    // glGenBuffers(1, &EBO);

    // glBindVertexArray(VAO);

    // glBindBuffer(GL_ARRAY_BUFFER, VBO);
    // glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

    // glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
    // glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW );

    // glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
    // glEnableVertexAttribArray(0);

    // glBindBuffer(GL_ARRAY_BUFFER, 0);
    // glBindVertexArray(0);
    // glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);

    // glClearColor(0.07f, 0.13f, 0.17f, 1.0f);
    // glClear(GL_COLOR_BUFFER_BIT);
    // glfwSwapBuffers(window);

    GLuint uniID = glGetUniformLocation(shaderProgram.ID, "scale");

    // Texture
    int widthImg, heightImg, numColCh;
    stbi_set_flip_vertically_on_load(true);
    unsigned char* bytes = stbi_load("res/textures/pop_cat.png", &widthImg, &heightImg, &numColCh, 0);

    GLuint texture;
    glGenTextures(1, &texture);
    glActiveTexture(GL_TEXTURE0);
    glBindTexture(GL_TEXTURE_2D, texture);

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);

    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, widthImg, heightImg, 0, GL_RGBA, GL_UNSIGNED_BYTE, bytes);
    glGenerateMipmap(GL_TEXTURE_2D);

    stbi_image_free(bytes);
    glBindTexture(GL_TEXTURE_2D, 0);

    GLuint tex0Uni = glGetUniformLocation(shaderProgram.ID, "tex0");
    shaderProgram.Activate();
    glUniform1i(tex0Uni, 0);

    while(!glfwWindowShouldClose(window)) {
        glClearColor(0.07f, 0.13f, 0.17f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);
        // glUseProgram(shaderProgram);
        shaderProgram.Activate();
        glUniform1f(uniID, 0.5f);
        glBindTexture(GL_TEXTURE_2D, texture);
        // glBindVertexArray(VAO);
        VAO1.Bind(); 
        glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
        glfwSwapBuffers(window);

        glfwPollEvents();
    }

    // glDeleteVertexArrays(1, &VAO);
    // glDeleteBuffers(1, &VBO);
    // glDeleteBuffers(1, &EBO);
    // glDeleteProgram(shaderProgram);
    VAO1.Delete();
    VBO1.Delete();
    EBO1.Delete();
    glDeleteTextures(1, &texture);
    shaderProgram.Delete();


    glfwDestroyWindow(window);
    glfwTerminate();
    return 0;
}