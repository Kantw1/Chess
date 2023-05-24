#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include "chessboard.h"
#include "tableau.h"
#include <windows.h>
#include <ctype.h>
#include "Moves.h"
#include "Solde.h"

#define size 12
#define ANSI_COLOR_BLUE "\033[0;34m"
#define ANSI_COLOR_RED "\033[0;31m"
#define ANSI_COLOR_GREEN "\033[0;32m"
#define ANSI_COLOR_RESET "\033[0m"


int main(){

  
HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

    HWND consoleWindow = GetConsoleWindow();
    ShowWindow(consoleWindow, SW_MAXIMIZE);

system("cls || clear");

printf(ANSI_COLOR_BLUE);


    printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
    printf("   ******************   ******************   ******************   ******************   ***            ***    ******************   ***            ***   ******************   ******************   ******************\n");
    printf("   ******************   ******************   ******************   ******************   ***            ***    ******************   ***            ***   ******************   ******************   ******************\n");
    printf("   ****                 ***             **   **              **                 ***     ***          ***     ****                 ***            ***   ***                  ***                  ***               \n");
    printf("   ****                 ***             **   **              **                ***       ***        ***      ****                 ***            ***   ***                  ***                  ***               \n");
    printf("   ****                 ***             **   **              **               ***         ***      ***       ****                 ***            ***   ***                  ***                  ***               \n");
    printf("   ****                 ***             **   **              **              ***           ***    ***        ****                 ***            ***   ***                  ***                  ***               \n");
    printf("   ****                 ***             **   **              **             ***             ***  ***         ****                 ***            ***   ***                  ***                  ***               \n");
    printf("   ****                 ******************   ******************            ***               ******          ****                 ***            ***   ***                  ***                  ***               \n");
    printf("   ****                 ******************   ******************           ***                 ****           ****                 ******************   ****************     ******************   ******************\n");
    printf("   ****                 ***  ***             **              **          ***                  ****           ****                 ******************   ****************     ******************   ******************\n");
    printf("   ****                 ***   ***            **                         ***                   ****           ****                 ***            ***   ***                                 ***                  ***\n");
    printf("   ****                 ***    ***           **              **        ***                    ****           ****                 ***            ***   ***                                 ***                  ***\n");
    printf("   ****                 ***     ***          **              **       ***                     ****           ****                 ***            ***   ***                                 ***                  ***\n");
    printf("   ****                 ***      ***         **              **      ***                      ****           ****                 ***            ***   ***                                 ***                  ***\n");
    printf("   ****                 ***       ***        **              **     ***                       ****           ****                 ***            ***   ***                                 ***                  ***\n");
    printf("   ****                 ***        ***       **              **    ***                        ****           ****                 ***            ***   ***                                 ***                  ***\n");
    printf("   ******************   ***         ***      **              **   ******************         ******          ******************   ***            ***   ******************   ******************   ******************\n");
    printf("   ******************   ***          ***     **              **   ******************         ******          ******************   ***            ***   ******************   ******************   ******************\n");


printf(ANSI_COLOR_RESET);

getch();
system("cls || clear");


//regle du jeu

printf(ANSI_COLOR_RED);

printf("\n\n\n\n\n\n					Ce jeux est une variante du jeux d'échec \n");
printf("			Il se présente sur un echiquier de 11 * 11 et les regles sont différentes:\n");
printf("			1. Vous allez tout d'abord devoir acheter les pieces avec lesquelles vous voulez jouer\n");
printf("			2. Pour Gagner la partie vous allez devoir tout simplement manger le roi\n\n\n");

printf(ANSI_COLOR_GREEN);

printf("                    Bonne chance a vous !!!");

printf(ANSI_COLOR_RESET);


getch();
system("cls || clear");



/*[lignes][colonnes]*/
char tab[size][size];
char * chessboard = &tab[0][0];


build(chessboard);

/*affichetab(chessboard);*/
printchess(chessboard);

int j1 = 0;
int fin = 0;
char sauvegarde = 'n'; 
int pts1 = 40;
int pts2 = 40;

int * points_j1 = &pts1;
int * points_j2 = &pts2;

/*printf("%d\n", points_j1);*/

        printf(ANSI_COLOR_BLUE);
        printf("PERIODE D'ACHAT DES PIECES\n");
        printf(ANSI_COLOR_RESET);

while(*points_j1 + *points_j2 > 0){

    if( j1 == 0){

        if ( *points_j1 > 0){

        printf(ANSI_COLOR_RED);
        printf("AU TOUR DU JOUEUR 1\n\n");
        printf(ANSI_COLOR_RESET);

        solde(chessboard, points_j1, 1);
        printchess(chessboard);
        }

        j1 ++;
    }
    else {

        if(*points_j2 >0){

            printf(ANSI_COLOR_GREEN);
            printf("AU TOUR DU JOUEUR 2\n\n");
            printf(ANSI_COLOR_RESET);

            solde(chessboard, points_j2, 2);
            printchess(chessboard);

        }

            j1--;

    }
}
        system("cls || clear");
        printf(ANSI_COLOR_BLUE);
        printf("VOUS ETES ENFIN PRET A JOUER\n\n");
        printf(ANSI_COLOR_RESET);
        printf("appuyer sur une touche pour continuer...");
        getch();
        system("cls || clear");
        

char exit;

while(fin != 1 ){

    exit ='b';

    if( j1 == 0){

        printchess(chessboard);

        printf(ANSI_COLOR_RED);
        printf("AU TOUR DU JOUEUR 1\n\n");
        printf(ANSI_COLOR_RESET);


        selection_piece(chessboard);
        

        j1 ++;
    }
    else {

        printchess(chessboard);

        printf(ANSI_COLOR_GREEN);
        printf("AU TOUR DU JOUEUR 2\n\n");
        printf(ANSI_COLOR_RESET);

        selection_piece(chessboard);

        printchess(chessboard);

         j1--;

    }

fin = fin_de_partie(chessboard);


printf("partir z\n");
scanf("\n%c",&exit);
if(exit == 'z'){
    fin = 1;
}

/*if (fin != 1){
    printf("Voulez vous sauvegarder la partie? o? n?\n");
    scanf("\n%c",sauvegarde);
    if (sauvegarde == 'o'){
        fin = 1;
    }
}*/

}



getch();


    return 0;
}