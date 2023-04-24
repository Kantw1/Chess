#include <stdio.h>
#include <stdlib.h>
#include "chessboard.h"

#define size 12

void printchess(char chess[size][size]){

    int a = 0;
    int b = 0;
    int c = 0;
    
    for( int i = 0; i<= (size-1) *4 +1; i++){
        for(int j = 0; j<= (size-1) *10+1; j++){
            if(j<1){
                if((i-2)%4 == 0 && i>0){
                printf("  %c  ", chess[0][a]);
                a++;
                }
                else {
                    printf("     ");
                }
            }
            else if(i%4==0){
                printf("*");
            }
            else {
                if (i == (size-1) *4 +1){

                    if((j-6)%10==0){
                        printf("%c", chess[b][size-1]);
                        b++;
                    }
                    else {
                    printf(" ");
                    }
                }
                else if((j+4)%10== 0){

                    if((i-1)%2==0){
                        printf(" ");
                    }
                    else {
                    printf("%c", chess[c][a-1]);
                    c++;
                    }
                }
                else if((j-1)%10 ==0 || j == 1) {
                    printf("*");
                }
                else {
                printf(" ");
                }
            }
        
         }
            printf("\n");
            c = 1;

        }
        
    }
    
