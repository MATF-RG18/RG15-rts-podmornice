#include <stdio.h>
#include <unistd.h>
int main(){
	execlp("gcc","gcc", "podmornice.c", "-o", "run", "-lGL", "-lGLU","-lglut","-lm",NULL);
}