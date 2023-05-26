#include <stdio.h>
#include <stdlib.h>

int getche(){
   #ifdef _WIN32 // Pour les systèmes Windows
    #include <conio.h>
    getch();
#elif __linux__ // Pour les systèmes Linux

initscr(); // Initialise l'environnement ncurses
    #include <ncurses.h>
    cbreak(); // Désactive la mise en mémoire tampon de ligne
    noecho(); // Désactive l'affichage automatique des entrées

    int ch = getch(); // Attend une saisie de l'utilisateur

    endwin(); // Restaure l'environnement du terminal

#elif __APPLE__ // Pour les systèmes macOS
#else
    // Système d'exploitation non pris en charge
    printf("Impossible d'afficher la console en plein écran sur ce système d'exploitation.\n");
#endif
}