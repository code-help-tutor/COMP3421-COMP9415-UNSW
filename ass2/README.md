# COMP3421/9415 Assignment 2 - Developing Historical 3D Graphics

### Changelog
- Version 0.1 (Released on 19/10/2021): copy pasting Assignment 1 as a blueprint
- Version 1.0 (Released on 19/10/2021): first draft of Assignment 2
- Version 1.1 (Released on 19/10/2021): revisions based on tutor feedback, ready for public release
- Version 1.2 (Released on 20/10/2021): fixed due date to Friday Week 09
- Version 1.3 (5/11/2021): Changed Multiple Lights to allow for only a single Directional Light

## Introduction
The purpose of this assignment is to learn about the fundamentals of 3D Graphics and Lighting. It's titled Historical 3D Graphics as these techniques were cutting edge in the late 1990s. The main focus is on two things:
- 3D Geometry with scene organisation and realtime animation
- Lighting, including diffuse and specular objects as well as directional and point lights


## Rationale
While some of the techniques you're working on in this assignment aren't the main techniques for lighting and animation in present day realtime graphics, they are still definitely the basis for modern techniques. Without a solid understanding of the basics underlying Polygon Rendering, advanced techniques like Skeletal Animation/Inverse Kinematics or Deferred Rendering/Ray Tracing would be nearly impossible to understand.

This assignment sits at a very good place for students who have only been working on Graphics for a month or two. Your understanding should hopefully be at a point where you can approach a project like this with some useful knowledge, but it's also still challenging enough to teach you something interesting.

## Difficulty Rating: Medium
This assignment is more difficult than the first assignment and it's reasonable for people to hand in partial solutions without being too worried about not fully understanding Graphics at this introductory level.

The expectation is the average student in the course will complete around 50-70% of this assignment (as opposed to 80-100% for Assignment 1). There is less guidance in the tutorials on exactly how to complete all the tasks in the assignment and you will need to come up with some of your own solutions to the challenges in the assignment.


## Getting Started
Clone the git repository for the assignment. Each student has their own repository for this assignment accessible via a link: https://gitlab.cse.unsw.edu.au/COMP3421/21T3/students/z5555555/ass2

(you need to change the zID from 5555555 to your ID)

This project should look very similar to the projects you've been using in your tutorials and has been designed to be the same basis that we've been using in this subject.

## Tasks and Assessment Criteria

### 1. Creation and Use of 3D Objects (35%)
1a. (5%) Your application is able to create or import a 3D object and it is visible in the application window.

1b. (10%) Your application is able to create multiple 3D objects (or models) that are organised in a transform hierarchy. To complete this criteria, there must be at least three levels of objects in the hierarchy, organised in a scene graph. If objects are not animating and hence, it's not clear there's a hierarchy in the application, documentation must be included of how the scene graph is structured and implemented.

1c. (10%) Realtime use of objects. Your application makes objects animate relative to each other using delta time to control speed regardless of a computer's performance. They will maintain a scene graph while doing this.

1d. (10%) Use of splines. Show that you can use parametric splines either to create curved shapes or curved paths for an object to animate on (or both).

### 2. Camera (15%)
2a. (5%) You have a camera in the scene which is controllable by the user. A camera that's able to "fly" in the scene by translating and rotating based on user input and also uses delta time to control speed.

2b. (5%) The Player Camera. A camera that can "walk". Its movement is bound to the X-Z plane in the scene (or it can follow uneven terrain, maintaining a Y distance from a surface) while it can still look around in nearly all directions and does not gimbal lock.

2c. (5%) The Cutscene Camera. This camera can switch to a different mode (without needing to restart the application) where it animates a specific path using both delta time and parametric splines. This can be a fly through, or an orbit of an object etc, but it takes control away from the player temporarily.

## 3. Lighting (40%)
3a. (5%) Diffuse Lighting. Your application includes a directional light which is implemented correctly and can be seen to be lighting objects from its direction correctly.

3b. (10%) Specular Lighting. Your application includes specular lighting and one or more of your objects is capable of showing specular highlights that appear correct from the viewer's (camera's) perspective.

3c. (10%) Point Light(s). Your application has the capability to use point lights and this is shown clearly by having a distinct colour point light near multiple objects so that you can see it lighting objects around it. The point light(s) must be able to apply both diffuse and specular lighting to objects and this must be clearly seen in the application.

3d. (5%) Multiple Lights. In 3a-c, you are required to have at least 1 directional light and one point light. This component involves making multiple lights of different types and using them in the scene. Each light should be obviously a different colour/location/direction so it is clear the different effects they're having on the scene. There must be a minimum of 2 point lights to score marks in this section.

3e. (10%) Maps. Your application can implement different maps on one object. The most obvious examples would be a specular map that makes only part of an object "shiny" or a normal/bump map that gives a surface visible "roughness".

**For 1, 2 and 3, If you are able to create code that can be seen to be implementing the criteria, but cannot be proven through visible evidence in the application window, you can receive a maximum of half of the available marks for those criteria.**

## Subjective Mark (10%)
Can you create something that is interesting to the human eye? A great deal of successful games/films evoke a feeling of recognition or nostalgia or use colours and movement in an interesting way to attract attention.

Can you use the technical capability you've shown in the use of 3D shapes, basic animation and lighting to show an idea, a character or part of a story? Or if it's not that explicit, can you evoke a feeling through use of shapes and artistic lighting?

Note that this mark is not given for impressive technical capability but whether you can use the graphics techniques to evoke a feeling in an observer. You can even be unable to complete the technical part of the assignment but create something that "feels" like an artwork and score highly in this category. It is, as described, a Subjective mark that is entirely about what effect you can have on a human observer.

How this is marked:
- 10/10 - "Wow, look at this, I want to share it right now, my (non-graphics) friends will think it looks cool" or "This looks really interesting, I can't even tell that it's a bunch of rectangles with image textures on them."
- 5/10 - "Hey, this person did the assignment and the texture is a picture of something cool or recognisable"
- 0/10 - "This looks like the tutorials copy pasted into the assignment"

## Documentation Template
A template text file called JUSTIFICATION.md has been included in the cloned project. You will need to edit this file with information on what you have implemented in the assignment.

**IMPORTANT: You will be documenting evidence of what you have worked on in the assignment and will be marked based on what you have claimed to have completed. If you leave this document unedited or empty, you will receive no marks for the assignment.**

**Make sure to refer to which criteria you have completed (e.g. “I completed 3a and 3b but not 3c or 3d”). Also be specific in your justification! Make sure to state which functions and/or line numbers meet a specific criteria (and don’t just say “in main” or “in the render loop”). __Failure to do these things may result in an administrative penalty to your marks for this assignment.__**

Some example text that you can use in the document. You can obviously write your documentation how you like if these examples don't fit your project.

### 1. Creation and Use of 3D Shapes
1a. "In part 1, a,b and c are completed, while d is only partially working. The majority of the code for these is in the functions in the following list: . . . The structs xxxx and xxxx are also important for these functions."

1b. "The scene is organised into a scene graph. The code structures are declared at line xxxx and used from lines xxxx to xxx to create the initial scene. Note how the xxxx is a child of xxxx, and xxxx is a child of xxxx."

1c. "Without moving the camera from its starting position, you can clearly see the xxxx in motion. Its child object xxxx is obviously attached to xxxx and is also animating its own path relative to it. The code governing the changing relationship between the two starts at line xxxx in file xxxx, the function animate_xxxx()."

1d. "I am not claiming any marks for 1d."

### 2. Camera
2b. "Press xxxx to switch back and forth between the animating camera and the free roam camera. The animating camera is following a series of bezier curves to do a "fly through" of the scene. The entire fly through should take 20 seconds. Pressing xxxx the viewpoint to where it was before switching to the animating camera. The code that deals with the free roam camera (and user input) is at lines xxxx and the animating camera is controlled by the function xxxx at line xxxx."

### 3. Lighting
3c. "There is a point light between the xxxx and the xxxx, which are just to the left of where the camera starts in the scene. This light is coloured a bright xxxx, so it is obvious that the two objects are being lit from that point in space. In order to visualise it easier, I have placed a small model of a xxxx at the exact position of the light. My main lighting code starts at line xxxx. Note that code at xxxx deals with multiple lights and lines xxxx show use of both diffuse and specular components in the lighting."

### 4. Subjective Mark
"This project shows a reference to a scene from 2001's xxxx by xxxx where a particular event happens which has a particularly striking effect, which is replicated here by use of xxxx . . ."

Remember to explain any references you are using in case they are too obscure for your tutors to know them. You can include links here to other artworks or pop culture references you have used. If you have used any images for your textures, they must be credited appropriately.

## How to submit
To submit this assignment, you push your solution project to the repository that you have cloned it from. You can push at any time and as many times as you like. We will be marking the final version of your code that has been pushed to the repository.


## Use of External Code and Libraries
If you wish to use any external libraries with the assignment, you do so at your own risk. If you do add any external code to the assignment project, you must clearly state in your submitted document what you are using and exactly how it integrates into the build system as well as exactly what functionality that library adds.

Also note that you do not have any control over what system will be used to test your assignment. We have been very careful with the projects we've given you to make sure they work on Windows, Linux and Mac and all our tutors' testing environments. We obviously cannot give that guarantee for any external libraries, so bear in mind that there's a chance that including external libraries will cause a project to fail even the simplest tests and potentially cost a great deal of marks.

## Due Date: Friday 12th November 8pm
Late penalty is 20% off maximum mark for every 24 hours after 8pm. This means if you hand something in that's between 1 and 2 days late, your maximum mark will be lowered to 60%. Your mark itself will not be changed if it's lower than the new maximum.

We're not trying to be harsh with these deadlines, so if you have a reason why you weren't able to hand something in in time, you can contact your tutor for an extension and we'll be quite friendly with short extensions.

### Special Consideration
If you have any issues that stop you from being able to complete this assignment, you may be eligible for Special Consideration through UNSW. Please see https://student.unsw.edu.au/special-consideration if you need more information. Some of you may already have let us know that you have Special Consideration in advance. If this is the case and you would like to make use of any extensions you have been granted, you can contact your tutor.

### Plagiarism and Academic Misconduct (changes from Assignment 1)
This assignment is an individual assessment and is intended to be completed and submitted by an individual student. If you would like more information about Plagiarism please see https://student.unsw.edu.au/plagiarism .

You are free to discuss any content that has been covered in tutorials, but, as opposed to the previous Assignment, any code that you have written that extends beyond the tutorials is not allowed to be shared with other students or discussed at a close enough level to result in two students implementing functionally the same code.

This means you can discuss algorithms (especially at the level that we've taught in class), but once you delve into design of specific code structures or any code itself, that is considered to be plagiarism.

If any two assignments provide identical visual output, they will be investigated for code similarities to determine if the work is definitely individual and similarities are coincidental.
