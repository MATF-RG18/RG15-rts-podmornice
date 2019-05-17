#ifndef _KEYBOARD_H_
#define _KEYBOARD_H_

#include "constants.h"

extern int pauseGame;
extern float rotation_parametar,rotationDir;
extern float  heliX;
extern float  heliZ;
extern float heliDirAngle;
extern int coords;
extern int heliMoved;
extern int platform[];
extern float platformX[];
extern float platformZ[];
extern float cPers,cPersMover;

extern int size2Ship[], size3Ship[], size4Ship[], size5Ship[];
extern float size2ShipX[], size3ShipX[], size4ShipX[], size5ShipX[];
extern float size2ShipZ[], size3ShipZ[], size4ShipZ[], size5ShipZ[];
extern int size2ShipRotation[];

extern int **playerShips;

extern int targetMoved;
extern float targetDir;

extern int novac;
extern int shipPrices[];

void on_keyboard(unsigned char key, int x, int y);
void up_key(unsigned char key, int x, int y);

#endif