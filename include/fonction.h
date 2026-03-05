
#ifndef FONCTION_H
#define FONCTION_H

#include <stdio.h>
#include <stdlib.h>

#define False 0
#define True 1

/*initialisation de mes fonctions*/
int coup_possible(int g[6][7], int colonne); 
void jouer(int g[6][7], int j, int colonne);
int verticale(int g[6][7], int j, int ligne, int colonne2); 
int horizontale(int g[6][7], int j, int ligne, int colonne2); 
int diagonale(int g[6][7], int j, int ligne, int colonne2); 
int victoire(int g[6][7], int j);
int match_nul(int g[6][7]); 

#endif
