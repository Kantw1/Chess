#include <stdio.h>
#include "Solde.h"
//fonctions qui permettronts de vérifier si le roi est en echec

void echec_de_depart(char* chessboard,int*point_j1,int joueur){
    if (*(chessboard+3*12+6)=='T' || *(chessboard+3*12+6)=='Q'){
        if (*(chessboard+8*12+6)==' ' && *(chessboard+7*12+6)==' '){
            printf("echec de depart, reessayez de placer une piece\n");
            if (*(chessboard+3*12+6)=='T'){
                *point_j1+=5;
            }
            else if (*(chessboard+3*12+6)=='Q'){
                *point_j1+=10;
            }
            *(chessboard+3*12+6)=' ';
            solde(chessboard,point_j1,joueur);
        }         
    }
    else if (*(chessboard+7*12+6)=='t' || *(chessboard+7*12+6)=='q'){
        if (*(chessboard+2*12+6)==' ' && *(chessboard+3*12+6)==' '){
            printf("echec de depart, reessayez de placer une piece\n");
            
            if (*(chessboard+7*12+6)=='t'){
                *point_j1+=5;
            }
            else if (*(chessboard+7*12+6)=='q'){
                *point_j1+=10;
            }
            *(chessboard+7*12+6)=' ';
            solde(chessboard,point_j1,joueur);
        }         
    }
    else if (*(chessboard+2*12+6)=='T' || *(chessboard+2*12+6)=='Q'){
        if (*(chessboard+3*12+6)==' '){
           if (*(chessboard+8*12+6)==' ' && *(chessboard+7*12+6)==' '){
                printf("echec de depart, reessayez de placer une piece\n");
                if (*(chessboard+2*12+6)=='T'){
                    *point_j1+=5;
                }
                else if (*(chessboard+2*12+6)=='Q'){
                    *point_j1+=10;
                }
                *(chessboard+2*12+6)=' ';
                solde(chessboard,point_j1,joueur);
            } 
        }
    }
    else if (*(chessboard+8*12+6)=='t' || *(chessboard+8*12+6)=='q'){
        if (*(chessboard+7*12+6)==' '){
           if (*(chessboard+2*12+6)==' ' && *(chessboard+3*12+6)==' '){
                printf("echec de depart, reessayez de placer une piece\n");
                if (*(chessboard+8*12+6)=='t'){
                    *point_j1+=5;
                }
                else if (*(chessboard+8*12+6)=='q'){
                    *point_j1+=10;
                }
                *(chessboard+8*12+6)=' ';
                solde(chessboard,point_j1,joueur);
            }
        }
    }
}
