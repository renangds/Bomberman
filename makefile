all:
	gcc -o main main.c -Wall -lSDL -lSDL_image -lSDL_ttf -lSDL_mixer
	./main