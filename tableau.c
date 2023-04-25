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

    chessboard[1][0] = 'P';
    chessboard[2][1] = 'P';
    chessboard[3][2] = 'P';
    chessboard[4][3] = 'P';

    chessboard[6][1] = 'K';

    chessboard[11][0] = 'P';
    chessboard[10][1] = 'P';
    chessboard[9][2] = 'P';
    chessboard[8][3] = 'P';

    chessboard[1][10] = 'p';
    chessboard[2][9] = 'p';
    chessboard[3][8] = 'p';
    chessboard[4][7] = 'p';

    chessboard[6][9] = 'k';

    chessboard[11][10] = 'p';
    chessboard[10][9] = 'p';
    chessboard[9][8] = 'p';
    chessboard[8][7] = 'p';



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





}

/*
void affichage(){

    char chessboard[size][size];
    build(chessboard);
    affichetab(chessboard);
}

*/