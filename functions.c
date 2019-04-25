#include <math.h>
#include <stdlib.h>
#include <stdio.h>
#include "functions.h"
#include "constants.h"


float getHeliX(){
	return (float) floor(heliX);
}
float getHeliZ(){
	return (float) (0.5 + floor(heliZ - 0.5));

}

float getTargetX(){
	return (float) floor(targetX);
}
float getTargetZ(){
	return (float) (0.5 + floor(targetZ - 0.5));

}

int heliInsideX(float pomeraj){
    if (heliX+pomeraj>-5 && heliX+pomeraj<5) return 1;
    else return 0;
}

int heliInsideZ(float pomeraj){
    if (heliZ+pomeraj<10.5 && heliZ+pomeraj>0.5) return 1;
    else return 0;
}

int targetInsideX(float pomeraj){
    if (targetX+pomeraj>-5 && targetX+pomeraj<5) return 1;
    else return 0;
}

int targetInsideZ(float pomeraj){
    if (targetZ+pomeraj>-10.5 && targetZ+pomeraj<-0.5) return 1;
    else return 0;
}

void setArrayNull(int *array, int size){
	int i;
	for (i=0;i<size;i++){
		array[i]=0;
	}
}

int** initMatrixToZero(int **matrix, int size){
	matrix = (int **)calloc(size, sizeof(int*));
	for(int i = 0; i < size; i++) matrix[i] = (int *)calloc(size, sizeof(int));
	return matrix;
}

void printMatrix(int **matrix,int size){
	int i,j;
	for (i=0;i<size;i++){
		for (j=0;j<size;j++){
			printf("%d ",matrix[i][j]);
		}
		printf("\n");
	}
	printf("########################################\n");
}

int getPlayerMatrixX(){
	return 5+getHeliX();
}
int getPlayerMatrixZ(){
	return -0.5+getHeliZ();
}

float getPlXFromMatrix(int x){
	return -5.0+x;
}

float getPlZFromMatrix(int z){
	return 0.5+z;
}

int canPlaceShip(int shipSize, int shipRotation){//provera da li brod moze da se postavi
	int x=getPlayerMatrixX();
	int z=getPlayerMatrixZ();
	int i;
	switch (shipRotation){
		case 0:
			for (i=0; i<shipSize;i++){
				if ((x-i)<0 || playerShips[x-i][z] != 0) return 0;
			}
			break;
		case 1:
			for (i=0; i<shipSize;i++){
				if ((z-i)<0 || playerShips[x][z-i] != 0) return 0;
			}
			break;
		case 2:
			for (i=0; i<shipSize;i++){
				if ((x+i)>=gridSize || playerShips[x+i][z] != 0) return 0;
			}
			break;
		case 3:
			for (i=0; i<shipSize;i++){
				if ((z+i)>=gridSize || playerShips[x][z+i] != 0) return 0;
			}
			break;
	}
	return 1;
}

int placeShip(int shipSize, int shipRotation){
	int x=getPlayerMatrixX();
	int z=getPlayerMatrixZ();
	int i;
	switch (shipRotation){
		case 0:
			if (x<gridSize-1 && playerShips[x+1][z]==0)
				playerShips[x+1][z]=-1;

			if (x-shipSize>=0 && playerShips[x-shipSize][z]==0)
				playerShips[x-shipSize][z]=-1;

			for (i=0; i<shipSize;i++){
				playerShips[x-i][z]=shipSize;

				if (z>0 && playerShips[x-i][z-1]==0)
					playerShips[x-i][z-1]=-1;

				if (z<gridSize-1 && playerShips[x-i][z+1]==0)
					playerShips[x-i][z+1]=-1;

			}
			break;

		case 1:
			if (z<gridSize-1 && playerShips[x][z+1]==0)
				playerShips[x][z+1]=-1;

			if (z-shipSize>=0 && playerShips[x][z-shipSize]==0)
				playerShips[x][z-shipSize]=-1;

			for (i=0; i<shipSize;i++){
				playerShips[x][z-i]=shipSize;

				if (x>0 && playerShips[x-1][z-i]==0)
					playerShips[x-1][z-i]=-1;

				if (x<gridSize-1 && playerShips[x+1][z-i]==0)
					playerShips[x+1][z-i]=-1;
			}
			break;

		case 2:
			if (x+shipSize<=gridSize-1 && playerShips[x+shipSize][z]==0)
				playerShips[x+shipSize][z]=-1;

			if (x>0 && playerShips[x-1][z]==0)
				playerShips[x-1][z]=-1;

			for (i=0; i<shipSize;i++){
				playerShips[x+i][z]=shipSize;

				if (z>0 && playerShips[x+i][z-1]==0)
					playerShips[x+i][z-1]=-1;

				if (z<gridSize-1 && playerShips[x+i][z+1]==0)
					playerShips[x+i][z+1]=-1;
			}
			break;
		case 3:
			if (z+shipSize<=gridSize-1 && playerShips[x][z+shipSize]==0)
				playerShips[x][z+shipSize]=-1;

			if (z>0 && playerShips[x][z-1]==0)
				playerShips[x][z-1]=-1;


			for (i=0; i<shipSize;i++){
				playerShips[x][z+i]=shipSize;

				if (x>0 && playerShips[x-1][z+i]==0)
					playerShips[x-1][z+i]=-1;

				if (x<gridSize-1 && playerShips[x+1][z+i]==0)
					playerShips[x+1][z+i]=-1;
			}
			break;

	}

	switch(shipSize){
		case 1:
			platformX[platformCounter] = getHeliX();
            platformZ[platformCounter] = getHeliZ();
            platform[platformCounter]=1;
            platformCounter++;
			break;
		case 2:
			size2ShipX[size2ShipCounter] = getHeliX();
            size2ShipZ[size2ShipCounter] = getHeliZ();
            size2Ship[size2ShipCounter]=1;
            size2ShipRotation[size2ShipCounter] = shipRotation;
            size2ShipCounter++;
            break;

	}

}




void printXZ(){
	printf("%d %d\n",getPlayerMatrixX(),getPlayerMatrixZ());
}










