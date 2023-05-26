#include <stdio.h>
#include <stdlib.h>
#include "tableau.h"

#define size 12
void build(char *chessboard){
    
    
    for(int i = 0; i<size; i++){
        for(int j = 0; j<size; j++){
            *(chessboard +j+i*12) = ' ';
        }
    }
    
    for(int i=0; i<size; i++){
        *(chessboard +12*11+i) = 'A' + i;
    }
    for(int i=0; i<size-1; i++){
        *(chessboard + 12*i) = 'k' -i;
    }

    *(chessboard+1+12*0) = 'P';
    *(chessboard+2+12*1) = 'P';
    *(chessboard+3+2*12) = 'P';
    *(chessboard+4+3*12) = 'P';

    *(chessboard+6+12) = 'K';

    *(chessboard+11+12*0) = 'P';
    *(chessboard+10+12*1) = 'P';
    *(chessboard+9+12*2) = 'P';
    *(chessboard+8+12*3) = 'P';

    *(chessboard+1+12*10) = 'p';
    *(chessboard+2+12*9) = 'p';
    *(chessboard+3+12*8) = 'p';
    *(chessboard+4+12*7) = 'p';

    *(chessboard+6+12*9) = 'k';

    *(chessboard+11+12*10) = 'p';
    *(chessboard+10+12*9) = 'p';
    *(chessboard+9+12*8) = 'p';
    *(chessboard+8+12*7) = 'p';



}
