WeChat: cstutorcs
QQ: 749389476
Email: tutorcs@163.com
#include "static_mesh.hpp"
#include "shapes.hpp"

namespace shapes {
    static_mesh::mesh_t make_sphere(float radius, unsigned int tessellation) {
        static_mesh::mesh_template_t sphere;

        float ang_inc = 2.0f * (float) M_PI / (float) tessellation;
        unsigned int stacks = tessellation / 2;
        unsigned int start_angle_i = 3 * tessellation / 4;
        for (unsigned int i = start_angle_i; i <= start_angle_i + stacks; ++i) {
            float alpha = ang_inc * (float) i;
            float y = radius * std::sin(alpha);
            float slice_radius = radius * std::cos(alpha);
            for (unsigned int j = 0; j <= tessellation; ++j) {
                float beta = ang_inc * (float) j;
                float z = slice_radius * std::cos(beta);
                float x = slice_radius * std::sin(beta);
                sphere.positions.emplace_back(x, y, z);
                sphere.tex_coords.emplace_back(
                        (float) j * 1.0f / (float) tessellation,
                         (float) (i - start_angle_i) * 2.0f / (float) tessellation);
            }
        }
        // create the indices
        for (unsigned int i = 1; i <= tessellation / 2; ++i) {
            unsigned int prev = (1u + tessellation) * (i - 1);
            unsigned int curr = (1u + tessellation) * i;
            for (unsigned int j = 0; j < tessellation; ++j) {
                sphere.indices.push_back(curr + j);
                sphere.indices.push_back(prev + j);
                sphere.indices.push_back(prev + j + 1);
                sphere.indices.push_back(prev + j + 1);
                sphere.indices.push_back(curr + j + 1);
                sphere.indices.push_back(curr + j);
            }
        }

        return static_mesh::init(sphere);
    }

}
