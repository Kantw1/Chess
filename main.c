#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include "chessboard.h"
#include "tableau.h"
#include <windows.h>
#include <ctype.h>

#define size 12

int main(){
  
/*[lignes][colonnes]*/
char chessboard[size][size];

build(chessboard);

/*affichetab(chessboard);*/



choosepiece(chessboard);
printchess(chessboard);

    /*HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN);
    printf("creme\n");
    SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
    */

getch();


    return 0;
}