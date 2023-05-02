#include <stdio.h>
#define size 12


void selection_piece(char chessboard[size][size]);

void cavalier(char chessboard[size][size], int i_debut,int i_fin, int j_debut, int j_fin){
    if (i_debut+2==i_fin || i_debut-2==i_fin){
        if (j_debut+1==j_fin || j_debut-1==j_fin){
            if (chessboard[i_debut][j_debut]=='c'){
                chessboard[i_fin][j_fin]='c';
                chessboard[i_debut][j_fin]=' ';
            }
            else if (chessboard[i_debut][j_debut]='C'){
                chessboard[i_fin][j_fin]='C';
                chessboard[i_debut][j_fin]=' ';
            }
        }
    }
    else {
        printf("coup illégal,réessayez de déplacer une pièce\n");
        selection_piece(chessboard);
    }
}

void pion(char chessboard[size][size],int i_debut,int i_fin,int j_debut,int j_fin){
    if (i_debut+1==i_fin && j_debut==j_fin && chessboard[i_debut][j_debut]=='p'){
        chessboard[i_fin][j_fin]='p';
        chessboard[i_debut][j_debut]=' ';
    }
    else if (i_debut-1==i_fin && j_debut==j_fin && chessboard[i_debut][j_debut]=='P'){
        chessboard[i_fin][j_fin]='P';
        chessboard[i_debut][j_debut]=' ';
    }
    else {
        printf("coup illégal,réessayez de déplacer une pièce\n");
        selection_piece(chessboard);
    }
}

void tour(char chessboard[size][size],int i_debut,int i_fin,int j_debut,int j_fin){
    if (i_debut==i_fin || j_debut==j_fin){
        if (i_debut!=i_fin || j_debut!=j_fin){
            if(chessboard[i_debut][j_debut]=='t'){
                chessboard[i_fin][j_fin]='t';
                chessboard[i_debut][j_debut]=' ';
            }
             if(chessboard[i_debut][j_debut]=='T'){
                chessboard[i_fin][j_fin]='t';
                chessboard[i_debut][j_debut]=' ';
            }
        }
    }
     else {
        printf("coup illégal,réessayez de déplacer une pièce\n");
        selection_piece(chessboard);
    }
}

void fou(char chessboard[size][size],int i_debut,int i_fin,int j_debut,int j_fin){
    char i,j;
    if(i_debut<i_fin && j_debut<j_fin){
       i=-(i_fin-i_debut);
       j=-(j_fin-j_debut);
       if (i==j){
           if (chessboard[i_debut][j_debut]=='f'){
               chessboard[i_fin][j_fin]='f';
               chessboard[i_debut][j_debut]=' ';
           }
           else if (chessboard[i_debut][j_debut]=='F'){
               chessboard[i_fin][j_fin]='F';
               chessboard[i_debut][j_debut]=' ';
           }
       }
       else {
           printf("coup illégal,réessayez de déplacer une pièce\n");
           selection_piece(chessboard);
       }
    }
    if(i_debut<i_fin && j_debut>j_fin){
       i=-(i_fin-i_debut);
       j=j_fin-j_debut;
       if (i==j){
           if (chessboard[i_debut][j_debut]=='f'){
               chessboard[i_fin][j_fin]='f';
               chessboard[i_debut][j_debut]=' ';
           }
           else if (chessboard[i_debut][j_debut]=='F'){
               chessboard[i_fin][j_fin]='F';
               chessboard[i_debut][j_debut]=' ';
           }
       }
       else {
           printf("coup illégal,réessayez de déplacer une pièce\n");
           selection_piece(chessboard);
       }
    }
    if(i_debut>i_fin && j_debut>j_fin){
       i=i_fin-i_debut;
       j=j_fin-j_debut;
       if (i==j){
           if (chessboard[i_debut][j_debut]=='f'){
               chessboard[i_fin][j_fin]='f';
               chessboard[i_debut][j_debut]=' ';
           }
           else if (chessboard[i_debut][j_debut]=='F'){
               chessboard[i_fin][j_fin]='F';
               chessboard[i_debut][j_debut]=' ';
           }
       }
       else {
           printf("coup illégal,réessayez de déplacer une pièce\n");
           selection_piece(chessboard);
       }
    }
    if(i_debut>i_fin && j_debut<j_fin){
       i=i_fin-i_debut;
       j=-(j_fin-j_debut);
       if (i==j){
           if (chessboard[i_debut][j_debut]=='f'){
               chessboard[i_fin][j_fin]='f';
               chessboard[i_debut][j_debut]=' ';
           }
           else if (chessboard[i_debut][j_debut]=='F'){
               chessboard[i_fin][j_fin]='F';
               chessboard[i_debut][j_debut]=' ';
           }
       }
       else {
           printf("coup illégal,réessayez de déplacer une pièce\n");
           selection_piece(chessboard);
       }
    }
}

void roi(char chessboard[size][size],int i_debut,int i_fin,int j_debut,int j_fin){
    if (i_debut+1==i_fin || j_debut+1==j_fin){
        if (chessboard[i_debut][j_debut]=='k'){
               chessboard[i_fin][j_fin]='k';
               chessboard[i_debut][j_debut]=' ';
           }
        if (chessboard[i_debut][j_debut]=='K'){
               chessboard[i_fin][j_fin]='K';
               chessboard[i_debut][j_debut]=' ';
           }
    }
    else {
        printf("coup illégal,réessayez de déplacer une pièce\n");
        selection_piece(chessboard);
    }
}

int emplacement(char lettre){

    int num;

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

void selection_piece(char chessboard[size][size]){
    char a,b,c,d;
    int i_debut,i_fin,j_debut,j_fin;
    printf("indiquez la ligne puis la colonne de la pièce à déplacer\n");
    scanf("%c",&a);
    i_debut = emplacement(a);
    scanf("%c",&b);
    j_debut = emplacement(b);
    printf("indiquez la ligne puis la colonne de la nouvelle position\n");
    scanf("%c",&b);
    i_fin = emplacement(c);
    scanf("%c",&d);
    j_fin = emplacement(d);
    if (chessboard[i_debut][j_debut]=='p' || chessboard[i_debut][j_debut]=='P'  ){
        pion(chessboard,i_debut,i_fin,j_debut,j_fin);
    }
    else if (chessboard[i_debut][j_debut]=='c' || chessboard[i_debut][j_debut]=='C'  ){
        cavalier(chessboard,i_debut,i_fin,j_debut,j_fin);
    }
    else if (chessboard[i_debut][j_debut]=='t' || chessboard[i_debut][j_debut]=='T'  ){
        tour(chessboard,i_debut,i_fin,j_debut,j_fin);
    }
    else if (chessboard[i_debut][j_debut]=='k' || chessboard[i_debut][j_debut]=='K'  ){
        roi(chessboard,i_debut,i_fin,j_debut,j_fin);
    }
   /* else if (chessboard[i_debut][j_debut]=='q' || chessboard[i_debut][j_debut]=='Q'  ){
        dame(chessboard,i_debut,i_fin,j_debut,j_fin);
    }*/
    else if (chessboard[i_debut][j_debut]=='f' || chessboard[i_debut][j_debut]=='F'  ){
        fou(chessboard,i_debut,i_fin,j_debut,j_fin);
    }
    /*else if (chessboard[i_debut][j_debut]=='o' || chessboard[i_debut][j_debut]=='O'  ){
        cavalier_fou(chessboard,i_debut,i_fin,j_debut,j_fin);
    }*/
    /*else if (chessboard[i_debut][j_debut]=='h' || chessboard[i_debut][j_debut]=='H'  ){
        prince(chessboard,i_debut,i_fin,j_debut,j_fin);
    }*/
    else{
        printf("il n'y a pas de pièce ici\n");
        selection_piece(chessboard);
    }
}
