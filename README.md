# Boids
 
 "Boid" = Bird Oid Object
 
 No Preview on this.
 
 Youtube video - https://youtu.be/YBTd4U5xedY
 
Concept from -
https://cs.stanford.edu/people/eroberts/courses/soco/projects/2008-09/modeling-natural-systems/boids.html
.-
.-
.-
.-
.-
.-
.-
.-
[Setup]
This uses the SFML library. -- I think its the 64bit Visual Studio 15 one.

Setup - (This is for myself in the future)

Go into Project Properties- Select all Configurations In C++ -> Additional Include Dicts add "c:\SFMLVS\INCLUDE" In Linker -> Additional Library Dicts "c:\SFMLVS\lib" In Linker, Linker Input -> Additional Dependencies "sfml-window.lib;sfml-system.lib;sfml-graphics.lib;sfml-audio.lib;sfml-network.lib;"

Apply <- Go into Debug Configuration In Linker, Linker Input -> "sfml-window-d.lib;sfml-system-d.lib;sfml-graphics-d.lib;sfml-audio-d.lib;sfml-network-d.lib;"

After that get SFMLVS Bin .dlls and add into solution with CPP files. --> Build and Run
