static struct hero{
    SDL_Rect front_clip[3];
    SDL_Rect behind_clip[3];
    SDL_Rect left_clip[3];
    SDL_Rect right_clip[3];
    int yVel;
    int xVel;
    int x;
    int y;
    int frames;
    int status;
} HERO;

static struct bomb{
    SDL_Rect bomb_img[9];
    SDL_Rect explosion[10];
    int timeStart;
} BOMB;

static struct enemy1_coordinates{
    SDL_Rect front_clip[3];
    SDL_Rect behind_clip[3];
    SDL_Rect left_clip[3];
    SDL_Rect right_clip[3];
} ENEMY1;

struct enemy_moves{
    int yVel;
    int xVel;
} enemy;