#include <stdio.h>
#include <stdlib.h>

struct elementInPile {
    int data;
    struct elementInPile *next;
};
typedef struct elementInPile Element;

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



int main() {
    Element *sommet = NULL;

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
    afficher(sommet);
    return 0;
}
