#include <stdio.h>
#include <stdlib.h>
#include "chessboard.h"
#include <ctype.h>

#define size 12
#define ANSI_COLOR_BLUE "\033[0;34m"
#define ANSI_COLOR_RED "\033[0;31m"
#define ANSI_COLOR_GREEN "\033[0;32m"
#define ANSI_COLOR_RESET "\033[0m"

/*    SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN);
    printf("%c", chess[c][a-1]);
    SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);*/

void maj1(char a){


    if( a == toupper(a)){
        printf(ANSI_COLOR_GREEN);
        printf("%c", a);
        printf(ANSI_COLOR_RESET);
    }
    else {

        printf(ANSI_COLOR_RED);
        printf("%c", a);
        printf(ANSI_COLOR_RESET);

    }
}



void letter_to_num(char lettre){

    for(int i=0; i < 2; i++){
        
        if ( lettre == 'k'-i){

            printf("     %d   ",11-i);


        }

    }

    for(int i=2; i < size-1; i++){

        if ( lettre == 'k'-i){

            printf("      %d   ",11-i);


        }

    }
}

void printchess(char * chessboard){

     system("cls || clear");

    int a = 0;
    int b = 0;
    int c = 0;
    
    for( int i = 0; i<= (size-1) *4 +1; i++){
        for(int j = 0; j<= (size-1) *10+1; j++){
            if(j<1){
                if((i-2)%4 == 0 && i>0){
                letter_to_num(*(chessboard+0+12*a));  
                a++;
                }
                else {
                    printf("          ");
                }
            }
            else if(i%4==0){
                printf("*");
            }
            else {
                if (i == (size-1) *4 +1){

                    if((j-6)%10==0){
                        
                        printf("%c",*(chessboard+b+12*(size-1)));
                        
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
                    maj1(*(chessboard+c+12*(a-1)));
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
    
