# Tutorial 04

This week we are looking at 3D scenes and very primitive animation

## Celestial Bodies

In this exercise, we implement a scene graph to model the solar system.

### A. Explore the starter code (10 min)

Some starter questions:

- What does the `shape::make_sphere` function do and return?
- What does `texture_2d::init` function do and return?
- What is the `scene::node_t` struct for? What type of data structure would it be a part of?

### B. Implementing scene::draw (20 min)

- What is a scene graph?
- How is a scene graph useful?

Implement the function `scene::draw` in scene.cpp so that it:

- Calculates and sets the global transform in the shader
- Draws the node's mesh using its texture (if given)
- Recursively draws all its children

### C. The Solar System (25 mins)

Create and animate a scene graph with a hierarchy that looks like this:

![Imgur](https://imgur.com/IDsXDB7.png)

What is wrong with this scene graph and how might we improve it?

More specifically:

- How can we get the Sun to spin faster on its own y-axis without affecting the other planets?
- How can we give Earth and Mars different orbit speeds around the Sun?

Hint: You can add scene nodes that do not render anything

To get an idea of the relative speeds of rotation between planets you can reference
this [video](https://www.youtube.com/watch?v=uheAXFMQkZU).

### D. Blending Earth's Atmosphere (5 mins)

If there is time remaining use the `CLOUD_TEXTURE_PATH` to create a textured transparent sphere slightly larger than
Earth to give it 'atmosphere'.

Hint: You will have to turn on blending with `glEnable(GL_BLENDING)` and the `glBlendFunc` function.

## Challenges

### 1. Rings of ...Earth?

The scene right now looks too realistic.

Create a new 2D disc primitive to simulate a ring and add it to either the Earth or the Moon.

The ring should also rotate with whichever celestial body it is attached to.

After this, why not stack multiple rings on top of each other and try to blend them?

### 2. Better Orbits

In the real world, orbits are not spherical but are elliptical instead.

Modify the animation of the Moon so that it elliptically orbits the Earth.

You can either make up the focii of the ellipse, or you can search what the actual orbit of the Moon is.

### 3. Data-Oriented Scene Graph

How would you represent  scene graph in a flat 1D array where instead of each node keeping a list of its children it keeps a single index to its parent? How would you draw the nodes?

This alternate implementation is considered more cache-friendly than our current approach (i.e. more data-oriented).

The idea with
[data-oriented design](https://blog.klipse.tech/databook/2020/09/25/data-book-chap0.html)
is if a critical function (like animation) needs to work on a lot of data,
we try to organise that data to be contiguous in memory and not polluted with other data not required by the critical function.

We can take this approach further and separate a scene node's transformation data from its render data so that we have two arrays each representing the same scene graph but containing different data.
The transformation data can then be efficiently processed by an animation system.

## Further Resources

- [LearnOpenGL: Blending](https://learnopengl.com/Advanced-OpenGL/Blending)
- [How to Draw a Sphere](https://stackoverflow.com/questions/5988686/creating-a-3d-sphere-in-opengl-using-visual-c/5989676#5989676)
- [Wikipedia on Scenegraphs](https://en.wikipedia.org/wiki/Scene_graph)
