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

    HERO.table_x = (HERO.x+30)/48;
    HERO.table_y = (HERO.y+35)/48;

    sprintf(x, "%d ", HERO.x);
    sprintf(y, "%d ", HERO.y);

    SDL_Surface* coord = TTF_RenderText_Solid(kono_font, strcat(x, y), color_menu1);

    ins_object(100, 100, coord, screen, null);

    char xt[10];
    char yt[10];
    char obji[10];

    //HERO.table_x = (HERO.x+23)/33;
    //HERO.table_y = (HERO.y+25)/34;

    //printf("%d %d\n", HERO.table_x, HERO.table_y);

    sprintf(xt, "%d ", HERO.table_x);
    sprintf(yt, "%d ", HERO.table_y);

    SDL_Surface* coordTab = TTF_RenderText_Solid(kono_font, strcat(xt, yt), color_menu1);

    ins_object(100, 200, coordTab, screen, null);

    sprintf(obji, "%d ", map_stage[HERO.table_y][HERO.table_x]);

    SDL_Surface* obj = TTF_RenderText_Solid(kono_font, obji, color_menu3);

    ins_object(100, 300, obj, screen, null);
}


void char_constructor(){
    HERO.xVel = 0;
    HERO.yVel = 0;
    HERO.x = 162;
    HERO.y = 110;
    HERO.status = DOWN;
}

void ia_enemy_up(){

}

enemylist* insert_enemy_list(enemylist* enemies, int x, int y, int enemyClass){
    enemylist* head = (enemylist*)malloc(sizeof(enemylist));
    enemy* e = (enemy*)malloc(sizeof(enemy));
    e->enemyClass = enemyClass;
    e->x = x;
    e->y = y;

    if(!enemies){
        head->enemy = e;
        head->next = null;

        return head;
    } else{
        head->next = enemies;
        head->enemy = e;

        return head;
    }
}

enemylist* read_map(enemylist* enemies){
    FILE* arq;
    char* str[2];

    if((arq = fopen("Arquivos/stage1.txt", "r")) == null){
        exit(1);
    }

    for(int i = 0; i < 10; i++){
        for(int j = 0; j < 16; j++){
            fscanf(arq, "%s ", str);
            map_stage[i][j] = atoi(str);
            
            if(map_stage[i][j] == 5){
                enemies = insert_enemy_list(enemies, i, j, 1);
            }
            
           if(map_stage[i][j] == 6){
               PORTAL_RESPAWN.x = i;
               PORTAL_RESPAWN.y = j;
           }
            if(map_stage[i][j] == 5){
                PORTAL.x = i;
                PORTAL.y = j;
            }
        }
    }

    fclose(arq);

    return enemies;
}

void draw_enemies(enemylist* enemies){
    enemylist* temp = enemies;

    if(temp){
        while(temp != NULL){
            ins_object((temp->enemy->y * 48), (temp->enemy->x * 48) + 80, frog_sprite, screen, &ENEMY1.clips[0]);
            if(enemy_kick(temp->enemy)){
                HERO.x = PORTAL_RESPAWN.x*48;
                HERO.y = PORTAL_RESPAWN.y*48;
                HERO.life -= 1;
            }
            temp = temp->next;
        }
    }
}

void draw_map(){
    for(int i = 0; i < 10; i++){
        for(int j = 0; j < 16; j++){
            if(map_stage[i][j] == 2) ins_object((j * 48), (i * 48) + 80, stage_objs, screen, &IOBJ.barrel);
            if(map_stage[i][j] == false) ins_object((j * 48), (i * 48) + 80, stage_objs, screen, &IOBJ.indest);
            if(map_stage[i][j] == 4) ins_object((j * 48), (i * 48) + 80, chest, screen, &IOBJ.destructive);
            //if(map_stage[i][j] == 5) ins_object((j * 48), (i * 48) + 80, frog_sprite, screen, &ENEMY1.clips[0]);
        }
    }
}

void portal_on(){
    ins_object((PORTAL.y * 33) - 5, (PORTAL.x * 37) + PORTAL.portal_animation[PORTAL.frames].h, portal, screen, &PORTAL.portal_animation[PORTAL.frames]);

    PORTAL.frames++;

    if(PORTAL.frames == 2){
        PORTAL.frames = 0;
    }
}

void stage_clear(){

}

void portal_respawn(){
    ins_object(PORTAL_RESPAWN.y * 48, PORTAL_RESPAWN.x * 48, portal, screen, &PORTAL_RESPAWN.portal);
}

void game_start(){
    int quit = true;

    listEnemies = read_map(listEnemies);

    HERO.life = 3;
    HERO.points = 0;
    HERO.time = 300;

    PORTAL.frames = 0;

    fase1 = IMG_Load("Mapas/stage1.png");
    frog_sprite = IMG_Load("Sprites/frog_m.png");


    HERO.x = (PORTAL_RESPAWN.x * 48);
    HERO.y = (PORTAL_RESPAWN.y * 48);

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

        SDL_FillRect( screen, &screen->clip_rect, SDL_MapRGB( screen->format, 62, 101, 91 ) );

        show_guis();

        ins_object(0, 80, fase1, screen, null);

        ins_object((PORTAL_RESPAWN.y * 48), (PORTAL_RESPAWN.x * 48)+80, portal, screen, &PORTAL_RESPAWN.portal);

        //move_enemies(&e1);

        draw_map();

        draw_enemies(listEnemies);

        //show_coordinate();

        //portal_on();

        quit = its_gameover();

        if(BOMB.bombStatus == true){
            bomb_timer();
        }

        if(EXPLOSION.status == true){
            explosion_animation();
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