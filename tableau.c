#include <stdio.h>
#include <stdlib.h>
#include "tableau.h"

#define size 12

void build(char chessboard[size*2][size]){
    
    
    for(int i = 0; i<size; i++){
        for(int j = 0; j<size*2; j++){
            chessboard[j][i] = 'A';
        }
    }
    
    for(int i=1; i<size*2; i++){
        chessboard[i][8] = 'A' + i -1;
    }
    for(int i=0; i<size-1; i++){
        chessboard[0][i] = '8' -i;
    }

}

void affichetab(char chessboard[size][size]){

    for(int i = 0; i< size; i++){
        for(int j = 0; j<size; j++){
            printf(" %c ", chessboard[j][i]);
        }
        printf("\n\n");



    }
}

/*
void affichage(){

    char chessboard[size][size];
    build(chessboard);
    affichetab(chessboard);
}

*/