/**
* @Description: pile.c
* @Author: Anthony Menghi alias @antocreadev - contact@antocrea.dev
* @Created: 2024-04-05
*/

/* Inclusion des librairies ========== */
#include <stdio.h>
#include <stdlib.h>
#include "include/pile.h"

/* Macros et constantes ============== */
/* Variables globales ================ */
Element *sommet = NULL;
/* Déclaration des prototypes ======== */
/* Fonction principale =============== */
int main() {

    // Pour l'implémenation d'une pile, j'ai choisi d'utiliser une liste chainée.
    // En effet, une liste chainée est une structure de données dynamique qui permet d'ajouter et de supprimer des éléments en temps constant. De plus il est facile d'ajouter ou de supprimer un élément en tête de liste. Et avec une liste chaînée, la gestion de la mémoire est simplifiée car les nœuds de la liste sont alloués individuellement au besoin. Cela évite les problèmes liés à l'allocation statique de mémoire ou à la nécessité de redimensionner un tableau dynamique. Juste milieu sur la complexité d'implémentation légèrement plus complexe à mettre en œuvre qu'un tableau statique, une liste chaînée reste relativement simple à coder, les opérations d'ajout et de suppression sont simples à mettre en œuvre avec les pointeurs.

    si_vide(sommet) ? printf("le sommet est null \n") : printf("le sommet n'est pas null \n");

    empiler(&sommet, 5);
    empiler(&sommet, 10);
    empiler(&sommet, 15);

    si_vide(sommet) ? printf("le sommet est null \n") : printf("le sommet n'est pas null \n");
    recuperer_valeur_sommet(sommet);
    afficher(sommet);
    depile(&sommet);
    afficher(sommet);
    empiler(&sommet, 15);
    afficher(sommet);
    depile(&sommet);
    empiler(&sommet, 15);
    afficher(sommet);
    printf("--------\n");
    inverse_pile(&sommet);
    printf("--------\n");
    afficher(sommet);

    return 0;
}

/* Fonctions secondaires ============= */

int si_vide(Element *p_sommet) {
    return p_sommet == NULL;
}

void empiler(Element **p_sommet, int valeur) {

    // p_sommet aura comme valeur l'adresse du somment donc poura utiliser l'opérateur de deferencement pour changer sa valeur 
    Element *new_element = malloc(sizeof(Element));
    if (new_element == NULL) {
        printf("Erreur : impossible d'allouer de la mémoire\n");
        exit(EXIT_FAILURE);
    }
    new_element->data = valeur;
    new_element->next = *p_sommet;
    *p_sommet = new_element;
}

void afficher(Element *p_sommet) {
    while (p_sommet != NULL) {
        printf("%d ", p_sommet->data);
        p_sommet = p_sommet->next;
    }
    printf("\n");
}

int recuperer_valeur_sommet(Element* p_sommet){
    printf("Contenu de la pile : ");
    printf("Le sommet à pour valeur : %d \nIl a pour suivant l'adresse : %p \nLe suivant à pour valeur : %d \n",p_sommet->data, p_sommet->next, *(p_sommet->next) );
    return p_sommet->data;
}

int depile(Element** p_sommet){
    int data = (*p_sommet)->data;
    Element* next = (*p_sommet)->next;
    free(*p_sommet);
    *p_sommet = next;

    return data;
}

void inverse_pile(Element** p_sommet){
    // on va récupérer la longueur de la pile, on créer un pointeur temporaire pour le modifier car on aura de sa valeur et de le modifier pour depiler toute la pile
    Element *p_tempo = * p_sommet;
    int taille = 0;
     while (p_tempo != NULL) {
        taille++;
        p_tempo = p_tempo->next;
    }
    printf("taille de la pile : %d\n", taille);

    // on créer un tableau pour stcoker les datas de la depilation
    int* datas = malloc(sizeof(int)* taille); 
    if (datas == NULL) {
        printf("Erreur : impossible d'allouer de la mémoire\n");
        exit(EXIT_FAILURE);
    }

    // on stocke toutes les valeurs de la pile
    int i=0;
    for (i = 0; i < taille; i++)
    {
    datas[i] = (*p_sommet)->data;
    *p_sommet = (*p_sommet)->next;
    }

    // on créer une nouvelle pille en empilant toutes les valeurs de l'ancienne pille 
    int k = 0;
    *p_sommet = NULL;
    for (k = 0; k < taille; k++)
    {
        empiler(p_sommet, datas[k]);
    }
    free(datas);
}
