#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include "chessboard.h"
#include "tableau.h"

#define size 12

int main(){
  
/*[lignes][colonnes]*/
char chessboard[size][size];

build(chessboard);

/*affichetab(chessboard);*/


choosepiece(chessboard);
printchess(chessboard);


    return 0;
}