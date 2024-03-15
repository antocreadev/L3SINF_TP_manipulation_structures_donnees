#include "include/menghilisteint.h"
/* Initialise un nouveau maillon avec une valeur aléatoire entre 0 et 20
@output : maillon_int* : pointeur vers le nouveau maillon initialisé
@precondition : aucune
@postcondition : un nouveau maillon est créé et initialisé avec une valeur aléatoire
*/
maillon_int* init_elt()
{
    maillon_int* p_nv_elt = malloc(sizeof(maillon_int));
    p_nv_elt->val = rand() % 21;
    p_nv_elt->p_suiv = NULL;
    return p_nv_elt;
}

/* Ajoute un nouveau maillon en tête d'une liste
@param p_tete : pointeur vers le premier maillon de la liste
@param p_nv_elt : pointeur vers le nouveau maillon à ajouter en tête de liste
@output : maillon_int* : pointeur vers le premier maillon de la liste mise à jour après l'ajout
@precondition : aucune
@postcondition : le nouveau maillon est ajouté en tête de liste et la tête de liste est mise à jour
*/
maillon_int* ajout_tete_v1(maillon_int* p_tete, maillon_int* p_nv_elt)
{
    p_nv_elt->p_suiv = p_tete;
    p_tete = p_nv_elt;
    return p_tete;
}

/* Ajoute un nouveau maillon en tête d'une liste
@param p_p_tete : pointeur vers un pointeur sur le premier maillon de la liste
@param p_nv_elt : pointeur vers le nouveau maillon à ajouter en tête de liste
@output : void
@precondition : aucune
@postcondition : le nouveau maillon est ajouté en tête de liste et la tête de liste est mise à jour
*/
void ajout_tete_v2(maillon_int** p_p_tete, maillon_int* p_nv_elt)
{
    p_nv_elt->p_suiv = *p_p_tete;
    *p_p_tete = p_nv_elt;
}


/* Parcourt une liste d'entiers et affiche ses éléments
@param p_tete : pointeur vers le premier maillon de la liste
@output : void
@precondition : aucune
@postcondition : les éléments de la liste sont affichés à l'écran
*/
void parcourir(maillon_int* p_tete)
{
    if (p_tete == NULL)
        printf("liste vide");
    else
        while (p_tete != NULL) {
            printf("%d--", p_tete->val);
            p_tete = p_tete->p_suiv;
        }
    putchar('\n');
}

/* Insère un nouveau maillon dans une liste triée de manière croissante
@param p_tete : pointeur vers le premier maillon de la liste
@param p_nv_elt : pointeur vers le maillon à insérer dans la liste
@output : maillon_int* : pointeur vers le premier maillon de la liste mise à jour après l'insertion
@precondition : la liste est triée de manière croissante
@postcondition : le maillon p_nv_elt est inséré dans la liste de manière à ce que la liste reste triée
*/
maillon_int* inserer1(maillon_int* p_tete, maillon_int* p_nv_elt)
{
    maillon_int* n, * prec;
    
    if (p_tete == NULL || p_nv_elt->val <= p_tete->val) {  
        p_nv_elt->p_suiv = p_tete;
        p_tete = p_nv_elt;
    }
    else {  
        n = prec = p_tete;
        while (n != NULL && p_nv_elt->val > n->val) {
            prec = n;
            n = n->p_suiv;
        }
        p_nv_elt->p_suiv = n;
        prec->p_suiv = p_nv_elt;
    }
    return p_tete;
}


/* Insère un nouveau maillon dans une liste triée de manière croissante
@param prem : pointeur vers un pointeur sur le premier maillon de la liste
@param e : pointeur vers le maillon à insérer dans la liste
@output : void
@precondition : la liste est triée de manière croissante
@postcondition : le maillon e est inséré dans la liste de manière à ce que la liste reste triée
*/
void inserer2(maillon_int** prem, maillon_int* e)
{
    maillon_int* n, * prec;
    if (*prem == NULL || e->val <= (*prem)->val){ 
        e->p_suiv = *prem;
        *prem = e;
    }
    else {  
        n = prec = *prem;
        while (n != NULL && e->val > n->val) {
            prec = n;
            n = n->p_suiv;
        }
        e->p_suiv = n;
        prec->p_suiv = e;
    }
}


/* Supprime le premier maillon d'une liste donnée
@param prem : pointeur vers un pointeur sur le premier maillon de la liste
@output : void
@precondition : la liste ne doit pas être vide
@postcondition : le premier maillon de la liste est supprimé, et la tête de la liste est mise à jour
*/
void supprimer_debut(maillon_int** prem)
{
    maillon_int* n;
    if (*prem != NULL) {
        n = *prem;
        *prem = (*prem)->p_suiv;
        free(n);
    }
}

/*
Cette fonction supprime tous les maillons de la liste d'entiers (maillon_int) dont le premier élément est pointé par le pointeur prem et dont la valeur est égale à val 
@input : maillon_int* prem, pointeur sur le premier élément de la liste à modifier
         int val, valeur des éléments à supprimer
@output : maillon_int*, pointeur sur le premier élément de la liste modifiée
@precondition : le pointeur prem est soit NULL (aucune action) soit pointe sur le premier élément d'une liste d'entiers
@postcondition : la liste est modifiée et tous les éléments de valeur val sont supprimés de la liste. Les maillons supprimés sont libérés de la mémoire
*/
maillon_int* critere_supp_un1(maillon_int* prem, int val)
{
    maillon_int* e = prem, * prec = NULL, * n;

    while (e != NULL) {
        n = NULL;
        if (e->val == val) {
            n = e;
            if (prec == NULL)
                prem = e->p_suiv;
            else
                prec->p_suiv = e->p_suiv;
        }
        else
            prec = e;
        e = e->p_suiv;
        if (n != NULL)
            free(n);
    }
    return prem;

}


/*
Cette fonction supprime tous les maillons de la liste d'entiers (maillon_int) dont
le premier élément est pointé par le pointeur prem et dont la valeur est égale à val
@input : maillon_int** prem, pointeur sur le premier élément de la liste à modifier
         int val, valeur des éléments à supprimer
@precondition : le pointeur prem est soit NULL (aucune action) soit pointe sur
                le premier élément d'une liste d'entiers
@postcondition : la liste est modifiée et tous les éléments de valeur val sont supprimés
                de la liste. Les maillons supprimés sont libérés de la mémoire
*/
void critere_supp_un2(maillon_int** prem, int val)
{
    maillon_int* e = *prem, * prec = NULL, * n;

    while (e != NULL) {
        n = NULL;
        if (e->val == val) {
            n = e;
            if (prec == NULL)
                *prem = e->p_suiv;
            else
                prec->p_suiv = e->p_suiv;
        }
        else
            prec = e;
        e = e->p_suiv;
        if (n != NULL)
            free(n);
    }
}


/*
Cette fonction détruit la liste d'entiers (maillon_int) dont le premier élément
est pointé par le pointeur prem
@input : maillon_int* prem, pointeur sur le premier élément de la liste à détruire
@precondition : le pointeur prem est soit NULL (aucune action) soit pointe sur
                le premier élément d'une liste d'entiers
@postcondition : la liste est détruite et le pointeur prem est mis à NULL
*/
void detruire_liste(maillon_int** prem)
{
    maillon_int* n;
    while (*prem != NULL) {
        n = *prem;
        *prem = (*prem)->p_suiv;
        free(n);
    }
}


/*
Cette fonction est une version alternative de la fonction detruire_liste
qui utilise un pointeur sur pointeur pour le premier élément de la liste
@input : maillon_int** prem, pointeur sur le premier élément de la liste à détruire
@precondition : le pointeur prem est soit NULL (aucune action) soit pointe sur
                le premier élément d'une liste d'entiers
@postcondition : la liste est détruite et le pointeur prem est mis à NULL
*/
void detruire_liste2(maillon_int** prem)
{
    while (*prem != NULL)
        supprimer_debut(prem);
    
}

/* Permet la sérialisation format binaire dans le fichier
"saveliste.bin" de la liste d'entier (maillon_int) dont
le pointeur sur le premier élément est passé en paramètre
@input : maillon_int * prem, pointeur sur l'élément de tête de la liste à sérialiser
@output : void
@precondition : le répertoire courant et le processus père permettent l'écriture 
                le pointeur prem, est soit NULL (aucune action) soit pointe sur
                le premier élément d'une liste d'entiers
@postcondition : le fichier saveliste.bin contient les éléments de la liste 
                dont le premier élément est pointé par prem. 
                Nota : il n'y a pas de libération de la mémoire occupée par la 
                liste. Il faut donc la détruire avant d'éventuellement la recharger.
*/
void sauver_liste(maillon_int* prem)
{
    //ouvrir un fichier binaire en écriture : suffixe b
    FILE* f=fopen("saveliste.bin", "wb");
    printf("Ouvertude du fichier %p\n",f);
    // si liste non vide
    if (prem != NULL) {
        if (f==NULL)
            fprintf(stderr,"erreur création fichier :%i\n",errno);
        else // parcourir la liste jusque fin
            while (prem != NULL) {
                // écrire chaque maillon en binaire
                if (1 !=fwrite(prem, sizeof(maillon_int), 1, f))
                    fprintf(stderr,"Erreur d'écriture du maillon %p\n",prem);
                else 
                // passer au maillon suivant
                prem = prem->p_suiv;
            }
            fclose(f);	// fermer le fichier
    }
    else
        fprintf(stderr,"pas de sauvegarde pour une liste vide\n");
}

/* Charge une liste depuis un fichier binaire "saveliste.bin"
@output : maillon_int* : pointeur vers le premier maillon de la liste chargée depuis le fichier
@precondition : le fichier "saveliste.bin" doit exister et contenir des données valides
@postcondition : une liste est chargée depuis le fichier et retournée
*/
maillon_int* load_liste()
{
    FILE* f;
    maillon_int* prem = NULL, * p, e;
    if ((f= fopen("saveliste.bin", "rb")) != NULL) {
        prem = malloc(sizeof(maillon_int));
        fread(prem, sizeof(maillon_int), 1, f);
        p = prem;
        while (fread(&e, sizeof(maillon_int), 1, f)) {
            p->p_suiv = malloc(sizeof(maillon_int));
            p = p->p_suiv;
            *p = e;
            p->p_suiv = NULL;
        }
        fclose(f);
    }
    else
        printf("erreur ou fichier inexistant");
    return prem;
}