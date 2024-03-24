# Tutorial 2

This week is all about 2D: 2D textures and 2D transforms.

## A. Simple 2D Texturing (30 mins)

In this exercise, we're going to be exploring texturing a simple rectangle.
We are also going to see what changing some of the **sampler** properties of the texture do.

Currently, the program in `src/simple_texture.cpp` draws a black rectangle on a blue background.

Change `simple_texture` so that:
- `res/img/arrows256.jpg` is textured on the rectangle.
  - Make sure that the bottom-left has texture-coordinate (0, 0)
  - bottom-right has texture-coordinate (1, 0)
  - top-right has texture-coordinate(1, 1)
  - top-left has texture-coordinate (0, 1)
- The vertex shader passes through the texture-coordinate to the fragment shader
- The fragment shader stops hard-coding the colour of the fragments.

## B. Simple Transforms (30 mins)

The aim of this exercise is to show off two-dimensional transforms and also get familiar with user input in GLFW.

We're going to translate, rotate, and scale an emoji circle.

Complete the program in `src/simple_transforms.cpp` so that:
- Initially the emoji is in the center of the screen with no rotation or scale.
- When the user presses:
  - "w", "a", "s", "d", the emoji moves up, left, down, or right by 0.05 respectively.
- When the user presses:
  - "q" or "e" on the keyboard, the emoji rotates 30 degrees anti-clockwise and clockwise respectively.
- When the user scrolls:
  - up or down, the emoji scales by up or down by 0.1x respectively.
- When the user clicks:
  - the left mouse button, the emoji resets to its initial translation, rotation, and scale.


## Challenge Yourself

### 1. _Multum in parvo_ (Mipmaps)
One _extremely_ common way to attenuate texture aliasing is through [mipmapping](https://en.wikipedia.org/wiki/Mipmap).
In a nutshell, a mipmap is an array of multiple copies of the same texture at different sizes.
Each size is selected based on how small the object appears to the viewer.

Try to reimplement (B), but using mipmaps.

Hints:
- you will need to customise the texture parameters from (A) with the `GL_MIPMAP_*` set of filtering modes.
- OpenGL has a very convenient function to help with generating mipmaps... (search the docs)

### 2. Explicit Samplers
It is possible to have explicit sampler objects that override the default sampling parameters of a texture.

Convert (A) to use an explicit sampler object rather than the default.

Hints:
- You will need to create and bind the sampler to the active texture unit.
- You will need to bind the sampler to the sampler uniform in the fragment shader.

### 3. Emoji Rain
Using the emoji circle and the transforms from (B), create a program that animates emojis raining from the sky.
By sky, from the top of the screen to the bottom is meant.

The emojis should:
- have randomly generated scale, horizontal translation, and rotation
- have a constant velocity going down (hardcoded or randomly-generated)
- have 64 shown on-screen at any one time.

Hint: realtime renderers don't just have a run-loop. _They have an animator_ i.e. something that renders at a set interval. For 60fps this means rendering every 16.67 milliseconds.


## Further Reading
- [Textures in more depth](https://www.khronos.org/opengl/wiki/Texture)
- [Learn OpenGL: Texturing](https://learnopengl.com/Getting-started/Textures)
- [2D Transform Theory](https://www.cs.utexas.edu/users/fussell/courses/cs384g-fall2011/lectures/lecture07-Affine.pdf)
