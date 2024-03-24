# Tutorial 05

This week is dedicated to loading pre-made custom models from an artist and animating it via Bezier curves.

## Grand Prix

In this exercise, we will be loading a custom racetrack, car, and monkey model in the `.obj` format and also animating the car and monkey to progress around a figure-8 track (called a _lemniscate_ in mathematical parlance).

### Loading `.obj` Models (30 mins)

The code inside of `src/model.cpp` is not finished.

Complete the code so that the models are loaded into `model_t` as it is laid out in `include/tute05/model.hpp`

After this is done, answer the following questions:
- What is a "material"? Have we been using these all along or are they completely new?

- What is inside the `.obj` format? Does it make use of all of the OpenGL featues we've seen up until now?

Arrange the scene now so that the racetrack is the root of the scenegraph, and the car and monkey are children.

### Animating (30 mins)

Once the scene is arranged, it is now time to animate our contestants before they duke it out on the figure-8 track.

There is already some code to animate the monkey in `src/animator.cpp`, but this animation uses the parameterised equation of a lemniscate.

To animate the car, we will be creating a similar lemniscate but using 2 segments of 4 control points each.
Use a graphing calculator (e.g. [Desmos](https://www.desmos.com/calculator/cahqdxeshd)) to find these control points.

**Warning**: the lemniscate is a smooth curve, so make sure that the segments share their starts and ends with each other!

After you've found these control points, complete the code in `src/animator.cpp` so that the car and monkey both go around the figure-8 track.

After this, well done! You have successfully loaded a complex model not built from primitives and animated with a non-elemental curve!

## Challenge Yourself

### 1. Adding Rotations
You may have noticed that as the car and monkey go around the track, though their position is changing, their rotation is not.

Modify the animations so that the models face toward whatever direction they are moving.

Hints:
- You will need to calculate a new rotation matrix (called a _Frenet frame_). This can be done by:
  - Finding the tangent to the curve and taking that as the forward vector.
  - Rotating that tangent 90 degrees to find the side vector.
  - Crossing these two vectors the find the up vector


### 2. The Second Derivative
In the animation, you may also notice the car speeds up as it approaches the origin.

This is because **the second derivative** of the Bezier curve is not 0 i.e. there is some acceleration.

Modify the animation so that there is constant (0) acceleration as the car moves around the track. 

### 3. More Efficiency.
Modify the model-loading code so that the various `.obj` index buffers are concatened into one, usable with OpenGL.

## Further Resources:
- [De Casteljau's algorithm for evaluating Bezier curves](https://blog.demofox.org/2015/07/05/the-de-casteljeau-algorithm-for-evaluating-bezier-curves/)
- [The homepage of the object loader we are using (docs)](https://github.com/tinyobjloader/tinyobjloader)