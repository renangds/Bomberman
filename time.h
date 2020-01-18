static struct timer{
    int startTicks;
    int pausedTicks;
    int start;
    int pause;
} Time;

void start();
void stop();
void pause();
void unpause();

int get_ticks();

void start(){
    Time.startTicks = SDL_GetTicks();
    Time.pausedTicks = 0;
    Time.pause = 0;
    Time.start = 1;
}

void stop(){
    Time.pause = 0;
    Time.start = 0;
}

int get_ticks(){
    if(Time.start == true){
        if(Time.pause == true){
            return Time.pausedTicks;
        } else{
            return SDL_GetTicks() - Time.startTicks;
        }
    }

    return 0;
}

void pause(){
    if(Time.start == true && Time.pause == false){
        Time.pause = true;

        Time.pausedTicks = SDL_GetTicks() - Time.startTicks;
    }
}

void unpause(){
    if(Time.pause == true){
        Time.pause = false;
        Time.startTicks = SDL_GetTicks() - Time.pausedTicks;

        Time.pausedTicks = 0;
    }
}