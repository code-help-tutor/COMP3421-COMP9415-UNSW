WeChat: cstutorcs
QQ: 749389476
Email: tutorcs@163.com
#ifndef COMP3421_TUTORIAL_05_ANIMATOR_HPP
#define COMP3421_TUTORIAL_05_ANIMATOR_HPP

#include <glm/ext.hpp>

#include <tute05/scene.hpp>

// TODO: complete this
struct bspline_t {
    // add members
    std::vector<glm::vec3> s1;
    std::vector<glm::vec3> s2;

};

/**
 * A type representing a figure-8, or lemniscate.
 * Unremarkable.
 */
struct lemniscate_t {};

/**
 * Our primitive animator only can draw lemniscates.
 *
 */
struct animator_t {
    bspline_t spline_animation;
    lemniscate_t lemniscate_animation;
};

/**
 * Given the current animation context animator and time, apply animations to the scene.
 *
 * Currently, the only two animations applied are figure-8s.
 *
 * @param animator The animation context
 * @param scene The scene to animate
 * @param now The current time in seconds.
 */
void animate(const animator_t &animator, scene_t &scene, float now);

/**
 * Initialise the animation context
 * @return A fresh animator
 */
animator_t make_animator();

#endif //COMP3421_TUTORIAL_05_ANIMATOR_HPP
