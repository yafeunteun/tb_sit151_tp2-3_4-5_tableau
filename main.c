#include <stdio.h>
#include <stdio.h>
#include <stdlib.h>
#include "tableau.h"

int main(int argc, char* argv[])
{

    FILE *fp;
    int taille = 0;
    Information dico[TAILLE_MAX];

    if (argc < 2)
       return EXIT_FAILURE;

    if ((fp = fopen(argv[1], "r")) == NULL) {
       printf("\n Pb d'ouverture du fichier %s \n", argv[1]);
       return EXIT_FAILURE;
    }

    taille = remplir(dico, taille, fp);
    afficher(dico, taille);

    return EXIT_SUCCESS;
}

