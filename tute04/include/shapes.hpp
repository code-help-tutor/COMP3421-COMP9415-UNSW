WeChat: cstutorcs
QQ: 749389476
Email: tutorcs@163.com
#ifndef COMP3421_SHAPES_HPP
#define COMP3421_SHAPES_HPP

#include <glm/glm.hpp>
#include <static_mesh.hpp>

namespace shapes {

    /**
    * Creates a sphere static mesh with texture coordinates and initialises it
    * @param tessellation - number of slices that make up the cube (must be divisible by 4)
    */
    static_mesh::mesh_t make_sphere(float radius, unsigned int tessellation = 64);

}

#endif //COMP3421_SHAPES_HPP
