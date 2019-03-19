PROGRAM = podmornice
CC		= gcc
LDFLAGS = -Wall -Wextra
LDLIBS	= -lGL -lGLU -lglut -lm 
LDDEPS	= main.o draw.o coords.o timer.o reshape.o keyboard.o display.o


$(PROGRAM): $(LDDEPS)
	$(CC) $(LDFLAGS) -o $(PROGRAM) $^ $(LDLIBS)

clean:
	rm *.o

rebuild: clean $(PROGRAM)

draw.o: draw.c draw.h
	gcc -c -o $@ $< $(LDLIBS)

coords.o: coords.c coords.h
	gcc -c -o $@ $< $(LDLIBS)

timer.o: timer.c timer.h
	gcc -c -o $@ $< $(LDLIBS)

reshape.o: reshape.c reshape.h
	gcc -c -o $@ $< $(LDLIBS)

keyboard.o: keyboard.c keyboard.h
	gcc -c -o $@ $< $(LDLIBS)

display.o: display.c display.h
	gcc -c -o $@ $< $(LDLIBS)



