void sort_records(int gamePoint){
    FILE* fl;
    char point[20];
    int points[5];
    int index = -1;

    if((fl = fopen("Arquivos/records.txt", "r")) == NULL){
        perror("Erro: fopen");
        exit(1);
    }

    while((fscanf(fl, "%s\n", point)) != EOF){
        points[++index] = atoi(point);
    }

    fclose(fl);

    if(gamePoint > points[4]){
        points[4] = gamePoint;

        for(int i = 0; i < 5; i++){
            for(int j = 0; j < 5-1; j++){
                if(points[j] < points[j+1]){
                    int swap = points[j];
                    points[j] = points[j+1];
                    points[j+1] = swap;
                }
            }
        }
    }

    if((fl = fopen("Arquivos/records.txt", "w")) == NULL){
        perror("Erro: fopen");
        exit(1);
    }

    for(int i = 0; i < 5; i++){
        sprintf(point, "%d", points[i]);
        fprintf(fl, "%s\n", point);
    }

    fclose(fl);
}