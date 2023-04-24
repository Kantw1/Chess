#include <stdio.h>
#include <stdlib.h>
#include "chessboard.h"
#include "tableau.h"

#define size 12

int main(){
  
/*[lignes][colonnes]*/
char chessboard[size][size];

build(chessboard);

/*affichetab(chessboard);*/

/*
chessboard[5][9] = 'P';
chessboard[10][3] = 'P';
chessboard[7][2] = 'P';
*/

printchess(chessboard);

    return 0;
}