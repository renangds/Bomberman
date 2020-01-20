#include <stdio.h>
#include <stdlib.h>

int map[13][22];

int main(){
    FILE* arq;
    char str[2];

    if((arq = fopen("Arquivos/fase1.txt", "r")) == NULL){
        exit(1);
    }

    for(int i = 0; i < 13; i++){
        for(int j = 0; j < 22; j++){
            fscanf(arq, "%s ", str);
            map[i][j] = atoi(str);
        }
    }

    for(int i = 0; i < 13; i++){
        for(int j = 0; j < 22; j++){
            printf("%d ", map[i][j]);
        }
        printf("\n");
    }

    fclose(arq);
}