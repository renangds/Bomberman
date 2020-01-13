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
    int life;
    int points;
    int time;
} HERO;

static struct bomb{
    SDL_Rect bomb_img[9];
    SDL_Rect explosion[10];
    int timeStart;
    int bombStatus;
    int x;
    int y;
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