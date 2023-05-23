#include <stdio.h>
#include <string.h>
#define size 12


void selection_piece(char* chessboard);
void deplacement_ligne(char* chessboard,int i1,int i2,int j1,int j2,char piece);
void deplacement_diagonale(char* chessboard,int i1,int i2,int j1,int j2,char piece);
void deplacement_en_L(char* chessboard,int i1,int i2,int j1,int j2,char piece);
int verif_deplacement_simple(char* chessboard,int i1,int i2,int j1,int j2);
int verif_deplacement_diagonale(char* chessboard,int i1,int i2,int j1,int j2);
int verif_deplacement_droit(char* chessboard,int i1,int i2,int j1,int j2);
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


void pion(char* chessboard,int i1,int i2,int j1,int j2){

    printf("%c\n",*(chessboard+i1*12+j1) );

    if (i1-1==i2 && j1==j2 && *(chessboard+i1*12+j1)=='p'){
        int v=verif_deplacement_simple(chessboard,i1,i2,j1,j2);
        if (v==0){
            *(chessboard+i2*12+j2)='p';
            *(chessboard+i1*12+j1)=' ';
        }
    }
    else if (i1+1==i2 && j1==j2 && *(chessboard+i1*12+j1)=='P'){
        int v=verif_deplacement_simple(chessboard,i1,i2,j1,j2);
        if (v==0){
            *(chessboard+i2*12+j2)='P';
            *(chessboard+i1*12+j1)=' ';
        }
    }
    else {
        printf("coup illegal,reessayez de deplacer une piece\n");
        selection_piece(chessboard);
    }
    promotion_pion(chessboard,i2,j2);
}

void fou(char* chessboard,int i1,int i2,int j1,int j2){
    deplacement_diagonale(chessboard,i1,i2,j1,j2,*(chessboard+i1*12+j1));
    if (*(chessboard+i1*12+j1)=='f','F'){
        printf("coup illegal,reessayez de deplacer une piece\n");
        selection_piece(chessboard);
    }
}

void tour(char* chessboard,int i1,int i2,int j1,int j2){
    deplacement_ligne(chessboard,i1,i2,j1,j2,*(chessboard+i1*12+j1));
    if (*(chessboard+i1*12+j1)=='t','T'){
        printf("coup illegal,reessayez de deplacer une piece\n");
        selection_piece(chessboard);
    }
}

void cavalier(char* chessboard,int i1,int i2,int j1,int j2){
    deplacement_en_L(chessboard,i1,i2,j1,j2,*(chessboard+i1*12+j1));
    if (*(chessboard+i1*12+j1)=='c','C'){
        printf("coup illegal,reessayez de deplacer une piece\n");
        selection_piece(chessboard);
    }
}

void reine(char* chessboard,int i1,int i2,int j1,int j2){
    deplacement_diagonale(chessboard,i1,i2,j1,j2,*(chessboard+i1*12+j1));
    deplacement_ligne(chessboard,i1,i2,j1,j2,*(chessboard+i1*12+j1));
    if (*(chessboard+i1*12+j1)=='q','Q'){
        printf("coup illegal,reessayez de deplacer une piece\n");
        selection_piece(chessboard);
    }
}

void roi(char* chessboard,int i1,int i2,int j1,int j2){
    printf("pion pris en compte\n");
    if (i1+1==i2 || j1+1==j2 || i1-1==i2 || j1-1==j2){
        if (*(chessboard+i1*12+j1)=='k'){
            int v=verif_deplacement_simple(chessboard,i1,i2,j1,j2);
            if (v==0){
                *(chessboard+i2*12+j2)='k';
                *(chessboard+i1*12+j1)=' ';
            }
        }
        else if (*(chessboard+i1*12+j1)=='K'){
            int v=verif_deplacement_simple(chessboard,i1,i2,j1,j2);
            if (v==0){
                *(chessboard+i2*12+j2)='K';
                *(chessboard+i1*12+j1)=' ';
            }
        }
    }
    else {
        printf("coup illegal,reessayez de deplacer une piece\n");
        selection_piece(chessboard);
    }
}

void cavalier_fou(char* chessboard,int i1,int i2,int j1,int j2){
    deplacement_diagonale(chessboard,i1,i2,j1,j2,*(chessboard+i1*12+j1));
    deplacement_en_L(chessboard,i1,i2,j1,j2,*(chessboard+i1*12+j1));
    if (*(chessboard+i1*12+j1)=='l','L'){
        printf("coup illegal,reessayez de deplacer une piece\n");
        selection_piece(chessboard);
    }
}

void deplacement_ligne(char* chessboard,int i1,int i2,int j1,int j2,char piece){
    if (i1==i2 || j1==j2){
        if (i1!=i2 || j1!=j2){
            if(piece=='t','q'){
                int v=verif_deplacement_droit(chessboard,i1,i2,j1,j2);
                if (v==0){
                    *(chessboard+i2*12+j2)=piece;
                    piece=' ';
                }
            }
            else if(piece=='T','Q'){
                int v=verif_deplacement_droit(chessboard,i1,i2,j1,j2);
                if (v==0){
                    *(chessboard+i2*12+j2)=piece;
                    piece=' ';
                }
            }
        }
    }
}


void deplacement_diagonale(char* chessboard,int i1,int i2,int j1,int j2,char piece){
    char i,j;
    if(i1<i2 && j1<j2){
       i=-(i2-i1);
       j=-(j2-j1);
       if (i==j){
           if (piece=='f','q','o'){
               int v=verif_deplacement_diagonale(chessboard,i1,i2,j1,j2);
               if (v==0){
                   *(chessboard+i2*12+j2)=piece;
                    piece=' ';
               }
           }
           else if (*(chessboard+i1*12+j1)=='F','Q','O'){
               int v=verif_deplacement_diagonale(chessboard,i1,i2,j1,j2);
               if (v==0){
                   *(chessboard+i2*12+j2)=piece;
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
                   *(chessboard+i2*12+j2)=piece;
                    piece=' ';
               }
           }
           else if (piece=='F','Q','O'){
               int v=verif_deplacement_diagonale(chessboard,i1,i2,j1,j2);
               if (v==0){
                   *(chessboard+i2*12+j2)=piece;
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
                   *(chessboard+i2*12+j2)=piece;
                    piece=' ';
               }
           }
           else if (piece=='F','Q','O'){
               int v=verif_deplacement_diagonale(chessboard,i1,i2,j1,j2);
               if (v==0){
                   *(chessboard+i2*12+j2)=piece;
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
                   *(chessboard+i2*12+j2)=piece;
                    piece=' ';
               }
           }
           else if (piece=='F','Q','O'){
               int v=verif_deplacement_diagonale(chessboard,i1,i2,j1,j2);
               if (v==0){
                   *(chessboard+i2*12+j2)=piece;
                    piece=' ';
               }
           }
       }
    }
}

void deplacement_en_L(char* chessboard,int i1,int i2,int j1,int j2,char piece){
    if (i1+2==i2 || i1-2==i2){
        if (j1+1==j2 || j1-1==j2){
            if (piece=='c','o'){
                int v=verif_deplacement_simple(chessboard,i1,i2,j1,j2);
                if (v==0){
                    *(chessboard+i2*12+j2)=piece;
                    piece=' ';
                }
            }
            else if (piece=='C','O'){
                int v=verif_deplacement_simple(chessboard,i1,i2,j1,j2);
                if (v==0){
                    *(chessboard+i2*12+j2)=piece;
                    piece=' ';
                }
            }
        }
    }
}

int verif_deplacement_simple(char* chessboard,int i1,int i2,int j1,int j2){
    char piece[9];
    char piece2[9];
    strcpy(piece,"pktcfqol");
    strcpy(piece2,"PKTCFQOL");
    if (*(chessboard+i1*12+j1)=='p','c','k'){
        for (int i=0;i<9;i++){
            if (*(chessboard+i2*12+j2)==piece[i]){
                printf("coup illegal,reessayez de deplacer une piece\n");
                selection_piece(chessboard);
                return 1;
            }
        }
            
    }
    else if (*(chessboard+i1*12+j1)=='P','C','K'){
        for (int i=0;i<9;i++){
            if (*(chessboard+i2*12+j2)==piece2[i]){
                printf("coup illegal,reessayez de deplacer une piece\n");
                selection_piece(chessboard);
                return 1;
            }
        }
            
    }
    if (i2>10 || j2<0 || j2>11){
        printf("coup illegal,reessayez de deplacer une piece\n");
        selection_piece(chessboard);
        return 1;
    }
    return 0;
    
}


int verif_deplacement_diagonale(char* chessboard,int i1,int i2,int j1,int j2){
    char piece[9];
    char piece2[9];
    strcpy(piece,"pktcfqol");
    strcpy(piece2,"PKTCFQOL");
    if (i1<i2 && j1<j2){
        if (*(chessboard+i1*12+j1)=='f','q','o'){
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
                if (*(chessboard+i2*12+j2)==piece[i]){
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
                if (*(chessboard+i2*12+j2)==piece[i]){
                   printf("coup illegal,reessayez de deplacer une piece\n");
                   selection_piece(chessboard);
                   return 1;
                }
            }
        }
    }    
    else if (i1<i2 && j1>j2){
        if (*(chessboard+i1*12+j1)=='f','q','o'){
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
                if (*(chessboard+i2*12+j2)==piece[i]){
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
                if (*(chessboard+i2*12+j2)==piece[i]){
                   printf("coup illegal,reessayez de deplacer une piece\n");
                   selection_piece(chessboard);
                   return 1;
                }
            }
        } 
    }   
    
    else if (i1>i2 && j1>j2){
        if (*(chessboard+i1*12+j1)=='f','q','o'){
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
                if (*(chessboard+i2*12+j2)==piece[i]){
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
                if (*(chessboard+i2*12+j2)==piece[i]){
                    printf("coup illegal,reessayez de deplacer une piece\n");
                    selection_piece(chessboard);
                    return 1;
                }
            }
        }
    }
    
    else if (i1>i2 && j1<j2){
        if (*(chessboard+i1*12+j1)=='f','q','o'){
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
                if (*(chessboard+i2*12+j2)==piece[i]){
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
                if (*(chessboard+i2*12+j2)==piece[i]){
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

int verif_deplacement_droit(char* chessboard,int i1,int i2,int j1,int j2){
    char piece[9];
    char piece2[9];
    strcpy(piece,"pktcfqol");
    strcpy(piece2,"PKTCFQOL");
    if (i2>i1){
        if(*(chessboard+i1*12+j1)=='t','q','l'){
            for (int i=i1+1;i<i2;i++){
                for (int i0=0;i0<9;i0++){
                    if (*(chessboard+i*12+j1)==piece[i0],piece2[i0]){
                        printf("coup illegal,reessayez de deplacer une piece\n");
                        selection_piece(chessboard);
                        return 1;
                    }
                }
            }
            for (int i=0;i<9;i++){
                if (*(chessboard+i2*12+j2)==piece[i]){
                   printf("coup illegal,reessayez de deplacer une piece\n");
                   selection_piece(chessboard);
                   return 1;
                }
            }
        }
        else if(*(chessboard+i1*12+j1)=='T','Q','L'){
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
                if (*(chessboard+i2*12+j2)==piece2[i]){
                    printf("coup illegal,reessayez de deplacer une piece\n");
                    selection_piece(chessboard);
                    return 1;
                }
            }
        }
    }
    else if (j2>j1){
        if(*(chessboard+i1*12+j1)=='t','q','l'){
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
                if (*(chessboard+i2*12+j2)==piece[i]){
                    printf("coup illegal,reessayez de deplacer une piece\n");
                    selection_piece(chessboard);
                    return 1;
                }
            }
        }
        else if(*(chessboard+i1*12+j1)=='T','Q','L'){
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
                if (*(chessboard+i2*12+j2)==piece2[i]){
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
    if (*(chessboard+i2*12+j2)=='p'){
        if (i2==11){
            char np;
            printf("promotion pion : voulez vous que votre pion devient un fou,une tour,un cavalier ou une reine ?\n");
            scanf("%c",np);
            *(chessboard+i2*12+j2)==np;
        }
    }
    
    if (*(chessboard+i2*12+j2)=='P'){
        char np;
        if (i2==0){
            char np;
            printf("promotion pion : voulez vous que votre pion devient un fou,une tour,un cavalier ou une reine ?\n");
            scanf("%c",np);
            *(chessboard+i2*12+j2)==np;
        }
    }
}

void selection_piece(char* chessboard){
    int i_debut,i_fin,j_debut,j_fin;
    char jdeb, jfin;
    printf("indiquez la colonne de la piece a deplacer\n");
    scanf("\n%c",&jdeb);
    printf("indiquez la ligne de la piece a deplacer\n");
    scanf("\n%d",&i_debut);
    printf("indiquez la colonne de la nouvelle position\n");
    scanf("\n%c",&jfin);
    printf("indiquez la ligne de la nouvelle position\n");
    scanf("\n%d",&i_fin);



    j_debut =emplacement(jdeb);
    j_fin = emplacement(jfin);

    i_debut = 11 - i_debut;
    i_fin = 11 - i_fin;

    printf("%d\n",i_debut);
    printf("%d\n",i_fin);

    if (*(chessboard+i_debut*12+j_debut)=='p' || *(chessboard+i_debut*12+j_debut)=='P'){
        printf("ca marche P\n");
        pion(chessboard,i_debut,i_fin,j_debut,j_fin);
    }
    else if (*(chessboard+i_debut*12+j_debut)=='c' || *(chessboard+i_debut*12+j_debut)=='C'){
        cavalier(chessboard,i_debut,i_fin,j_debut,j_fin);
    }
    else if (*(chessboard+i_debut*12+j_debut)=='t' || *(chessboard+i_debut*12+j_debut)=='T'){
        tour(chessboard,i_debut,i_fin,j_debut,j_fin);
    }
    else if (*(chessboard+i_debut*12+j_debut)=='k' || *(chessboard+i_debut*12+j_debut)=='K'){
        printf("ca marche R\n");
        roi(chessboard,i_debut,i_fin,j_debut,j_fin);
        
    }
    else if (*(chessboard+i_debut*12+j_debut)=='q' || *(chessboard+i_debut*12+j_debut)=='Q'){
        reine(chessboard,i_debut,i_fin,j_debut,j_fin);
    }
    else if (*(chessboard+i_debut*12+j_debut)=='f' || *(chessboard+i_debut*12+j_debut)=='F'){
        fou(chessboard,i_debut,i_fin,j_debut,j_fin);
    }
    else if (*(chessboard+i_debut*12+j_debut)=='o' || *(chessboard+i_debut*12+j_debut)=='O'){
        cavalier_fou(chessboard,i_debut,i_fin,j_debut,j_fin);
    }
    /*else if (*(chessboard+i_debut*12+j_debut)=='h' || *(chessboard+i_debut*12+j_debut)=='H'){
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
            if (*(chessboard+j+i*12)=='k'){
                king1=1;
            }
        
            if (*(chessboard+j+i*12)=='K'){
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