#ifndef _FUNCTIONS_H_
#define _FUNCTIONS_H_


extern float heliX, heliZ, targetX, targetZ;
extern int **playerShips;
extern int size2Ship[], size3Ship[], size4Ship[], size5Ship[];
extern float size2ShipX[], size3ShipX[], size4ShipX[], size5ShipX[];
extern float size2ShipZ[], size3ShipZ[], size4ShipZ[], size5ShipZ[];
extern int size2ShipRotation[],size3ShipRotation[],size4ShipRotation[],size5ShipRotation[];
extern int platformCounter,size2ShipCounter,size3ShipCounter,size4ShipCounter,size5ShipCounter;

extern int platform[];
extern float platformX[];
extern float platformZ[];

#define radToDeg( r ) ((r) * 57.295779513082321)

float getHeliX();
float getHeliZ();
float getTargetX();
float getTargetZ();
int heliInsideX(float pomeraj);
int heliInsideZ(float pomeraj);
int targetInsideX(float pomeraj);
int targetInsideZ(float pomeraj);
void setArrayNull(int *array, int size);
int** initMatrixToZero(int **matrix, int size);
void printMatrix(int **matrix,int size);
int getPlayerMatrixX();
int getPlayerMatrixZ();
float getPlXFromMatrix(int x);
float getPlZFromMatrix(int z);
int canPlaceShip(int shipSize, int shipRotation);
int placeShip(int shipSize, int shipRotation);
void printXZ();

#endif