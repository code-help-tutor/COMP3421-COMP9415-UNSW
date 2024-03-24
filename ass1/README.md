# COMP3421 Assignment 1: Getting Ready for Graphics Programming

### Changelog
- Version 1.0 (Released on 18/9/2021): Note that Information on Infrastructure is still pending.
- Version 1.1 (Released on 18/9/2021): Assignment repos proper released to students
- Version 1.2 (Released on 20/9/2021): Assignment build system and submission instructions updated

## Introduction
The purpose of this assignment is to get you ready for Graphics Programming and to give you a taste of how the basic setup and "Hello World" of an OpenGL Programming environment should work.

### Rationale
In a professional sense, programmers and engineers are usually expected to be able to set up complicated project environments from basic web based documentation (that might not be 100% clear or even fully tested). In other, less commercial fields, we will often be building homebrew setups for our own entertainment and things like hobbyist programming, so getting practice with this is good regardless of your aspirations.

On top of this, a basic environment is necessary to continue learning the technical side of this course, so we put this test in here before the UNSW Census date so that you can decide if your progress is enough for you to be confident in continuing.

### Difficulty Rating: Routine
This assignment is not objectively difficult and does not push you beyond what you've learnt in tutorials.

The major points of difficulty are:
- Correct install and use of a programming environment such that you can share code with someone else using the same environment and they can achieve the same result as you.
- Some understanding of OpenGL setup code and basic use of vertices and textures.
- Clear documentation of your work.


## Getting Started
Clone the git repository for the assignment.

This project should look very similar to the projects you've been using in your tutorials and has been designed to be the same basis that we've been using in this subject.


## Tasks and Assessment Criteria
### 1. It runs (30%)
Your code compiles on someone else's computer (in this case, the tutor) in our basic environment and builds successfully. When run, it opens an OpenGL window (even if nothing is visible).

This 30% tests whether you can successfully set up and configure your development environment. You are free to get any help you need from course staff to complete this as it's also part of your tutorials to be able to do this.

Consider success in this task a baseline necessity to complete this course.

### 2. Visibility and Shaders (10%)
Vertex and fragment shaders are working in the project. They build without causing errors. There is a demonstration in the running application that shaders are functioning. This means if you are unable to complete the tasks using Textures, you can at least prove that shaders are working with colours.

Your application window shows that you can display something. If it is unable to display any objects, you can set your background colour to something obvious to show that OpenGL is running.

### 3. Creation and Use of 2D Shape(s) (25%)

3a. (10%) Your application is able to create a 2D shape and it is visible in the application window.

3b. (5%) Your application is able to create multiple 2D shapes that are visible in the application window.

3c. (5%) Your application uses Matrix Transforms to position and/or alter a 2D shape and this is visible in the application window.

3d. (5%) Your application uses the render loop to animate transforms of shape(s) so that they move while the application is running.


### 4. Use of Texture(s) (25%)
4a. (10%) Your application is able to load texture a texture file and apply it to an object. Evidence of this is visible in the application window.

4b. (10%) Your application is able to load multiple textures and apply them to different objects. Evidence of this is visible in the application window.

4c. (5%) Your application is able to alter or change textures on objects during runtime. Evidence of this is visible in the application window.

**For 3 and 4, If you are able to create code that can be seen to be implementing the criteria, but cannot be proven through visible evidence in the application window, you can receive a maximum of half of the available marks for those criteria.**


### 5. Subjective Mark (10%)
Can you create something that is interesting to the human eye? A great deal of successful games/films evoke a feeling of recognition or nostalgia or use colours in an interesting way to attract attention.

Can you use the technical capability you've shown in the use of 2D shapes, transforms and textures to show an idea, a character or part of a story? Or if it's not that explicit, can you evoke a feeling through use of colours and artistic composition?

Note that this mark is not given for impressive technical capability but whether you can use the graphics techniques to evoke a feeling in an observer. You can even be unable to complete the technical part of the assignment but create something that "feels" like an artwork and score highly in this category. It is, as described, a Subjective mark that is entirely about what effect you can have on a human observer.

How this is marked:
- 10/10 - "Wow, look at this, I want to share it right now, my (non graphics) friends will think it looks cool" or "This looks really interesting, I can't even tell that it's a bunch of rectangles with image textures on them."
- 5/10 - "Hey, this person did the assignment and the texture is a picture of something cool or recognisable"
- 0/10 - "This looks like the tutorials copy pasted into the assignment"

## Documentation Template
A template text file called JUSTIFICATION.md has been included in the cloned project. You will need to edit this file with information on what you have implemented in the assignment.

**Important: You will be documenting evidence of what you have worked on in the assignment and will be marked based on what you have claimed to have completed. If you leave this document unedited or empty, you will receive no marks for the assignment.**

Some example text that you can use in the document:

### 1. It runs
"This project completes this task and I have tested that the application builds with no errors and runs under the assignment environment provided by the course."
"My project is based on the assignment project provided by the course. I have made changes to the following files . . . and have added the following files . . ."


### 2. Visibility and Shaders
"This project completes this task and includes shaders that compile and function correctly."
"My vertex shader is called xxxx.vert and is in the xxxx folder."
"My fragment shader is called xxxx.frag and is in the xxxx folder."

"I have tested that the application builds and runs with no shader errors."

"When running the built project, you should immediately see two squares with pictures of xxxx . . ."


### 3. Creation and Use of 2D Shapes
"This project completes 3a, 3b and 3c but not 3d." - example only, you'd write what you have actually completed!

"3a. You can see when you run the application that there is a xxxx near the centre of the view. The code that relates to that object is in the file xxxx. You can see the vertices and indices at lines xxxx and the code invoking the OpenGL calls at lines xxxx that make sure that this draws."


### 4. Use of Textures
"This project completes 4a, but not 4b or 4c." - example only, you'd write what you have actually completed!

"4a. The texture file is called xxxx and is in the xxxx folder. It is applied to the object named xxxx using the code at lines xxxx. Running the application, the square in the top left of the window should show xxxx."

### 5. Subjective Mark
"This project shows a reference to a scene from 2012's xxxx by xxxx where a particular event happens which has a particularly striking effect, which is replicated here by use of xxxx . . ."

Remember to explain any references you are using in case they are too obscure for your tutors to know them. You can include links here to other artworks or pop culture references you have used. If you have used any images for your textures, they must be credited appropriately.


## How to submit

To submit this assignment, you must submit your entire project folder, based on the repo cloned for the start of the assignment.


## Use of External Code and Libraries

If you wish to use any external libraries with the assignment, you do so at your own risk. If you do add any external code to the assignment project, you must clearly state in your submitted document what you are using and exactly how it integrates into the project as well as exactly what functionality that library adds.

Also note that you do not have any control over what system will be used to test your assignment. We have been very careful with the projects we've given you to make sure they work on Windows, Linux and Mac and all our tutors' testing environments. We obviously cannot give that guarantee for any external libraries, so bear in mind that there's a chance that including external libraries will cause a project to fail even the simplest tests and potentially cost a great deal of marks.

## Due Date: Friday 1st October 5pm

Late penalty is 20% off maximum mark for every 24 hours after 5pm. This means if you hand something in that's between 1 and 2 days late, your maximum mark will be lowered to 60%. Your mark itself will not be changed if it's lower than the new maximum.

We're not trying to be harsh with these deadlines, so if you have a reason why you weren't able to hand something in in time, you can contact your tutor for an extension and we'll be quite friendly with short extensions.

### Special Consideration
If you have any issues that stop you from being able to complete this assignment, you may be eligible for Special Consideration through UNSW. Please see https://student.unsw.edu.au/special-consideration if you need more information. Some of you may already have let us know that you have Special Consideration in advance. If this is the case and you would like to make use of any extensions you have been granted, you can contact your tutor.

### Plagiarism and Academic Misconduct
This assignment is an individual assessment and is intended to be completed and submitted by an individual student. If you would like more information about Plagiarism please see https://student.unsw.edu.au/plagiarism .

However, the majority of the technical skills and work involved in the assignment is from the course's tutorials, so you are free to discuss the requirements and the techniques (and are encouraged to do so on the course Discord where you can get advice from course staff).

It is not considered plagiarism for a student to submit code that they have worked on in tutorials for this assignment. It is also not considered plagiarism for students to help each other review and debug code in this assignment.

If any two assignments provide identical visual output, they will be investigated for code similarities to determine if the work is definitely individual and similarities are coincidental.
