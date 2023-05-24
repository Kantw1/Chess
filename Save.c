#include <stdlib.h>
#include <stdio.h>
#define size 12


void sauvegarde(char * chessboard, int j1){

    FILE* f = NULL;
    remove("save.txt");
    f = fopen( "save.txt", "w");
    char tab[size*size];

    for(int i = 0; i<size; i++){
        for(int j = 0; j<size; j++){

            fprintf(f,"%c",*(chessboard+i*size+j));

        }
    }
    fprintf(f,"%d",j1);
    fclose(f);


}

void charger(){


}