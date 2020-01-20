void ins_object(int x, int y, SDL_Surface* sour, SDL_Surface* dest, SDL_Surface* clip){
    SDL_Rect offset;

    offset.x = x;
    offset.y = y;

    SDL_BlitSurface(sour, clip, dest, &offset);
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