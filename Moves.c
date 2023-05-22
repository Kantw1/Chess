#include <stdio.h>
#include <string.h>
#define size 12


void selection_piece(char* chessboard);
void deplacement_ligne(char* chessboard,char i1,char i2,char j1,char j2,char piece);
void deplacement_diagonale(char* chessboard,char i1,char i2,char j1,char j2,char piece);
void deplacement_en_L(char* chessboard,char i1,char i2,char j1,char j2,char piece);
int verif_deplacement_simple(char* chessboard,char i1,char i2,char j1,char j2);
int verif_deplacement_diagonale(char* chessboard,char i1,char i2,char j1,char j2);
int verif_deplacement_droit(char* chessboard,char i1,char i2,char j1,char j2);
void promotion_pion(char* chessboard,char i2,char j2);




int emplacement(char lettre){

    int num = 0;

    if(lettre == 'A' || lettre == 'a'){
        num = 1;
    }
    else if (lettre == 'B' || lettre == 'b'){
        num = 2;
    }
    else if (lettre == 'C' || lettre == 'c'){
        num = 3;
    }
    else if (lettre == 'D' || lettre == 'd'){
        num = 4;
    }
    else if (lettre == 'E' || lettre == 'e'){
        num = 5;
    }
    else if (lettre == 'F' || lettre == 'f'){
        num = 6;
    }
    else if (lettre == 'G' || lettre == 'g'){
        num = 7;
    }
    else if (lettre == 'H' || lettre == 'h'){
        num = 8;
    }
    else if (lettre == 'I' || lettre == 'i'){
        num = 9;
    }
    else if (lettre == 'J' || lettre == 'j'){
        num = 10;
    }
    else if (lettre == 'K' || lettre == 'k'){
        num = 11;
    }

    return num;

}

char emplacement2(int num){

    char lettre;

    if(num == 1){
        lettre = 'a';
    }
    else if (num == 2){
        lettre = 'b';
    }
    else if (num == 3){
        lettre = 'c';
    }
    else if (num == 4){
        lettre = 'd';
    }
    else if (num == 5){
        lettre = 'e';
    }
    else if (num == 6){
        lettre = 'f';
    }
    else if (num == 7){
        lettre = 'g';
    }
    else if (num == 8){
        lettre = 'h';
    }
    else if (num == 9){
        lettre = 'i';
    }
    else if (num == 10){
        lettre = 'j';
    }
    else if (num == 11){
        lettre = 'k';
    }

    return lettre;

}

void pion(char* chessboard,char i1,char i2,char j1,char j2){

    printf("pion pris en compte\n");
    if (i1+1==i2 && j1==j2 && *(chessboard+i1+j1*12)=='p'){
        int v=verif_deplacement_simple(chessboard,i1,i2,j1,j2);
        printf("pion verif\n");
        if (v==0){
            *(chessboard+i2+j2*12)='p';
            *(chessboard+i1+j1*12)=' ';
        }
    }
    else if (i1+1==i2 && j1==j2 && *(chessboard+i1+j1*12)=='P'){
        int v=verif_deplacement_simple(chessboard,i1,i2,j1,j2);
        if (v==0){
            *(chessboard+i2+j2*12)='p';
            *(chessboard+i1+j1*12)=' ';
        }
    }
    else {
        printf("coup illegal,reessayez de deplacer une piece\n");
        selection_piece(chessboard);
    }
    promotion_pion(chessboard,i2,j2);
}

void fou(char* chessboard,char i1,char i2,char j1,char j2){
    deplacement_diagonale(chessboard,i1,i2,j1,j2,*(chessboard+i1+j1*12));
    if (*(chessboard+i1+j1*12)=='f','F'){
        printf("coup illegal,reessayez de deplacer une piece\n");
        selection_piece(chessboard);
    }
}

void tour(char* chessboard,char i1,char i2,char j1,char j2){
    deplacement_ligne(chessboard,i1,i2,j1,j2,*(chessboard+i1+j1*12));
    if (*(chessboard+i1+j1*12)=='t','T'){
        printf("coup illegal,reessayez de deplacer une piece\n");
        selection_piece(chessboard);
    }
}

void cavalier(char* chessboard,char i1,char i2,char j1,char j2){
    deplacement_en_L(chessboard,i1,i2,j1,j2,*(chessboard+i1+j1*12));
    if (*(chessboard+i1+j1*12)=='c','C'){
        printf("coup illegal,reessayez de deplacer une piece\n");
        selection_piece(chessboard);
    }
}

void reine(char* chessboard,char i1,char i2,char j1,char j2){
    deplacement_diagonale(chessboard,i1,i2,j1,j2,*(chessboard+i1+j1*12));
    deplacement_ligne(chessboard,i1,i2,j1,j2,*(chessboard+i1+j1*12));
    if (*(chessboard+i1+j1*12)=='q','Q'){
        printf("coup illegal,reessayez de deplacer une piece\n");
        selection_piece(chessboard);
    }
}

void roi(char* chessboard,char i1,char i2,char j1,char j2){
    printf("pion pris en compte\n");
    if (i1+1==i2 || j1+1==j2){
        if (*(chessboard+i1+j1*12)=='k'){
            int v=verif_deplacement_simple(chessboard,i1,i2,j1,j2);
            if (v==0){
                *(chessboard+i2+j2*12)='k';
                *(chessboard+i1+j1*12)=' ';
            }
        }
        else if (*(chessboard+i1+j1*12)=='K'){
            int v=verif_deplacement_simple(chessboard,i1,i2,j1,j2);
            if (v==0){
                *(chessboard+i2+j2*12)='K';
                *(chessboard+i1+j1*12)=' ';
            }
        }
    }
    else {
        printf("coup illegal,reessayez de deplacer une piece\n");
        selection_piece(chessboard);
    }
}

void cavalier_fou(char* chessboard,char i1,char i2,char j1,char j2){
    deplacement_diagonale(chessboard,i1,i2,j1,j2,*(chessboard+i1+j1*12));
    deplacement_en_L(chessboard,i1,i2,j1,j2,*(chessboard+i1+j1*12));
    if (*(chessboard+i1+j1*12)=='l','L'){
        printf("coup illegal,reessayez de deplacer une piece\n");
        selection_piece(chessboard);
    }
}

void deplacement_ligne(char* chessboard,char i1,char i2,char j1,char j2,char piece){
    if (i1==i2 || j1==j2){
        if (i1!=i2 || j1!=j2){
            if(piece=='t','q'){
                int v=verif_deplacement_droit(chessboard,i1,i2,j1,j2);
                if (v==0){
                    *(chessboard+i2+j2*12)=piece;
                    piece=' ';
                }
            }
            else if(piece=='T','Q'){
                int v=verif_deplacement_droit(chessboard,i1,i2,j1,j2);
                if (v==0){
                    *(chessboard+i2+j2*12)=piece;
                    piece=' ';
                }
            }
        }
    }
}


void deplacement_diagonale(char* chessboard,char i1,char i2,char j1,char j2,char piece){
    char i,j;
    if(i1<i2 && j1<j2){
       i=-(i2-i1);
       j=-(j2-j1);
       if (i==j){
           if (piece=='f','q','o'){
               int v=verif_deplacement_diagonale(chessboard,i1,i2,j1,j2);
               if (v==0){
                   *(chessboard+i2+j2*12)=piece;
                    piece=' ';
               }
           }
           else if (*(chessboard+i1+j1*12)=='F','Q','O'){
               int v=verif_deplacement_diagonale(chessboard,i1,i2,j1,j2);
               if (v==0){
                   *(chessboard+i2+j2*12)=piece;
                    piece=' ';
               }
           }
       }
    }
    if(i1<i2 && j1>j2){
       i=-(i2-i1);
       j=j2-j1;
       if (i==j){
           if (piece=='f','q','o'){
               int v=verif_deplacement_diagonale(chessboard,i1,i2,j1,j2);
               if (v==0){
                   *(chessboard+i2+j2*12)=piece;
                    piece=' ';
               }
           }
           else if (piece=='F','Q','O'){
               int v=verif_deplacement_diagonale(chessboard,i1,i2,j1,j2);
               if (v==0){
                   *(chessboard+i2+j2*12)=piece;
                    piece=' ';
               }
           }
       }
    }
    if(i1>i2 && j1>j2){
       i=i2-i1;
       j=j2-j1;
       if (i==j){
           if (piece=='f','q','o'){
               int v=verif_deplacement_diagonale(chessboard,i1,i2,j1,j2);
               if (v==0){
                   *(chessboard+i2+j2*12)=piece;
                    piece=' ';
               }
           }
           else if (piece=='F','Q','O'){
               int v=verif_deplacement_diagonale(chessboard,i1,i2,j1,j2);
               if (v==0){
                   *(chessboard+i2+j2*12)=piece;
                    piece=' ';
               }
           }
       }
    }
    if(i1>i2 && j1<j2){
       i=i2-i1;
       j=-(j2-j1);
       if (i==j){
           if (piece=='f','q','o'){
               int v=verif_deplacement_diagonale(chessboard,i1,i2,j1,j2);
               if (v==0){
                   *(chessboard+i2+j2*12)=piece;
                    piece=' ';
               }
           }
           else if (piece=='F','Q','O'){
               int v=verif_deplacement_diagonale(chessboard,i1,i2,j1,j2);
               if (v==0){
                   *(chessboard+i2+j2*12)=piece;
                    piece=' ';
               }
           }
       }
    }
}

void deplacement_en_L(char* chessboard,char i1,char i2,char j1,char j2,char piece){
    if (i1+2==i2 || i1-2==i2){
        if (j1+1==j2 || j1-1==j2){
            if (piece=='c','o'){
                int v=verif_deplacement_simple(chessboard,i1,i2,j1,j2);
                if (v==0){
                    *(chessboard+i2+j2*12)=piece;
                    piece=' ';
                }
            }
            else if (piece=='C','O'){
                int v=verif_deplacement_simple(chessboard,i1,i2,j1,j2);
                if (v==0){
                    *(chessboard+i2+j2*12)=piece;
                    piece=' ';
                }
            }
        }
    }
}

int verif_deplacement_simple(char* chessboard,char i1,char i2,char j1,char j2){
    char piece[9];
    char piece2[9];
    strcpy(piece,"pktcfqol");
    strcpy(piece2,"PKTCFQOL");
    if (*(chessboard+i1+j1*12)=='p','c','k'){
        for (int i=0;i<9;i++){
            if (*(chessboard+i2+j2*12)==piece[i]){
                printf("coup illegal,reessayez de deplacer une piece\n");
                selection_piece(chessboard);
                return 1;
            }
        }
            
    }
    else if (*(chessboard+i1+j1*12)=='P','C','K'){
        for (int i=0;i<9;i++){
            if (*(chessboard+i2+j2*12)==piece2[i]){
                printf("coup illegal,reessayez de deplacer une piece\n");
                selection_piece(chessboard);
                return 1;
            }
        }
            
    }
    if (i2>11 || j2>11){
        printf("coup illegal,reessayez de deplacer une piece\n");
        selection_piece(chessboard);
        return 1;
    }
    return 0;
    
}


int verif_deplacement_diagonale(char* chessboard,char i1,char i2,char j1,char j2){
    char piece[9];
    char piece2[9];
    strcpy(piece,"pktcfqol");
    strcpy(piece2,"PKTCFQOL");
    if (i1<i2 && j1<j2){
        if (*(chessboard+i1+j1*12)=='f','q','o'){
            int i,j;
            for (i=i1+1,j=j1+1;i<i2,j<j2;i++,j++){
                for (int i0=0;i0<9;i++){
                    if (*(chessboard+i+j*12)==piece[i0],piece2[i0]){
                        printf("coup illegal,reessayez de deplacer une piece\n");
                        selection_piece(chessboard);
                        return 1;
                    }
                }
            }
            for (int i=0;i<9;i++){
                if (*(chessboard+i2+j2*12)==piece[i]){
                   printf("coup illegal,reessayez de deplacer une piece\n");
                   selection_piece(chessboard);
                   return 1;
                }
            }
        }
        else if (*(chessboard+i1+j1+12)=='F','Q','O'){
            int i,j;
            for (i=i1+1,j=j1+1;i<i2,j<j2;i++,j++){
                for (int i0=0;i0<9;i++){
                    if (*(chessboard+i+j*12)==piece[i0],piece2[i0]){
                        printf("coup illegal,reessayez de deplacer une piece\n");
                        selection_piece(chessboard);
                        return 1;
                    }
                }
            }
            for (int i=0;i<9;i++){
                if (*(chessboard+i2+j2*12)==piece[i]){
                   printf("coup illegal,reessayez de deplacer une piece\n");
                   selection_piece(chessboard);
                   return 1;
                }
            }
        }
    }    
    else if (i1<i2 && j1>j2){
        if (*(chessboard+i1+j1*12)=='f','q','o'){
            int i,j;
            for (i=i1+1,j=j1-1;i<i2,j>j2;i++,j--){
                for (int i0=0;i0<9;i++){
                    if (*(chessboard+i+j*12)==piece[i0],piece2[i0]){
                        printf("coup illegal,reessayez de deplacer une piece\n");
                        selection_piece(chessboard);
                        return 1;
                    }
                }
            }
            for (int i=0;i<9;i++){
                if (*(chessboard+i2+j2*12)==piece[i]){
                   printf("coup illegal,reessayez de deplacer une piece\n");
                   selection_piece(chessboard);
                   return 1;
                }
            }
        }
        else if (*(chessboard+i1+j1+12)=='F','Q','O'){
            int i,j;
            for (i=i1+1,j=j1-1;i<i2,j>j2;i++,j--){
                for (int i0=0;i0<9;i++){
                    if (*(chessboard+i+j*12)==piece[i0],piece2[i0]){
                        printf("coup illegal,reessayez de deplacer une piece\n");
                        selection_piece(chessboard);
                        return 1;
                    }
                }
            }
            for (int i=0;i<9;i++){
                if (*(chessboard+i2+j2*12)==piece[i]){
                   printf("coup illegal,reessayez de deplacer une piece\n");
                   selection_piece(chessboard);
                   return 1;
                }
            }
        } 
    }   
    
    else if (i1>i2 && j1>j2){
        if (*(chessboard+i1+j1*12)=='f','q','o'){
            int i,j;
            for (i=i1-1,j=j1-1;i>i2,j>j2;i--,j--){
                for (int i0=0;i0<9;i++){
                    if (*(chessboard+i+j*12)==piece[i0],piece2[i0]){
                        printf("coup illegal,reessayez de deplacer une piece\n");
                        selection_piece(chessboard);
                        return 1;
                    }
                }
            }
            for (int i=0;i<9;i++){
                if (*(chessboard+i2+j2*12)==piece[i]){
                printf("coup illegal,reessayez de deplacer une piece\n");
                selection_piece(chessboard);
                return 1;
                }
            }
        }
        else if (*(chessboard+i1+j1+12)=='F','Q','O'){
            int i,j;
            for (i=i1-1,j=j1-1;i>i2,j>j2;i--,j--){
                for (int i0=0;i0<9;i++){
                    if (*(chessboard+i+j*12)==piece[i0],piece2[i0]){
                        printf("coup illegal,reessayez de deplacer une piece\n");
                        selection_piece(chessboard);
                        return 1;
                    }
                }
            }
            for (int i=0;i<9;i++){
                if (*(chessboard+i2+j2*12)==piece[i]){
                    printf("coup illegal,reessayez de deplacer une piece\n");
                    selection_piece(chessboard);
                    return 1;
                }
            }
        }
    }
    
    else if (i1>i2 && j1<j2){
        if (*(chessboard+i1+j1*12)=='f','q','o'){
            int i,j;
            for (i=i1-1,j=j1+1;i>i2,j<j2;i--,j++){
                for (int i0=0;i0<9;i++){
                    if (*(chessboard+i+j*12)==piece[i0],piece2[i0]){
                        printf("coup illegal,reessayez de deplacer une piece\n");
                        selection_piece(chessboard);
                        return 1;
                    }
                }
            }
            for (int i=0;i<9;i++){
                if (*(chessboard+i2+j2*12)==piece[i]){
                printf("coup illegal,reessayez de deplacer une piece\n");
                selection_piece(chessboard);
                return 1;
                }
            }
        }
        else if (*(chessboard+i1+j1+12)=='F','Q','O'){
            int i,j;
            for (i=i1-1,j=j1+1;i>i2,j<j2;i--,j++){
                for (int i0=0;i0<9;i++){
                    if (*(chessboard+i+j*12)==piece[i0],piece2[i0]){
                        printf("coup illegal,reessayez de deplacer une piece\n");
                        selection_piece(chessboard);
                        return 1;
                    }
                }
            }
            for (int i=0;i<9;i++){
                if (*(chessboard+i2+j2*12)==piece[i]){
                    printf("coup illegal,reessayez de deplacer une piece\n");
                    selection_piece(chessboard);
                    return 1;
                }
            }
        }
    }
    if (i2>11 || j2>11){
        printf("coup illegal,reessayez de deplacer une piece\n");
        selection_piece(chessboard);
        return 1;
    }
    return 0;
}

int verif_deplacement_droit(char* chessboard,char i1,char i2,char j1,char j2){
    char piece[9];
    char piece2[9];
    strcpy(piece,"pktcfqol");
    strcpy(piece2,"PKTCFQOL");
    if (i2>i1){
        if(*(chessboard+i1+j1*12)=='t','q','l'){
            for (int i=i1+1;i<i2;i++){
                for (int i0=0;i0<9;i0++){
                    if (*(chessboard+i+j1*12)==piece[i0],piece2[i0]){
                        printf("coup illegal,reessayez de deplacer une piece\n");
                        selection_piece(chessboard);
                        return 1;
                    }
                }
            }
            for (int i=0;i<9;i++){
                if (*(chessboard+i2+j2*12)==piece[i]){
                   printf("coup illegal,reessayez de deplacer une piece\n");
                   selection_piece(chessboard);
                   return 1;
                }
            }
        }
        else if(*(chessboard+i1+j1*12)=='T','Q','L'){
            for (int i=i1+1;i<i2;i++){
                for (int i0=0;i0<9;i0++){
                    if (*(chessboard+i+j1*12)==piece[i0],piece2[i0]){
                        printf("coup illegal,reessayez de deplacer une piece\n");
                        selection_piece(chessboard);
                        return 1;
                    }
                }
            }
            for (int i=0;i<9;i++){
                if (*(chessboard+i2+j2*12)==piece2[i]){
                    printf("coup illegal,reessayez de deplacer une piece\n");
                    selection_piece(chessboard);
                    return 1;
                }
            }
        }
    }
    else if (j2>j1){
        if(*(chessboard+i1+j1*12)=='t','q','l'){
            for (int j=j1+1;j<j2;j++){
                for (int i0=0;i0<9;i0++){
                    if (*(chessboard+i1+j*12)==piece[i0],piece2[i0]){
                        printf("coup illegal,reessayez de deplacer une piece\n");
                        selection_piece(chessboard);
                        return 1;
                    }
                }
            }
            for (int i=0;i<9;i++){
                if (*(chessboard+i2+j2*12)==piece[i]){
                    printf("coup illegal,reessayez de deplacer une piece\n");
                    selection_piece(chessboard);
                    return 1;
                }
            }
        }
        else if(*(chessboard+i1+j1*12)=='T','Q','L'){
            for (int i=i1+1;i<i2;i++){
                for (int i0=0;i0<9;i0++){
                    if (*(chessboard+i1+(j1+i)*12)==piece[i0],piece2[i0]){
                        printf("coup illegal,reessayez de deplacer une piece\n");
                        selection_piece(chessboard);
                        return 1;
                    }
                }
            }
            for (int i=0;i<9;i++){
                if (*(chessboard+i2+j2*12)==piece2[i]){
                    printf("coup illegal,reessayez de deplacer une piece\n");
                    selection_piece(chessboard);
                    return 1;
                }
            }
        }
    }
    if (i2>11 || j2>11){
        printf("coup illegal,reessayez de deplacer une piece\n");
        selection_piece(chessboard);
        return 1;
    }
    return 0;
    
}
void promotion_pion(char* chessboard,char i2,char j2){
    if (*(chessboard+i2+j2*12)=='p'){
        if (i2==11){
            char np;
            printf("promotion pion : voulez vous que votre pion devient un fou,une tour,un cavalier ou une reine ?\n");
            scanf("%c",np);
            *(chessboard+i2+j2*12)==np;
        }
    }
    
    if (*(chessboard+i2+j2*12)=='P'){
        char np;
        if (i2==0){
            char np;
            printf("promotion pion : voulez vous que votre pion devient un fou,une tour,un cavalier ou une reine ?\n");
            scanf("%c",np);
            *(chessboard+i2+j2*12)==np;
        }
    }
}

void selection_piece(char* chessboard){
    char i_debut,i_fin,j_debut,j_fin;
    int ideb, ifin;
    printf("indiquez la colonne de la piece a deplacer\n");
    scanf("\n%c",&j_debut);
    printf("indiquez la ligne de la piece a deplacer\n");
    scanf("\n%d",&ideb);
    printf("indiquez la colonne de la nouvelle position\n");
    scanf("\n%c",&j_fin);
    printf("indiquez la ligne de la nouvelle position\n");
    scanf("\n%d",&ifin);

    i_debut =emplacement2(ideb);
    i_fin = emplacement2(ifin);

    if (*(chessboard+i_debut+j_debut*12)=='p' || *(chessboard+i_debut+j_debut*12)=='P'){
        pion(chessboard,i_debut,i_fin,j_debut,j_fin);
    }
    else if (*(chessboard+i_debut+j_debut*12)=='c' || *(chessboard+i_debut+j_debut*12)=='C'){
        cavalier(chessboard,i_debut,i_fin,j_debut,j_fin);
    }
    else if (*(chessboard+i_debut+j_debut*12)=='t' || *(chessboard+i_debut+j_debut*12)=='T'){
        tour(chessboard,i_debut,i_fin,j_debut,j_fin);
    }
    else if (*(chessboard+i_debut+j_debut*12)=='k' || *(chessboard+i_debut+j_debut*12)=='K'){
        roi(chessboard,i_debut,i_fin,j_debut,j_fin);
    }
    else if (*(chessboard+i_debut+j_debut*12)=='q' || *(chessboard+i_debut+j_debut*12)=='Q'){
        reine(chessboard,i_debut,i_fin,j_debut,j_fin);
    }
    else if (*(chessboard+i_debut+j_debut*12)=='f' || *(chessboard+i_debut+j_debut*12)=='F'){
        fou(chessboard,i_debut,i_fin,j_debut,j_fin);
    }
    else if (*(chessboard+i_debut+j_debut*12)=='o' || *(chessboard+i_debut+j_debut*12)=='O'){
        cavalier_fou(chessboard,i_debut,i_fin,j_debut,j_fin);
    }
    /*else if (*(chessboard+i_debut+j_debut*12)=='h' || *(chessboard+i_debut+j_debut*12)=='H'){
        prince(chessboard,i_debut,i_fin,j_debut,j_fin);
    }*/
    else{
        printf("il n'y a pas de pièce ici\n");
        selection_piece(chessboard);
    }
}

int fin_de_partie(char* chessboard){
    int king1=0;
    int king2=0;
    int fin=0;
    for (int i = 0; i<size-1; i++){
        for (int j = 1;j<size; j++){
            if (*(chessboard+j+i*11)=='k'){
                king1=1;
            }
        
            if (*(chessboard+j+i*11)=='K'){
                king2=1;
            }
        }
    }
    if (king1==0){
        printf("Le joueur 1 a perdu\n");
        fin=1;
    }
    else if (king2==0){
        printf("le joueur 2 a perdu\n");
        fin=1;
    }
    return fin;
}