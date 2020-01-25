void bomb_handle(){
    if(BOMB.bombStatus == false){
        //Mix_PlayChannel( -1, drop_bomb, 0 );
        BOMB.x = ((HERO.table_x) * 48) + 2; //Os 2 são ajustes por causa do pixel!
        BOMB.y = ((HERO.table_y-1) * 48) + 80;
        ins_object(BOMB.x, BOMB.y, bomb, screen, null);
        BOMB.bombStatus = true;
        BOMB.frames = 1;
        BOMB.timeStart = SDL_GetTicks()/1000;
        BOMB.x_map = HERO.table_x;
        BOMB.y_map = HERO.table_y;
    }
}

void bomb_timer(){
    if(((SDL_GetTicks()/1000) - BOMB.timeStart) > BOMB_DEFAULT){
        if(map_stage[BOMB.y_map-1][BOMB.x_map+1] == 4) map_stage[BOMB.y_map-1][BOMB.x_map+1] = 1;
        EXPLOSION.x = BOMB.x-3;
        EXPLOSION.y = BOMB.y-3;
        EXPLOSION.x_map = BOMB.x_map;
        EXPLOSION.y_map = BOMB.y_map;
        BOMB.bombStatus = false;
        Mix_PlayChannel(-1, bomb_explosion, 0);
        EXPLOSION.status = true;
        EXPLOSION.frames = 0;
        EXPLOSION.timeStart = SDL_GetTicks()/1000;
    } else{
        ins_object(BOMB.x, BOMB.y, bomb, screen, null);
    }
}

void destroy_enemy(int x, int y){
    enemylist* temp = listEnemies;
    enemylist* ant = null;

    if(temp){
        while(temp != NULL){
            int posx = (temp->enemy->y+35)/48;
            int posy = (temp->enemy->x-80)/48;

            if(x == posx && y == posy){
                //HERO.points += 20;

                if(temp == listEnemies){

                }
            } 

            ant = temp;
            temp = temp->next;
        }
    }
}

void explosion_animation(){
    
    if(((SDL_GetTicks()/1000) - EXPLOSION.timeStart) > EXPLOSION_DEFAULT){
        EXPLOSION.status = false;
    } else{        

        ins_object(EXPLOSION.x, EXPLOSION.y, explosion_sprite, screen, &EXPLOSION.explosion_center);

        //Direita
        if(map_stage[EXPLOSION.y_map-1][EXPLOSION.x_map+1] > 0){
            ins_object(EXPLOSION.x+48, EXPLOSION.y, explosion_sprite, screen, &EXPLOSION.explosion_right[EXPLOSION.frames]);

            map_stage[EXPLOSION.y_map-1][EXPLOSION.x_map+1] = 1;

            destroy_enemy(EXPLOSION.x_map+1, EXPLOSION.y_map-1);

            if(map_stage[EXPLOSION.y_map-1][EXPLOSION.x_map+2] > 0){

                ins_object(EXPLOSION.x+96, EXPLOSION.y, explosion_sprite, screen, &EXPLOSION.explosion_right[EXPLOSION.frames+2]);

                map_stage[EXPLOSION.y_map-1][EXPLOSION.x_map+2] = 1;

                destroy_enemy(EXPLOSION.x_map+2, EXPLOSION.y_map-1);
            }
        }

        //Esquerda
        if(map_stage[EXPLOSION.y_map-1][EXPLOSION.x_map-1] > 0){
            ins_object(EXPLOSION.x-48, EXPLOSION.y, explosion_sprite, screen, &EXPLOSION.explosion_left[EXPLOSION.frames]);

            map_stage[EXPLOSION.y_map-1][EXPLOSION.x_map-1] = 1;

            destroy_enemy(EXPLOSION.x_map-1, EXPLOSION.y_map-1);
        
            if(map_stage[EXPLOSION.y_map-1][EXPLOSION.x_map-2] > 0){
                
                ins_object(EXPLOSION.x-96, EXPLOSION.y, explosion_sprite, screen, &EXPLOSION.explosion_left[EXPLOSION.frames+2]);

                map_stage[EXPLOSION.y_map-1][EXPLOSION.x_map-2] = 1;

                destroy_enemy(EXPLOSION.x_map-2, EXPLOSION.y_map-1);
            }
        }

        //Cima
        if(map_stage[EXPLOSION.y_map-2][EXPLOSION.x_map] > 0){
            ins_object(EXPLOSION.x, EXPLOSION.y - (EXPLOSION.explosion_center.h)
            , explosion_sprite, screen, &EXPLOSION.explosion_up[EXPLOSION.frames]);

            map_stage[EXPLOSION.y_map-2][EXPLOSION.x_map] = 1;

            destroy_enemy(EXPLOSION.x_map, EXPLOSION.y_map-2);
        
            if(map_stage[EXPLOSION.y_map-3][EXPLOSION.x_map] > 0){
                ins_object(EXPLOSION.x, EXPLOSION.y - (EXPLOSION.explosion_center.h) - (EXPLOSION.explosion_up[EXPLOSION.frames+2].h)
                , explosion_sprite, screen, &EXPLOSION.explosion_up[EXPLOSION.frames+2]);

                map_stage[EXPLOSION.y_map-3][EXPLOSION.x_map] = 1;

                destroy_enemy(EXPLOSION.x_map, EXPLOSION.y_map-3);
            }
        }

        //Baixo
        if(map_stage[EXPLOSION.y_map][EXPLOSION.x_map] > 0){
            ins_object(EXPLOSION.x, EXPLOSION.y + (EXPLOSION.explosion_center.h), 
            explosion_sprite, screen, &EXPLOSION.explosion_down[EXPLOSION.frames]);

            map_stage[EXPLOSION.y_map][EXPLOSION.x_map] = 1;

            destroy_enemy(EXPLOSION.x_map, EXPLOSION.y_map);
        
            if(map_stage[EXPLOSION.y_map+1][EXPLOSION.x_map] > 0){
                ins_object(EXPLOSION.x, EXPLOSION.y + (EXPLOSION.explosion_center.h)
                    + (EXPLOSION.explosion_down[EXPLOSION.frames+2].h), explosion_sprite, screen, &EXPLOSION.explosion_down[EXPLOSION.frames+2]);

                map_stage[EXPLOSION.y_map+1][EXPLOSION.x_map] = 1;

                destroy_enemy(EXPLOSION.x_map, EXPLOSION.y_map+1);
            }
        }

        EXPLOSION.frames++;

        if(EXPLOSION.frames == 2){
            EXPLOSION.frames = 0;
        }
    }
}