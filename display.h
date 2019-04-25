#ifndef _DISPLAY_H_
#define _DISPLAY_H_

void on_display(void);

extern float rotation_parametar, rotationDir, heliX, heliZ;
extern int coords;
extern int platform[];
extern float platformX[];
extern float platformZ[];
extern float cPers;
extern int size2Ship[], size3Ship[], size4Ship[], size5Ship[];
extern float size2ShipX[], size3ShipX[], size4ShipX[], size5ShipX[];
extern float size2ShipZ[], size3ShipZ[], size4ShipZ[], size5ShipZ[];
extern int size2ShipRotation[];
extern int heliMoved;
extern int shipRotation;
extern int shipSelection;
extern int **playerShips;

#endif