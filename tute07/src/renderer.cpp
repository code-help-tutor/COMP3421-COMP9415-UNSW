WeChat: cstutorcs
QQ: 749389476
Email: tutorcs@163.com
#include <tute07/renderer.hpp>

#include <stack>

#include <chicken3421/chicken3421.hpp>

const char *VERT_PATH = "res/shaders/default.vert";
const char *FRAG_PATH = "res/shaders/default.frag";

// TODO: add something here!
renderer_t make_renderer(const glm::mat4 &projection) {
    GLuint vs = chicken3421::make_shader(VERT_PATH, GL_VERTEX_SHADER);
    GLuint fs = chicken3421::make_shader(FRAG_PATH, GL_FRAGMENT_SHADER);

    GLuint render_program = chicken3421::make_program(vs, fs);

    chicken3421::delete_shader(vs);
    chicken3421::delete_shader(fs);

    GLint p_loc = chicken3421::get_uniform_location(render_program, "p");
    GLint v_loc = chicken3421::get_uniform_location(render_program, "v");
    GLint m_loc = chicken3421::get_uniform_location(render_program, "m");

    return renderer_t{ projection, render_program, p_loc, v_loc, m_loc };
}

void
draw(const renderer_t &renderer, const glm::mat4 &p, const glm::mat4 &v, const glm::mat4 &m, const model_t &model) {
    const auto &mesh = model.mesh;
    const auto &mtl = model.material;

    glBindTexture(GL_TEXTURE_2D, mtl.diff_map);

    glUniformMatrix4fv(renderer.p_loc, 1, GL_FALSE, glm::value_ptr(p));
    glUniformMatrix4fv(renderer.v_loc, 1, GL_FALSE, glm::value_ptr(v));
    glUniformMatrix4fv(renderer.m_loc, 1, GL_FALSE, glm::value_ptr(m));

    glBindVertexArray(mesh.vao);
    glBindBuffer(GL_ARRAY_BUFFER, mesh.vbo);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, mesh.ibo);

    glDrawElements(GL_TRIANGLES, (GLsizei) mesh.nverts, index_type, nullptr);

    glBindVertexArray(0);
    glBindBuffer(GL_ARRAY_BUFFER, 0);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
    glBindTexture(GL_TEXTURE_2D, 0);
}

// TODO: add something here!
void render(const renderer_t &renderer, const scene_t &scene) {
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_CULL_FACE);
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

    glUseProgram(renderer.program);

    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);

    glm::mat4 p = renderer.projection;
    glm::mat4 v = get_view(scene.cam);

    // an iterative approach allows for certain optimisations like tail-recursion not used here.
    // also, recursion of arbitrary depth is impossible, so this approach is more robust.
    std::stack<std::pair<const node_t &, glm::mat4>> renderables{{{ scene.root, scene.root.transform }}};
    while (!renderables.empty()) {
        const auto[node, parent_tf] = renderables.top();  // this is called a structured binding
        renderables.pop();

        glm::mat4 xform = parent_tf * node.transform;

        draw(renderer, p, v, xform, node.obj);

        for (const node_t &c: node.children) {
            renderables.push({ c, xform });
        }
    }

}