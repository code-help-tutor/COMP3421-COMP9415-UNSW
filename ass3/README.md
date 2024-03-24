# Assignment 3 - Show me what you got

### Changelog

- Version 0.1 (copy pasting Assignment 2 as a blueprint)
- Version 1.0 (14/11/21 - ready for tutor review)
- Version 1.1 (15/11/21 - release candidate)
- Version 1.2 (16/11/21 - released to students)

## Introduction

The purpose of this assignment is to give students a chance to showcase everything learnt in Graphics and to show mastery of many of the techniques shown in the course, especially those that go beyond what was in tutorials.

Some of the requirements given for this assignment match genuine present day techniques used in computer games. They may also only have been covered in lectures and extension exercises (if at all) and will take considerably more thinking and coding than purely tutorial based requirements from some of the previous assignments.

The assignment will start with content covered in the middle of the course (Setting Design etc), but the majority of the assessment is based on Week 8 content onwards.

### Rationale
 The requirements in this assignment are similar to what we might see when asked to make a custom renderer for a specific game project, so we're now getting much closer to a "real world" game engine's renderer.

Having said that, a modern game engine would potentially take several people months or years to build, so this assignment is only a small selection of techniques that have already been implemented and do not require specific research to implement.

### Difficulty Rating: Very Hard (Exam level of difficulty)

This assignment is mostly extension content that wasn't covered in tutorials. It is testing whether students are able to extend the techniques in the course to their logical "next step".

The expectation is the average student in the course will complete around 10-30% of this assignment (as opposed to much higher in previous assignments). Anyone attempting marks of 60% or higher should expect to look up more advanced techniques, some of which were mentioned in lectures without full implementation shown in tutorials.

In order to show that competency in Computer Graphics (at the introductory level that this course is), it is necessary to earn a mark of 50/100 total in the course. Some students will already have passed that mark before they start this assignment (and will know this before this assignment is due). Please take this into account when deciding how much of this assignment to attempt.

### Marking Notes

As there is some significant overlap between components, like a great number of techniques using renders to framebuffers, there are some overlapping criteria in this assignment. Some more complex techniques will award marks for less complex techniques. This means assignments don't need to do a simple post processing effect if they have implemented Deferred Rendering for example.

## Getting Started

Clone the git repository for the assignment. Each student has their own repository for this assignment accessible via a link: https://gitlab.cse.unsw.edu.au/COMP3421/21T3/students/z5555555/ass3

(you need to change the zID from 5555555 to your ID)

This project should look very similar to the projects you've been using in your tutorials and has been designed to be the same basis that we've been using in this subject.

## Tasks and Assessment Criteria

### 1. The Design Pitch (5%)

Write a design pitch for the project. Note that this pitch does not need to be achieved technically in this assignment, this is a design with a concrete plan for what technology would be needed, not a proof of implementation (see the Subjective Mark for that). No more than 200 words are necessary to complete this component and it can be done in point form if you do not want to write English prose.

1a. World/Setting
- What is the setting?
- What is unique about it?
- What kinds of Graphics features are necessary to display this setting?

1b. Story/Gameplay
- How will this world be used?
- Will characters traverse and view it in a particular way?
- How will it need to be rendered to be useful and visible to a player?

### 2. Advanced Lighting (10%)

2a. Blinn-Phong (5%). Implement Blinn Phong Lighting as the algorithm for calculating light intensity in fragments.

2b. HDR (5%). Implement High Dynamic Range Lighting, rendering the scene to a frame buffer that can hold high dynamic range, then tone mapping back to Low Dynamic Range screen RGB colours. Higher marks awarded for more nuanced tone mapping than linear (must be documented). (Completing this component awards marks for 4a. also)


### 3. Reflections (15%)

3a. (5%) Environment mapped. Implement at least one object with reflections to a premade cubemap like a skybox.

3b. (5%) Realtime Cube Map. Implement the ability to create a cube map in realtime and have at least one object that reflects that map. (Completion of this component awards marks for 3a also)

3c. (5%) Planar Reflections. Implement a Reflective surface using a plane-based render camera. Partial marks awarded for a simple camera that is aimed to look in the reflected view direction. Full marks for a camera with perspective and near plane correction.

### 4. Post Processing (20%)
4a. (2.5%) Simple colour change. Render the scene to a frame buffer, then make some change to the colours before they are displayed on screen. (Completing 2b. awards marks for this component also)

4b. (2.5%) Use of Kernels. Each pixel in the final display is a combination of multiple pixels from a framebuffer.

4c. (5%) Technique using multiple intermediate framebuffers. Use of more than one (necessary) frame buffer for different processes resulting in a final framebuffer.

4d. (5%) Multiple Render Targets. Implementation of a technique that doesn't just render the scene to a framebuffer for later use, but uses custom outputs from the fragment shader to collect data from the scene in potentially multiple buffers for later use. Eg: Screen Space Ambient Occlusion and Deferred Rendering both require fragment positions and surface normals (amongst other data) to be recorded by the fragment shader in separate buffers. (Completion of this component awards marks for 4a, 4b and 4c also)

4e. (5%) Temporal Post Processing. Implementation of a technique that makes use of frame buffer(s) from previous frames. Eg: Motion Blur or Temporal Anti-Aliaising. (Completion of this component awards marks for 4a, 4b and 4c also)
Shadow Mapping (10%)

### 5. Implement a system for casting shadows in your scene.

5a. (5%) Cast shadows from one directional light in the scene. Must use a depth map render from the light's perspective. Can cause artifacts in the scene and still be considered completion of this component.

5b. (5%) Correction of Shadow artifacts/glitches. Possible necessary solutions:
- Implement a shadow bias to remove Shadow Acne in your scene.
- Implement a solution to sampling outside the light's frustum.
- Implement PCF to correct shadow mapping resolution issues.

### 6. Deferred Rendering (15%)

Replace the lighting system in your project with Deferred Rendering. (Completing this with the right features can award marks for 2a, 2b, 4a, 4c, 4d).

6a. (7.5%) Implement a G-buffer, and populate it with a G-pass. If 6b is not implemented, calculate forward rendering using the G-buffer to still have accurate lighting.

6b. (7.5%) Implement Light Volumes. Implement multiple (at least 5) point lights as attenuated shapes that are rendered in a Lighting Pass using the G-buffer.

### 7. Show Me What You Got (15%)

Space to Explore Techniques. If there are any of the techniques in the assignment or course that you want to take further, these marks are here for you to earn credit for the extensions that you choose.

Examples of possible directions (in no particular order):
- Add Transparency Blending to a Deferred Renderer (involves adding a Forward Render pass after the Deferred Renderer is finished)
- Implement a Ray Tracer for Global Illumination. This doesn't have to work in realtime, you can, for example, use it to build scene-wide lightmaps that are later sampled for ambient lighting.
- Cel Shading. Implement a Lighting algorithm that replicates cel shaded animation (a two-tone lighting effect seen in some of the Zelda games). As a bonus, add in edge detection for comic black lining (the ink drawn Borderlands style effect).
- Skinned Animation. Build a skeletal animation system that can use a rigged model (made by someone else) that is able to animate correctly in the scene.
- Particle Effects. Build a particle system able to emit and display particle effects. Show how billboarding and lifetime tracking works.
- Physical Based Rendering. Implement

**For 1, 2 and 3, If you are able to create code that can be seen to be implementing the criteria, but cannot be proven through visible evidence in the application window, you can receive a maximum of half of the available marks for those criteria.**

### 8. Subjective Mark (10%)
Can you create something that is interesting to the human eye? A great deal of successful games/films evoke a feeling of recognition or nostalgia or use colours and movement in an interesting way to attract attention.

Can you use the technical capability you've shown in the use of advanced screen space effects to convey a feeling or an environment?

Note that this mark is not given for impressive technical capability but whether you can use the graphics techniques to evoke a feeling in an observer. You can even be unable to complete the technical part of the assignment but create something that "feels" like an artwork and score highly in this category. It is, as described, a Subjective mark that is entirely about what effect you can have on a human observer.

How this is marked:
- 10/10 - "Wow, look at this, I want to share it right now, my (non-graphics) friends will think it looks cool" or "This looks really interesting, is this a commercially released game?"
- 5/10 - "Hey, this person did the basic parts of the assignment and the scene represents something cool or recognisable"
- 0/10 - "This looks like the tutorials copy pasted into the assignment"

## Documentation Template
A template text file called JUSTIFICATION.md has been included in the cloned project. You will need to edit this file with information on what you have implemented in the assignment.

**IMPORTANT: You will be documenting evidence of what you have worked on in the assignment and will be marked based on what you have claimed to have completed. If you leave this document unedited or empty, you will receive no marks for the assignment.**

**Make sure to refer to which criteria you have completed (e.g. “I completed 3a and 3b but not 3c or 3d”). Also be specific in your justification! Make sure to state which functions and/or line numbers meet a specific criteria (and don’t just say “in main” or “in the render loop”). Failure to do these things may result in an administrative penalty to your marks for this assignment.**

Some example text that you can use in the document. You can obviously write your documentation how you like if these examples don't fit your project.

### Design Pitch (You can't use this pitch and earn marks, it's an example!)

"Welcome to Break Time, the game designed by 2021's Computer Graphics Team. On a planet set too close to a Black Hole, time is literally broken. In one hemisphere, it moves incredibly quickly and in the other, glacially. Hence the setting swaps between high tech and primeval at different parts of the game. Played as a 3rd person open world action adventure game, this has a human perspective while allowing the players to traverse and explore a world.

Our technological side will need motion blur and highly reflective objects to show both its speed and technology. We'll need to make sure the engine can handle arbitrary reflections as well as temporal post processing effects. On the primeval side, we're expecting large vistas, so skyboxing and draw distance will help here as well as using screen space ambient occlusion to deal with complicated outdoor ambient light situations. Suggesting a Deferred Renderer to deal with many lights in the technological side, but this assignment has no intention of implementing that."

### Post Processing

4a. "Implemented a post processing effect that changes all colours to resemble xxxx. The frame buffer is implemented at xxxx and the code that alters the colours and writes them to the final frambuffer is at xxxx in file xxxx"

4d. "Implemented xxxx which requires the use of xxxx and xxxx in the initial fragment shader pass. These details have been written to framebuffers at xxxx and xxxx which are storing the information in the format xxxx. Those are then read in xxxx.frag on line xxxx where they are written to the final framebuffer."

### Subjective Mark

"This project builds a game in the genre of xxxx where the environment usually consists of xxxx with effects that match like xxxx and xxxx. xxxx technique is being used to give a feeling of xxxx."

Remember to explain any references you are using in case they are too obscure for your tutors to know them. You can include links here to other artworks or pop culture references you have used. If you have used any images for your textures or 3D models created by someone else, they must be credited appropriately.

## How to submit

To submit this assignment, you push your solution project to the repository that you have cloned it from. You can push at any time and as many times as you like. We will be marking the final version of your code that has been pushed to the repository.

## Use of External Code and Libraries

If you wish to use any external libraries with the assignment, you do so at your own risk. If you do add any external code to the assignment project, you must clearly state in your submitted document what you are using and exactly how it integrates into the build system as well as exactly what functionality that library adds.

Also note that you do not have any control over what system will be used to test your assignment. We have been very careful with the projects we've given you to make sure they work on Windows, Linux and Mac and all our tutors' testing environments. We obviously cannot give that guarantee for any external libraries, so bear in mind that there's a chance that including external libraries will cause a project to fail even the simplest tests and potentially cost a great deal of marks.

## Due Date: Friday 3rd December 8pm

Late penalty is 20% off maximum mark for every 24 hours after 8pm. This means if you hand something in that's between 1 and 2 days late, your maximum mark will be lowered to 60%. Your mark itself will not be changed if it's lower than the new maximum.

As this assignment is due during the exam period, different students will have different time pressure based on your exam schedule. If you require an extension due to exams conflicting with the time you need to work on this assignment (particularly exams close to the 3rd), email cs3421@cse and we will arrange an extension for you. Note that any extensions may delay the release of your marks, but will not affect what mark you eventually receive.

### Special Consideration

If you have any issues that stop you from being able to complete this assignment, you may be eligible for Special Consideration through UNSW. Please see https://student.unsw.edu.au/special-consideration if you need more information. Some of you may already have let us know that you have Special Consideration in advance. If this is the case and you would like to make use of any extensions you have been granted, you can contact your tutor.

### Plagiarism and Academic Misconduct
This assignment is an individual assessment and is intended to be completed and submitted by an individual student. If you would like more information about Plagiarism please see https://student.unsw.edu.au/plagiarism .

You are free to discuss any content that has been covered in tutorials, but any code that you have written that extends beyond the tutorials is not allowed to be shared with other students or discussed at a close enough level to result in two students implementing functionally the same code.

This means you can discuss algorithms (especially at the level that we've taught in class), but once you delve into design of specific code structures or any code itself, that is considered to be plagiarism.

If any two assignments provide identical visual output, they will be investigated for code similarities to determine if the work is definitely individual and similarities are coincidental.
