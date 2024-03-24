WeChat: cstutorcs
QQ: 749389476
Email: tutorcs@163.com
#include <ass2/renderer.hpp>

#include <stack>

#include <chicken3421/chicken3421.hpp>

const char *VERT_PATH = "res/shaders/default.vert";
const char *FRAG_PATH = "res/shaders/default.frag";

renderer_t make_renderer(const glm::mat4 &projection) {
    GLuint vs = chicken3421::make_shader(VERT_PATH, GL_VERTEX_SHADER);
    GLuint fs = chicken3421::make_shader(FRAG_PATH, GL_FRAGMENT_SHADER);

    GLuint render_program = chicken3421::make_program(vs, fs);

    chicken3421::delete_shader(vs);
    chicken3421::delete_shader(fs);

    GLint p_loc = chicken3421::get_uniform_location(render_program, "p");
    GLint v_loc = chicken3421::get_uniform_location(render_program, "v");
    GLint m_loc = chicken3421::get_uniform_location(render_program, "m");

    GLint light_pos_loc = chicken3421::get_uniform_location(render_program, "u_light_pos");
    GLint light_color_loc = chicken3421::get_uniform_location(render_program, "u_light_color");
    GLint light_attenuation_loc = chicken3421::get_uniform_location(render_program, "u_light_attenuation");
    GLint diff_map_loc = chicken3421::get_uniform_location(render_program, "u_diff_map");
    GLint spec_map_loc = chicken3421::get_uniform_location(render_program, "u_spec_map");

    GLint diffuse_loc = chicken3421::get_uniform_location(render_program, "u_diffuse");
    GLint specular_loc = chicken3421::get_uniform_location(render_program, "u_specular");
    GLint emissive_loc = chicken3421::get_uniform_location(render_program, "u_emissive");
    GLint shininess_loc = chicken3421::get_uniform_location(render_program, "u_shininess");

    return { projection,
             render_program,
             p_loc, v_loc, m_loc,
             light_pos_loc, light_color_loc, light_attenuation_loc, diff_map_loc, spec_map_loc,
             diffuse_loc, specular_loc, emissive_loc, shininess_loc
    };
}

void
draw(const renderer_t &renderer, const glm::mat4 &p, const glm::mat4 &v, const glm::mat4 &m, const model_t &model) {
    const auto &mesh = model.mesh;
    const auto &mtl = model.material;

    // set material parameters
    glUniform3fv(renderer.diffuse_loc, 1, glm::value_ptr(mtl.diffuse));
    glUniform3fv(renderer.specular_loc, 1, glm::value_ptr(mtl.specular));
    glUniform3fv(renderer.emissive_loc, 1, glm::value_ptr(mtl.emissive));
    glUniform1f(renderer.shininess_loc, mtl.shininess);

    // set the diffuse map
    glActiveTexture(GL_TEXTURE0);
    glBindTexture(GL_TEXTURE_2D, mtl.diff_map);

    // set the spec map
    glActiveTexture(GL_TEXTURE1);
    glBindTexture(GL_TEXTURE_2D, mtl.spec_map);

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
    glActiveTexture(GL_TEXTURE0 + 0);
    glBindTexture(GL_TEXTURE_2D, 0);
    glActiveTexture(GL_TEXTURE0 + 1);
    glBindTexture(GL_TEXTURE_2D, 0);
}

void render(const renderer_t &renderer, const scene_t &scene) {
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_CULL_FACE);
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

    glUseProgram(renderer.program);

    glUniform1i(renderer.diff_map_loc, 0);
    glUniform1i(renderer.spec_map_loc, 1);

    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);

    glm::mat4 p = renderer.projection;
    glm::mat4 v = get_view(scene.cam);

    // set up the lighting
    glUniform3fv(renderer.light_pos_loc, 1, glm::value_ptr(scene.point_light.pos));
    glUniform3fv(renderer.light_color_loc, 1, glm::value_ptr(scene.point_light.color));
    glUniform1f(renderer.light_attenuation_loc, scene.point_light.attenuation);

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