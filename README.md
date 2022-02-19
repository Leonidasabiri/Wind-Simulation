# Grass-Simulation

- About the project

This is grass simulation written with c++ and based on the opengl API, it contains grass blades with segments that gets affected by gravity and wind force.

- The approach that i used

The first thing to do is to create a single grass blade with segments that can rotate using a simple rotation matrix, having that single grass blade work kinda made the rest of the process on how to code this simulation clear enough to experiment some ideas, .. to make things simple and keep track of what i will be doing i went with 2D first.

## The segment at the start
<img src="https://user-images.githubusercontent.com/54768823/149226084-12adf85c-8411-4d1d-9c7b-5dfa3c8a30ca.gif" width=250>

## Using noise for winds
To make the grass swaying look like it's been affected by actual wind, using generated shader noise is perfect approach for that, i tried getting the x and y value from the noise to affect each grass blade on it's own, the grass terrass is rendered using GPU instancing to save memory and to hold performance even if the grass blades are more than 200000 blade.
