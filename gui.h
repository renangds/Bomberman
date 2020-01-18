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
   int realLife = 3 - HERO.life;

   for(int i = 0; i < HERO.life; i++){
       ins_object(30 + (i*HERO.heart_clip[0].w), 10, heart_sprite, screen, &HERO.heart_clip[0]);
   }
}