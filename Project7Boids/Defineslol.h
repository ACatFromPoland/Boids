#pragma once

#define XY(v) (v).x,(v).y
#define getrandom(min, max) ((rand()%(int)(((max) + 1) - (min)))+ (min))

#define WINDOWX 1600
#define WINDOWY 1000

#define NUMBER_OF_BOIDS 600

// Boid Settings
#define B_SIGHT 150.f
#define B_BUBBLE 10.f
#define B_SPEED 80000.f


#define separateModifier 1.f
#define allignModifier 1000.f
#define cohesionModifier 1000.f

// Camera Settings

#define C_SPEED 400000.f