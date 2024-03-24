WeChat: cstutorcs
QQ: 749389476
Email: tutorcs@163.com
// #include <tute05/animator.hpp>

// #include <iostream>

// #include <cmath>
// #include <stack>

// // Repeat each animation every 10 seconds
// const float PERIOD = 10.f;

// glm::vec3 cubic(const std::vector<glm::vec3> &p, float t) {
//     float s = 1 - t;
//     auto pos = (s * s * s * p[0]) + (3 * t * s * s * p[1]) + (3 * t * t * s * p[2]) + (t * t * t * p[3]);
//     return pos;
// }


// // TODO: complete this
// glm::mat4 animate(const bspline_t &bspline, float now) {
//     // clamps between 0 and 10.
//     double cycle = std::fmod(now, PERIOD);

//     // [0, 5) is the first segment, [5, 10) is the second
//     const std::vector<glm::vec3> &segment = cycle < PERIOD / 2.f ? bspline.s1 : bspline.s2;

//     // clamps between 0 and 1
//     float t = 2 * std::fmod(cycle, PERIOD/2) / PERIOD;

//     // get the translation value
//     auto tr = cubic(segment, (float)t);

//     return glm::translate(glm::mat4(1), tr);

// }

// /**
//  * Calculate a transformation matrix using a parameterised lemniscate.
//  * Here mainly for comparison with the corresponding BSpline.
//  * @param lemni A tag type to represent a lemniscate
//  * @param now The time now in seconds
//  * @return A transformation matrix
//  */
// glm::mat4 animate(const lemnisacte_t &lemni, float now) {
//     auto t = std::fmod(now, PERIOD);

//     auto denom = 1 + std::sin(t) * std::sin(t);
//     auto a = 7.5f;
//     auto x = (a * a * std::cos(t)) / denom;
//     auto y = 0;
//     auto z = (a * a * std::sin(t) * std::cos(t)) / denom;

//     return glm::translate(glm::mat4(1), glm::vec3{ x, y, z });
// }


// animator_t make_animator() {
//     std::vector<glm::vec3> s1 = {
//             { 0,    0, 0 },
//             { 1.85, 0, 1.5 },
//             { 1.85, 0, -1.5 },
//             { 0,    0, 0 },
//     };

//     std::vector<glm::vec3> s2 = {
//             { 0,     0, 0 },
//             { -1.85, 0, 1.5 },
//             { -1.85, 0, -1.5 },
//             { 0,     0, 0 }
//     };

//     /*
//      * This is a correction factor since the original control points assume a smaller curve
//      * This is not the only way to do this; alternatively, one could calculate new control points.
//      * For thr purposes of demonstration, this way is obviously quicker to show
//      */
//     float scale = 40.f;
//     for (glm::vec3 &cp : s1) {
//         cp *= scale;
//     }

//     for (glm::vec3 &cp : s2) {
//         cp *= scale;
//     }


//     return animator_t{ bspline_t{ s1, s2 }, lemniscate_t{ }};
// }

// void animate(const animator_t &animator, scene_t &scene, float now) {
//     std::stack<node_t *> animatables{{ &scene.root }};
//     while (!animatables.empty()) {
//         node_t *n = animatables.top();
//         animatables.pop();

//         switch (n->kind) {
//             case node_t::CAR:
//                 // TODO: add code here
//                 break;
//             case node_t::SARU:
//                 // TODO add code here
//                 n->transform = animate(animator.lemniscate_animation, now);
//                 break;
//             default:
//                 break;
//         }

//         for (node_t &c: n->children) {
//             animatables.push(&c);
//         }
//     }
// }

#include <tute05/animator.hpp>

#include <iostream>

#include <cmath>
#include <stack>

// Repeat each animation every 10 seconds
const float PERIOD = 10.f;

/**
 * Following De Casteljau's algorithm, after linearly interpreting the 4 control points, we end up with this cubic eqn.
 * Easily derivable by hand.
 * The coefficients come from the binomial equation, but the nomenclature also calls these "Bernstein polynomials"
 * If you know Pascal's Triangle, it is easy to compute, though.
 *
 * @param p A vector of 4 control points
 * @param t The current interpolation value. Must be between 0 and 1.
 * @return The point along the Bezier curve at time t.
 */
glm::vec3 cubic(const std::vector<glm::vec3> &p, float t) {
    float s = 1 - t;
    auto pos = (s * s * s * p[0]) + (3 * t * s * s * p[1]) + (3 * t * t * s * p[2]) + (t * t * t * p[3]);
    return pos;
}

/**
 * Calculate a transformation matrix based upon a Bezier cubic.
 *
 * @param bspline The Bezier curve to use.
 * @param now The time in seconds
 * @return A transformation matrix
 */
glm::mat4 animate(const bspline_t &bspline, float now) {
    // clamps between 0 and 10.
    double cycle = std::fmod(now, PERIOD);

    // [0, 5) is the first segment, [5, 10) is the second
    const std::vector<glm::vec3> &segment = cycle < PERIOD / 2.f ? bspline.s1 : bspline.s2;

    // clamps between 0 and 1
    float t = 2 * std::fmod(cycle, PERIOD/2) / PERIOD;

    // get the translation value
    auto tr = cubic(segment, (float)t);

    return glm::translate(glm::mat4(1), tr);
}

/**
 * Calculate a transformation matrix using a parameterised lemniscate.
 * Here mainly for comparison with the corresponding BSpline.
 * @param lemni A tag type to represent a lemniscate
 * @param now The time now in seconds
 * @return A transformation matrix
 */
glm::mat4 animate(const lemniscate_t &lemni, float now) {
    auto t = now;

    auto denom = 1 + std::sin(t) * std::sin(t);
    auto a = 7.5f;
    auto x = (a * a * std::cos(t)) / denom;
    auto y = 0;
    auto z = (a * a * std::sin(t) * std::cos(t)) / denom;

    return glm::translate(glm::mat4(1), glm::vec3{ x, y, z });
}


animator_t make_animator() {
    std::vector<glm::vec3> s1 = {
            { 0,    0, 0 },
            { 1.85, 0, 1.5 },
            { 1.85, 0, -1.5 },
            { 0,    0, 0 },
    };

    std::vector<glm::vec3> s2 = {
            { 0,     0, 0 },
            { -1.85, 0, 1.5 },
            { -1.85, 0, -1.5 },
            { 0,     0, 0 }
    };

    /*
     * This is a correction factor since the original control points assume a smaller curve
     * This is not the only way to do this; alternatively, one could calculate new control points.
     * For thr purposes of demonstration, this way is obviously quicker to show
     */
    float scale = 40.f;
    for (glm::vec3 &cp : s1) {
        cp *= scale;
    }

    for (glm::vec3 &cp : s2) {
        cp *= scale;
    }


    return animator_t{ bspline_t{ s1, s2 }, lemniscate_t{ }};
}

void animate(const animator_t &animator, scene_t &scene, float now) {
    std::stack<node_t *> animatables{{ &scene.root }};
    while (!animatables.empty()) {
        node_t *n = animatables.top();
        animatables.pop();

        switch (n->kind) {
            case node_t::CAR:
                n->transform = animate(animator.spline_animation, now);
                break;
            case node_t::SARU:
                n->transform = animate(animator.lemniscate_animation, now);
                break;
            default:
                break;
        }

        for (node_t &c: n->children) {
            animatables.push(&c);
        }
    }
}
