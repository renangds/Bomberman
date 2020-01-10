#include "library.h"
#include "time.h"
#include "hero_coordinates.h"

const int _FPS = 30;

#define LEFT 0
#define RIGHT 1
#define UP 2
#define DOWN 3

#define GAMESTART 0
#define INSTRUCOES 1
#define SAIR 2

void define_coordinates(){
    HERO.front_clip[0].x = 195;
    HERO.front_clip[0].y = 4;
    HERO.front_clip[0].h = 44;
    HERO.front_clip[0].w = 27;

    HERO.front_clip[1].x = 226;
    HERO.front_clip[1].y = 3;
    HERO.front_clip[1].h = 44;
    HERO.front_clip[1].w = 29;

    HERO.front_clip[2].x = 259;
    HERO.front_clip[2].y = 3;
    HERO.front_clip[2].h = 44;
    HERO.front_clip[2].w = 27;


    HERO.behind_clip[0].x = 194;
    HERO.behind_clip[0].y = 148;
    HERO.behind_clip[0].h = 44;
    HERO.behind_clip[0].w = 28;

    HERO.behind_clip[1].x = 226;
    HERO.behind_clip[1].y = 147;
    HERO.behind_clip[1].h = 44;
    HERO.behind_clip[1].w = 29;

    HERO.behind_clip[2].x = 258;
    HERO.behind_clip[2].y = 148;
    HERO.behind_clip[2].h = 44;
    HERO.behind_clip[2].w = 29;


    HERO.left_clip[0].x = 197;
    HERO.left_clip[0].y = 52;
    HERO.left_clip[0].h = 43;
    HERO.left_clip[0].w = 23;

    HERO.left_clip[1].x = 229;
    HERO.left_clip[1].y = 51;
    HERO.left_clip[1].h = 44;
    HERO.left_clip[1].w = 23;

    HERO.left_clip[2].x = 261;
    HERO.left_clip[2].y = 51;
    HERO.left_clip[2].h = 44;
    HERO.left_clip[2].w = 23;


    HERO.right_clip[0].x = 196;
    HERO.right_clip[0].y = 100;
    HERO.right_clip[0].h = 43;
    HERO.right_clip[0].w = 23;

    HERO.right_clip[1].x = 228;
    HERO.right_clip[1].y = 99;
    HERO.right_clip[1].h = 44;
    HERO.right_clip[1].w = 23;

    HERO.right_clip[2].x = 260;
    HERO.right_clip[2].y = 100;
    HERO.right_clip[2].h = 43;
    HERO.right_clip[2].w = 23;

}

void start(){
    Time.startTicks = SDL_GetTicks();
    Time.pausedTicks = 0;
    Time.pause = 0;
    Time.start = 1;
}

void stop(){
    Time.pause = 0;
    Time.start = 0;
}

int get_ticks(){
    if(Time.start == true){
        if(Time.pause == true){
            return Time.pausedTicks;
        } else{
            return SDL_GetTicks() - Time.startTicks;
        }
    }

    return 0;
}

void pause(){
    if(Time.start == true && Time.pause == false){
        Time.pause = true;

        Time.pausedTicks = SDL_GetTicks() - Time.startTicks;
    }
}

void unpause(){
    if(Time.pause == true){
        Time.pause = false;
        Time.startTicks = SDL_GetTicks() - Time.pausedTicks;

        Time.pausedTicks = 0;
    }
}

SDL_Surface* load_image(){
    SDL_Surface* loadedImage = IMG_Load("hero.png");

    if(!loadedImage) exit(1);

    return loadedImage;
}

void load_characters(){
    map_characters = load_image();
}

void init_sdl(){
    if(SDL_Init(SDL_INIT_EVERYTHING) == -1) exit(1);
}           

void init_modules(){
    screen = SDL_SetVideoMode(SCREEN_WIDTH, SCREEN_HEIGHT, SCREEN_BPP, SDL_SWSURFACE);

    if(!screen) exit(1);

    SDL_WM_SetCaption("Zeldavania", null);

    if(TTF_Init() == -1) exit(1);

    font = TTF_OpenFont("gameboy.ttf", 18); 

    if(font == null) exit(1); 
}

void ins_object(int x, int y, SDL_Surface* sour, SDL_Surface* dest){
    SDL_Rect offset;

    offset.x = x;
    offset.y = y;

    SDL_BlitSurface(sour, &HERO.front_clip[1], dest, &offset);
}

void end_sdl(){
    SDL_FreeSurface(map_characters);

    SDL_Quit();
}

void event_keyboard_handle(){
    if(event.type == SDL_KEYDOWN){
        switch(event.key.keysym.sym){
            case SDLK_UP : HERO.yVel -= 5; break;
            case SDLK_DOWN : HERO.yVel += 5; break;
            case SDLK_LEFT: HERO.xVel -= 5; break;
            case SDLK_RIGHT: HERO.xVel += 5; break;
        }
    } else if (event.type == SDL_KEYUP){
        switch(event.key.keysym.sym){
            case SDLK_UP : HERO.yVel += 5; break;
            case SDLK_DOWN : HERO.yVel -= 5; break;
            case SDLK_LEFT: HERO.xVel += 5; break;
            case SDLK_RIGHT: HERO.xVel -= 5; break;
        }   
    }
}

void move_actor(){
    HERO.x += HERO.xVel;

    //If the dot went too far to the left or right
    if( ( HERO.x < 0 ) || ( HERO.x + 32 > SCREEN_WIDTH ) )
    {
        //move back
        HERO.x -= HERO.xVel;
    }

    //Move the dot up or down
    HERO.y += HERO.yVel;

    //If the dot went too far up or down
    if( ( HERO.y < 0 ) || ( HERO.y + 32 > SCREEN_HEIGHT ) )
    {
        //move back
        HERO.y -= HERO.yVel;
    }
}

void insert_actor(){
    if(HERO.yVel < 0){
        HERO.status = LEFT;
        HERO.frames++;
    } else if (HERO.xVel > 0){
        HERO.status = RIGHT;
        HERO.frames++;
    } else{
        HERO.frames = 0;
    }

    if(HERO.frames > 2){
        HERO.frames = 0;
    }

    if(HERO.status == LEFT){
        ins_object(HERO.x, HERO.y, map_characters, screen);
    } else if (HERO.status == RIGHT){
        ins_object(HERO.x, HERO.y, map_characters, screen);
    }

    ins_object(HERO.x, HERO.y, map_characters, screen);
}

void char_constructor(){
    HERO.xVel = 0;
    HERO.yVel = 0;
    HERO.x = 20;
    HERO.y = 20;
}

int main(){
    init_sdl();

    char_constructor();

    init_modules();

    define_coordinates();

    load_characters();

    SDL_FillRect( screen, &screen->clip_rect, SDL_MapRGB( screen->format, 0xFF, 0xFF, 0xFF ) );

    SDL_Surface* mensagem = TTF_RenderText_Solid(font, "Teste do texto", color_main);

    int quit = true;

    int gametime = 100;
    int startGame = 0;

    ins_object(HERO.x, HERO.y, map_characters, screen);

    while(quit == true){
        start();

        while(SDL_PollEvent(&event)){
            event_keyboard_handle();

            if(event.type == SDL_QUIT){
                quit = false;
            }
        }
        
        move_actor();

        SDL_FillRect( screen, &screen->clip_rect, SDL_MapRGB( screen->format, 0xFF, 0xFF, 0xFF ) );

        insert_actor();

        if(SDL_Flip(screen) == -1){
            return 1;
        }

        if(get_ticks() < 1000 / _FPS){
            SDL_Delay( ( 1000 / _FPS ) - get_ticks() );
        }
    }

    end_sdl();

    return 0;
}