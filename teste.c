#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main(){
    int i = 10;
    char c[2];

    sprintf(c, "%d", i);

    char* a = "lalala";

    char* b = "lelele";

    strcat(*a, *b);

    printf("%s", b);

    return 0;
}