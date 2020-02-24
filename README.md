# RG33-vwm
VWM

Virtual Window Manager, or short for VWM, is supposed to be a copy of working windows in Microsoft HoloLens
but in virtual reality.

For now it's pretty BASIC where you have one window that can folow you or stay at its place. It can be opend and closed
and it shuffels some pictures* on command.

Commands:

w - move forward
a - move left
s - move backward
d - move right

j - look left
k - look right

space - jump

n - shuffle pictures on screen
t - toggle screen on and off
f - toggle screen follow on and off
v - toggle betwen first person view and third person view


![alt text](https://github.com/BlagojeM/RG33-vwm/blob/master/screenshots/w.gif "Walking Demonstration")



The idea when finnished is that it could be used with vr goggles and android phone** for a numberof free monitors 
that are fully functional, any size, any resolution, placed anywhere. 

*   all pictures were taken by me using a smartphone
**  phone will be used only as a display and its position in real space for look around (using accselormeter, gyro..) 
    picture would be modified for vr goggles of course.


DISCLAMERS

I   The project is not finished and i will continue to work on it, but i want to add that the last serval updated
    were a real mess, because it started as a school project and i was forced to make a deadline.

    timers, input method(keyboard and mouse for now), textures and shaders will have there own files, there will be
    a better file structure, Makefile will be usefull, textures will probably be done much diffrently, The code will
    have propper and usefull comments..

II  I would like to thank Nebojsa Koturovic for his help while learning openGL, the code that was copied from him was:
		-image.cpp
		-image.h
		-objloader.cpp
		-objloader.h
		-cube.obj

    You can follow his work on: https://github.com/kotur95
