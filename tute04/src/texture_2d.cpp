WeChat: cstutorcs
QQ: 749389476
Email: tutorcs@163.com
#include <glad/glad.h>
#include <iostream>
#include <stb/stb_image.h>
#include <chicken3421/chicken3421.hpp>

#include "texture_2d.hpp"

namespace texture_2d {
    GLuint init(std::string file_name, params_t const &params) {
        GLuint tex;
        glGenTextures(1, &tex);

        stbi_set_flip_vertically_on_load(true);

        // load the image using stb lib
        void *data = 0;
        int width, height, n_channels;
        data = stbi_load(file_name.data(), &width, &height, &n_channels, 0);

        chicken3421::expect(data, "Could not read " + file_name);

        glBindTexture(GL_TEXTURE_2D, tex);

        GLenum format = n_channels == 3 ? GL_RGB : GL_RGBA;
        glTexImage2D(GL_TEXTURE_2D, 0, (GLint)format, width, height, 0, format, GL_UNSIGNED_BYTE, data);

        // generate mimap if filter_min is a mipmap filter
        switch (params.filter_min) {
            case GL_LINEAR_MIPMAP_LINEAR:
            case GL_NEAREST_MIPMAP_LINEAR:
            case GL_LINEAR_MIPMAP_NEAREST:
            case GL_NEAREST_MIPMAP_NEAREST:
                glGenerateMipmap(GL_TEXTURE_2D);
                break;
            default:
                break;
        }

        // wrap options
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, params.wrap_s);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, params.wrap_t);
        // mag/min options
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, params.filter_min);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, params.filter_max);

        glBindTexture(GL_TEXTURE_2D, 0);

        return tex;
    }

    void bind(GLuint tex) {
        glBindTexture(GL_TEXTURE_2D, tex);
    }

    void destroy(GLuint tex) {
        glDeleteTextures(1, &tex);
    }
}

