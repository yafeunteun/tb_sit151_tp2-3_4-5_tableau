/**
 * \file tableau.h
 * \brief Header du fichier tableau.c
 * \author Yann Feunteun
 * \version 0.1
 * \date 19 Septembre 2014
 *
 */

#ifndef TABLEAU_H
#define TABLEAU_H

#include <stdio.h>
#define TAILLE_MAX 100000 /*!< Taille physique maximale du tableau */


/**
 * \struct Information
 * \brief Objet Information
 *
 * Information est un petit objet de gestion de duet mot-nombre d'occurence du mot dans un texte.
 */
typedef struct  {
    char *mot;
    int nbOcc;
}Information;



/**
 * \fn Information *remplir(Information* dico, FILE* flux)
 * \brief Remplir la structure avec les mots du fichier correspondant à flux.
 * \param dico Un pointeur sur l'index à remplir.
 * \param taille La taille logique du tableau càd le nombre d'éléments du tableau.
 * \param flux Un flux de données comprenant les mots à ajouter à l'index.
 * \return La nouvelle taille logique du tableau.
 * */
int remplir(Information* dico, int taille, FILE* flux);


/**
 * \fn void afficher(Information* dico)
 * \brief Afficher le contenu de la structure sous la forme d'un duet <mot => nombre d'occurence>.
 * \param dico Un pointeur sur l'index à afficher.
 * \param taille La taille logique de l'index.
 **/
void afficher(Information* dico, int taille);


/**
 * \fn Information* existe(Information* dico, char* mot)
 * \brief Tester si le mot mot est présent ou non dans la structure.
 * \param dico Un pointeur sur l'index à afficher.
 * \param taille La taille logique de l'index.
 * \param mot Le le mot recherché.
 * \return L'indice de l'élément de la structure contenant le mot recherché
 * ou -1 si le mot n'est pas encore dans la structure.
 * */
int existe(Information* dico, int taille, char* mot);


/**
 * \fn int lireMot(FILE * fp, char * mot)
 * \brief Lit un mot dans flux de données et remplit le tableau mot.
 * La chaine est convertie en majuscule.
 * \param fp Un flux de données comprenant les mots à lire.
 * \param mot Une chaine de caractères qui sera ramplie avec le mot lu.
 * \return Retourne 1 si un mot a été lu, 0 sinon.
 * */
int lireMot(FILE * fp, char * mot);


#endif // TABLEAU_H
