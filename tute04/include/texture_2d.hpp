WeChat: cstutorcs
QQ: 749389476
Email: tutorcs@163.com
#ifndef TEXTURE2D_H
#define TEXTURE2D_H

#include <glad/glad.h>
#include <string>

namespace texture_2d {

    struct params_t {
        GLint wrap_s = GL_REPEAT; // wrapping mode on S axis
        GLint wrap_t = GL_REPEAT; // wrapping mode on T axis
        GLint filter_min = GL_LINEAR_MIPMAP_LINEAR; // filtering mode if texture pixels < screen pixels
        GLint filter_max = GL_LINEAR; // filtering mode if texture pixels > screen pixels
    };

    void bind(GLuint tex);

    GLuint init(std::string file_name, params_t const &params = params_t{});

    void destroy(GLuint tex);
}

#endif
