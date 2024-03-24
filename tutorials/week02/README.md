# Tutorial 2

This week is all about 2D: 2D textures and 2D transforms.

## A. Simple 2D Texturing (20 mins)

In this exercise, we're going to be texturing a simple circle with an emoji image.

Write a program inside of `src/simple_texture.cpp` that draws a circle to the screen and textures it with `res/img/emoji512.jpg`.



## B. Simple 2D Texture Sampling  (20 mins)

OpenGL has a notion of texture _units_. These are comprised of textures, binding points, and **texture samplers**.

Though every texture has an internal default sampler, in this question we're going to explore explicit sampler customisation.

Run `src/simple_sampler.cpp` and examine the output. As you can, the crate texture only fills the bottom left corner.

Fix up `simple_sampler` by exploring the various ways OpenGL can automatically repeat textures.
Don't forget to also modify `res/shaders/simple_sample.frag` so that the fragment shader is using our custom sampler.


## C. Simple Transforms (20 mins)

The aim of this exercise is to show off two-dimensional transforms.

We're going to translate, rotate, and scale the emoji circle from the previous exercise.

Complete the program in `src/simple_transforms.cpp` so that:
- Initially the emoji is in the center of the screen with no rotation or scale.
- When the user presses:
  - "w", "a", "s", "d", the emoji moves up, left, down, or right by 1 unit respectively.
- When the user presses:
  - "q" or "e" on the keyboard, the emoji rotates 60 degrees anti-clockwise and clockwise respectively.
- When the user presses:
  - the up or down arrow key, the emoji scales to double and half its size respectively.
- When the user clicks the left mouse button, the emoji resets to its initial position.

Hint: you may want to reuse the emoji drawing code from (A).


## Challenge Yourself

### 1. Emoji Rain
Using the emoji circle from (A) and the transforms from (C), create a program that animates emojis falling from the top of the screen to the bottom.
The emojis should:
- have randomly generated scale, horizontal translation, and rotation
- have a constant velocity going down
- be capped at 64 shown on-screen at any one time.

Hint: realtime renderers don't just have a run-loop. _They have an animator_ i.e. something that renders at a set interval. For 60fps this means rendering every 16.67 milliseconds.

### 2. _Multum in parvo_ (Mipmaps)
From (C), you can see that when detailed textures become small weird aliasing effects happen. One _extremely_ common way to attenuate this is through [mipmapping](https://en.wikipedia.org/wiki/Mipmap). In a nutshell, a mipmap is multiple copies of the same texture at different sizes and the different size is selected based on how small the textured object is.

Try to reimplement (C), but using mipmaps.

Hints:
- you will need to use the **sampler** from (B) and modify it.
- OpenGL has a very convenient function to help with mipmaps... (search the docs)


## Further Reading
- [2D Transform Theory](https://www.cs.utexas.edu/users/fussell/courses/cs384g-fall2011/lectures/lecture07-Affine.pdf)
- [Learn OpenGL: Texturing](https://learnopengl.com/Getting-started/Textures)