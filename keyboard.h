#ifndef _KEYBOARD_H_
#define _KEYBOARD_H_

extern int pauseGame;
extern float rotation_parametar;
extern float  heliX;
extern float  heliZ;
extern float heliDirAngle;
extern int coords;
extern int heliMoved;
extern int platform[];
extern float platformX[];
extern float platformZ[];
extern float cPers;

void on_keyboard(unsigned char key, int x, int y);

#endif