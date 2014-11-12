/**
 * \file tableau.c
 * \brief Fonctions permettant de manipuler un tableau représentant un index des mots d'un texte
 * ainsi que leur fréquence dans ce dernier.
 * \author Yann Feunteun
 * \version 0.1
 * \date 19 Septembre 2014
 *
 */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <limits.h>
#include "tableau.h"


int remplir(Information* dico, int taille, FILE* flux)
{
   char buffer[512];
   int index_insertion = -1;

   if(taille >= TAILLE_MAX) {
       fprintf(stderr, "Taille max du tableau atteinte !\n");
       exit(EXIT_FAILURE);
   }

    while (lireMot(flux, &buffer[0])) {
        index_insertion = existe(dico, taille, buffer);
        if(index_insertion == -1) /* le mot n'est pas présent dans le tableau */
        {
            dico[taille].mot = (char *)malloc(strlen(buffer) + 1 * sizeof(char));
            if(dico[taille].mot == NULL){
                fprintf(stderr, "Impossible d'allouer la mémoire nécessaire\n");
                exit(EXIT_FAILURE);
            }
            strcpy(dico[taille].mot, buffer);
            dico[taille].nbOcc = 1;
            ++taille;
            if(taille >= TAILLE_MAX) {
                fprintf(stderr, "Taille max du tableau atteinte !\n");
                exit(EXIT_FAILURE);
            }

        } else {                    /* Le mot est déjà présent dans le tableau */
            ++dico[index_insertion].nbOcc;
        }
    }

    return taille;
}

void afficher(Information* dico, int taille)
{
    int i = 0;
    for(i = 0; i < taille; ++i){
        printf("%s => %d\n", dico[i].mot, dico[i].nbOcc);
    }
}

int existe(Information* dico, int taille, char* mot)
{
    int i = 0;
    for(i = 0; i < taille; ++i){
        if(strcmp(mot, dico[i].mot) == 0) {
            return i;
        }
    }

    return -1;
}

int lireMot(FILE * fp, char * mot) {
   int i;
   char c;
   while ( ! (isalpha (c = fgetc(fp)))) {
      if  (c == EOF) {
         mot[0] = '\0';
         return 0;
      }
   }
   mot[0] = c & 0xdf;
   i = 1;
   while ( isalpha (c = fgetc(fp))) {
      mot[i] = c & 0xdf;
      i++;
   }
   mot[i] = '\0';
   return 1;
}
