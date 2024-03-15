#ifndef LIST_OPERATIONS_H
#define LIST_OPERATIONS_H

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <errno.h>

typedef struct maillon {
    int val;
    struct maillon* p_suiv;
} maillon_int;


maillon_int* init_elt();
void ajout_tete_v2(maillon_int** p_p_tete, maillon_int* p_nv_elt);
void parcourir(maillon_int* p_tete);
void inserer2(maillon_int** prem, maillon_int* e);
void supprimer_debut(maillon_int** prem);
void critere_supp_un2(maillon_int** prem, int val);
void detruire_liste2(maillon_int** prem);
void sauver_liste(maillon_int* prem);
maillon_int* load_liste();

#endif
