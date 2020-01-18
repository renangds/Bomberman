#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct person{
    int x;
    int y;
} PERSON;

void printPersons(PERSON* vec){
    for(int i = 0; i < 2; i++){
        printf("%d \n", vec[i].x);
    }

    vec[0].x = 20;
}

int main(){
    PERSON* p = (PERSON*)malloc(sizeof(PERSON));
    PERSON* s = (PERSON*)malloc(sizeof(PERSON));

    p->x = 10;
    s->x = 20;

    PERSON vec[2];

    vec[0] = *p;
    vec[1] = *s;

    PERSON* vec2 = s;

    printPersons(vec);

    printf("%d \n", vec[0].x);

    printf("%d \n", vec2->x);

    free(p);
    free(s);

    return 0;
}