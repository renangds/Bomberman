#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){
    for(int i = 0; i < 100; i++){
        printf("%d ", rand()%4);
    }

    return 0;
}