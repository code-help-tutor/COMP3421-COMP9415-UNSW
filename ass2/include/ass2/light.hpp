WeChat: cstutorcs
QQ: 749389476
Email: tutorcs@163.com
#ifndef COMP3421_ASS2_LIGHT_HPP
#define COMP3421_ASS2_LIGHT_HPP

#include <glm/glm.hpp>

struct directional_light_t {
    glm::vec3 ambient;
    glm::vec3 diffuse;
    glm::vec3 specular;
};

struct point_light_t {
    glm::vec3 pos;
    glm::vec3 color;
    float attenuation;
};

#endif 