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