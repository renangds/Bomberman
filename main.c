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

    BOMB.bomb_img[0].x = 6;
    BOMB.bomb_img[0].y = 76;
    BOMB.bomb_img[0].h = 40;
    BOMB.bomb_img[0].w = 32;


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


    //Heart Clips

    HERO.heart_clip[0].x = 0;
    HERO.heart_clip[0].y = 0;
    HERO.heart_clip[0].h = 42;
    HERO.heart_clip[0].w = 42;

    HERO.heart_clip[1].x = 143;
    HERO.heart_clip[1].y = 0;
    HERO.heart_clip[1].h = 42;
    HERO.heart_clip[1].w = 42;

    //Frog Clips

    ENEMY1.front_clip[0].x = 57;
    ENEMY1.front_clip[0].y = 15;
    ENEMY1.front_clip[0].h = 30;
    ENEMY1.front_clip[0].w = 30;

    ENEMY1.front_clip[1].x = 6;
    ENEMY1.front_clip[1].y = 8;
    ENEMY1.front_clip[1].h = 37;
    ENEMY1.front_clip[1].w = 36;

    ENEMY1.front_clip[2].x = 102;
    ENEMY1.front_clip[2].y = 8;
    ENEMY1.front_clip[2].h = 37;
    ENEMY1.front_clip[2].w = 36;


    ENEMY1.left_clip[0].x = 53;
    ENEMY1.left_clip[0].y = 70;
    ENEMY1.left_clip[0].h = 24;
    ENEMY1.left_clip[0].w = 33;

    ENEMY1.left_clip[1].x = 0;
    ENEMY1.left_clip[1].y = 62;
    ENEMY1.left_clip[1].h = 32;
    ENEMY1.left_clip[1].w = 47;

    ENEMY1.left_clip[2].x = 96;
    ENEMY1.left_clip[2].y = 62;
    ENEMY1.left_clip[2].h = 32;
    ENEMY1.left_clip[2].w = 47;


    ENEMY1.right_clip[0].x = 58;
    ENEMY1.right_clip[0].y = 118;
    ENEMY1.right_clip[0].h = 24;
    ENEMY1.right_clip[0].w = 33;

    ENEMY1.right_clip[1].x = 1;
    ENEMY1.right_clip[1].y = 110;
    ENEMY1.right_clip[1].h = 33;
    ENEMY1.right_clip[1].w = 47;

    ENEMY1.right_clip[2].x = 97;
    ENEMY1.right_clip[2].y = 110;
    ENEMY1.right_clip[2].h = 32;
    ENEMY1.right_clip[2].w = 47;


    ENEMY1.behind_clip[0].x = 54;
    ENEMY1.behind_clip[0].y = 159;
    ENEMY1.behind_clip[0].h = 29;
    ENEMY1.behind_clip[0].w = 38;

    ENEMY1.behind_clip[1].x = 6;
    ENEMY1.behind_clip[1].y = 148;
    ENEMY1.behind_clip[1].h = 45;
    ENEMY1.behind_clip[1].w = 32;

    ENEMY1.behind_clip[2].x = 102;
    ENEMY1.behind_clip[2].y = 148;
    ENEMY1.behind_clip[2].h = 44;
    ENEMY1.behind_clip[2].w = 32;
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

void init_sdl(){
    if(SDL_Init(SDL_INIT_EVERYTHING) == -1) exit(1);

    if(TTF_Init() == -1) exit(1);

    if(Mix_OpenAudio( 22050, MIX_DEFAULT_FORMAT, 2, 4096 ) == -1 ) exit(1);

    screen = SDL_SetVideoMode(SCREEN_WIDTH, SCREEN_HEIGHT, SCREEN_BPP, SDL_SWSURFACE);

    if(!screen) exit(1);

    SDL_WM_SetCaption("BomberSuba! Megumin's Last Explosion!", null);
}

init_fonts(){
    font = TTF_OpenFont("gameboy.ttf", 18); 

    if(font == null) exit(1); 

    kono_font = TTF_OpenFont("Fonte/grobold.ttf", 28);

    if(kono_font == null) exit(1);

    kono_gui = TTF_OpenFont("Fonte/grobold.ttf", 34);

    if(!kono_gui) exit(1);
}

init_images(){
    heart_sprite = IMG_Load("Sprites/heart_med.png");

    map_characters = IMG_Load("Sprites/kono_hero.jpg");

    if(!heart_sprite || !map_characters) exit(1);
}

init_mixes(){
    drop_bomb = Mix_LoadWAV("Musica/megumin_explosion.wav");

    main_music = Mix_LoadMUS("Musica/stage1.mp3");

    music_menu = Mix_LoadMUS("Musica/intro_music.mp3");

    bomb_explosion = Mix_LoadWAV("Musica/boom.wav");

    if(!drop_bomb || !main_music || !music_menu || !bomb_explosion) exit(1);
}

void close_fonts(){
    TTF_CloseFont(font);
    TTF_CloseFont(kono_font);
    TTF_CloseFont(kono_gui);
}

void close_images(){
    SDL_FreeSurface(heart_sprite);
    SDL_FreeSurface(map_characters);
}

void close_mixes(){
    Mix_FreeMusic(main_music);
    Mix_FreeChunk(bomb_explosion);
    Mix_FreeChunk(drop_bomb);
}

void init_modules(){
    init_fonts();
    init_mixes();
    init_images();
}

void end_sdl(){
    close_images();
    close_mixes();
    close_fonts();

    SDL_Quit();
}

void ins_object(int x, int y, SDL_Surface* sour, SDL_Surface* dest, SDL_Surface* clip){
    SDL_Rect offset;

    offset.x = x;
    offset.y = y;

    SDL_BlitSurface(sour, clip, dest, &offset);
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
}

int menu_start(){
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
    SDL_Surface* records = TTF_RenderText_Solid(kono_font, "Record", color_main);

    if(!startGame || !instructions || !exitGame || !records ) exit(1);

    ins_object(78, 286, startGame, screen, null);
    ins_object(78, 316, instructions, screen, null);
    ins_object(78, 346, records, screen, null);
    ins_object(78, 376, exitGame, screen, null);

    while(quit == true){
        start();

        while(SDL_PollEvent(&event)){
            if(event.type == SDL_Quit){
                quit = false;
            }
        }

        /*
        if(Mix_PlayingMusic() == 0){
            Mix_PlayMusic(music_menu, -1);
        }
        */

        Uint8* keystates = SDL_GetKeyState(NULL);

        if(keystates[SDLK_UP]){
            Mix_PlayChannel( -1, sound_menu, 0 );
            if(option == 0){
                option = 3;
            } else{
                option--;
            }
        } else if (keystates[SDLK_DOWN]){
            Mix_PlayChannel( -1, sound_menu, 0 );
            if(option == 3){
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
                records = TTF_RenderText_Solid(kono_font, "Record", menu_unselected);
                exitGame = TTF_RenderText_Solid(kono_font, "Sair", menu_unselected);
                break;
            case 1:
                startGame = TTF_RenderText_Solid(kono_font, "Explosion!", menu_unselected);
                instructions = TTF_RenderText_Solid(kono_font, "Intrucoes", color_menu2);
                records = TTF_RenderText_Solid(kono_font, "Record", menu_unselected);
                exitGame = TTF_RenderText_Solid(kono_font, "Sair", menu_unselected);    
                break;
            case 2:
                startGame = TTF_RenderText_Solid(kono_font, "Explosion!", menu_unselected);
                instructions = TTF_RenderText_Solid(kono_font, "Intrucoes", menu_unselected);
                records = TTF_RenderText_Solid(kono_font, "Record", color_menu3);
                exitGame = TTF_RenderText_Solid(kono_font, "Sair", menu_unselected);
                break;
            case 3:
                startGame = TTF_RenderText_Solid(kono_font, "Explosion!", menu_unselected);
                instructions = TTF_RenderText_Solid(kono_font, "Intrucoes", menu_unselected);
                records = TTF_RenderText_Solid(kono_font, "Record", menu_unselected);
                exitGame = TTF_RenderText_Solid(kono_font, "Sair", color_menu1);
                break;
        }

        ins_object(0, 0, telaIntro, screen, null);

        ins_object(78, 286, startGame, screen, null);
        ins_object(78, 316, instructions, screen, null);
        ins_object(78, 346, records, screen, null);
        ins_object(78, 376, exitGame, screen, null);

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
    SDL_free(records);
    SDL_free(telaIntro);

   return option;
}

void sort_records(int gamePoint){
    FILE* fl;
    char point[20];
    int points[5];
    int index = -1;

    if((fl = fopen("Arquivos/records.txt", "r")) == NULL){
        perror("Erro: fopen");
        exit(1);
    }

    while((fscanf(fl, "%s\n", point)) != EOF){
        points[++index] = atoi(point);
    }

    fclose(fl);

    if(gamePoint > points[4]){
        points[4] = gamePoint;

        for(int i = 0; i < 5; i++){
            for(int j = 0; j < 5-1; j++){
                if(points[j] < points[j+1]){
                    int swap = points[j];
                    points[j] = points[j+1];
                    points[j+1] = swap;
                }
            }
        }
    }

    if((fl = fopen("Arquivos/records.txt", "w")) == NULL){
        perror("Erro: fopen");
        exit(1);
    }

    for(int i = 0; i < 5; i++){
        sprintf(point, "%d", points[i]);
        fprintf(fl, "%s\n", point);
    }

    fclose(fl);
}

void menu_records(){
    SDL_Surface* telaRecordes = IMG_Load("Intro/megumin_recordes.png");

    if(!telaRecordes) exit(1);

    int quit = true;

    ins_object(0, 0, telaRecordes, screen, null);

    FILE* fl;
    char point[20];
    int points[5];
    int index = -1;

    if((fl = fopen("Arquivos/records.txt", "r")) == NULL){
        perror("Erro: fopen");
        exit(1);
    }

    while((fscanf(fl, "%s\n", point)) != EOF){
        points[++index] = atoi(point);
    }

    SDL_Surface* imgPoint; 

    while(quit == true){
        start();

        while(SDL_PollEvent(&event)){
            if(event.type == SDL_KEYDOWN){
                switch(event.key.keysym.sym){
                    case SDLK_SPACE: quit = false;
                }
            }
        }

        ins_object(0, 0, telaRecordes, screen, null);

        for(int i = 0; i < 5; i++){
            sprintf(point, "%d", points[i]);
            imgPoint = TTF_RenderText_Solid(kono_font, point, menu_unselected);
            ins_object(40, 144 + (i*30), imgPoint, screen, null);
        }

        if( SDL_Flip( screen ) == -1 )
        {
            return 1;
        }

        if(get_ticks() < 1000 / 8){
            SDL_Delay( ( 1000 / 8 ) - get_ticks() );
        }
    }

    SDL_free(telaRecordes);
}

void game_over(){
    Mix_PauseMusic();

    int quit = true;

    SDL_Surface* img = IMG_Load("Intro/megumin_gameover_2.png");

    ins_object(0, 0, img, screen, null);

    if(SDL_Flip(screen) == -1) exit(1);

    sort_records(HERO.points);

    SDL_Delay(5000);

    SDL_free(img);
}

int its_gameover(){
    if(HERO.life == 0){
        return false;
    } else{
        return true;
    }
}

void game_time(){
    char time[20];

    int realTime = HERO.time - (SDL_GetTicks()/1000);

    sprintf(time, "%d", realTime);

    

    if(realTime > 200){
        time_gui = TTF_RenderText_Solid(kono_gui, time, color_menu3);
    } else if (realTime > 100){
        time_gui = TTF_RenderText_Solid(kono_gui, time, color_menu2);
    } else{
        time_gui = TTF_RenderText_Solid(kono_gui, time, color_menu1);
    }

    ins_object(370, 15, time_gui, screen, null);

    ins_object(312, 5, clock_sprite, screen, null);
}

void sum_point(){
    char point[20];

    sprintf(point, "%d", HERO.points);

    points_gui = TTF_RenderText_Solid(kono_gui, point, color_menu2);

    ins_object(500, 17, points_gui, screen, null);
}

void life_game(){
    /*
    char life[2];

    sprintf(life, "%d", HERO.life);

    char vida[50] = "Vida: ";

    life_gui = TTF_RenderText_Solid(font, strcat(vida, life), menu_game_main);

    ins_object(5, 5, life_gui, screen, null);
    */

   int realLife = 3 - HERO.life;

   for(int i = 0; i < HERO.life; i++){
       ins_object(30 + (i*HERO.heart_clip[0].w), 10, heart_sprite, screen, &HERO.heart_clip[0]);
   }
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
        BOMB.x = HERO.table_x * 33;
        BOMB.y = HERO.table_y * 33;
        ins_object(BOMB.x, BOMB.y, bomb_sprites, screen, &BOMB.bomb_img[0]);
        BOMB.bombStatus = true;
        BOMB.timeStart = SDL_GetTicks()/1000;
    }
}

void bomb_timer(){

    if(((SDL_GetTicks()/1000) - BOMB.timeStart) > BOMB_DEFAULT){
        BOMB.bombStatus = false;
        Mix_PlayChannel(-1, bomb_explosion, 0);
    }
}

void move_actor(){
    HERO.x += HERO.xVel;

    if( ( HERO.x < 0 ) || ( HERO.x + 32 > SCREEN_WIDTH ) )
    {
        HERO.x -= HERO.xVel;
    }

    HERO.y += HERO.yVel;

    if( ( HERO.y < 0 ) || ( HERO.y + 32 > SCREEN_HEIGHT ) )
    {
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

void show_coordinate(){
    char x[10];
    char y[10];

    sprintf(x, "%d ", HERO.x);
    sprintf(y, "%d ", HERO.y);

    SDL_Surface* coord = TTF_RenderText_Solid(kono_font, strcat(x, y), color_menu1);

    ins_object(100, 100, coord, screen, null);

    char xt[10];
    char yt[10];

    HERO.table_x = (HERO.x/33)+1;
    HERO.table_y = (HERO.y/33)+1;

    printf("%d %d\n", HERO.table_x, HERO.table_y);

    sprintf(xt, "%d ", ((HERO.x)/31));
    sprintf(yt, "%d ", ((HERO.y)/31));

    SDL_Surface* coordTab = TTF_RenderText_Solid(kono_font, strcat(xt, yt), color_menu1);

    ins_object(100, 200, coordTab, screen, null);
}

void insert_enemy(enemy* e, SDL_Surface* image){
    ins_object(e->x, e->y, frog_sprite, screen, image);
}

void move_frog(enemy* e){
        int direction = rand()%4;

        switch(direction){
            case 0:
                e->x = e->x;
                e->y -= 2;
                insert_enemy(e, &ENEMY1.behind_clip[1]);
                break;
            case 1:
                e->x = e->x;
                e->y = e->y + 2;
                insert_enemy(e, &ENEMY1.front_clip[1]);
                break;
            case 2:
                e->x = e->x -1;
                e->y = e->y;
                insert_enemy(e, &ENEMY1.left_clip[1]);
                break;
            case 3:
                e->x = e->x;
                e->y = e->y + 1;
                insert_enemy(e, &ENEMY1.right_clip[1]);
                break;
        }
}

void move_enemies(enemy* e){

    switch(e->enemyClass){
        case 0:
            move_frog(e);
    }
}

enemy* enemies_stage(){
    enemy enemies[10];

    return enemies;
}

void char_constructor(){
    HERO.xVel = 0;
    HERO.yVel = 0;
    HERO.x = 162;
    HERO.y = 110;
    HERO.status = DOWN;
}

void game_start(){
    int quit = true;

    HERO.life = 3;
    HERO.points = 0;
    HERO.time = 300;

    fase1 = IMG_Load("Mapas/fase1_new_remod.png");
    bomb_sprites = IMG_Load("Sprites/bomb.png");
    frog_sprite = IMG_Load("Sprites/frog.png");
    clock_sprite = IMG_Load("Sprites/clock.png");

    enemy e1;

    e1.x = 200;
    e1.y = 300;
    e1.enemyClass = 0;

    while(quit){
        start();

        ins_object(HERO.x, HERO.y, map_characters, screen, &HERO.front_clip[1]);

        while(SDL_PollEvent(&event)){
            event_keyboard_handle();

            if(event.type == SDL_QUIT){
                exit(1);
            }
        }

        move_actor();

        SDL_FillRect( screen, &screen->clip_rect, SDL_MapRGB( screen->format, 62, 101, 91 ) );

        ins_object(0, 61, fase1, screen, null);

        //move_enemies(&e1);

        //printf("%d %d", HERO.table_x, HERO.table_y);

        life_game();

        sum_point();

        game_time();

        show_coordinate();

        quit = its_gameover();

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

    game_over();
}

int main(){
    init_sdl();

    char_constructor();

    init_modules();

    define_coordinates();

    int quit = true;

    while(quit == true){
        int option = menu_start();

        if(option == 0){
            game_start();
        } else if (option == 1){
            instrucoes();
        } else if(option == 2){
            menu_records();
        } else if(option == 3){
            quit = false;
        }
    }

    end_sdl();

    return 0;
}