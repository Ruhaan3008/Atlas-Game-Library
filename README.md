# Atlas Game Library
This is a game library based on the OpenGL, that I made as a side project. I fairly new to C++ there might be a few bugs here and especially the error handling code.

## Adding Altas to your porject
First you will need to GLFW and GLEW to your project. Make sure that the GLFW and GLEW header files are selected in addition header files. Then go ahead and paste the src folder into your project.
The source code contains STBI and glm source files also so you don't need to add them. If you want to know how to use Atlas youu can go through the Main.cpp file in sample folder.

## Why isn't Atlas working for you?
- The first reason is bacause you did not call the AtlasInnit() function. This has to be called before any other Atlas function or class. 

- Second you must call the Window class immediately after the AtlasInnit() function.

- Third because this library is still in its early stages some functionality will change over time.