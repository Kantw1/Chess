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



/* creer une fonction à tour de role*/

int main(){

//permet de quitter le programme mais je ne sais pas encore comment le mettre en place
/*void quit_if_stop(char input[]) {
  if (strcmp(input, "stop") == 0) {
    printf("Le programme a été interrompu.\n");
    exit(0);
  }
}*/


  
HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

    HWND consoleWindow = GetConsoleWindow();
    ShowWindow(consoleWindow, SW_MAXIMIZE);

system("cls || clear");




    SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE);

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


SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);

getch();
system("cls || clear");


//regle du jeu

SetConsoleTextAttribute(hConsole, FOREGROUND_RED);

printf("\n\n\n\n\n\n					Ce jeux est une variante du jeux d'échec \n");
printf("			Il se présente sur un echiquier de 11 * 11 et les regles sont différentes:\n");
printf("			1. Vous allez tout d'abord devoir acheter les pieces avec lesquelles vous voulez jouer\n");
printf("			2. Pour Gagner la partie vous allez devoir tout simplement manger le roi\n\n\n");

SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN);

printf("                    Bonne chance a vous !!!");

SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);


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

        SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE);
        printf("PERIODE D'ACHAT DES PIECES\n");
        SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);

while(*points_j1 + *points_j2 > 0){

    if( j1 == 0){

        if ( *points_j1 > 0){

        SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
        printf("AU TOUR DU JOUEUR 1\n\n");
        SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);

        solde(chessboard, points_j1, 1);
        printchess(chessboard);
        }

        j1 ++;
    }
    else {

        if(*points_j2 >0){

            SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN);
            printf("AU TOUR DU JOUEUR 2\n\n");
            SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);

            solde(chessboard, points_j2, 2);
            printchess(chessboard);

        }

            j1--;

    }
}
        system("cls || clear");
        SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE);
        printf("VOUS ETES ENFIN PRET A JOUER\n\n");
        SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
        printf("appuyer sur une touche pour continuer...");
        getch();
        system("cls || clear");
        

char exit;

while(fin != 1 ){

    exit ='b';

    if( j1 == 0){

        printchess(chessboard);

        SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
        printf("AU TOUR DU JOUEUR 1\n\n");
        SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);


        selection_piece(chessboard);
        

        j1 ++;
    }
    else {

        printchess(chessboard);

        SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN);
        printf("AU TOUR DU JOUEUR 2\n\n");
        SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);

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