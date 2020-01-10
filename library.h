#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>

#define null NULL
#define true 1
#define false 0

static int SCREEN_WIDTH = 704;
static int SCREEN_HEIGHT = 574;
static int SCREEN_BPP = 32;

SDL_Event event;
SDL_Surface* screen;
SDL_Surface* map_characters;

TTF_Font* font = null;

SDL_Color color_main = {255, 255, 255};
SDL_Color selected = {255, 255, 0};