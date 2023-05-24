#include <stdio.h>
#include <stdlib.h>
#include "tableau.h"
#include "Moves.h"
#include <ctype.h>

#define size 12


/*
une fonction solde() qui permet d'acheter les pièces en fonction du nombre de points dispo (int pts ) ainsi que de présenter les pièces disponibles avec leurs points d'achat

une fonction buy() qui permet de lancer la fonction solde à tour de rôle et qui diminue le nombre de pts

utiliser une fonction eche à l'interieur


*/

void position(char *chessboard, char piece_selectionne, int joueur){

    char lettre1 = 'b';
    int nombre = 0;
    
    int ligne, colonne;
    printf("indiquez la colonne de la case ou vous voulez mettre la piece\n");
    scanf("\n%c",&lettre1);
    printf("\nindiquez la ligne de la case ou vous voulez mettre la piece\n");
    scanf("\n%d",&nombre);

    colonne = 11-nombre;
    ligne = emplacement(lettre1);

    if(joueur == 1){

        if((colonne == 10 &&( ligne == 2 || ligne == 3 || ligne == 4 || ligne == 5 || ligne == 6 || ligne == 7 || ligne == 8 
        || ligne == 9 || ligne == 10))|| (colonne == 9 &&( ligne == 3 || ligne == 4 || ligne == 5 || ligne == 6 || ligne == 7 
        || ligne == 8 || ligne == 9 )) || (colonne == 8 &&( ligne == 4 || ligne == 5 || ligne == 6 || ligne == 7 || ligne == 8)) 
        || (colonne == 7 &&( ligne == 5 || ligne == 6 || ligne == 7  ))){

            if ( *(chessboard + ligne + 12*(colonne)) == ' '){

                    *(chessboard + ligne + 12*(colonne)) = piece_selectionne;
            }
            else{
                printf("il y a des deja une piece ici, veuillez choisir un autre emplacement\n");
                position(chessboard, piece_selectionne, joueur);
            }

        }
        else{
                printf("cette case n'est pas valide, veuillez choisir un autre emplacement\n");
                position(chessboard, piece_selectionne, joueur);
        }

    }
    else{

        if((colonne == 0 &&( ligne == 2 || ligne == 3 || ligne == 4 || ligne == 5 || ligne == 6 || ligne == 7 || ligne == 8 
        || ligne == 9 || ligne == 10))|| (colonne == 1 &&( ligne == 3 || ligne == 4 || ligne == 5 || ligne == 6 || ligne == 7 
        || ligne == 8 || ligne == 9 )) || (colonne == 2 &&( ligne == 4 || ligne == 5 || ligne == 6 || ligne == 7 || ligne == 8)) 
        || (colonne == 3 &&( ligne == 5 || ligne == 6 || ligne == 7  ))){

            if ( *(chessboard + ligne + 12*(colonne)) == ' '){

                    *(chessboard + ligne + 12*(colonne)) = piece_selectionne;
            }
            else{
                position(chessboard, piece_selectionne, joueur);
                printf("il y a des deja une piece ici, veuillez choisir un autre emplacement\n");
            }

        }
        else{
                printf("cette case n'est pas valide, veuillez choisir un autre emplacement");
                position(chessboard, piece_selectionne, joueur);
        }

    }

    

}
    

char informations(int pts){

    char piece = 'a';
    printf("Vous de disposez de %d points et vous pouvez acheter : \n q -> dame = 10 pts \n c -> cavalier = 3 pts \n f-> fou = 3pts \n t -> tour = 5 pts \n o-> cavalier fou = 7pts \n h-> prince = 6pts \n ", pts);
    printf("Rentrez la lettre correspondante a la piece voulu ; et si vous ne voulez plus de piece rentrez la lettre 'a':\n");

    scanf("\n%c", &piece);

    printf("\n");

    return piece;

}

void solde(char *chessboard, int * pts, int joueur){

    int verif = 0;

    char piece_selectionne;


    piece_selectionne = informations(*pts);

    if ( joueur == 1){

        piece_selectionne = tolower(piece_selectionne);

        if ( piece_selectionne == 'q'){

            *pts = *pts - 10;
             position(chessboard, piece_selectionne, joueur);
        }
        else if ( piece_selectionne == 'c'){

            *pts = *pts - 3;
            position(chessboard, piece_selectionne, joueur);
        }
        else if ( piece_selectionne == 'f'){

            *pts = *pts - 3;
            position(chessboard, piece_selectionne, joueur);
        }
        else if ( piece_selectionne == 't'){
            
            *pts = *pts - 5;
            position(chessboard, piece_selectionne, joueur);
        }
        else if ( piece_selectionne == 'o'){
            
            *pts = *pts - 7;
            position(chessboard, piece_selectionne, joueur);
        }
        else if ( piece_selectionne == 'h'){

            *pts = *pts - 6;
            position(chessboard, piece_selectionne, joueur);
        }
        else if ( piece_selectionne == 'a'){

            *pts = 0;
        }
        else{

             solde(chessboard,pts,joueur);

        }

    }

    else {

        piece_selectionne = toupper(piece_selectionne);


        if ( piece_selectionne == 'Q'){

            *pts = *pts - 10;
            position(chessboard, piece_selectionne, joueur);
        }
        else if ( piece_selectionne == 'C'){

            *pts = *pts - 3;
            position(chessboard, piece_selectionne, joueur);
        }
        else if ( piece_selectionne == 'F'){

            *pts = *pts - 3;
            position(chessboard, piece_selectionne, joueur);
        }
        else if ( piece_selectionne == 'T'){
            
            *pts = *pts - 5;
            position(chessboard, piece_selectionne, joueur);
        }
        else if ( piece_selectionne == 'O'){
            
            *pts = *pts - 7;
            position(chessboard, piece_selectionne, joueur);
        }
        else if ( piece_selectionne == 'H'){

            *pts = *pts - 6;
            position(chessboard, piece_selectionne, joueur);
        }
        else if ( piece_selectionne == 'A'){

            *pts = 0;
        }
        else{

            printf("Choisissez une piece qui existe");
             solde(chessboard,pts,joueur);

        }

    }

    
}
