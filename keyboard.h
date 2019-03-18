#ifndef _KEYBOARD_H_
#define _KEYBOARD_H_

extern int pauseGame;
extern float rotation_parametar;
extern float  mainShipX;
extern float  mainShipZ;
extern float  mainShipSpeed;
extern int coords;

void on_keyboard(unsigned char key, int x, int y);

#endif