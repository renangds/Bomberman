void instrucoes(){
    SDL_Surface* telaInstrucao = IMG_Load("Intro/kono_instrucoes.png");

    if(!telaInstrucao) exit(1);

    int quit = true;

    ins_object(0, 0, telaInstrucao, screen, null);

    while(quit == true){
        start();

        while(SDL_PollEvent(&event)){
            if(event.type == SDL_KEYDOWN){
                switch(event.key.keysym.sym){
                    case SDLK_SPACE: quit = false;
                }
            }
        }

        SDL_FillRect( screen, &screen->clip_rect, SDL_MapRGB( screen->format, 148, 57, 72));
        ins_object(0, 0, telaInstrucao, screen, null);

        if( SDL_Flip( screen ) == -1 )
        {
            return 1;
        }

        if(get_ticks() < 1000 / 8){
            SDL_Delay( ( 1000 / 8 ) - get_ticks() );
        }
    }

    SDL_free(telaInstrucao);
}

int menu_start(){
    int option = 0;
    int quit = true;

    SDL_Surface* telaIntro = IMG_Load("Intro/kono_intro.png");

    if(telaIntro == -1){
        exit(1);
    }

    SDL_Surface* startGame = TTF_RenderText_Solid(kono_font, "Explosion!", color_main);
    SDL_Surface* instructions = TTF_RenderText_Solid(kono_font, "Intrucoes", color_main);
    SDL_Surface* exitGame = TTF_RenderText_Solid(kono_font, "Sair", color_main);
    SDL_Surface* records = TTF_RenderText_Solid(kono_font, "Record", color_main);

    if(!startGame || !instructions || !exitGame || !records ) exit(1);

    ins_object(78, 286, startGame, screen, null);
    ins_object(78, 316, instructions, screen, null);
    ins_object(78, 346, records, screen, null);
    ins_object(78, 376, exitGame, screen, null);

    while(quit == true){
        start();

        while(SDL_PollEvent(&event)){
            if(event.type == SDL_Quit){
                quit = false;
            }
        }

        if(Mix_PlayingMusic() == 0){
            Mix_PlayMusic(music_menu, -1);
        }
        

        Uint8* keystates = SDL_GetKeyState(NULL);

        if(keystates[SDLK_UP]){
            Mix_PlayChannel( -1, sound_menu, 0 );
            if(option == 0){
                option = 3;
            } else{
                option--;
            }
        } else if (keystates[SDLK_DOWN]){
            Mix_PlayChannel( -1, sound_menu, 0 );
            if(option == 3){
                option = 0;
            } else{
                option++;
            }
        } else if(keystates[SDLK_SPACE]){
            quit = false;
        }

        switch(option){
            case 0:
                startGame = TTF_RenderText_Solid(kono_font, "Explosion!", color_menu1);
                instructions = TTF_RenderText_Solid(kono_font, "Intrucoes", menu_unselected);
                records = TTF_RenderText_Solid(kono_font, "Record", menu_unselected);
                exitGame = TTF_RenderText_Solid(kono_font, "Sair", menu_unselected);
                break;
            case 1:
                startGame = TTF_RenderText_Solid(kono_font, "Explosion!", menu_unselected);
                instructions = TTF_RenderText_Solid(kono_font, "Intrucoes", color_menu2);
                records = TTF_RenderText_Solid(kono_font, "Record", menu_unselected);
                exitGame = TTF_RenderText_Solid(kono_font, "Sair", menu_unselected);    
                break;
            case 2:
                startGame = TTF_RenderText_Solid(kono_font, "Explosion!", menu_unselected);
                instructions = TTF_RenderText_Solid(kono_font, "Intrucoes", menu_unselected);
                records = TTF_RenderText_Solid(kono_font, "Record", color_menu3);
                exitGame = TTF_RenderText_Solid(kono_font, "Sair", menu_unselected);
                break;
            case 3:
                startGame = TTF_RenderText_Solid(kono_font, "Explosion!", menu_unselected);
                instructions = TTF_RenderText_Solid(kono_font, "Intrucoes", menu_unselected);
                records = TTF_RenderText_Solid(kono_font, "Record", menu_unselected);
                exitGame = TTF_RenderText_Solid(kono_font, "Sair", color_menu1);
                break;
        }

        SDL_FillRect( screen, &screen->clip_rect, SDL_MapRGB( screen->format, 148, 57, 72));

        ins_object(0, 0, telaIntro, screen, null);

        ins_object(78, 286, startGame, screen, null);
        ins_object(78, 316, instructions, screen, null);
        ins_object(78, 346, records, screen, null);
        ins_object(78, 376, exitGame, screen, null);

        if( SDL_Flip( screen ) == -1 )
        {
            return 1;
        }

        if(get_ticks() < 1000 / 8){
            SDL_Delay( ( 1000 / 8 ) - get_ticks() );
        }
    }

    SDL_FreeSurface(startGame);
    SDL_FreeSurface(instructions);
    SDL_FreeSurface(exitGame);
    SDL_FreeSurface(records);
    SDL_FreeSurface(telaIntro);

   return option;
}

void menu_records(){
    SDL_Surface* telaRecordes = IMG_Load("Intro/megumin_recordes.png");

    if(!telaRecordes) exit(1);

    int quit = true;

    ins_object(0, 0, telaRecordes, screen, null);

    FILE* fl;
    char point[20];
    int points[5];
    int index = -1;

    if((fl = fopen("Arquivos/records.txt", "r")) == NULL){
        perror("Erro: fopen");
        exit(1);
    }

    while((fscanf(fl, "%s\n", point)) != EOF){
        points[++index] = atoi(point);
    }

    SDL_Surface* imgPoint; 

    while(quit == true){
        start();

        while(SDL_PollEvent(&event)){
            if(event.type == SDL_KEYDOWN){
                switch(event.key.keysym.sym){
                    case SDLK_SPACE: quit = false;
                }
            }
        }

        SDL_FillRect( screen, &screen->clip_rect, SDL_MapRGB( screen->format, 148, 57, 72));
        ins_object(0, 0, telaRecordes, screen, null);

        for(int i = 0; i < 5; i++){
            sprintf(point, "%d", points[i]);
            imgPoint = TTF_RenderText_Solid(kono_font, point, menu_unselected);
            ins_object(40, 144 + (i*30), imgPoint, screen, null);
        }

        if( SDL_Flip( screen ) == -1 )
        {
            return 1;
        }

        if(get_ticks() < 1000 / 8){
            SDL_Delay( ( 1000 / 8 ) - get_ticks() );
        }
    }

    SDL_free(telaRecordes);
}

void game_over(){
    Mix_PauseMusic();

    int quit = true;

    SDL_Surface* img = IMG_Load("Intro/megumin_gameover_2.png");

    SDL_FillRect( screen, &screen->clip_rect, SDL_MapRGB( screen->format, 148, 57, 72));
    ins_object(0, 80, img, screen, null);

    if(SDL_Flip(screen) == -1) exit(1);

    sort_records(HERO.points);

    SDL_Delay(5000);

    SDL_free(img);
}

void stage_clear(){

}

int its_gameover(){
    if(HERO.life == 0 || HERO.time == 0){
        return false;
    } else{
        return true;
    }
}