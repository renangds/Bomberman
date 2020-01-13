#include "library.h"
#include "time.h"
#include "hero_coordinates.h"

const int _FPS = 22;

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

    //Bomba

    BOMB.bomb_img[0].x = 9;
    BOMB.bomb_img[0].y = 435;
    BOMB.bomb_img[0].h = 23;
    BOMB.bomb_img[0].w = 18;


    BOMB.bomb_img[1].x = 5;
    BOMB.bomb_img[1].y = 399;
    BOMB.bomb_img[1].h = 26;
    BOMB.bomb_img[1].w = 22;


    BOMB.bomb_img[2].x = 30;
    BOMB.bomb_img[2].y = 395;
    BOMB.bomb_img[2].h = 30;
    BOMB.bomb_img[2].w = 26;


    BOMB.bomb_img[3].x = 61;
    BOMB.bomb_img[3].y = 392;
    BOMB.bomb_img[3].h = 33;
    BOMB.bomb_img[3].w = 28;


    BOMB.bomb_img[4].x = 94;
    BOMB.bomb_img[4].y = 390;
    BOMB.bomb_img[4].h = 35;
    BOMB.bomb_img[4].w = 28;


    BOMB.bomb_img[5].x = 45;
    BOMB.bomb_img[5].y = 442;
    BOMB.bomb_img[5].h = 10;
    BOMB.bomb_img[5].w = 10;


    BOMB.bomb_img[6].x = 62;
    BOMB.bomb_img[6].y = 440;
    BOMB.bomb_img[6].h = 14;
    BOMB.bomb_img[6].w = 14;


    BOMB.bomb_img[7].x = 84;
    BOMB.bomb_img[7].y = 438;
    BOMB.bomb_img[7].h = 16;
    BOMB.bomb_img[7].w = 16;


    BOMB.bomb_img[8].x = 107;
    BOMB.bomb_img[8].y = 438;
    BOMB.bomb_img[8].h = 16;
    BOMB.bomb_img[8].w = 16;

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

    if( Mix_OpenAudio( 22050, MIX_DEFAULT_FORMAT, 2, 4096 ) == -1 ) exit(1);

    drop_bomb = Mix_LoadWAV("Musica/all_sound.wav");

    main_music = Mix_LoadMUS("Musica/musica_jogo.mp3");
}

void ins_object(int x, int y, SDL_Surface* sour, SDL_Surface* dest, SDL_Surface* clip){
    SDL_Rect offset;

    offset.x = x;
    offset.y = y;

    SDL_BlitSurface(sour, clip, dest, &offset);
}

void end_sdl(){
    SDL_FreeSurface(map_characters);

    SDL_Quit();
}

void instrucoes(){
    SDL_Surface* telaInstrucao = IMG_Load("Intro/kawaii.jpg");

    if(!telaInstrucao) exit(1);

    int quit = true;

    ins_object(0, 0, telaInstrucao, screen, null);

    while(quit == true){
        start();

        while(SDL_PollEvent(&event)){
            if(event.type == SDL_KEYDOWN){
                switch(event.key.keysym.sym){
                    case SDLK_SPACE: quit = false;
                }
            }
        }

        ins_object(0, 0, telaInstrucao, screen, null);

        if( SDL_Flip( screen ) == -1 )
        {
            return 1;
        }

        if(get_ticks() < 1000 / 8){
            SDL_Delay( ( 1000 / 8 ) - get_ticks() );
        }
    }

    SDL_free(telaInstrucao);

    menu_start();
}

void menu_start(){
    int option = 0;
    int quit = true;

    SDL_Surface* telaIntro = IMG_Load("Intro/intro.jpg");

    sound_menu = Mix_LoadWAV("Musica/blip_select.wav");

    if(telaIntro == -1){
        exit(1);
    }

    SDL_Surface* startGame = TTF_RenderText_Solid(font, "Bombardear", color_main);
    SDL_Surface* instructions = TTF_RenderText_Solid(font, "Intrucoes", color_main);
    SDL_Surface* exitGame = TTF_RenderText_Solid(font, "Meter o pe", color_main);

    if(!startGame || !instructions || !exitGame ) exit(1);

    ins_object(259, 369, startGame, screen, null);
    ins_object(259, 421, instructions, screen, null);
    ins_object(259, 472, exitGame, screen, null);

    while(quit == true){
        start();

        while(SDL_PollEvent(&event)){
            if(event.type == SDL_Quit){
                quit = false;
            }
        }

        Uint8* keystates = SDL_GetKeyState(NULL);

        if(keystates[SDLK_UP]){
            Mix_PlayChannel( -1, sound_menu, 0 );
            if(option == 0){
                option = 2;
            } else{
                option--;
            }
        } else if (keystates[SDLK_DOWN]){
            Mix_PlayChannel( -1, sound_menu, 0 );
            if(option == 2){
                option = 0;
            } else{
                option++;
            }
        } else if(keystates[SDLK_SPACE]){
            quit = false;
        }

        switch(option){
            case 0:
                exitGame = TTF_RenderText_Solid(font, "Meter o pe", color_main);
                instructions = TTF_RenderText_Solid(font, "Intrucoes", color_main);
                startGame = TTF_RenderText_Solid(font, "Bombardear", selected);
                break;
            case 1:
                exitGame = TTF_RenderText_Solid(font, "Meter o pe", color_main);
                startGame = TTF_RenderText_Solid(font, "Bombardear", color_main);
                instructions = TTF_RenderText_Solid(font, "Intrucoes", selected);
                break;
            case 2:
                startGame = TTF_RenderText_Solid(font, "Bombardear", color_main);
                instructions = TTF_RenderText_Solid(font, "Intrucoes", color_main);
                exitGame = TTF_RenderText_Solid(font, "Meter o pe", selected);
                break;
        }

        ins_object(0, 0, telaIntro, screen, null);

        ins_object(259, 369, startGame, screen, null);
        ins_object(259, 421, instructions, screen, null);
        ins_object(259, 472, exitGame, screen, null);

        if( SDL_Flip( screen ) == -1 )
        {
            return 1;
        }

        if(get_ticks() < 1000 / 8){
            SDL_Delay( ( 1000 / 8 ) - get_ticks() );
        }
    }

    SDL_free(startGame);
    SDL_free(instructions);
    SDL_free(exitGame);
    SDL_free(telaIntro);

    if(option == 1) instrucoes();
    if(option == 2) exit(1);
}

void game_over(){
    char msg[10] = "Game Over";

    int quit = true;

    while(quit){
        
    }
}

void its_gameover(){
    if(!HERO.life || !HERO.time){
        game_over();
    }
}

void game_time(){
    char time[20];

    int realTime = HERO.time - (SDL_GetTicks()/1000);

    sprintf(time, "%d", realTime);

    char tempo[50] = "Tempo: ";

    time_gui = TTF_RenderText_Solid(font, strcat(tempo, time), menu_game_main);

    ins_object(182, 5, time_gui, screen, null);
}

void sum_point(){
    char point[20];

    sprintf(point, "%d", HERO.points);

    char ponto[50] = "Pontos: ";

    points_gui = TTF_RenderText_Solid(font, strcat(ponto, point), menu_game_main);

    ins_object(452, 5, points_gui, screen, null);
}

void life_game(){
    char life[2];

    sprintf(life, "%d", HERO.life);

    char vida[50] = "Vida: ";

    life_gui = TTF_RenderText_Solid(font, strcat(vida, life), menu_game_main);

    ins_object(5, 5, life_gui, screen, null);
}

void event_keyboard_handle(){
    if(event.type == SDL_KEYDOWN){
        switch(event.key.keysym.sym){
            case SDLK_UP : HERO.yVel -= 5; HERO.status = UP; break;
            case SDLK_DOWN : HERO.yVel += 5; HERO.status = DOWN; break;
            case SDLK_LEFT: HERO.xVel -= 5; HERO.status = LEFT; break;
            case SDLK_RIGHT: HERO.xVel += 5; HERO.status = RIGHT; break;
            case SDLK_SPACE: bomb_handle(); break;
            case SDLK_F10: HERO.life = 1; break;
            case SDLK_F11: HERO.points += 10; break;
        }
    } else if (event.type == SDL_KEYUP){
        if(HERO.yVel != 30 || HERO.xVel != 30){
            switch(event.key.keysym.sym){
                case SDLK_UP : HERO.yVel += 5; break;
                case SDLK_DOWN : HERO.yVel -= 5; break;
                case SDLK_LEFT: HERO.xVel += 5; break;
                case SDLK_RIGHT: HERO.xVel -= 5; break;
            }  
        } 
    }
}

void bomb_handle(){
    if(BOMB.bombStatus == false){
        Mix_PlayChannel( -1, drop_bomb, 0 );
        BOMB.x = HERO.x;
        BOMB.y = HERO.y;
        ins_object(BOMB.x, BOMB.y, bomb_sprites, screen, &BOMB.bomb_img[0]);
        BOMB.bombStatus = true;
        BOMB.timeStart = SDL_GetTicks()/1000;
    }
}

void bomb_timer(){

    if(((SDL_GetTicks()/1000) - BOMB.timeStart) > BOMB_DEFAULT){
        BOMB.bombStatus = false;
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
   HERO.frames++;

   if(HERO.yVel == 0 && HERO.xVel == 0){
       HERO.frames = 0;
   }

    if(HERO.frames > 2){
        HERO.frames = 0;
    }

    if(HERO.status == LEFT){
        ins_object(HERO.x, HERO.y, map_characters, screen, &HERO.left_clip[HERO.frames]);
    } else if (HERO.status == RIGHT){
        ins_object(HERO.x, HERO.y, map_characters, screen, &HERO.right_clip[HERO.frames]);
    } else if (HERO.status == UP){
        ins_object(HERO.x, HERO.y, map_characters, screen, &HERO.behind_clip[HERO.frames]);
    } else if (HERO.status == DOWN){
        ins_object(HERO.x, HERO.y, map_characters, screen, &HERO.front_clip[HERO.frames]);
    }

}

void char_constructor(){
    HERO.xVel = 0;
    HERO.yVel = 0;
    HERO.x = 162;
    HERO.y = 110;
    HERO.status = DOWN;
}

int main(){
    init_sdl();

    char_constructor();

    init_modules();

    define_coordinates();

    load_characters();

    menu_start();

    HERO.time = 350;

    HERO.life = 3;

    //SDL_FillRect( screen, &screen->clip_rect, SDL_MapRGB( screen->format, 0xFF, 0xFF, 0xFF ) );

    SDL_Surface* mensagem = TTF_RenderText_Solid(font, "Teste do texto", menu_game_main);

    int quit = true;

    fase1 = IMG_Load("fase1.png");
    bomb_sprites = IMG_Load("bomb.png");

    ins_object(HERO.x, HERO.y, map_characters, screen, &HERO.front_clip[1]);

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

        ins_object(0, 30, fase1, screen, null);

        //ins_object(5, 5, mensagem, screen, null);
        life_game();

        sum_point();

        game_time();

        if(BOMB.bombStatus == true){
            ins_object(BOMB.x, BOMB.y, bomb_sprites, screen, &BOMB.bomb_img[0]);
            bomb_timer();
        }

        insert_actor();

        if(Mix_PlayingMusic() == 0){
            Mix_PlayMusic(main_music, -1);
        }

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