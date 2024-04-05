#ifndef PILE_H
#define PILE_H

struct elementInPile {
    int data;
    struct elementInPile *next;
};
typedef struct elementInPile Element;

int si_vide(Element *p_sommet);

void empiler(Element **p_sommet, int valeur);

void afficher(Element *p_sommet);

int recuperer_valeur_sommet(Element* p_sommet);

int depile(Element** p_sommet);

void inverse_pile(Element** p_sommet);

#endif
