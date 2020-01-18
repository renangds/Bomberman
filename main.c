#include "library.h"
#include "time.h"
#include "hero_coordinates.h"
#include "define_coordinates.h"
#include "start_sdl_modules.h"
#include "record.h"
#include "menus.h"
#include "gui.h"
#include "bomb.h"
#include "moves_inserts.h"

void show_coordinate(){
    char x[10];
    char y[10];

    sprintf(x, "%d ", HERO.x);
    sprintf(y, "%d ", HERO.y);

    SDL_Surface* coord = TTF_RenderText_Solid(kono_font, strcat(x, y), color_menu1);

    ins_object(100, 100, coord, screen, null);

    char xt[10];
    char yt[10];

    HERO.table_x = (HERO.x/33);
    HERO.table_y = (HERO.y/34);

    //printf("%d %d\n", HERO.table_x, HERO.table_y);

    sprintf(xt, "%d ", ((HERO.x)/33));
    sprintf(yt, "%d ", ((HERO.y)/34));

    SDL_Surface* coordTab = TTF_RenderText_Solid(kono_font, strcat(xt, yt), color_menu1);

    ins_object(100, 200, coordTab, screen, null);
}

void char_constructor(){
    HERO.xVel = 0;
    HERO.yVel = 0;
    HERO.x = 162;
    HERO.y = 110;
    HERO.status = DOWN;
}

void colision(OBJ* obj){
    int bottomH = 
}

void game_start(){
    int quit = true;

    HERO.life = 3;
    HERO.points = 0;
    HERO.time = 300;

    fase1 = IMG_Load("Mapas/fase1_new_remod.png");
    bomb_sprites = IMG_Load("Sprites/bomb2.png");
    frog_sprite = IMG_Load("Sprites/frog.png");
    clock_sprite = IMG_Load("Sprites/clock.png");

    enemy e1;

    e1.x = 200;
    e1.y = 300;
    e1.enemyClass = 0;

    OBJ objeto;

    objeto.x = 200;
    objeto.y = 200;

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

        ins_object(objeto.x, objeto.y, objects, screen, &IOBJ.destructive);

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
            //Mix_PlayMusic(main_music, -1);
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