static struct hero{
    SDL_Rect front_clip[3];
    SDL_Rect behind_clip[3];
    SDL_Rect left_clip[3];
    SDL_Rect right_clip[3];
    SDL_Rect heart_clip[2];
    int yVel;
    int xVel;
    int x;
    int y;
    int table_x;
    int table_y;
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
    int frames;
} BOMB;

static struct enemy1_coordinates{
    SDL_Rect front_clip[3];
    SDL_Rect behind_clip[3];
    SDL_Rect left_clip[3];
    SDL_Rect right_clip[3];
} ENEMY1;

static struct object_image{
    SDL_Rect destructive;
    SDL_Rect indest;
} IOBJ;

typedef struct object{
    int x;
    int y;
} OBJ;

static struct explosion_animation{
    SDL_Rect explosion_up[4];
    SDL_Rect explosion_down[4];
    SDL_Rect explosion_left[4];
    SDL_Rect explosion_right[4];
    SDL_Rect explosion_center;
    int active;
    int status;
    int frames;
    int x;
    int y;
    int timeStart;
} EXPLOSION;

typedef struct enemy_moves{
    int x;
    int y;
    int nextMove;
    int enemyClass;
} enemy;

typedef struct enemy_list{
    struct enemy_list* next;
    enemy* enemy;
} enemylist;

static struct portal{
    SDL_Rect portal_animation[3];
    int frames;
    int x;
    int y;
} PORTAL;

enemylist* listEnemies;