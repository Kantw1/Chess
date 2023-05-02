#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include "chessboard.h"
#include "tableau.h"
#include <windows.h>
#include <ctype.h>
#include "Moves.h"
#include "Solde.h"

#define size 12


/* creer une fonction à tour de role*/

int main(){
  
/*[lignes][colonnes]*/
char chessboard[size][size];


build(chessboard);

/*affichetab(chessboard);*/
printchess(chessboard);

int j1 = 0;
int num = 0; /*à enlever+*/

int pts1 = 40;
int pts2 = 40;

int * points_j1 = &pts1;
int * points_j2 = &pts2;

/*printf("%d\n", points_j1);*/

printf("PERIODE D'ACHAT DES PIECES\n");

while(*points_j1 > 0 && *points_j2 > 0){

    if( j1 == 0){

        if ( *points_j1 > 0){

        printf("Au tour du joueur 1\n\n");
        solde(chessboard, points_j1, 1);
        printchess(chessboard);
        }

        j1 ++;
    }
    else {

        if(*points_j2 >0){

            printf("Au tour du joueur 2\n\n");
            solde(chessboard, points_j2, 2);
            printchess(chessboard);

        }

            j1--;

    }
}


while(num != 5 /*en attendant la fonctione echec et mat*/){

    if( j1 == 0){

        printf("Au tour du joueur 1\n");

        j1 ++;
    }
    else {

            printf("Au tour du joueur 2\n");

            j1--;

    }
    num ++;

}

    /*HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN);
    printf("creme\n");
    SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
    */

getch();


    return 0;
}