#include <stdio.h>
#include <stdlib.h>
#include "chessboard.h"
#include "tableau.h"

#define size 12

int main(){
  
/*[lignes][colonnes]*/
char chessboard[size*2][size];

build(chessboard);
affichetab(chessboard);

    return 0;
}