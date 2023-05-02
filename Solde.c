#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include "tableau.h"
#include "Moves.h"

#define size 12


/*
une fonction solde() qui permet d'acheter les pièces en fonction du nombre de points dispo (int pts ) ainsi que de présenter les pièces disponibles avec leurs points d'achat

une fonction buy() qui permet de lancer la fonction solde à tour de rôle et qui diminue le nombre de pts

utiliser une fonction eche à l'interieur
*/

void position(char chessboard[size][size], char piece_selectionne){

    char a,b;
    int ligne, colonne;
    printf("indiquez la ligne puis la colonne de la case ou vous voulez mettre la piece\n");
    scanf("%c",&a);
    ligne = emplacement(a);
    scanf("%c",&b);
    colonne = emplacement(b);

    chessboard[ligne][colonne] = piece_selectionne;

}
    

char informations(int pts){

    char piece = ' ';
    printf("Vous de disposez de %d points et vous pouvez acheter : \n q -> dame = 10 pts \n c -> cavalier = 3 pts \n f-> fou = 3pts \n t -> tour = 5 pts \n o-> cavalier fou = 7pts \n h-> prince = 6pts \n ", pts);
    printf("Rentrez la lettre correspondante a la piece voulu ; et si vous ne voulez plus de piece rentrez la lettre 'a':\n");

    scanf("%c\n", &piece);

    return piece;

}

void solde(char chessboard[size][size], int * pts, int joueur){

    int verif = 0;

    char piece_selectionne;


    piece_selectionne = informations(*pts);

    if ( joueur == 1){

        if ( piece_selectionne == 'q'){

            *pts = *pts - 10;
            position(chessboard, piece_selectionne);
        }
        else if ( piece_selectionne == 'c'){

            *pts = *pts - 3;
            position(chessboard, piece_selectionne);
        }
        else if ( piece_selectionne == 'f'){

            *pts = *pts - 3;
            position(chessboard, piece_selectionne);
        }
        else if ( piece_selectionne == 't'){
            
            *pts = *pts - 5;
            position(chessboard, piece_selectionne);
        }
        else if ( piece_selectionne == 'o'){
            
            *pts = *pts - 7;
            position(chessboard, piece_selectionne);
        }
        else if ( piece_selectionne == 'h'){

            *pts = *pts - 6;
            position(chessboard, piece_selectionne);
        }
        else if ( piece_selectionne == 'a'){

            *pts = 0;
        }
        else{

             solde(chessboard,pts,joueur);

        }

    }

    else {


        if ( piece_selectionne == 'q'){

            *pts = *pts - 10;
            position(chessboard, piece_selectionne);
        }
        else if ( piece_selectionne == 'c'){

            *pts = *pts - 3;
            position(chessboard, piece_selectionne);
        }
        else if ( piece_selectionne == 'f'){

            *pts = *pts - 3;
            position(chessboard, piece_selectionne);
        }
        else if ( piece_selectionne == 't'){
            
            *pts = *pts - 5;
            position(chessboard, piece_selectionne);
        }
        else if ( piece_selectionne == 'o'){
            
            *pts = *pts - 7;
            position(chessboard, piece_selectionne);
        }
        else if ( piece_selectionne == 'h'){

            *pts = *pts - 6;
            position(chessboard, piece_selectionne);
        }
        else if ( piece_selectionne == 'a'){

            *pts = 0;
        }
        else{

             solde(chessboard,pts,joueur);

        }

    }

    getch();


}
