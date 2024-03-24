WeChat: cstutorcs
QQ: 749389476
Email: tutorcs@163.com
#include <chicken3421/chicken3421.hpp>

#include <ass3/memes.hpp>

const char *MARCCOIN_TEXTURE_PATH = "res/textures/marccoin.png";

/**
 * Please don't kill me marc
 * @param win The window to make GLORIOUS
 * @return a better window
 */
GLFWwindow *marcify(GLFWwindow *win) {
    chicken3421::image_t marccoin = chicken3421::load_image(MARCCOIN_TEXTURE_PATH, false);

    GLFWimage favicon = {marccoin.width, marccoin.height, (unsigned char *) marccoin.data};
    glfwSetWindowIcon(win, 1, &favicon);


    chicken3421::delete_image(marccoin);

    return win;
}
