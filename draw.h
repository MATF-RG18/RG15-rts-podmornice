#ifndef _DRAW_H_
#define _DRAW_H_

void DrawCircle();
void drawHeli();
void drawPlatform(float x, float z);
void draw2Ship(float x,float z, int shipRotation);
void draw3Ship(float x, float z);
void draw5Ship(float x, float z);
void draw4Ship(float x, float z);
void drawShade(float x,float z);
void drawTarget();
void drawShip(int size, float x, float z, float shipRotation);

extern int brojac;
extern float heliX, heliZ, rotation_parametar, heliDirAngle;
extern int heliMoved;
extern float targetX, targetZ;
extern int targetMoved;
extern float targetDir;

#endif