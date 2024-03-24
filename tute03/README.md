# Tutorial 03

This week we are moving into the 3D world: 3D objects and 3D transforms.

## A. Cube Cam (60 mins)

This exercise consists of two parts: building our first (true) 3D object with an EBO, and implementing a first-person camera.

The object will be a coloured cube.


### Part 1. Building the Cube

Inside of `src/main.cpp`, complete the functions marked `TODO: Part 1` to draw and colour the cube with an **element buffer object**.


The observer should be looking at the front of the cube at a reasonable distance when the program is executed.

### Part 2. Discovering the Secret

Once the cube has been built, complete the functions marked `TODO: Part 2` to implement a movable FPS camera.

The camera should:
- move:
  - toward wherever it is looking when W is pressed
  - away from wherever it is looking when S is pressed
  - strafe left when A is pressed
  - strafe right when D is pressed
- change where it is currently looking by moving the mouse around

Using this camera, why don't you go for a nice flighty stroll around the cube?

## Challenge Yourself

### 1. Removing fly-mode

Having the ability to fly anywhere in the world is useful for development but hardly realistic in most cases. Modify the FPS camera so that even though you can look anywhere, movement is always limited to a two-dimensional flat plane.

### 2. Adding boundaries

Currently, there is nothing stopping the user from going through geometry (so-called "clipping"). How might you change the program to add some physics to the world so that you cannot go through the cube?

Things to consider:
- Data layout is very important. Should you store the boundaries of the brick cube with the position, texture-coordinates, etc.? Or should you store them separately? What are the tradeoffs?
- [AABB](https://tutorialedge.net/gamedev/aabb-collision-detection-tutorial/) collision detection is quite nice for 2D, but will it work unmodified for 3D?

### 3. Texturing in 3D

Currently, the cube is using colour interpolation.

A more realistic thing to do would be to have a flat texture map for the cube and map each respective face to the cube.
Change the program so that a dice texture is applied to the cube faces.
You will have to source a texture yourself.

## Further Reading

- [Learn OpenGL: Cameras](https://learnopengl.com/Getting-started/Camera)
- [Essence of linear algebra](https://www.youtube.com/playlist?list=PLZHQObOWTQDPD3MizzM2xVFitgF8hE_ab)
- [Data-Oriented Design in C++ (Presentation)](https://www.youtube.com/watch?v=rX0ItVEVjHc)

