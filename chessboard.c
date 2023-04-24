#include <stdio.h>
#include <stdlib.h>
#include "chessboard.h"

#define size 12

/*void printchess(char chess[size][size]){
    
    for( int i = 0; i<= size *3; i++){
        for(int j = 0; j<= size *5; j++){
         if(i%2 == 0){
             printf("*");
         }
         else {
             if(j%2!= 0){
                 printf(" ");
             }
             else if((j-2)%4==0){
                 printf("A");
             }
             
             else {
                 printf("*");
             }
         }
        }
        printf("\n");
    }
    
}

*/