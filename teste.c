#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){

    for(int i=0; i<20; i++){
        printf("%d\n", rand()%3);
    }

    return 0;
}