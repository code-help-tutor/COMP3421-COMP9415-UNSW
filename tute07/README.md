# Tutorial 07

## Let There Be Light

This is the first of a series of tutorials dedicated to the simulation of light in computer graphics.

This week focuses on ambient and diffuse lighting, as well as directional lights.

### A. Normal on the Surface (20 mins)

One vertex attribute only alluded to until now is the surface normal at that vertex. Normals are indispensable in the Phong shading model.

Look at `src/primitives.hpp`: currently there is code there to draw volumes (rectangular prisms), spheres, and toruses (tori).

Add to this code logic to calculate the normals. You will also need to modify `upload_mesh()` so that the normals are added to the vertex buffer objects. Furthermore, you will need to modify `default.vert` so that it now accepts the new vertex attribute.

### B. Directional Sunlight (20 mins)

In addition to normals, the light equation unsurprisingly requires a light source.

We shall create a **directional** light, which consists only of a direction vector _to_ the light source.

To the vertex shader add a "sunlight" direction vector of `{0, 100, 0}` in world-space.

Then, complete the diffuse and ambient Phong lighting calculation in the fragment shader as discussed in lectures.

What else do you need to add to the vertex shader to make sure the calculations are valid?


### C. Naive Day/Night Cycle (20 mins)

To examine how the light direction affects shading, let's create a primitive day/night cycle.

Modify the scene struct so that the sunlight vector is passed to the shader as a uniform like the MVP matrices.

Then, modify `main.cpp` so that:
- When the user presses Q, the sun vector is rotated about Z so that it moves towards the negative X-axis. This effectively simulates "setting" in the west.
- When the user presses E, the sun vector is rotated about Z so that it moves towards the positive X-axis. This effectively simulates "rising" in the east.

## Challenge Yourself

### 1. Lighting `.obj` models

The `.obj` model format stores the surface normals of each vertex.

Try loading a model of your choosing and lighting it.

### 2. Sunrise & Sunset

The full Phong shading light equation multiplies the material's diffuse coefficient with the light's diffuse coefficient; in this tutorial we assume the sun's diffuse coefficient is `{1, 1, 1}` (as real sunlight is).

This need not be the case, however. Coloured lights do exist.

A great place to apply coloured lighting would be in simulating the sunlight colour as sunrise and sunset.

Modify the sunlight light source so that at extremely oblique viewing angles its diffuse colour changes in accordance with sunrise and sunset.

## Further Resources
- [LearnOpenGL: Lighting](https://learnopengl.com/Lighting/Colors)
- [Gouraud vs. Phong shading](https://vivadifferences.com/difference-between-gouraud-shading-and-phong-shading/)
- [Creating Diffuse Maps (in only 15 seconds!!!)](https://www.youtube.com/watch?v=ihOwGUR3igI)

