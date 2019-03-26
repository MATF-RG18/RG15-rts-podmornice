#ifndef _DRAW_H_
#define _DRAW_H_

void DrawCircle();
void drawHeli();
void drawPlatform(float x, float z);
void draw2Ship(float x,float z);
void drawShade(float x,float z);
void drawTarget();

extern float heliX, heliZ, rotation_parametar, heliDirAngle;
extern int heliMoved;

#endif