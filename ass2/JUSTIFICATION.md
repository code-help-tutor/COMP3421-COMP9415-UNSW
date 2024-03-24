# Assignment 2 Justification

If you think any of the questions within the sections are not applicable, please write "N/A".

## Section 1: Creation and Use of 3D Objects

### 1a: Show that you have created or imported at least one 3D object that is visible in your application. Include references to where this is implemented in your code.

My application creates several primitive 3d objects like cube, sphere ...

### 1b: Describe your scene graph and the hierarchy within the scene. Include references to where this is implemented in your code.

In my scene graph, root node is ground and it has children volumn, sphere. On seconde level , shpere has child earth which is also a sphere.

### 1c: Describe how your objects are moving or animating in realtime. Include code references (line numbers and function names) to use of delta time and also how this affects the scene graph.

In my application, we can use real time to update point_light, the speed is controlled by dt. Also, the camera move is also controlled by dt.

### 1d: Describe how you have used parametric splines in your application. Include code references to the implementation of control point based curves in your project.

I didn't successfully apply spline curve in animation.

## Section 2: Camera

### 2a: Describe what controls the player should use to move the camera in your scene. Include code references to the implementation of delta time control of speed and use of user input in your project.

"fly" camera was successfully designed to view above.

### 2b: Describe how your camera interacts with the scene. Is it able to "walk" on the Z-X plane or follow terrain? Include code references.

without mouse input, control the camera simply by "w" "a" "s" "d" can alllow view to stay at Z-X plane.

### 2c: Describe how the view of your scene can change from player controlled to application controlled (specify user input that makes this change happen). Include code references to use of parametric curves and delta time in the application controlled camera.

No cutscene camera was applied.

## Section 3: Lighting

### 3a: Describe where Diffuse Lighting is clear to see in your application. Include code references to your implemented lighting (including where this is implemented in your shaders).

Diffuse lighting was successfully designed.

### 3b: Describe where Specular Lighting is clear to see in your application, including how the camera position affects the lighting. Include code references to your implemented lighting (including where this is implemented in your shaders).

Specular lighting was successfully designed.

### 3c: Describe which of your light(s) in your scene are point light(s) and how you have placed objects in the scene to clearly show the point lights functioning. Include code references to point light implementation.

Point light was added in the scene.

### 3d: Describe all the lights in your scene and what type they are. Include code references to implementation of the capability to work with an arbitrary number of lights.

I didn't use multiple lights here.

### 3e: Explain what maps you have used and which objects they are on. Your application should clearly show the effect these maps are having on lighting. Include code references to maps on objects and vertices as well as lighting code that uses the maps.

diffuse mapping and specular mapping have been used on the sphere and cube.

## Section 4: Subjective Mark

### How have you fulfilled this requirement?

I did not fulfill this requirement and will not receive marks for Section 4. 
(If you would like your Section 4 to be marked, you will need to replace these lines)

### What is your vision for the scene you are showing?

cubes and spheres on flat earth...

### Are you referencing anything in this scene? Is this a quote or homage to any other art? Please describe it.

No

### Please give instructions for how a viewer/player should interact with this scene to see all the content you have created.

Use "wasd" and mouse to adjust camera and "q" "e" keys to adjust point light position.

## Section 5 (optional): Code Style Feedback

### There are no marks assigned to code style in this assignment. However, if you would like to receive some feedback on your coding style, please point out a section of your code (up to 100 lines) and your tutor will give you some written feedback on the structure and readability of that code.

Write your answer here (lines numbers or function names that you'd like reviewed)

## Section 6 (optional): Use of External Libraries

### What does the library do?

Write your answer here...

### Why did you decide to use it?

Write your answer here...

### How does this integrate with the assignment project build system? Please include any instructions and requirements if a marker needs to integrate an external library.

Write your answer here...
