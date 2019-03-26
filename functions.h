#ifndef _FUNCTIONS_H_
#define _FUNCTIONS_H_


extern float heliX, heliZ, targetX, targetZ;

#define radToDeg( r ) ((r) * 57.295779513082321)

float getHeliX();
float getHeliZ();
float getTargetX();
float getTargetZ();
int heliInsideX(float pomeraj);
int heliInsideZ(float pomeraj);
int targetInsideX(float pomeraj);
int targetInsideZ(float pomeraj);

#endif