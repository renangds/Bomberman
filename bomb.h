void bomb_handle(){
    if(BOMB.bombStatus == false){
        Mix_PlayChannel( -1, drop_bomb, 0 );
        BOMB.x = (HERO.table_x+1) * 33;
        BOMB.y = ((HERO.table_y-1) * 34) + 55;
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