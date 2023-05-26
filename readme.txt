Fiche ReadMe Fourrier Quentin Robard Baptiste Crazy Chess
Cette fiche a pour but de présenter le jeu Crazy Chess, créé par Quentin Fourrier et Baptiste Robard, élèves en MEFG02.
Principes du jeu :
Tout d’abord, Crazy Chess est un jeu d’échec jouable en 1 contre 1, codé en langage C avec des règles un peu particulières, tout en suivant quelques normes du jeu d’échec classique.
Le jeu se présente sous un échiquier de 11x11. Le début de partie est assez spéciale, les joueurs doivent acheter des pièces qui ont un certain coût. Chaque joueur commence avec un total de 40 points, qu’ils utiliseront pour acheter leurs pièces. Les pièces disponibles sont les pièces classiques du jeu d’échec mais également des nouvelles pièces propre à CRAZY CHESS. Les placements des pions et du roi sont imposés alors que les emplacements de départ des autres pièces sont choisis par les joueurs tant qu’elles restent dans la zone d’achat. Une fois les deux joueurs prêts, la partie commence et se jouera de façon normal, jusqu’à qu’un des deux rois présents sur l’échiquier soit mangé par une pièce adverse. Le joueur ayant perdu son roi a perdu. Fonctionnement en C :
Afin que le jeu marche sans aucun problème, le jeu est codé à l’aide de plusieurs fonctions et fonctionnalités en langage C permettant un bon déroulement sans bug généré. Voici une liste d’explication des principales fonctions du jeu :
- main.c : Fonction principale du jeu qui représente « la ligne continue » du déroulement de la partie, allant de l’affichage du logo du jeu et de ses règles, jusqu’à la proposition de sauvegarde de la partie ou l’annonce de la fin de la partie si la partie a été gagné par l’un des deux joueurs. Elle fait appel à plusieurs fonctions crées dans les autres fichiers de l’espace GitHub.
- moves.c : Fichier C global des mouvements de déplacement de chaque pièce. Elle regroupe donc les fonctions de toutes les pièces ainsi que la fonction de sélection de la pièce a déplacé durant le tour d’un des joueurs. C’est le fichier le plus volumineux du projet et aussi par principe le plus important car celui-ci permet le déplacement des pièces.
- tableau.c : Fonctions permettant la création de l’échiquier et le placement des pièces imposées (pions et rois) au début de la partie.
- solde.c : Fonctions utilisées durant la période d’achat des pièces, permettant son bon déroulement, le bon placement de chaque pièce, et la suivie du solde de points d’achat de chaque joueur.
- chessboard.c : Fonctions qui permettent l’affichage du tableau en continue.
- save.c : Fichier regroupant les différentes fonctions de sauvegarde de la partie si un des deux
joueurs le souhaite.
- echec.c : Fonction générant un message d’erreur « échec de départ » si une des pièces durant
la phase d’achat mettait en échec le roi adverse.
Lancement du jeu :
Une fois les bibliothèques nécessaires installées, il suffit simplement de lancer le fichier exécutable chess.exe et le jeu se lancera normalement.

