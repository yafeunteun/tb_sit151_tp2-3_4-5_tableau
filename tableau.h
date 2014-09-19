#ifndef TABLEAU_H
#define TABLEAU_H

#include <stdio.h>
#define TAILLE_MAX 100000

typedef struct  {
    char *mot;
    int nbOcc;
}Information;


/** Remplir la structure avec les mots du fichier correspondant à flux.
 * Le remplissage se fait à partir de index_insertion sous réserve qu'il reste suffisamment de place.
 * Retourne la nouvelle taille logique du tableau.
 * */
int remplir(Information* dico, int taille, FILE* flux);

/** Afficher le contenu de la structure sous la forme d'un duet <mot => nombre d'occurence>.
 **/
void afficher(Information* dico, int taille);

/** Tester si le mot mot est présent ou non dans la structure.
 * Si oui, la fonction retourne l'indice du mot dans le tableau et -1 sinon.
 * */
int existe(Information* dico, int taille, char* mot);

/** Lit un mot dans fp et remplit le tableau mot.
 * Retourne 1 si un mot a été lu, 0 sinon.
 * */
int lireMot(FILE * fp, char * mot);


#endif // TABLEAU_H
