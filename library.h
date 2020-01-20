#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>
#include <SDL/SDL_mixer.h>
#include <string.h>
#include <time.h>   

#define null NULL
#define true 1
#define false 0

#define BOMB_DEFAULT 2
#define EXPLOSION_DEFAULT 1

static int SCREEN_WIDTH = 720;
static int SCREEN_HEIGHT = 480;
static int SCREEN_BPP = 32;

int map[13][22];

SDL_Event event;
SDL_Surface* screen;
SDL_Surface* map_characters;
SDL_Surface* bomb_sprites;
SDL_Surface* frog_sprite;
SDL_Surface* objects_sprites;
SDL_Surface* clock_sprite;
SDL_Surface* heart_sprite;
SDL_Surface* objects;
SDL_Surface* explosion_sprite;

SDL_Surface* life_gui;
SDL_Surface* time_gui;
SDL_Surface* points_gui;

SDL_Surface* fase1;

TTF_Font* gameOver = null;

TTF_Font* kono_font = null;

TTF_Font* kono_gui = null;

SDL_Color color_main = {0, 0, 0};
SDL_Color selected = {0, 0, 255};
SDL_Color menu_game_main = {0 ,0 ,0};

SDL_Color menu_unselected = {255, 255, 255};
SDL_Color color_menu1 = {240, 0, 111};
SDL_Color color_menu2 = {237, 130, 2};
SDL_Color color_menu3 = {109, 28, 9};
SDL_Color background_status = {62, 101, 91};

Mix_Chunk* sound_menu = null;
Mix_Chunk* drop_bomb = null;
Mix_Chunk* bomb_explosion = null;
Mix_Music* main_music = null;

Mix_Music* music_menu = null;

const int _FPS = 22;

#define LEFT 0
#define RIGHT 1
#define UP 2
#define DOWN 3

#define GAMESTART 0
#define INSTRUCOES 1
#define SAIR 2