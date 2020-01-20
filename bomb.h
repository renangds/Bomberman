void bomb_handle(){
    if(BOMB.bombStatus == false){
        Mix_PlayChannel( -1, drop_bomb, 0 );
        BOMB.x = ((HERO.table_x) * 33) - BOMB.bomb_img[0].w/2;
        BOMB.y = ((HERO.table_y) * 33) + BOMB.bomb_img[0].h/2;
        ins_object(BOMB.x, BOMB.y, bomb_sprites, screen, &BOMB.bomb_img[0]);
        BOMB.bombStatus = true;
        BOMB.frames = 1;
        BOMB.timeStart = SDL_GetTicks()/1000;
    }
}

void bomb_timer(){
    if(((SDL_GetTicks()/1000) - BOMB.timeStart) > BOMB_DEFAULT){
        EXPLOSION.x = BOMB.x-3;
        EXPLOSION.y = BOMB.y-3;
        BOMB.bombStatus = false;
        Mix_PlayChannel(-1, bomb_explosion, 0);
        EXPLOSION.status = true;
        EXPLOSION.frames = 0;
        EXPLOSION.timeStart = SDL_GetTicks()/1000;
    } else{
        ins_object(BOMB.x, BOMB.y, bomb_sprites, screen, &BOMB.bomb_img[BOMB.frames]);

        BOMB.frames++;

        if(BOMB.frames == 3){
            BOMB.frames = 1;
        }
    }
}

void explosion_animation(){
    
    if(((SDL_GetTicks()/1000) - EXPLOSION.timeStart) > EXPLOSION_DEFAULT){
        EXPLOSION.status = false;
    } else{
        
        ins_object(EXPLOSION.x, EXPLOSION.y+35, explosion_sprite, screen, &EXPLOSION.explosion_down[EXPLOSION.frames]);
        ins_object(EXPLOSION.x, EXPLOSION.y+68, explosion_sprite, screen, &EXPLOSION.explosion_down[EXPLOSION.frames+2]);

        ins_object(EXPLOSION.x, EXPLOSION.y-35, explosion_sprite, screen, &EXPLOSION.explosion_up[EXPLOSION.frames]);
        ins_object(EXPLOSION.x, EXPLOSION.y-68, explosion_sprite, screen, &EXPLOSION.explosion_up[EXPLOSION.frames+2]);

        ins_object(EXPLOSION.x+35, EXPLOSION.y, explosion_sprite, screen, &EXPLOSION.explosion_right[EXPLOSION.frames]);
        ins_object(EXPLOSION.x+68, EXPLOSION.y, explosion_sprite, screen, &EXPLOSION.explosion_right[EXPLOSION.frames+2]);

        ins_object(EXPLOSION.x-35, EXPLOSION.y, explosion_sprite, screen, &EXPLOSION.explosion_left[EXPLOSION.frames]);
        ins_object(EXPLOSION.x-68, EXPLOSION.y, explosion_sprite, screen, &EXPLOSION.explosion_left[EXPLOSION.frames+2]);

        ins_object(EXPLOSION.x, EXPLOSION.y, explosion_sprite, screen, &EXPLOSION.explosion_center);

        EXPLOSION.frames++;

        if(EXPLOSION.frames == 2){
            EXPLOSION.frames = 0;
        }
    }
}