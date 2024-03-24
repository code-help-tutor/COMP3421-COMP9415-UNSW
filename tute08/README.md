# Tutorial 08

This is the second of a series of tutorials dedicated to the simulation of light in computer graphics.

## eSpecially Spectacular Specular Spectacles

This week focuses on point lights and the specular highlight, as well as nifty ways to encode the specularity of a model through a specular map.

### A. Gamma Accuracy (10 mins)

Our lighting calculations so far have assumed that color is linear - that multiplying a color by 0.5 will give a color half a bright. However, most computer monitors use an sRGB color space which is not linear.

Why do most computer monitors use sRGB?

The mathematical function `f(x) = x^2.2` can be used to approximate a conversion from sRGB to linear. Write two GLSL functions to convert linear to sRGB and sRGB to linear. Use these functions on any input or output colors so that all lighting calculations are in linear space.

Notice how the lighting now has a much sharper edge. This may look unrealistic, but this is how an object lit by a single light looks (see the moon for reference). Adding more lights and/or ambient lighting can help with this.

### B. Point Lighting (10 mins)

Directional lights conceptually are infinitely far away from the viewer and so their light vector is the same everywhere.

Point lights on the other hand exist at a specific position, and so the direction to them depends on both the light's position as well as the camera's.

Additionally, objects that are closer to the light source should be brighter. Directional light sources are so far away this isn't noticable, but for a smaller light source this matters.

Complete the `point_light_t` type definition in `light.hpp` and modify the scene's directional light to be a point light.
Additionally, modify the renderer and shaders to calculate the direction to the light and the falloff for each fragment.

### C. Creating the Specular Highlight (10 mins)

Now it is time to make our first specular highlight. For the first attempt:
- Create a `uniform vec3` in the fragment shader for the models' specular colours.
  - Feel free to experiment with colours.
- Create a `uniform float` for the intensity of the specular highlight (termed 'shininess').
  - What do bigger values produce? Smaller?
  - > Bigger values mean a larger highlight. Smaller will produce a smaller one.

Add logic to the vertex and fragment shaders to implement the specular portion of the Phong light model.

### D. Blinn-Phong (5 mins)

Modify the fragment shader to implement the canonical Blinn-Phong lighting model.

Hint: you will need to calculate the halfway vector between the light direction and the viewer.

> Additionally, instead of doing dot(R, V), where R is the reflection vector and V the viewer vector, you'll need to do dot(N, H), where N is the surface normal andH is the halfway vector.

### E. Specular Maps (25 mins)

A common (read: ubiquitous) technique to model a model's relative specularity with ease is to encode the specular colour in a texture known as a specular map (spec map for short).

> Feel to create or use your own, too!

Use the provided spec maps for the cube, sphere and torus and apply them in the fragment shader rather than using the hardcoded uniforms.

You will need to use two samplers in your fragment shader to access these textures.

> Multiple textures of the same type can be used in a shader by using the various texture units and binding to the uniform samplers 0 for GL_TEXTURE0, 1 for GL_TEXTURE1, etc.

## Challenge Yourself

### 1. Homebrew Texture Maps

Rather than using the provided specular maps, [create your own](https://www.youtube.com/watch?v=h5I0k3xifdg&list=PLZpDYt0cyiuu-sxJKbuYh8OjtgmXNacCV&index=89&ab_channel=RoyalSkies) for the cube, sphere, and torus.

You can also try loading in your own custom models and creating specular maps for them too!

### 2. Emissive Maps

The technique of baking into a texture properties of how light should interact with your model can be extended to far more than specularity.

Another such map is called an emissive map, which can be thought of as how much your model "glows".

Try creating an emissive map and applying it to a model.

How does it add to the light equation?

### 3. Dynamically Moving Lights

Add some kind of animation to the point light so that you can see in realtime how position affects the lighting of models.

## Further Resources
- [Learn OpenGL on lighting](https://learnopengl.com/Lighting/Basic-Lighting)
- [Excellent tutorials on how to use GIMP for 3D artists](https://www.youtube.com/playlist?list=PLZpDYt0cyiuu-sxJKbuYh8OjtgmXNacCV)
- [How Wind Waker implemented a cartoon lighting model](https://www.youtube.com/watch?v=mnxs6CR6Zrk)
