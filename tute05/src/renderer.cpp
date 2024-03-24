WeChat: cstutorcs
QQ: 749389476
Email: tutorcs@163.com
#include <tute05/renderer.hpp>

#include <stack>


#include <chicken3421/chicken3421.hpp>

const char *VERT_PATH = "res/shaders/shader.vert";
const char *FRAG_PATH = "res/shaders/shader.frag";

renderer_t make_renderer(const glm::mat4 &projection) {
    GLuint vs = chicken3421::make_shader(VERT_PATH, GL_VERTEX_SHADER);
    GLuint fs = chicken3421::make_shader(FRAG_PATH, GL_FRAGMENT_SHADER);

    GLuint render_program = chicken3421::make_program(vs, fs);

    chicken3421::delete_shader(vs);
    chicken3421::delete_shader(fs);

    GLint mvp_loc = chicken3421::get_uniform_location(render_program, "uMVP");
    GLint tf_loc = chicken3421::get_uniform_location(render_program, "uTexFactor");
    GLint col_loc = chicken3421::get_uniform_location(render_program, "uColor");

    return renderer_t{ projection, render_program, mvp_loc, tf_loc, col_loc };
}

void draw(const renderer_t &renderer, const glm::mat4 &mvp, const model_t &m) {
    for (const mesh_t &mesh: m.meshes) {

        if (mesh.material_id != -1) {
            const material_t &mtl = m.materials[mesh.material_id];

            glBindTexture(GL_TEXTURE_2D, mtl.texture);
            glUniform1f(renderer.tf_loc, mtl.texture == 0 ? 0.f : 1.f);
            glUniform4fv(renderer.col_loc, 1, glm::value_ptr(mtl.color));
        } else {
            // default material
            glUniform1f(renderer.tf_loc, 0.f);
            glUniform4f(renderer.col_loc, 1, 1, 1, 1);
        }

        glUniformMatrix4fv(renderer.mvp_loc, 1, GL_FALSE, glm::value_ptr(mvp));

        glBindVertexArray(mesh.vao);
        glBindBuffer(GL_ARRAY_BUFFER, mesh.vbo);
        glDrawArrays(GL_TRIANGLES, 0, mesh.nverts);

        glBindVertexArray(0);
        glBindBuffer(GL_ARRAY_BUFFER, 0);
        glBindTexture(GL_TEXTURE_2D, 0);
    }
}

void render(const renderer_t &renderer, const scene_t &scene) {
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_CULL_FACE);
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

    glUseProgram(renderer.program);

    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glClearColor(0.0f, 0.2f, 0.4f, 1.0f);

    const glm::mat4 &vp = renderer.projection * get_view(scene.cam);

    // an iterative approach allows for certain optimisations like tail-recursion not used here.
    // also, recursion of arbitrary depth is impossible, so this approach is more robust.
    std::stack<std::pair<const node_t &, glm::mat4>> renderables{{{ scene.root, scene.root.transform }}};
    while (!renderables.empty()) {
        const auto &[node, parent_tf] = renderables.top();  // this is called a structured binding
        renderables.pop();

        glm::mat4 xform = parent_tf * node.transform;

        draw(renderer, vp * xform, node.obj);

        for (const node_t &c: node.children) {
            renderables.push({ c, xform });
        }
    }
}