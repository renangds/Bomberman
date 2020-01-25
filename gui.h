void game_time(){
    char time[20];

    if(!tempo){
        tempo = _FPS;
        HERO.time -= 1;
    } 

    tempo--;

    sprintf(time, "%d", HERO.time);

    if(HERO.time > 100){
        time_gui = TTF_RenderText_Solid(kono_gui, time, color_menu3);
    } else if (HERO.time > 50){
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

    ins_object(480, 25, points_gui, screen, null);
}

void life_game(){
   int realLife = 3 - HERO.life;

   for(int i = 0; i < HERO.life; i++){
       ins_object(30 + (i*HERO.heart_clip[0].w), 20, heart_sprite, screen, &HERO.heart_clip[0]);
   }
}

void key_gui(){
    if(HERO.haveKey) ins_object(600, 15, items_game, screen, &ITEMS.items_bonus[3]);
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
    key_gui();
    bomb_show_gui();
    explosion_show_gui();
}