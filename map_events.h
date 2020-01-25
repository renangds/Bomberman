enemylist* insert_enemy_list(enemylist* enemies, int x, int y, int enemyClass){
    enemylist* head = (enemylist*)malloc(sizeof(enemylist));
    enemy* e = (enemy*)malloc(sizeof(enemy));
    e->enemyClass = enemyClass;
    e->x = (x * 48) + 80;
    e->y = (y * 48);
    e->control = 0;
    e->isItem = false;

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

            if(map_stage[i][j] == 9){
                enemies = insert_enemy_list(enemies, i, j, 2);
            }

            if(map_stage[i][j] == 3){
                enemies = insert_enemy_list(enemies, i, j, 3);
            }

            if(map_stage[i][j] == 4){
                enemies = insert_enemy_list(enemies, i, j, 4);
            }

            if(map_stage[i][j] == 7){
                enemies = insert_enemy_list(enemies, i, j, 7);
            }
            
           if(map_stage[i][j] == 6){
               PORTAL_RESPAWN.x = i * 48;
               PORTAL_RESPAWN.y = j * 48;
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

void damage_character(){
    HERO.x = 100;
    HERO.y = 100;
    HERO.life -= 1;
    HERO.status = DOWN;
}

void get_item(int itemType){
    switch(itemType){
        case 0:
            Mix_PlayChannel( -1, sound_gettime, 0 );
            HERO.time += 30;
            break;
        case 1:
            Mix_PlayChannel( -1, sound_getothers, 0 );
            HERO.points += 40;
            break;
        case 2:
            Mix_PlayChannel( -1, sound_getothers, 0 );
            if(HERO.life < 5) HERO.life += 1;
            break;
        case 3:
            Mix_PlayChannel( -1, sound_getkey, 0 );
            HERO.haveKey = true;
            break;
    }
}

void draw_enemies(enemylist* enemies){
    enemylist* temp = enemies;

    if(temp){
        while(temp != NULL){
            if(temp->enemy->enemyClass == 3 && !temp->enemy->isItem) ins_object(temp->enemy->y, temp->enemy->x, chest, screen, &IOBJ.blue_chest);
            if(temp->enemy->enemyClass == 4 && !temp->enemy->isItem) ins_object(temp->enemy->y, temp->enemy->x, chest, screen, &IOBJ.destructive);
            if(temp->enemy->isItem){
                ins_object(temp->enemy->y, temp->enemy->x, items_game, screen, &ITEMS.items_bonus[temp->enemy->itemType]);
                if(enemy_kick(temp->enemy)){
                    get_item(temp->enemy->itemType);
                    temp->enemy->isItem = false;
                    temp->enemy->enemyClass = -1;
                }
            }
            if(temp->enemy->enemyClass == 1 && !temp->enemy->isItem){
                move_frog_down_up(temp->enemy);
                ins_object(temp->enemy->y, temp->enemy->x, frog_sprite, screen, &ENEMY1.clips[0]);
                if(enemy_kick(temp->enemy)) damage_character();
            } 
            if(temp->enemy->enemyClass == 2 && !temp->enemy->isItem){
                move_frog_left_right(temp->enemy);
                ins_object(temp->enemy->y, temp->enemy->x, frog_sprite, screen, &ENEMY1.clips[0]);
                if(enemy_kick(temp->enemy)) damage_character();
            } 
            if(temp->enemy->enemyClass == 7 && !temp->enemy->isItem){
                ins_object(temp->enemy->y, temp->enemy->x, exit_portal, screen, &EXIT.door);
                if(!enemy_kick(temp->enemy)){
                    if(HERO.haveKey && map_stage[HERO.table_y-2][HERO.table_x] == 7) success = true;
                }
            } 
            temp = temp->next;
        }
    }
}

void draw_map(){
    for(int i = 0; i < 10; i++){
        for(int j = 0; j < 16; j++){
            if(map_stage[i][j] == 2) ins_object((j * 48), (i * 48) + 80, stage_objs, screen, &IOBJ.barrel);
            //if(map_stage[i][j] == 7) ins_object((j * 48), (i * 48) + 80, exit_portal, screen, &EXIT.door);
            if(map_stage[i][j] == false) ins_object((j * 48), (i * 48) + 80, stage_objs, screen, &IOBJ.indest);
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

void portal_respawn(){
    ins_object(PORTAL_RESPAWN.y * 48, PORTAL_RESPAWN.x * 48, portal, screen, &PORTAL_RESPAWN.portal);
}