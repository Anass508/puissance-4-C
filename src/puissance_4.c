#include "fonction.h"

/* déclaration de fonctionnalités supplémentaires */
#include <stdio.h>
#include <stdlib.h>

/* fonction principale */
int main() {
    /*initialiser une matrice qui sera la grille du puissance 4 */
    /*grille de 6 ligne pour 7 colonne*/
    int g[6][7] = {
        {0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0}
    };

    int j=1; /*initialisation du premier joueur */

    /*première boucle d'instruction de base */
    /*va servir a demander au joueur et lancer le jeu*/
    while (!(victoire(g, 1)) && !(victoire(g, 2)) && !match_nul(g)) {
        int colonne;
        printf("C'est a vous de jouer joueur  : %d\n ", j); /*dit quelle joueur doit jouer ce tour*/
        printf("Quelle colonne voulez vous jouer ? (entre 0 et 6) : "); /*demande au joueur le coup jouer*/
        scanf("%d", &colonne); /*stockent le coup jouer qui est la colonne*/
        while (!coup_possible(g, colonne)){ /*pour ne pas changer de joueur si le coup est invalide*/
          printf("Impossible de jouer dans cette colonne!!!!\n"); 
          printf("Quelle colonne voulez-vous jouer ? (entre 0 et 6) : "); 
          scanf("%d", &colonne); 
        } /* si le coup possible alors jouer le jeton*/ 
        jouer(g, j, colonne);
      
        /*parcoure ma grille pour l'actualiser et l'afficher a chaque tour*/
        for(int i=0;i<6;i++) {
            printf(" ");
            for(int li=0;li<7;li++) {
                printf(" ");
                printf("%d",g[i][li]);
            }
            printf("\n");
        }
       
       /*afficher le numéro de la colonnes correspondante  */
        printf("  _____________ \n"); /*délimiter la grille au numéro */
        printf("  ");/*cadrer les numéros de colonnes*/
        for(int li=0;li<7;li++){ /*boucle qui va donner le numéro de la colonne*/
          printf("%d",li);
          printf(" ");/*cadrer les numéros de colonnes*/
        }
        printf("\n");
        
        

        /*changement de joueur après le que le coup soit jouer */
        if (j==1) {
            j=2;
        } 
        else {
            j=1;
        }
    }

    /*résultat d'une partie fini*/
    if (victoire(g, 1)) {
        printf("Félicitations Joueur 1, vous avez gagné !\n"); /*affichage en cas de victoire d'une joueur*/
    } 
    else if (victoire(g, 2)) {
        printf("Félicitations Joueur 2, vous avez gagné !\n"); /*affichage en cas de victoire d'une joueur*/
    } 
    else {
        printf("C'est un match nul.\n"); /*affichage en cas de match nul */
    }
    
    /*renvoie 4 jeton horizontale qui servira a une autre fonction pour gagné*/
    /* valeur fonction */
    return EXIT_SUCCESS;
}





