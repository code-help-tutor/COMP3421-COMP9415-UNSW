WeChat: cstutorcs
QQ: 749389476
Email: tutorcs@163.com
#include <tute07/primitives.hpp>

#include <glm/ext.hpp>

#include <chicken3421/chicken3421.hpp>

namespace {
    struct vertex_t {
        glm::vec3 pos;

        // TODO add something here!

        glm::vec2 tc;
    };

    const float PI = glm::pi<float>();
    const float TWOPI = 2 * PI;

    GLuint upload_texture(const std::string &path) {
        chicken3421::image_t teximg = chicken3421::load_image(path);
        GLint fmt = teximg.n_channels == 3 ? GL_RGB : GL_RGBA;

        GLuint tex = chicken3421::make_texture();
        glBindTexture(GL_TEXTURE_2D, tex);
        glTexImage2D(GL_TEXTURE_2D, 0, fmt, teximg.width, teximg.height, 0, fmt, GL_UNSIGNED_BYTE, teximg.data);
        glGenerateMipmap(GL_TEXTURE_2D);

        glBindTexture(GL_TEXTURE_2D, 0);

        chicken3421::delete_image(teximg);

        return tex;
    }

    mesh_t upload_mesh(const std::vector<vertex_t> &vertices, const std::vector<index_t> &indices) {
        GLuint vao = chicken3421::make_vao();
        glBindVertexArray(vao);

        GLuint vbo = chicken3421::make_buffer();
        glBindBuffer(GL_ARRAY_BUFFER, vbo);
        glBufferData(GL_ARRAY_BUFFER, sizeof(vertex_t) * vertices.size(), vertices.data(), GL_STATIC_DRAW);

        GLuint ibo = chicken3421::make_buffer();
        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ibo);
        glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(index_t) * indices.size(), indices.data(), GL_STATIC_DRAW);

        glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(vertex_t), (void *) offsetof(vertex_t, pos));
        glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, sizeof(vertex_t), (void *) offsetof(vertex_t, tc));

        glEnableVertexAttribArray(0);
        glEnableVertexAttribArray(2);

        glBindVertexArray(0);
        glBindBuffer(GL_ARRAY_BUFFER, 0);
        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);

        return mesh_t{ vao, vbo, ibo, indices.size() };
    }

    mesh_t make_volume_mesh(const volume_param_t &params) {
        float w = params.width;
        float h = params.height;
        float d = params.depth;

        float hw = w / 2;
        float hh = h / 2;
        float hd = d / 2;

        std::vector<vertex_t> verts = {
                // assuming looking down the negative-z axis...

                // front face
                {{ -w, -h, d },  { 0,  0 }},
                {{ w,  -h, d },  { hw, 0 }},
                {{ w,  h,  d },  { hw, hh }},
                {{ -w, h,  d },  { 0,  hh }},

                // right face
                {{ w,  -h, d },  { 0,  0 }},
                {{ w,  -h, -d }, { hd, 0 }},
                {{ w,  h,  -d }, { hd, hh }},
                {{ w,  h,  d },  { 0,  hh }},

                // back face
                {{ w,  -h, -d }, { 0,  0 }},
                {{ -w, -h, -d }, { hw, 0 }},
                {{ -w, h,  -d }, { hw, hh }},
                {{ w,  h,  -d }, { 0,  hh }},

                // left face
                {{ -w, -h, -d }, { 0,  0 }},
                {{ -w, -h, d },  { hd, 0 }},
                {{ -w, h,  d },  { hd, hh }},
                {{ -w, h,  -d }, { 0,  hh }},

                // top face
                {{ -w, h,  d },  { 0,  0 }},
                {{ w,  h,  d },  { hw, 0 }},
                {{ w,  h,  -d }, { hw, hd }},
                {{ -w, h,  -d }, { 0,  hd }},

                // bottom face
                {{ -w, -h, -d }, { 0,  0 }},
                {{ w,  -h, -d }, { hw, 0 }},
                {{ w,  -h, d },  { hw, hd }},
                {{ -w, -h, d },  { 0,  hd }},
        };
        std::vector<index_t> indices = {
                0, 1, 2,
                0, 2, 3,

                4, 5, 6,
                4, 6, 7,

                8, 9, 10,
                8, 10, 11,

                12, 13, 14,
                12, 14, 15,

                16, 17, 18,
                16, 18, 19,

                20, 21, 22,
                20, 22, 23
        };

        return upload_mesh(verts, indices);
    }

    mesh_t make_sphere_mesh(const sphere_param_t &params) {
        int stacks = params.stacks;
        int slices = params.slices;

        std::vector<vertex_t> verts;
        for (int i = 0; i <= stacks; ++i) {
            double phi = glm::pi<double>() * i / (double) stacks;

            for (int j = 0; j <= slices; ++j) {
                double theta = 2 * glm::pi<double>() * j / (double) slices;

                glm::vec3 p = { std::cos(theta) * std::sin(phi), std::cos(phi), std::sin(theta) * std::sin(phi) };
                glm::vec2 tc = { (float) -j / (float) slices, (float) i / (float) stacks };

                verts.push_back({ p, tc });
            }
        }

        std::vector<index_t> indices;
        for (int i = 0; i < slices * stacks + slices; ++i) {
            indices.push_back(index_t(i));
            indices.push_back(index_t(i + slices + 1));
            indices.push_back(index_t(i + slices));

            indices.push_back(index_t(i + slices + 1));
            indices.push_back(index_t(i));
            indices.push_back(index_t(i + 1));
        }

        return upload_mesh(verts, indices);
    }

    mesh_t make_torus_mesh(const torus_param_t &params) {
        float c = (params.inner_r + params.outer_r) / 2;
        float r = (params.outer_r - params.inner_r) / 2;
        int lod = params.lod;

        std::vector<vertex_t> verts;
        for (int i = 0; i <= lod; ++i) {
            float phi = i * TWOPI / (float) lod;
            glm::mat4 rt = glm::rotate(glm::identity<glm::mat4>(), phi, { 0, 1, 0 });
            for (int j = 0; j <= lod; ++j) {
                float theta = j * TWOPI / (float) lod;

                glm::vec4 tr = glm::vec4{ c + r * std::cos(theta), c + r * std::sin(theta), 0, 1 };

                glm::vec3 pos = rt * tr;
                glm::vec2 tc = { (float) i / (float) lod, (float) j / (float) lod };

                verts.push_back({ pos, tc });
            }
        }

        std::vector<index_t> indices;
        int cycle = lod + 1;
        for (int k = 0; k < cycle * cycle - cycle - 1; ++k) {
            indices.push_back(index_t(k));
            indices.push_back(index_t(k + cycle));
            indices.push_back(index_t(k + cycle + 1));

            indices.push_back(index_t(k));
            indices.push_back(index_t(k + cycle + 1));
            indices.push_back(index_t(k + 1));
        }

        return upload_mesh(verts, indices);
    }

    material_t make_volume_mat(const material_param_t &params) {
        GLuint diff = upload_texture(params.diff_map_path);

        return material_t{ diff };
    }

    material_t make_sphere_mat(const material_param_t &params) {
        GLuint diff = upload_texture(params.diff_map_path);

        return material_t{ diff };
    }

    material_t make_torus_mat(const material_param_t &params) {
        GLuint diff = upload_texture(params.diff_map_path);

        return material_t{ diff };
    }
}

model_t make_volume(const volume_param_t &geo_params, const material_param_t &mat_params) {
    return model_t{ make_volume_mesh(geo_params), make_volume_mat(mat_params) };

}

model_t make_sphere(const sphere_param_t &geo_params, const material_param_t &mat_params) {
    return model_t{ make_sphere_mesh(geo_params), make_sphere_mat(mat_params) };
}

model_t make_torus(const torus_param_t &geo_params, const material_param_t &mat_params) {
    return { make_torus_mesh(geo_params), make_torus_mat(mat_params) };
}