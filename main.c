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
#include "Save.h"
#include "echec.h"

#define size 12
#define ANSI_COLOR_BLUE "\033[0;34m"
#define ANSI_COLOR_RED "\033[0;31m"
#define ANSI_COLOR_GREEN "\033[0;32m"
#define ANSI_COLOR_RESET "\033[0m"


int main(){

/*
#ifdef _WIN32 // Pour les systèmes Windows
    system("mode con cols=120 lines=30");
#elif __linux__ // Pour les systèmes Linux
    system("printf '\\e[8;30;120t'");
#elif __APPLE__ // Pour les systèmes macOS
    system("printf '\\e[8;30;120t'");
#else
    // Système d'exploitation non pris en charge
    printf("Impossible d'afficher la console en plein écran sur ce système d'exploitation.\n");
#endif
*/


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

int j1 = 0;
int fin = 0;
char sauv = 'n'; 
int pts1 = 40;
int pts2 = 40;

int * points_j1 = &pts1;
int * points_j2 = &pts2;


FILE* f = fopen("save.txt","r");


char charge = ' ';
charge = fgetc(f);
fclose(f);

char info =' ';
if(charge == 'k'){
    printf("Voulez vous charger la sauvegarde precedente? o? n?\n");
    scanf("\n%c",&info);
}
    if(info!='o'){

build(chessboard);

printchess(chessboard);

        printf(ANSI_COLOR_BLUE);
        printf("PERIODE D'ACHAT DES PIECES\n");
        printf(ANSI_COLOR_RESET);

while(*points_j1 >2 || *points_j2 > 2){

    if( j1 == 0){

        if ( *points_j1 > 2){

        printf(ANSI_COLOR_RED);
        printf("AU TOUR DU JOUEUR 1\n\n");
        printf(ANSI_COLOR_RESET);

        solde(chessboard, points_j1, 1);
        echec_de_depart(chessboard, points_j1,1);
        printchess(chessboard);
        }
        j1 ++;
    }
    else {

        if(*points_j2 >2){

            printf(ANSI_COLOR_GREEN);
            printf("AU TOUR DU JOUEUR 2\n\n");
            printf(ANSI_COLOR_RESET);

            solde(chessboard, points_j2, 2);
            echec_de_depart(chessboard, points_j2,2);
            printchess(chessboard);
        }

            j1--;
    }
}

    }
    else{

    f = fopen("save.txt","r");

    for(int i = 0; i<size; i++){
        for(int j = 0; j<size; j++){

        *(chessboard+i*size+j) = fgetc(f);

        }
    }
    char joueur = fgetc(f);
    if (joueur == '0'){
        j1 = 0;
    }
    else{
        j1 = 1;
    }

    }









        system("cls || clear");
        printf(ANSI_COLOR_BLUE);
        printf("VOUS ETES ENFIN PRET A JOUER\n\n");
        printf(ANSI_COLOR_RESET);
        printf("appuyer sur une touche pour continuer...");
        getch();
        system("cls || clear");
        

while(fin != 1 ){


    if( j1 == 0){

        printchess(chessboard);

        printf(ANSI_COLOR_RED);
        printf("AU TOUR DU JOUEUR 1\n\n");
        printf(ANSI_COLOR_RESET);


        selection_piece(chessboard, j1);

        printchess(chessboard);        

        j1 ++;
    }
    else {

        printchess(chessboard);

        printf(ANSI_COLOR_GREEN);
        printf("AU TOUR DU JOUEUR 2\n\n");
        printf(ANSI_COLOR_RESET);

        selection_piece(chessboard, j1);

        printchess(chessboard);

         j1--;

    }

fin = fin_de_partie(chessboard);



if (fin != 1){
    printf("Voulez vous sauvegarder la partie? o? n?\n");
    scanf("\n%c",&sauv);

    if (sauv == 'o'){
        printf("sauvegarde effectuee\n");
        sauvegarde(chessboard,j1);
        fin = 1;
    }
}
else{
    fclose(f);
    remove("save.txt");
}

}



getch();


    return 0;
}