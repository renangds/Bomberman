#include "library.h"
#include "time.h"
#include "hero_coordinates.h"
#include "define_coordinates.h"
#include "start_sdl_modules.h"
#include "record.h"
#include "menus.h"
#include "gui.h"
#include "moves_inserts.h"
#include "bomb.h"
#include "map_events.h"


void char_constructor(){
    HERO.xVel = 0;
    HERO.yVel = 0;
    HERO.x = 162;
    HERO.y = 110;
    HERO.status = DOWN;
}

void game_start(){
    int x, y, z;
    int quit = true;
    success = false;
    HERO.haveKey = false;

    listEnemies = read_map(listEnemies);

    HERO.life = 3;
    HERO.points = 0;
    HERO.time = 150;

    HERO.xVel = 0;
    HERO.yVel = 0;

    PORTAL.frames = 0;

    fase1 = IMG_Load("Mapas/stage1.png");
    frog_sprite = IMG_Load("Sprites/frog_m.png");

    HERO.x = PORTAL_RESPAWN.x;
    HERO.y = PORTAL_RESPAWN.y;

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

        portal_respawn();

        portal_on();

        SDL_FillRect( screen, &screen->clip_rect, SDL_MapRGB( screen->format, 0, 0, 0 ) );

        show_guis();

        ins_object(0, 80, fase1, screen, null);

        ins_object(((PORTAL_RESPAWN.y-1) * 48), (PORTAL_RESPAWN.x * 48)+90, portal, screen, &PORTAL_RESPAWN.portal);

        draw_map();

        draw_enemies(listEnemies);

        quit = its_gameover();

        if(BOMB.bombStatus == true){
            bomb_timer();
        }

        if(EXPLOSION.status == true){
            explosion_animation();
        }

        insert_actor();

        if(Mix_PlayingMusic() == 0){
            Mix_PlayMusic(main_music, -1);
        }

        if(SDL_Flip(screen) == -1){
            return 1;
        }

        if(get_ticks() < 1000/_FPS){
            SDL_Delay((1000/_FPS) - get_ticks());
        }
    }

    Mix_HaltMusic();
    
    free(listEnemies);
    
    listEnemies = NULL;

    SDL_FreeSurface(fase1);
    SDL_FreeSurface(frog_sprite);

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
            Mix_HaltMusic();
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