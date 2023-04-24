#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include "tableau.h"

#define size 12



void build(char chessboard[size][size]){
    
    
    for(int i = 0; i<size; i++){
        for(int j = 0; j<size; j++){
            chessboard[j][i] = ' ';
        }
    }
    
    for(int i=0; i<size; i++){
        chessboard[i][11] = 'A' + i;
    }
    for(int i=0; i<size-1; i++){
        chessboard[0][i] = 'k' -i;
    }

}

void affichetab(char chessboard[size][size]){

    for(int i = 0; i< size; i++){
        for(int j = 0; j<size; j++){
            printf("  %c  ", chessboard[j][i]);
        }
        printf("\n\n");



    }
}

void choosepiece(char chessboard[size][size]){

    

    chessboard[5][9] = 'P';
    chessboard[10][3] = 'P';
    chessboard[7][2] = 'P';

}

/*
void affichage(){

    char chessboard[size][size];
    build(chessboard);
    affichetab(chessboard);
}

*/