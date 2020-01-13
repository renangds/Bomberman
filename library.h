#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>
#include <SDL/SDL_mixer.h>
#include <string.h>

#define null NULL
#define true 1
#define false 0

#define BOMB_DEFAULT 3

static int SCREEN_WIDTH = 704;
static int SCREEN_HEIGHT = 574;
static int SCREEN_BPP = 32;

SDL_Event event;
SDL_Surface* screen;
SDL_Surface* map_characters;
SDL_Surface* bomb_sprites;

SDL_Surface* life_gui;
SDL_Surface* time_gui;
SDL_Surface* points_gui;

SDL_Surface* fase1;

TTF_Font* font = null;

SDL_Color color_main = {0, 0, 0};
SDL_Color selected = {0, 0, 255};
SDL_Color menu_game_main = {0 ,0 ,0};

Mix_Chunk* sound_menu = null;
Mix_Chunk* drop_bomb = null;
Mix_Music* main_music = null;