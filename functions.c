#include <math.h>
#include "functions.h"


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