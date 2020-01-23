void init_sdl(){
    if(SDL_Init(SDL_INIT_EVERYTHING) == -1) exit(1);

    if(TTF_Init() == -1) exit(1);

    if(Mix_OpenAudio( 22050, MIX_DEFAULT_FORMAT, 2, 4096 ) == -1 ) exit(1);

    screen = SDL_SetVideoMode(SCREEN_WIDTH, SCREEN_HEIGHT, SCREEN_BPP, SDL_SWSURFACE);

    if(!screen) exit(1);

    SDL_WM_SetCaption("BomberSuba! Megumin's Last Explosion!", null);
}

init_fonts(){
    kono_font = TTF_OpenFont("Fonte/grobold.ttf", 28);

    if(kono_font == null) exit(1);

    kono_gui = TTF_OpenFont("Fonte/grobold.ttf", 34);

    if(!kono_gui) exit(1);
}

init_images(){
    objects = IMG_Load("Sprites/icones.png");

    heart_sprite = IMG_Load("Sprites/heart_med.png");

    map_characters = IMG_Load("Sprites/megumin.png");

    explosion_sprite = IMG_Load("Sprites/explosion.png");

    portal = IMG_Load("Sprites/portal_m.png");

    bomb = IMG_Load("Sprites/bombnew.png");

    stage_objs = IMG_Load("Sprites/objects.png");

    chest = IMG_Load("Sprites/chest.png");

    items_game = IMG_Load("Sprites/items.png");

    clock_sprite = IMG_Load("Sprites/clock.png");
    
    background_gui = IMG_Load("Sprites/background_gui.png");

    if(!heart_sprite || !map_characters) exit(1);
}

init_mixes(){
    drop_bomb = Mix_LoadWAV("Musica/megumin_explosion.wav");

    main_music = Mix_LoadMUS("Musica/stage1.mp3");

    music_menu = Mix_LoadMUS("Musica/intro_music.mp3");

    bomb_explosion = Mix_LoadWAV("Musica/boom.wav");

    if(!drop_bomb || !main_music || !music_menu || !bomb_explosion) exit(1);
}

void close_fonts(){
    TTF_CloseFont(kono_font);
    TTF_CloseFont(kono_gui);
}

void close_images(){
    SDL_FreeSurface(heart_sprite);
    SDL_FreeSurface(map_characters);
}

void close_mixes(){
    Mix_FreeMusic(main_music);
    Mix_FreeChunk(bomb_explosion);
    Mix_FreeChunk(drop_bomb);
}

void init_modules(){
    init_fonts();
    init_mixes();
    init_images();
}

void end_sdl(){
    close_images();
    close_mixes();
    close_fonts();

    SDL_Quit();
}