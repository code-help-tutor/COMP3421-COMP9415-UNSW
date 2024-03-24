# COMP3421/9415 Tutorials

## Introduction
This is a monorepo that contains the tutorial content as well as build system for COMP3421/9415.

You are free to clone this repo and hack away at it to your heart's content. However, we will not be accepting merge requests so please don't make any.


## How To Use
It is assumed that you at least have Git and CMake installed on your system. If not, please see [this](https://gitlab.cse.unsw.edu.au/COMP3421/21T3/opengl_cmake_setup) and [this](https://gitlab.cse.unsw.edu.au/COMP3421/21T3/git101).

Simply clone this repo with `git clone --recurse` and open CMake with the root CMakeLists.txt file being the one in this directory.
Don't forget to make a directory called `build` that should be the root of your build tree.
If there aren't any problems with requisite packages, all executables and resources should compile and be copied into `bin/<the week>/`.
You can either navigate to that directory directly and run the executables, or use whatever runner your IDE of choice has.

As we update the tutorials, you will need to periodically `git pull` the changes and also run `git submodule update --recursive --remote` to grab the latest updates to our dependencies.

## General Structure
Every tutorial has a theme that follows the [course outline](https://webcms3.cse.unsw.edu.au/COMP3421/21T3/outline).


Each week your tutor will go through that week's tutorial questions with an emphasis on practicality. This means that there will be alot of livecoding.
Solutions will be available for the tutorial questions at the end of each respective week.


To supplement the demonstration, each week also has several challenge exercises that build off the tutorial questions and are designed to get you personally familiar with the OpenGL API and also teach you things we don't have time to cover.
There are **no marks** associated with these exercises and **solutions will not be released.**
You are of course welcome and encouraged to openly discuss these exercises with your peers on the forum, and can ask your tutors about them.


