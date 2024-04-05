#ifndef HORAIRE_H
#define HORAIRE_H

typedef struct {
    char* depart;
    char* arrivee;
    char* heure_depart;
    char* heure_arrivee;
    int distance;
} Horaire;

typedef struct node {
    Horaire horaire;
    struct node *suivant;
} Noeud;

void ajouter_horaire(char* depart, char* arrivee, char* heure_depart, char* heure_arrivee, int distance);

void afficher_horaires_depart(char* ville);

float vitesse_moyenne(char* depart, char* arrivee, char* heure_depart, char* heure_arrivee, int distance);

void vitesse_moyenne_maximale();

void echanger_horaires(Horaire *horaire1, Horaire *horaire2);

void trier_horaires_par_heure_depart();

void moyen_plus_rapide(char* vd, char* va);

void liberer_memoire();

#endif
