/* déclaration de fonctionnalités supplémentaires */
#include <stdio.h>
#include <stdlib.h>

#include "fonction.h" /*fichier avec les fonction défini*/


/* declaration constantes et types utilisateurs */
#define False 0
#define True 1

/* définitions des fonctions utilisateurs */


/*fonction n_1 :coup_possible,vérifie la possibilité des coups  */

int coup_possible(int g[6][7],int colonne) {
    if(colonne<0 || colonne>=7) { /*delimiter ma grille pour pas sortir*/
      return False;  /*selection de colonne invalide*/
    }
    if (g[0][colonne] !=0) { /*en cas de colonne pleine*/
      return False;  /*selection de colonne invalide*/
    }
    return True;
}

/*fonction n_2 :jouer,placer le jeton dans la bonne colonne */

void jouer(int g[6][7], int j, int colonne) {
    for (int i=5;i>=0;i--) { /*pour ne pas rentrer en conflie avec casse plein*/
        if (g[i][colonne]==0) {
            g[i][colonne]=j;  
            break; /*sinon va renvoyer le coup jouer a l'infini sur la colonne*/
        }
    }
}

/*fonction n_3 :verticale,sert a savoir si un joueur a réussi a mettre 4 jeton verticalement et gagné*/

int verticale(int g[6][7],int j,int ligne,int colonne2) {
    int cpt=1; /*initialisation du compteur de jeton a la verticale*/
    for (int i=1;i<4;i++) { /*regarde a la verticale pour la boucle suivante*/
        if (ligne + i<6 && g[ligne + i][colonne2] == j) { /*verifie si il ne dépasse pas la grille et si le jeton est celui du bon joueur compter*/
            cpt++; /*incrémentation d'un jeton si il est a la verticale(et du meme joueur)*/
        } 
        else {
            break;
        }
    }
    return cpt==4; /*renvoie 4 jeton verticale qui servira a une autre fonction pour gagné*/
}

/*fonction n_4 :horizontale,sert a savoir si un joueur a réussi a mettre 4 jeton horizontalement et gagné*/
int horizontale(int g[6][7],int j,int ligne,int colonne2) {
    int cpt = 1;/*initialisation du compteur de jeton a la horizontalement*/
    for (int i=1;i<4;i++) { /*regarde a l'horizontale pour la boucle suivante*/
        if (colonne2 + i< 7 && g[ligne][colonne2 + i] == j) { /*verifie si il ne dépasse pas la grille et si le jeton est celui du bon joueur compter*/
            cpt++; /*incrémentation d'un jeton si il est a la horizontale(et du meme joueur)*/
        } 
        else {
            break;
        }
    }
    return cpt == 4; /*renvoie 4 jeton horizontale qui servira a une autre fonction pour gagné*/
}

/*fonction n_5 :diagonale,sert a savoir si un joueur a réussi a mettre 4 jeton sur la diagonale et gagne*/
int diagonale(int g[6][7], int j, int ligne, int colonne2) {
    int cpt=1; /*initialisation du compteur de jeton a la diagonale*/
    /*verifie la diagonale en commençant par le haut gauche jusqu'en bas droite */
    for (int i=1;i<4;i++) { 
        if (ligne + i< 6 && colonne2 + i< 7 && g[ligne + i][colonne2 + i] == j) { /*verifie si il ne dépasse pas la grille et si le jeton est celui du bon joueur compter*/
            cpt++; /*incrémentation d'un jeton si il est a la diagonale(et du meme joueur)*/
        } 
        else {
            break;
        }
    }
    if (cpt==4){ /*renvoie 4 jeton diagonale qui servira a une autre fonction pour gagné*/
       return True;
    } 

    cpt=1; /*initialisation du compteur de jeton a la diagonale*/
    /*verifie la diagonale en commençant par le bas gauche jusqu'en haut droite */
    for (int i=1;i<4;i++) {
        if (ligne - i >= 0 && colonne2 + i < 7 && g[ligne - i][colonne2 + i] == j) { /*verifie si il ne dépasse pas la grille et si le jeton est celui du bon joueur compter*/
            cpt++; /*incrémentation d'un jeton si il est a la diagonale(et du meme joueur)*/
        } 
        else {
            break;
        }
    }
    return cpt==4; /*renvoie 4 jeton diagonale qui servira a une autre fonction pour gagné*/
}

/*fonction n_6 :victoire,sert a savoir si un joueur a réussi a gagné la partie dans tout les situation sauf match nul*/
int victoire(int g[6][7],int j) {
    for(int i=0;i<6;i++) { /*première boucle parcourant chaque ligne une par une*/
        for (int b=0;b<7;b++) { /*deuxième boucle parcourant chaque colonne une par une*/
            if (g[i][b]==j) { /*condition sur la réussite dans la grille,victoire definie par la boucle suivant*/
                if (verticale(g,j,i,b) || horizontale(g,j,i,b) || diagonale(g,j,i,b)) { /* chaque fonction qui définie chaque facon de gagner le jeu */
                    return True;
                }
            }
        }
    }
    return False;
}


/*fonction n_7:match_nul,sert a vérifier si tout les case sont remplie et qu'aucun joueur n'est déclarer (alors match nul) */
int match_nul(int g[6][7]) { 
    for (int i=0;i<6;i++) { /*première boucle parcourant chaque ligne une par une*/
        for (int b=0;b<7;b++) { /*deuxième boucle parcourant chaque colonne une par une*/
            if (g[i][b]==0) { /*si la colonne est non remplie alors continuer le jeu*/
                return False;  
            }
        }
    }
    return True;  /*si tout les condition remplie renvoie true signifiant un match nul*/
}

