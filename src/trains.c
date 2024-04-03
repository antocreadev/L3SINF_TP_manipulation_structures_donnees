#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// nombre de caractere max pour nom de ville
#define MAX_VILLE 100

// nombre de caractere max pour heure ex : 10h00 donc 6 char avec le \0
# define MAX_HEURE 6

typedef struct {
    char depart[MAX_VILLE];
    char arrivee[MAX_VILLE];
    char heure_depart[MAX_HEURE];
    char heure_arrivee[MAX_HEURE];
    int distance;
} Horaire;

typedef struct node {
    Horaire horaire;
    struct node *suivant;
} Noeud;

Noeud *liste_horaires = NULL;

// q2 
// ajoute un horaire
void ajouter_horaire(char depart[], char arrivee[], char heure_depart[], char heure_arrivee[], int distance) {
    Noeud *nouveau_noeud = (Noeud*)malloc(sizeof(Noeud));
    if (nouveau_noeud == NULL) {
        printf("Erreur : impossible d'allouer de la mémoire.\n");
        return;
    }
    strcpy(nouveau_noeud->horaire.depart, depart);
    strcpy(nouveau_noeud->horaire.arrivee, arrivee);
    strcpy(nouveau_noeud->horaire.heure_depart, heure_depart);
    strcpy(nouveau_noeud->horaire.heure_arrivee, heure_arrivee);
    nouveau_noeud->horaire.distance = distance;
    nouveau_noeud->suivant = liste_horaires;
    liste_horaires = nouveau_noeud;
}
// q3
// affiche les horaires de depart
void afficher_horaires_depart(char ville[]) {
    Noeud *courant = liste_horaires;
    while (courant != NULL) {
        if (strcmp(courant->horaire.depart, ville) == 0) {
            printf("Départ de %s à destination de %s à %s, arrivée à %s\n", 
                   courant->horaire.depart, courant->horaire.arrivee, 
                   courant->horaire.heure_depart, courant->horaire.heure_arrivee);
        }
        courant = courant->suivant;
    }
}

// q4
// calcule la vitesse moyenne
float vitesse_moyenne(char depart[], char arrivee[], char heure_depart[], char heure_arrivee[], int distance) {
    int heures_depart, minutes_depart, heures_arrivee, minutes_arrivee;
    sscanf(heure_depart, "%dh%d", &heures_depart, &minutes_depart);
    sscanf(heure_arrivee, "%dh%d", &heures_arrivee, &minutes_arrivee);
    
    float temps_trajet = (heures_arrivee - heures_depart) + (minutes_arrivee - minutes_depart) / 60.0;
    float vitesse = distance / temps_trajet;
    return vitesse;
}

// trouve la vitesse moyenne la plus rapide
void vitesse_moyenne_maximale() {
    float vitesse_max = 0;
    Horaire trajet_max;
    Noeud *courant = liste_horaires;
    while (courant != NULL) {
        float vitesse = vitesse_moyenne(courant->horaire.depart, courant->horaire.arrivee,
                                        courant->horaire.heure_depart, courant->horaire.heure_arrivee,
                                        courant->horaire.distance);
        if (vitesse > vitesse_max) {
            vitesse_max = vitesse;
            trajet_max = courant->horaire;
        }
        courant = courant->suivant;
    }
    printf("trajet avec la vitesse moyenne la plus elevee :\n");
    printf("depart de %s à destination de %s à %s, arrivee à %s\n", 
           trajet_max.depart, trajet_max.arrivee, 
           trajet_max.heure_depart, trajet_max.heure_arrivee);
    printf("la vitesse moyenne : %.2f km/h\n", vitesse_max);
}

// question 5
// echange les horaires
void echanger_horaires(Horaire *horaire1, Horaire *horaire2) {
    Horaire temp = *horaire1;
    *horaire1 = *horaire2;
    *horaire2 = temp;
}

// tri 
void trier_horaires_par_heure_depart() {
    Noeud *courant;
    int modifie;
    if (liste_horaires == NULL) {
        return;
    }
    do {
        modifie = 0;
        courant = liste_horaires;
        while (courant->suivant != NULL) {
            if (strcmp(courant->horaire.heure_depart, courant->suivant->horaire.heure_depart) > 0) {
                echanger_horaires(&courant->horaire, &courant->suivant->horaire);
                modifie = 1;
            }
            courant = courant->suivant;
        }
    } while (modifie);
}

// question 6
void moyen_plus_rapide(char vd[], char va[]) {
    Noeud *courant1 = liste_horaires;
    while (courant1 != NULL) {
        if (strcmp(courant1->horaire.depart, vd) == 0 && strcmp(courant1->horaire.arrivee, va) != 0) {
            Noeud *courant2 = liste_horaires;
            while (courant2 != NULL) {
                if (strcmp(courant1->horaire.arrivee, courant2->horaire.depart) == 0 && strcmp(courant2->horaire.arrivee, va) == 0) {
                    int heures_arrivee_train1, minutes_arrivee_train1, heures_depart_train2, minutes_depart_train2;
                    sscanf(courant1->horaire.heure_arrivee, "%dh%d", &heures_arrivee_train1, &minutes_arrivee_train1);
                    sscanf(courant2->horaire.heure_depart, "%dh%d", &heures_depart_train2, &minutes_depart_train2);
                    int temps_attente = (heures_depart_train2 - heures_arrivee_train1) * 60 + (minutes_depart_train2 - minutes_arrivee_train1);
                    if (temps_attente >= 5 && temps_attente <= 120) {
                        printf("le plus rapide pour aller de %s à %s :\n", vd, va);
                        printf("prendre le train de %s à %s à %s, arrivee à %s\n", 
                               courant1->horaire.depart, courant1->horaire.arrivee, 
                               courant1->horaire.heure_depart, courant1->horaire.heure_arrivee);
                        printf("et prendre le train de %s à %s à %s, arrivee à %s\n", 
                               courant2->horaire.depart, courant2->horaire.arrivee, 
                               courant2->horaire.heure_depart, courant2->horaire.heure_arrivee);
                        return;
                    }
                }
                courant2 = courant2->suivant;
            }
        }
        courant1 = courant1->suivant;
    }
    printf("impossible d'aller de %s à %s avec ou sans correspondance.\n", vd, va);
}

int main() {
    // Pour la gestion des horaires de trains, une liste chaînée serait préférable. Elle permet un ajout efficace de nouveaux horaires, une recherche satisfaisante des horaires au départ d'une ville donnée, des opérations d'insertion et de suppression rapides, une gestion de la mémoire plus simple, et une mise en œuvre relativement facile.


    // on ajoute les horaires de base - q2
    ajouter_horaire("Lille", "Paris", "08h00", "08h59", 237);
    ajouter_horaire("Lille", "Lyon", "07h00", "10h00", 709);
    ajouter_horaire("Lille", "Calais", "15h19", "18h34", 110);
    ajouter_horaire("Paris", "Marseille", "12h00", "18h00", 900);
    ajouter_horaire("Lyon", "Marseille", "10h07", "15h01", 450);
    ajouter_horaire("Lyon", "Marseille", "11h50", "17h00", 450);

    // affiche question 3
    afficher_horaires_depart("Lille");

    // trouve la vitesse moyenne la rapide , q4
    vitesse_moyenne_maximale();

    // q5 tri
    trier_horaires_par_heure_depart();
    afficher_horaires_depart("Lille");

    // question 6
    moyen_plus_rapide("Lille", "Marseille");

    return 0;
}
