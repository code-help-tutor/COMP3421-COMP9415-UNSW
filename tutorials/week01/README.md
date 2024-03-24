# Tutorial 1

The aim of this tutorial is to successfully set up your development environment and familiarise yourself with the basics of rendering with OpenGL.

As the term progresses, set-up and/or boilerplate code will be contained inside a support library called `chicken3421`. We encourage you to be confident you can code all of the examples yourself before using the library, however.

## A. Preliminary Setup
Please see `SETUP.md` to set up your development environment if you haven't already.

Please also see `GIT101.md` if you're unfamiliar with Git/Gitlab, or want a basic refresher.

## B. Breaking the Ice (20 mins)
Your tutor will do an activity to get to know everyone. Say hello!

Some questions that might be worth exploring:
- Why are you interested in computer graphics?
- What was the last cool effect you saw in either a movie or a game?
- What do you hope to get out of this course?


## C. Introduction to OpenGL (5 mins)

Take this time to ask your tutor about OpenGL and/or computer graphics at a high level.

Some starters:
- Why does OpenGL exist? What problems does it seek to solve?
- Differences between OpenGL versions?
- Fixed-function pipeline vs. programmable pipeline.
- Where does my GPU fit into rendering with OpenGL?

## D. Hello, triangle! (35 mins)

Look at the code in `src/main.cpp`. This file contains a main function that calls stubs which:
1. Initialises the windowing library
2. Creates a new window
3. Creates an OpenGL context
4. Creates a simple vertex and fragment shader
5. Links the above shaders into a rendering program (and then cleans up the shaders)
6. Creates a basic mesh and loads the mesh data in VAOs and VBOs
7. Renders in a loop.

Fill in the stubs so that a red triangle with vertices A = (0, 0, 0), B = (1, 0, 0), C = (0, 1, 0) is drawn to the screen.

Resize the window. What happens?

Finally, add a glfw callback function that resets the viewport size when the window size changes.

## Challenge Yourself

These are extension questions for self-learning outside of your tute. If there is time in the tutorial, your tutor may go through some of them.

### 1. Draw more than shape on the screen / change the shape
Modify **(D)** so that either more than shape is drawn on the screen or another shape is drawn. What happens if you use really far apart vertices, like (100, 0, 0), (0, 100, 0), (0, 0, 0)?

### 2. Pass the colour into the fragment shader
Modify **(D)** so that the fragment shader doesn't hardcode the colour, but instead accepts it as a variable.

Hint: you will also need to modify the vertex shader to make this happen.

### 3. More exercises in the [set-up repo](https://gitlab.cse.unsw.edu.au/COMP3421/21T3/opengl_cmake_setup)
There are two exercises in the OpenGL environment set-up repo. After this tutorial, see if you can complete them without looking back at any of this week's starter code.

## Further Reading
- [Working with GLFW windows](https://www.glfw.org/docs/latest/window_guide.html)
- [Hello Triangle! on LearnOpenGL.com](https://learnopengl.com/Getting-started/Hello-Triangle)
- [A brief history of computer graphics](https://www.youtube.com/watch?v=QyjyWUrHsFc&t=1s)