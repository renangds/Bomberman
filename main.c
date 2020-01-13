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
    HERO.front_clip[0].x = 145;
    HERO.front_clip[0].y = 1;
    HERO.front_clip[0].h = 47;
    HERO.front_clip[0].w = 45;

    HERO.front_clip[1].x = 193;
    HERO.front_clip[1].y = 0;
    HERO.front_clip[1].h = 48;
    HERO.front_clip[1].w = 45;

    HERO.front_clip[2].x = 241;
    HERO.front_clip[2].y = 1;
    HERO.front_clip[2].h = 47;
    HERO.front_clip[2].w = 45;


    HERO.behind_clip[0].x = 146;
    HERO.behind_clip[0].y = 145;
    HERO.behind_clip[0].h = 47;
    HERO.behind_clip[0].w = 43;

    HERO.behind_clip[1].x = 194;
    HERO.behind_clip[1].y = 144;
    HERO.behind_clip[1].h = 48;
    HERO.behind_clip[1].w = 43;

    HERO.behind_clip[2].x = 242;
    HERO.behind_clip[2].y = 145;
    HERO.behind_clip[2].h = 47;
    HERO.behind_clip[2].w = 43;

    
    HERO.left_clip[0].x = 146;
    HERO.left_clip[0].y = 49;
    HERO.left_clip[0].h = 47;
    HERO.left_clip[0].w = 43;

    HERO.left_clip[1].x = 194;
    HERO.left_clip[1].y = 48;
    HERO.left_clip[1].h = 48;
    HERO.left_clip[1].w = 43;

    HERO.left_clip[2].x = 242;
    HERO.left_clip[2].y = 49;
    HERO.left_clip[2].h = 47;
    HERO.left_clip[2].w = 43;

    HERO.right_clip[0].x = 146;
    HERO.right_clip[0].y = 97;
    HERO.right_clip[0].h = 47;
    HERO.right_clip[0].w = 43;

    HERO.right_clip[1].x = 194;
    HERO.right_clip[1].y = 96;
    HERO.right_clip[1].h = 48;
    HERO.right_clip[1].w = 43;

    HERO.right_clip[2].x = 242;
    HERO.right_clip[2].y = 97;
    HERO.right_clip[2].h = 47;
    HERO.right_clip[2].w = 43;

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
    SDL_Surface* loadedImage = IMG_Load("Sprites/kono_hero.jpg");

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

    SDL_WM_SetCaption("BomberSuba! Megumin's Last Explosion!", null);

    if(TTF_Init() == -1) exit(1);

    font = TTF_OpenFont("gameboy.ttf", 18); 

    if(font == null) exit(1); 

    kono_font = TTF_OpenFont("Fonte/grobold.ttf", 28);

    if(font == null) exit(1);

    if( Mix_OpenAudio( 22050, MIX_DEFAULT_FORMAT, 2, 4096 ) == -1 ) exit(1);

    drop_bomb = Mix_LoadWAV("Musica/megumin_explosion.wav");

    main_music = Mix_LoadMUS("Musica/stage1.mp3");

    music_menu = Mix_LoadMUS("Musica/intro_music.mp3");
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
    SDL_Surface* telaInstrucao = IMG_Load("Intro/kono_instrucoes.png");

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

    SDL_Surface* telaIntro = IMG_Load("Intro/kono_intro.png");

    sound_menu = Mix_LoadWAV("Musica/blip_select.wav");

    if(telaIntro == -1){
        exit(1);
    }

    SDL_Surface* startGame = TTF_RenderText_Solid(kono_font, "Explosion!", color_main);
    SDL_Surface* instructions = TTF_RenderText_Solid(kono_font, "Intrucoes", color_main);
    SDL_Surface* exitGame = TTF_RenderText_Solid(kono_font, "Sair", color_main);

    if(!startGame || !instructions || !exitGame ) exit(1);

    ins_object(78, 286, startGame, screen, null);
    ins_object(78, 319, instructions, screen, null);
    ins_object(78, 355, exitGame, screen, null);

    while(quit == true){
        start();

        while(SDL_PollEvent(&event)){
            if(event.type == SDL_Quit){
                quit = false;
            }
        }

        if(Mix_PlayingMusic() == 0){
            Mix_PlayMusic(music_menu, -1);
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
                startGame = TTF_RenderText_Solid(kono_font, "Explosion!", color_menu1);
                instructions = TTF_RenderText_Solid(kono_font, "Intrucoes", menu_unselected);
                exitGame = TTF_RenderText_Solid(kono_font, "Sair", menu_unselected);
                break;
            case 1:
                startGame = TTF_RenderText_Solid(kono_font, "Explosion!", menu_unselected);
                instructions = TTF_RenderText_Solid(kono_font, "Intrucoes", color_menu2);
                exitGame = TTF_RenderText_Solid(kono_font, "Sair", menu_unselected);    
                break;
            case 2:
                startGame = TTF_RenderText_Solid(kono_font, "Explosion!", menu_unselected);
                instructions = TTF_RenderText_Solid(kono_font, "Intrucoes", menu_unselected);
                exitGame = TTF_RenderText_Solid(kono_font, "Sair", color_menu3);
                break;
        }

        ins_object(0, 0, telaIntro, screen, null);

        ins_object(78, 286, startGame, screen, null);
        ins_object(78, 319, instructions, screen, null);
        ins_object(78, 355, exitGame, screen, null);

        if( SDL_Flip( screen ) == -1 )
        {
            return 1;
        }

        if(get_ticks() < 1000 / 8){
            SDL_Delay( ( 1000 / 8 ) - get_ticks() );
        }
    }


    Mix_PauseMusic();

    SDL_free(startGame);
    SDL_free(instructions);
    SDL_free(exitGame);
    SDL_free(telaIntro);

    if(option == 1) instrucoes();
    if(option == 2) exit(1);
}

void game_over(){
    Mix_PauseMusic();

    int quit = true;

    SDL_Surface* img = IMG_Load("Intro/megumin_gameover.png");

    ins_object(0, 0, img, screen, null);

    if(SDL_Flip(screen) == -1) exit(1);

    SDL_Delay(5000);

    SDL_free(img);

    menu_start();
}

void its_gameover(){
    if(HERO.life == 0){
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
            case SDLK_F10: HERO.life -= 1; break;
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

void game_start(){
    
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

    Mix_ResumeMusic();

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

        its_gameover();

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