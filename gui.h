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

    ins_object(370, 25, time_gui, screen, null);

    ins_object(312, 15, clock_sprite, screen, null);
}

void sum_point(){
    char point[20];

    sprintf(point, "%d", HERO.points);

    points_gui = TTF_RenderText_Solid(kono_gui, point, color_menu2);

    ins_object(530, 25, points_gui, screen, null);
}

void life_game(){
   int realLife = 3 - HERO.life;

   for(int i = 0; i < HERO.life; i++){
       ins_object(30 + (i*HERO.heart_clip[0].w), 20, heart_sprite, screen, &HERO.heart_clip[0]);
   }
}

void bomb_show_gui(){
    if(BOMB.bombStatus == true){
        ins_object(650, 15, items_game, screen, &ITEMS.bomb_activate);
    }
}

void explosion_show_gui(){
    if(EXPLOSION.status == true){
        ins_object(710, 20, items_game, screen, &ITEMS.bomb_exploded);
    }
}

void show_guis(){
    ins_object(0, 0, background_gui, screen, null);
    game_time();
    sum_point();
    life_game();
    bomb_show_gui();
    explosion_show_gui();
}