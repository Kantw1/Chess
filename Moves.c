#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>


#define size 12 //taille du tableau

void vide_buffer1(){
    while(getchar()!='\n'){
    }
}

void selection_piece(char* chessboard, int joueur);
void deplacement_ligne(char* chessboard,int i1,int i2,int j1,int j2, int joueur,char piece);
void deplacement_diagonale(char* chessboard,int i1,int i2,int j1,int j2, int joueur,char piece);
void deplacement_en_L(char* chessboard,int i1,int i2,int j1,int j2, int joueur,char piece);
int verif_deplacement_simple(char* chessboard,int i1,int i2,int j1,int j2, int joueur);
int verif_deplacement_diagonale(char* chessboard,int i1,int i2,int j1,int j2, int joueur);
int verif_deplacement_droit(char* chessboard,int i1,int i2,int j1,int j2, int joueur);
void promotion_pion(char* chessboard,char i2,char j2);
void deplacement_pion_x2(char* chessboard,int i1,int i2,int j1,int j2, int joueur);
void prince(char* chessboard,int i1,int i2,int j1,int j2, int joueur);




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


void pion(char* chessboard,int i1,int i2,int j1,int j2, int joueur){
    
    if (i1-1==i2 && j1-1==j2 && (*(chessboard+i2*size+j2)=='P'||*(chessboard+i2*size+j2)=='Q'||*(chessboard+i2*size+j2)=='T'||*(chessboard+i2*size+j2)=='F'||*(chessboard+i2*size+j2)=='O'||*(chessboard+i2*size+j2)=='H')){
        *(chessboard+i2*size+j2)='p';
        *(chessboard+i1*size+j1)=' ';
    }
    else if (i1-1==i2 && j1+1==j2 && (*(chessboard+i2*size+j2)=='P'||*(chessboard+i2*size+j2)=='Q'||*(chessboard+i2*size+j2)=='T'||*(chessboard+i2*size+j2)=='F'||*(chessboard+i2*size+j2)=='O'||*(chessboard+i2*size+j2)=='H')){
        *(chessboard+i2*size+j2)='p';
        *(chessboard+i1*size+j1)=' ';
    }
    else if (i1+1==i2 && j1-1==j2 && (*(chessboard+i2*size+j2)=='p'||*(chessboard+i2*size+j2)=='q'||*(chessboard+i2*size+j2)=='t'||*(chessboard+i2*size+j2)=='f'||*(chessboard+i2*size+j2)=='o'||*(chessboard+i2*size+j2)=='h')){
        *(chessboard+i2*size+j2)='P';
        *(chessboard+i1*size+j1)=' ';
    }
    else if (i1+1==i2 && j1+1==j2 && (*(chessboard+i2*size+j2)=='p'||*(chessboard+i2*size+j2)=='q'||*(chessboard+i2*size+j2)=='t'||*(chessboard+i2*size+j2)=='f'||*(chessboard+i2*size+j2)=='o'||*(chessboard+i2*size+j2)=='h')){
        *(chessboard+i2*size+j2)='P';
        *(chessboard+i1*size+j1)=' ';
    }
    else if (i1-1==i2 && j1==j2 && *(chessboard+i1*size+j1)=='p'){
        int v=verif_deplacement_simple(chessboard,i1,i2,j1,j2, joueur);
        if (v==0){
            *(chessboard+i2*size+j2)='p';
            *(chessboard+i1*size+j1)=' ';
        }
    }
    else if (i1+1==i2 && j1==j2 && *(chessboard+i1*size+j1)=='P'){
        int v=verif_deplacement_simple(chessboard,i1,i2,j1,j2,joueur);
        if (v==0){
            *(chessboard+i2*size+j2)='P';
            *(chessboard+i1*size+j1)=' ';
        }
    }
    else {
        deplacement_pion_x2(chessboard,i1,i2,j1,j2,joueur);
        
    }
    promotion_pion(chessboard,i2,j2);
}

void fou(char* chessboard,int i1,int i2,int j1,int j2, int joueur){
    deplacement_diagonale(chessboard,i1,i2,j1,j2,joueur,*(chessboard+i1*size+j1));
    if (*(chessboard+i1*size+j1)=='f' || *(chessboard+i1*size+j1)=='F'){
        printf("coup illegal,reessayez de deplacer une piece\n");
        selection_piece(chessboard, joueur);
    }
}

void tour(char* chessboard,int i1,int i2,int j1,int j2, int joueur){
    deplacement_ligne(chessboard,i1,i2,j1,j2,joueur,*(chessboard+i1*size+j1));
    if (*(chessboard+i1*size+j1)=='t' || *(chessboard+i1*size+j1)=='T'){
        printf("coup illegaL,reessayez de deplacer une piece\n");
        selection_piece(chessboard, joueur);
    }
}

void cavalier(char* chessboard,int i1,int i2,int j1,int j2, int joueur){
    deplacement_en_L(chessboard,i1,i2,j1,j2,joueur,*(chessboard+i1*size+j1));
    if (*(chessboard+i1*size+j1)=='c' || *(chessboard+i1*size+j1)=='C'){
        printf("coup illegal,reessayez de deplacer une piece\n");
        selection_piece(chessboard, joueur);
    }
}

void reine(char* chessboard,int i1,int i2,int j1,int j2, int joueur){
    deplacement_diagonale(chessboard,i1,i2,j1,j2,joueur,*(chessboard+i1*size+j1));
    deplacement_ligne(chessboard,i1,i2,j1,j2,joueur,*(chessboard+i1*size+j1));
    if (*(chessboard+i1*size+j1)=='q' || *(chessboard+i1*size+j1)=='Q'){
        printf("coup illegal,reessayez de deplacer une piece\n");
        selection_piece(chessboard, joueur);
    }
}

void roi(char* chessboard,char i1,char i2,char j1,char j2, int joueur){
    if ((i2>=i1-1 && i2<=i1+1) && (j2>=j1-1 && j2<=j1+1)){
        if (*(chessboard+i1*size+j1)=='k'){
            int v=verif_deplacement_simple(chessboard,i1,i2,j1,j2,joueur);
            if (v==0){
                *(chessboard+i2*size+j2)='k';
                *(chessboard+i1*size+j1)=' ';
            }
        }
        else if (*(chessboard+i1*size+j1)=='K'){
            int v=verif_deplacement_simple(chessboard,i1,i2,j1,j2, joueur);
            if (v==0){
                *(chessboard+i2*size+j2)='K';
                *(chessboard+i1*size+j1)=' ';
            }
        }
    }
    else {
        printf("coup illegal,reessayez de deplacer une piece\n");
        selection_piece(chessboard,joueur);
    }
}

void cavalier_fou(char* chessboard,int i1,int i2,int j1,int j2, int joueur){
    deplacement_diagonale(chessboard,i1,i2,j1,j2,joueur,*(chessboard+i1*size+j1));
    deplacement_en_L(chessboard,i1,i2,j1,j2,joueur,*(chessboard+i1*size+j1));
    if (*(chessboard+i1*size+j1)=='o'||*(chessboard+i1*size+j1)=='O'){
        printf("coup illegal,reessayez de deplacer une piece\n");
        selection_piece(chessboard, joueur);
    }
}

void prince(char* chessboard,int i1,int i2,int j1,int j2, int joueur){
    if ((i2>=i1-1 && i2<=i1+1) && (j2>=j1-1 && j2<=j1+1)){
        if (*(chessboard+i1*size+j1)=='h'){
            int v=verif_deplacement_simple(chessboard,i1,i2,j1,j2,joueur);
            if (v==0){
                *(chessboard+i2*size+j2)='h';
                *(chessboard+i1*size+j1)=' ';
            }
        }
        else if (*(chessboard+i1*size+j1)=='H'){
            int v=verif_deplacement_simple(chessboard,i1,i2,j1,j2,joueur);
            if (v==0){
                *(chessboard+i2*size+j2)='H';
                *(chessboard+i1*size+j1)=' ';
            }
        }
    }
    else if (((i2>=i1-2 && i2<=i1+2) && j1==j2) || (i1==i2 && (j2>=j1-2 && j2<=j1+2))){
        if (*(chessboard+i1*size+j1)=='h'){
            int v=verif_deplacement_droit(chessboard,i1,i2,j1,j2, joueur);
            if (v==0){
                *(chessboard+i2*size+j2)='h';
                *(chessboard+i1*size+j1)=' ';
            }
        }
        else if (*(chessboard+i1*size+j1)=='H'){
            int v=verif_deplacement_droit(chessboard,i1,i2,j1,j2, joueur);
            if (v==0){
                *(chessboard+i2*size+j2)='H';
                *(chessboard+i1*size+j1)=' ';
            }
        }
    }
    else if ((i2>=i1-2 && i2<=i1+2) && (j2>=j1-2 && j2<=j1+2)){
        if (*(chessboard+i1*size+j1)=='h'){
            int v=verif_deplacement_diagonale(chessboard,i1,i2,j1,j2, joueur);
            if (v==0){
                *(chessboard+i2*size+j2)='h';
                *(chessboard+i1*size+j1)=' ';
            }
        }
        else if (*(chessboard+i1*size+j1)=='H'){
            int v=verif_deplacement_diagonale(chessboard,i1,i2,j1,j2, joueur);
            if (v==0){
                *(chessboard+i2*size+j2)='H';
                *(chessboard+i1*size+j1)=' ';
            }
        }
    }
        if (*(chessboard+i1*size+j1)=='h'||*(chessboard+i1*size+j1)=='H'){
        printf("coup illegal,reessayez de deplacer une piece\n");
        selection_piece(chessboard, joueur);
    }
}

void deplacement_ligne(char* chessboard,int i1,int i2,int j1,int j2, int joueur,char piece){
    if (i1==i2 || j1==j2){
            if(piece=='t' || piece=='q'){
                int v=verif_deplacement_droit(chessboard,i1,i2,j1,j2,joueur);
                if (v==0){
                    *(chessboard+i2*size+j2)=piece;
                    *(chessboard+i1*size+j1)=' ';
                }
            }
            else if(piece=='T' || piece=='Q'){
                int v=verif_deplacement_droit(chessboard,i1,i2,j1,j2,joueur);
                if (v==0){
                    *(chessboard+i2*size+j2)=piece;
                    *(chessboard+i1*size+j1)=' ';
                }
            }
        }
    
}


void deplacement_diagonale(char* chessboard,int i1,int i2,int j1,int j2,int joueur, char piece){
    int i=i2-i1;
    int j=j2-j1;
    if (i==j){
        if (*(chessboard+i1*size+j1)=='f' || *(chessboard+i1*size+j1)=='q' || *(chessboard+i1*size+j1)=='o' ||*(chessboard+i1*size+j1)=='h'){
            int v=verif_deplacement_diagonale(chessboard,i1,i2,j1,j2,joueur);
            if (v==0){
                *(chessboard+i2*size+j2)=piece;
                *(chessboard+i1*size+j1)=' ';
            }
        }
        else if (*(chessboard+i1*size+j1)=='F' || *(chessboard+i1*size+j1)=='Q' || *(chessboard+i1*size+j1)=='O'||*(chessboard+i1*size+j1)=='H'){
            int v=verif_deplacement_diagonale(chessboard,i1,i2,j1,j2,joueur);
            if (v==0){
                *(chessboard+i2*size+j2)=piece;
                *(chessboard+i1*size+j1)=' ';
            }
        }
    }
    if (i==(-j)){
        if (*(chessboard+i1*size+j1)=='f' || *(chessboard+i1*size+j1)=='q' || *(chessboard+i1*size+j1)=='o'||*(chessboard+i1*size+j1)=='h'){
            int v=verif_deplacement_diagonale(chessboard,i1,i2,j1,j2, joueur);
            if (v==0){
                *(chessboard+i2*size+j2)=piece;
                *(chessboard+i1*size+j1)=' ';
            }
        }
        else if (*(chessboard+i1*size+j1)=='F' || *(chessboard+i1*size+j1)=='Q' || *(chessboard+i1*size+j1)=='O'||*(chessboard+i1*size+j1)=='H'){
            int v=verif_deplacement_diagonale(chessboard,i1,i2,j1,j2, joueur);
            if (v==0){
                *(chessboard+i2*size+j2)=piece;
                *(chessboard+i1*size+j1)=' ';
            }
        }
    }
    if ((-i)==j){
        if (*(chessboard+i1*size+j1)=='f' || *(chessboard+i1*size+j1)=='q' || *(chessboard+i1*size+j1)=='o'||*(chessboard+i1*size+j1)=='h'){
            int v=verif_deplacement_diagonale(chessboard,i1,i2,j1,j2, joueur);
            if (v==0){
                *(chessboard+i2*size+j2)=piece;
                *(chessboard+i1*size+j1)=' ';
            }
        }
        else if (*(chessboard+i1*size+j1)=='F' || *(chessboard+i1*size+j1)=='Q' || *(chessboard+i1*size+j1)=='O'||*(chessboard+i1*size+j1)=='H'){
            int v=verif_deplacement_diagonale(chessboard,i1,i2,j1,j2, joueur);
            if (v==0){
                *(chessboard+i2*size+j2)=piece;
                *(chessboard+i1*size+j1)=' ';
            }
        }
    }
}

void deplacement_pion_x2(char* chessboard,int i1,int i2,int j1,int j2, int joueur){
    if (i1*size+j1==0*size+1 || i1*size+j1==1*size+2 || i1*size+j1==2*size+3 || i1*size+j1==3*size+4 || i1*size+j1==0*size+11 || i1*size+j1==1*size+10 || i1*size+j1==2*size+9 || i1*size+j1==3*size+8){
        if (*(chessboard+i1*size+j1)=='P' && *(chessboard+i2*size+j2)==' '){
            if (i1+2==i2 && j1==j2){
                int v=verif_deplacement_droit(chessboard,i1,i2,j1,j2,joueur);
                if (v==0){
                    *(chessboard+i2*size+j2)='P';
                    *(chessboard+i1*size+j1)=' ';
                }   
            }
        }       
    }

    else if (i1*size+j1==10*size+1 || i1*size+j1==9*size+2 || i1*size+j1==8*size+3 || i1*size+j1==7*size+4 || i1*size+j1==10*size+11 || i1*size+j1==9*size+10 || i1*size+j1==8*size+9 || i1*size+j1==7*size+8){
        if (*(chessboard+i1*size+j1)=='p' && *(chessboard+i2*size+j2)==' '){
            if (i1-2==i2 && j1==j2){
                int v=verif_deplacement_droit(chessboard,i1,i2,j1,j2,joueur);
                if (v==0){
                    *(chessboard+i2*size+j2)='p';
                    *(chessboard+i1*size+j1)=' ';
                }   
            }
        }       
    }
    else{
        printf("coup illegal,reessayez de deplacer une piece\n");
        selection_piece(chessboard, joueur);
    }
}

void deplacement_en_L(char* chessboard,int i1,int i2,int j1,int j2, int joueur,char piece){
    if (i1+2==i2 || i1-2==i2){
        if (j1+1==j2 || j1-1==j2){
            if (piece=='c'||piece== 'o'){
                int v=verif_deplacement_simple(chessboard,i1,i2,j1,j2,joueur);
                if (v==0){
                    *(chessboard+i2*size+j2)=piece;
                    *(chessboard+i1*size+j1)=' ';
                }
            }
            else if (piece=='C'||piece=='O'){
                int v=verif_deplacement_simple(chessboard,i1,i2,j1,j2,joueur);
                if (v==0){
                    *(chessboard+i2*size+j2)=piece;
                    *(chessboard+i1*size+j1)=' ';
                }
            }
        }
    }
    else if (i1+1==i2 || i1-1==i2){
        if (j1+2==j2 || j1-2==j2){
            if (piece=='c'||piece== 'o'){
                int v=verif_deplacement_simple(chessboard,i1,i2,j1,j2,joueur);
                if (v==0){
                    *(chessboard+i2*size+j2)=piece;
                    *(chessboard+i1*size+j1)=' ';
                }
            }
            else if (piece=='C'||piece=='O'){
                int v=verif_deplacement_simple(chessboard,i1,i2,j1,j2,joueur);
                if (v==0){
                    *(chessboard+i2*size+j2)=piece;
                    *(chessboard+i1*size+j1)=' ';
                }
            }
        }
    }
}

int verif_deplacement_simple(char* chessboard,int i1,int i2,int j1,int j2, int joueur){
    char piece[9];
    char piece2[9];
    strcpy(piece,"pktcfqoh");
    strcpy(piece2,"PKTCFQOH");
    if (*(chessboard+i1*size+j1)=='p' ||*(chessboard+i1*size+j1)=='c' ||*(chessboard+i1*size+j1)=='k'||*(chessboard+i1*size+j1)=='o'){
        for (int i=0;i<9;i++){
            if (*(chessboard+i2*size+j2)==piece[i]){
                printf("coup illegal,reessayez de deplacer une piece\n");
                selection_piece(chessboard, joueur);
                return 1;
            }
        }
            
    }
    else if (*(chessboard+i1*size+j1)=='P'||*(chessboard+i1*size+j1)=='C'||*(chessboard+i1*size+j1)=='K'||*(chessboard+i1*size+j1)=='O'){
        for (int i=0;i<9;i++){
            if (*(chessboard+i2*size+j2)==piece2[i]){
                printf("coup illegal,reessayez de deplacer une piece\n");
                selection_piece(chessboard, joueur);
                return 1;
            }
        }
            
    }
    if (i2>10 || j2<0 || j2>11){
        printf("coup illegal,reessayez de deplacer une piece\n");
        selection_piece(chessboard, joueur);
        return 1;
    }
    return 0;
    
}


int verif_deplacement_diagonale(char* chessboard,int i1,int i2,int j1,int j2, int joueur){
    char piece[9];
    char piece2[9];
    strcpy(piece,"pktcfqoh");
    strcpy(piece2,"PKTCFQOH");
    if (i1<i2 && j1<j2){
        if (*(chessboard+i1*size+j1)=='f' || *(chessboard+i1*size+j1)=='q' || *(chessboard+i1*size+j1)=='o' || *(chessboard+i1*size+j1)=='h'){
            while (i1<i2-1 || j1<j2-1){
                if (*(chessboard+(i1+1)*size+(j1+1))!=' '){
                    printf("1coup illegal,reessayez de deplacer une piece\n");
                    selection_piece(chessboard,joueur);
                    return 1;
                }
                i1++;
                j1++;
            }
            for(int i=0;i<9;i++){
                if (*(chessboard+i2*size+j2)==piece[i]){
                    printf("2coup illegal,reessayez de deplacer une piece\n");
                    selection_piece(chessboard,joueur);
                    return 1;
                }
            }
        }
        else if (*(chessboard+i1*size+j1)=='F' || *(chessboard+i1*size+j1)=='Q' || *(chessboard+i1*size+j1)=='O' || *(chessboard+i1*size+j1)=='H'){
            while (i1<i2-1 || j1<j2-1){
                if (*(chessboard+(i1+1)*size+(j1+1))!=' '){
                    printf("3coup illegal,reessayez de deplacer une piece\n");
                    selection_piece(chessboard,joueur);
                    return 1;
                }
                i1++;
                j1++;
            }
            for(int i=0;i<9;i++){
                if (*(chessboard+i2*size+j2)==piece2[i]){
                    printf("4coup illegal,reessayez de deplacer une piece\n");
                    selection_piece(chessboard,joueur);
                    return 1;
                }
            }
        }
    }
    else if (i1<i2 && j1>j2){
        if (*(chessboard+i1*size+j1)=='f' || *(chessboard+i1*size+j1)=='q' || *(chessboard+i1*size+j1)=='o' || *(chessboard+i1*size+j1)=='h'){
            while (i1<i2-1 || j1>j2+1){
                if (*(chessboard+(i1+1)*size+(j1-1))!=' '){
                    printf("5coup illegal,reessayez de deplacer une piece\n");
                    selection_piece(chessboard,joueur);
                    return 1;
                }
                i1++;
                j1--;
            }
            for(int i=0;i<9;i++){
                if (*(chessboard+i2*size+j2)==piece[i]){
                    printf("6coup illegal,reessayez de deplacer une piece\n");
                    selection_piece(chessboard,joueur);
                    return 1;
                }
            }
        }
        else if (*(chessboard+i1*size+j1)=='F' || *(chessboard+i1*size+j1)=='Q' || *(chessboard+i1*size+j1)=='O' ||*(chessboard+i1*size+j1)=='H'){
            while (i1<i2-1 || j1>j2+1){
                if (*(chessboard+(i1+1)*size+(j1-1))!=' '){
                    printf("7coup illegal,reessayez de deplacer une piece\n");
                    selection_piece(chessboard,joueur);
                    return 1;
                }
                i1++;
                j1--;
            }
            for(int i=0;i<9;i++){
                if (*(chessboard+i2*size+j2)==piece2[i]){
                    printf("8coup illegal,reessayez de deplacer une piece\n");
                    selection_piece(chessboard,joueur);
                    return 1;
                }
            }
        }
    }
    else if (i1>i2 && j1>j2){
        if (*(chessboard+i1*size+j1)=='f' || *(chessboard+i1*size+j1)=='q' || *(chessboard+i1*size+j1)=='o'|| *(chessboard+i1*size+j1)=='h'){
            while (i1>i2+1|| j1>j2+1){
                if (*(chessboard+(i1-1)*size+(j1-1))!=' '){
                    printf("9coup illegal,reessayez de deplacer une piece\n");
                    selection_piece(chessboard,joueur);
                    return 1;
                }
                i1--;
                j1--;
            }
            for(int i=0;i<9;i++){
                if (*(chessboard+i2*size+j2)==piece[i]){
                    printf("10coup illegal,reessayez de deplacer une piece\n");
                    selection_piece(chessboard,joueur);
                    return 1;
                }
            }
        }
        else if (*(chessboard+i1*size+j1)=='F' || *(chessboard+i1*size+j1)=='Q' || *(chessboard+i1*size+j1)=='O' ||*(chessboard+i1*size+j1)=='H'){
            while (i1>i2+1 || j1>j2+1){
                if (*(chessboard+(i1-1)*size+(j1-1))!=' '){
                    printf("11coup illegal,reessayez de deplacer une piece\n");
                    selection_piece(chessboard,joueur);
                    return 1;
                }
                i1--;
                j1--;
            }
            for(int i=0;i<9;i++){
                if (*(chessboard+i2*size+j2)==piece2[i]){
                    printf("sizecoup illegal,reessayez de deplacer une piece\n");
                    selection_piece(chessboard,joueur);
                    return 1;
                }
            }
        }
    }
    else if (i1>i2 && j1<j2){
        if (*(chessboard+i1*size+j1)=='f' || *(chessboard+i1*size+j1)=='q' || *(chessboard+i1*size+j1)=='o'|| *(chessboard+i1*size+j1)=='h'){
            while (i1>i2+1 || j1<j2-1){
                if (*(chessboard+(i1-1)*size+(j1+1))!=' '){
                    printf("13coup illegal,reessayez de deplacer une piece\n");
                    selection_piece(chessboard,joueur);
                    return 1;
                }
                i1--;
                j1++;
            }
            for(int i=0;i<9;i++){
                if (*(chessboard+i2*size+j2)==piece[i]){
                    printf("14coup illegal,reessayez de deplacer une piece\n");
                    selection_piece(chessboard,joueur);
                    return 1;
                }
            }
        }
        else if (*(chessboard+i1*size+j1)=='F' || *(chessboard+i1*size+j1)=='Q' || *(chessboard+i1*size+j1)=='O' ||*(chessboard+i1*size+j1)=='H'){
            while (i1>i2+1 || j1<j2-1){
                if (*(chessboard+(i1-1)*size+(j1+1))!=' '){
                    printf("15coup illegal,reessayez de deplacer une piece\n");
                    selection_piece(chessboard,joueur);
                    return 1;
                }
                i1--;
                j1++;
            }
            for(int i=0;i<9;i++){
                if (*(chessboard+i2*size+j2)==piece2[i]){
                    printf("16coup illegal,reessayez de deplacer une piece\n");
                    selection_piece(chessboard,joueur);
                    return 1;
                }
            }
        }
    }
    if (i2<0 || i2>10 || j2<0 || j2>11){
        printf("20coup illegal,reessayez de deplacer une piece\n");
        selection_piece(chessboard, joueur);
        return 1;
    }
    return 0;
}

int verif_deplacement_droit(char* chessboard,int i1,int i2,int j1,int j2, int joueur){
    char piece[9];
    char piece2[9];
    strcpy(piece,"pktcfqoh");
    strcpy(piece2,"PKTCFQOH");
    if (i2>i1){
        if(*(chessboard+i1*size+j1)=='t' || *(chessboard+i1*size+j1)=='q' || *(chessboard+i1*size+j1)=='h'){
            for (int i=i1+1;i<i2;i++){
                for (int i0=0;i0<9;i0++){
                    if (*(chessboard+i*size+j1)==piece[i0] || *(chessboard+i*size+j1)==piece2[i0]){
                        printf("coup illegal,reessayez de deplacer une piece\n");
                        selection_piece(chessboard, joueur);
                        return 1;
                    }
                }
            }
            for (int i=0;i<9;i++){
                if (*(chessboard+i2*size+j2)==piece[i]){
                   printf("coup illegal,reessayez de deplacer une piece\n");
                   selection_piece(chessboard, joueur);
                   return 1;
                }
            }
        }
        else if(*(chessboard+i1*size+j1)=='T' || *(chessboard+i1*size+j1)=='Q' || *(chessboard+i1*size+j1)=='H'){
            for (int i=i1+1;i<i2;i++){
                for (int i0=0;i0<9;i0++){
                    if (*(chessboard+i*size+j1)==piece[i0] || *(chessboard+i*size+j1)==piece2[i0]){
                        printf("coup illegal,reessayez de deplacer une piece\n");
                        selection_piece(chessboard, joueur);
                        return 1;
                    }
                }
            }
            for (int i=0;i<9;i++){
                if (*(chessboard+i2*size+j2)==piece2[i]){
                    printf("coup illegal,reessayez de deplacer une piece\n");
                    selection_piece(chessboard, joueur);
                    return 1;
                }
            }
        }
    }
    if (j2>j1){
        if(*(chessboard+i1*size+j1)=='t'|| *(chessboard+i1*size+j1)=='q' || *(chessboard+i1*size+j1)=='h'){
            for (int j=j1+1;j<j2;j++){
                for (int i0=0;i0<9;i0++){
                    if (*(chessboard+i1*size+j)==piece[i0] || *(chessboard+i1*size+j)==piece2[i0]){
                        printf("coup illegal,reessayez de deplacer une piece\n");
                        selection_piece(chessboard, joueur);
                        return 1;
                    }
                }
            }
            for (int i=0;i<9;i++){
                if (*(chessboard+i2*size+j2)==piece[i]){
                    printf("coup illegal,reessayez de deplacer une piece\n");
                    selection_piece(chessboard, joueur);
                    return 1;
                }
            }
        }
        else if(*(chessboard+i1*size+j1)=='T' || *(chessboard+i1*size+j1)=='Q' || *(chessboard+i1*size+j1)=='H'){
            for (int j=j1+1;j<j2;j++){
                for (int i0=0;i0<9;i0++){
                    if (*(chessboard+i1*size+j)==piece[i0] || *(chessboard+i1*size+j)==piece2[i0]){
                        printf("coup illegal,reessayez de deplacer une piece\n");
                        selection_piece(chessboard, joueur);
                        return 1;
                    }
                }
            }
            for (int i=0;i<9;i++){
                if (*(chessboard+i2*size+j2)==piece2[i]){
                    printf("coup illegal,reessayez de deplacer une piece\n");
                    selection_piece(chessboard, joueur);
                    return 1;
                }
            }
        }
    }
    if (i2<i1){
        if(*(chessboard+i1*size+j1)=='t' || *(chessboard+i1*size+j1)=='q' || *(chessboard+i1*size+j1)=='h'){
            for (int i=i1-1;i>i2;i--){
                for (int i0=0;i0<9;i0++){
                    if (*(chessboard+i*size+j1)==piece[i0] || *(chessboard+i*size+j1)==piece2[i0]){
                        printf("coup illegal,reessayez de deplacer une piece\n");
                        selection_piece(chessboard, joueur);
                        return 1;
                    }
                }
            }
            for (int i=0;i<9;i++){
                if (*(chessboard+i2*size+j2)==piece[i]){
                   printf("coup illegal,reessayez de deplacer une piece\n");
                   selection_piece(chessboard, joueur);
                   return 1;
                }
            }
        }
        else if(*(chessboard+i1*size+j1)=='T' || *(chessboard+i1*size+j1)=='Q' || *(chessboard+i1*size+j1)=='H'){
            for (int i=i1-1;i>i2;i--){
                for (int i0=0;i0<9;i0++){
                    if (*(chessboard+i*size+j1)==piece[i0] || *(chessboard+i*size+j1)==piece2[i0]){
                        printf("coup illegal,reessayez de deplacer une piece\n");
                        selection_piece(chessboard, joueur);
                        return 1;
                    }
                }
            }
            for (int i=0;i<9;i++){
                if (*(chessboard+i2*size+j2)==piece2[i]){
                    printf("coup illegal,reessayez de deplacer une piece\n");
                    selection_piece(chessboard, joueur);
                    return 1;
                }
            }
        }
    }
    if (j2<j1){
        if(*(chessboard+i1*size+j1)=='t' || *(chessboard+i1*size+j1)=='q' || *(chessboard+i1*size+j1)=='h'){
            for (int j=j1-1;j>j2;j--){
                for (int i0=0;i0<9;i0++){
                    if (*(chessboard+i1*size+j)==piece[i0] || *(chessboard+i1*size+j)==piece2[i0]){
                        printf("coup illegal,reessayez de deplacer une piece\n");
                        selection_piece(chessboard, joueur);
                        return 1;
                    }
                }
            }
            for (int i=0;i<9;i++){
                if (*(chessboard+i2*size+j2)==piece[i]){
                    printf("coup illegal,reessayez de deplacer une piece\n");
                    selection_piece(chessboard, joueur);
                    return 1;
                }
            }
        }
        else if(*(chessboard+i1*size+j1)=='T' || *(chessboard+i1*size+j1)=='Q' || *(chessboard+i1*size+j1)=='H'){
            for (int j=j1-1;j>j2;j--){
                for (int i0=0;i0<9;i0++){
                    if (*(chessboard+i1*size+j)==piece[i0] || *(chessboard+i1*size+j)==piece2[i0]){
                        printf("coup illegal,reessayez de deplacer une piece\n");
                        selection_piece(chessboard, joueur);
                        return 1;
                    }
                }
            }
            for (int i=0;i<9;i++){
                if (*(chessboard+i2*size+j2)==piece2[i]){
                    printf("coup illegal,reessayez de deplacer une piece\n");
                    selection_piece(chessboard, joueur);
                    return 1;
                }
            }
        }
    }
    if (i2>10 || j2>11 || j2<0){
        printf("coup illegal,reessayez de deplacer une piece\n");
        selection_piece(chessboard, joueur);
        return 1;
    }
    return 0;
    
}


void promotion_pion(char* chessboard,char i2,char j2){
    if (*(chessboard+i2*size+j2)=='p'){
        if (i2==0){
            char np;
            printf("promotion pion : voulez vous que votre pion devient un fou,une tour,un cavalier ou une reine ?\n");
            scanf("\n%c",&np);
            np = tolower(np);
            *(chessboard+i2*size+j2)=np;
        }
    }
    
    if (*(chessboard+i2*size+j2)=='P'){
        char np;
        if (i2==10){
            char np;
            printf("promotion pion : voulez vous que votre pion devient un fou,une tour,un cavalier ou une reine ?\n");
            scanf("\n%c",&np);
            np = toupper(np);
            *(chessboard+i2*size+j2)=np;
        }
    }
}

void selection_piece(char* chessboard, int joueur){
    int i_debut,i_fin,j_debut,j_fin;
    char jdeb, jfin;
    int verif;

    printf("indiquez la colonne de la piece a deplacer\n");
    scanf("\n%c",&jdeb);
    do{
    printf("indiquez la ligne de la piece a deplacer\n");
    verif = scanf("\n%d",&i_debut);
    vide_buffer1();
    }while(verif!=1 || i_debut >11 || i_debut<1);
    printf("indiquez la colonne de la nouvelle position\n");
    scanf("\n%c",&jfin);
    do{
    printf("indiquez la ligne de la nouvelle position\n");
    verif = scanf("\n%d",&i_fin);
    vide_buffer1();
    }while(verif!=1 || i_fin> 11 || i_fin<1);


    j_debut =emplacement(jdeb);
    j_fin = emplacement(jfin);

    i_debut = 11 - i_debut;
    i_fin = 11 - i_fin;

    if (*(chessboard+i_debut*size+j_debut)== tolower(*(chessboard+i_debut*size+j_debut)) && joueur == 0 || *(chessboard+i_debut*size+j_debut)== toupper(*(chessboard+i_debut*size+j_debut)) && joueur == 1){    

    if (*(chessboard+i_debut*size+j_debut)=='p' || *(chessboard+i_debut*size+j_debut)=='P'){
        pion(chessboard,i_debut,i_fin,j_debut,j_fin,joueur);
    }
    else if (*(chessboard+i_debut*size+j_debut)=='c'|| *(chessboard+i_debut*size+j_debut)=='C'){
        cavalier(chessboard,i_debut,i_fin,j_debut,j_fin,joueur);
    }
    else if (*(chessboard+i_debut*size+j_debut)=='t'|| *(chessboard+i_debut*size+j_debut)=='T'){
        tour(chessboard,i_debut,i_fin,j_debut,j_fin,joueur);
    }
    else if (*(chessboard+i_debut*size+j_debut)=='k'|| *(chessboard+i_debut*size+j_debut)=='K'){
        roi(chessboard,i_debut,i_fin,j_debut,j_fin,joueur);
        
    }
    else if (*(chessboard+i_debut*size+j_debut)=='q'|| *(chessboard+i_debut*size+j_debut)=='Q'){
        reine(chessboard,i_debut,i_fin,j_debut,j_fin,joueur);
    }
    else if (*(chessboard+i_debut*size+j_debut)=='f'|| *(chessboard+i_debut*size+j_debut)=='F'){
        fou(chessboard,i_debut,i_fin,j_debut,j_fin,joueur);
    }
    else if (*(chessboard+i_debut*size+j_debut)=='o'|| *(chessboard+i_debut*size+j_debut)=='O'){
        cavalier_fou(chessboard,i_debut,i_fin,j_debut,j_fin,joueur);
    }
    else if (*(chessboard+i_debut*size+j_debut)=='h'|| *(chessboard+i_debut*size+j_debut)=='H'){
        prince(chessboard,i_debut,i_fin,j_debut,j_fin,joueur);
    }
    else{
        printf("il n'y a pas de piece ici\n\n");
        selection_piece(chessboard, joueur);
    }
    }
    else{
        printf("Vous n'avez pas selectionne votre piece\n\n");
        selection_piece(chessboard, joueur);
    }
}

int fin_de_partie(char* chessboard){
    int king1=0;
    int king2=0;
    int fin=0;
    for (int i = 0; i<size-1; i++){
        for (int j = 1;j<size; j++){
            if (*(chessboard+j+i*size)=='k'){
                king1=1;
            }
        
            if (*(chessboard+j+i*size)=='K'){
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