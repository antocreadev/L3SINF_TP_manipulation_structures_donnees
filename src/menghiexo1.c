#include "include/menghilisteint.h"

/* Affiche le menu du programme et récupère le choix de l'utilisateur
@output : int : choix de l'utilisateur
@precondition : aucune
@postcondition : le choix de l'utilisateur est récupéré et retourné
*/
int menu()
{
    int choix = 0;
    printf("1 Creer une liste d'entiers compris entre 0 et 20 de taille aleatoire comprise entre 1 et 20\n"
        "2 Ajouter un élément entier aléatoire (compris entre 0 et 20) en tête de liste\n"
        "3 Inserer un élément entier aléatoire dans sa place dans la liste suivant l'ordre croissant des premiers éléments\n"
        "4 Supprimer l'élément de tête\n"
        "5 Supprimer tous les maillons d'une valeur donnee\n"
        "6 Detruire liste\n"
        "7 Sauver la liste courante en binaire dans le fichier \"saveliste.bin\"\n"
        "8 Charger une liste depuis le fichier \"savelist.bin\"\n");

    scanf("%d", &choix);
    rewind(stdin);

    return choix;
}

int main() {
    maillon_int* premier = NULL;
    maillon_int* nouveau = NULL;
    int fin = 0;
    int i, nb;

    srand((unsigned)time(NULL));
    while (!fin) {
        i = menu();
        switch (i) {

        case 1:
            detruire_liste2(&premier);
            nb = rand() % 20 + 1;
            printf("Création d'une liste aléatoire de taille %d\n", nb);
            for (int j = 0; j < nb; j++) {
                nouveau = init_elt();
                ajout_tete_v2(&premier, nouveau);
            }
            printf("Liste créée : ");
            parcourir(premier);
            printf("\n\n\n");
            break;

        case 2:
            nouveau = init_elt();
            ajout_tete_v2(&premier, nouveau);
            printf("Élément ajouté en tête de liste : ");
            parcourir(premier);
            printf("\n\n\n");
            break;

        case 3:
            nouveau = init_elt();
            inserer2(&premier, nouveau);
            printf("Élément inséré dans la liste suivant l'ordre croissant : ");
            parcourir(premier);
            printf("\n\n\n");
            break;

        case 4:
            supprimer_debut(&premier);
            printf("Suppression de l'élément de tête : ");
            parcourir(premier);
            printf("\n\n\n");
            break;

        case 5:
            printf("Entrez la valeur à supprimer : ");
            scanf("%d", &nb);
            critere_supp_un2(&premier, nb);
            printf("Élément(s) de valeur %d supprimé(s) : ", nb);
            parcourir(premier);
            printf("\n\n\n");
            break;

        case 6:
            detruire_liste2(&premier);
            printf("Liste détruite\n\n\n");


            break;

        case 7:
            sauver_liste(premier);
            printf("Liste sauvegardée dans le fichier saveliste.bin\n\n\n");
            break;

        case 8:
            detruire_liste2(&premier);
            premier = load_liste();
            printf("Liste chargée depuis le fichier saveliste.bin : ");
            parcourir(premier);
            printf("\n\n\n");
            break;

        default:
            fin = 1;
            break;
        }
    }

    return 0;
}
