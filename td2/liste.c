#include <stdio.h>
#include <stdlib.h>
#include "liste.h"

lst creerListe(){
    lst list = (lst) malloc(sizeof(struct liste));
    list->debut = NULL;
    list->nbElem = 0;
    return list;
};

void ajouterEnTete(lst l, int x){
    //creation un maillon qui prend comme adresse suivante le premier maillon de la liste
    ml nouveauElem = (ml) malloc(sizeof(struct maillon));
    nouveauElem->val = x;
    nouveauElem->suivant = l->debut;

    //le debut de la liste devient ensuite le maillon crée
    l->debut=nouveauElem;
    l->nbElem++;
};

int supprimerEnTete(lst l) {
    if(l->nbElem > 0){
        ml suiv = l->debut->suivant;
        free(l->debut);
        l->debut = suiv;
        l->nbElem--;
    }
    return 0;
};

void afficherListe(lst l){
    if(l->debut == NULL) return;
    ml maillon = l->debut;
    while (maillon != NULL){
        printf("%d ", maillon->val);
        maillon = maillon->suivant;
    }
    printf("\n");
};

void supprimerListe(lst l){
    while(l->nbElem > 0){
        supprimerEnTete(l);
    }
    free(l);

};

int supprimer(lst l, int i){
    if(l->nbElem > i){
        if(i==0){supprimerEnTete(l);}
        else{
            int j=0;
            ml iter = l->debut;
            while(j<(i-1)){
                iter = iter->suivant;
                j++;
            }
            free(iter->suivant);
            // Actualizamos el puntero al nodo anterior para que apunte al nodo siguiente
            iter->suivant = iter->suivant->suivant;

            // Decrementamos el número de elementos de la lista
            l->nbElem--;

        }
    }
    //oui
    return 0;
}

void inserer(lst l, int val, int i){
    //test si index demandé est inferiur au nombre element de la liste
    if(l->nbElem > i){
        //si index demandé est 0 alors c'est un ajout en tete
        if(i==0){ajouterEnTete(l, val);}
        //sinon on se deplace dans la liste jusqu'à atteindre l'index demandé
        else{
            //compteur d'iteration a chaque avance de maillon
            int j=0;
            //on defini un maillon temporaire, on lui donne la valeur du premier de la liste
            ml iter = l->debut;
            //on boucle jusqu'à a tomber sur l'index i-1
            while(j<(i-1)){
                iter = iter->suivant;
                j++;
            }
            //creation du maillon qu'on va inserer
            ml elem = (ml) malloc(sizeof(struct maillon));
            elem->val = val;
            //on lui donne l'adresse du maillon suivant qi existait déjà
            elem->suivant = iter->suivant;
            //le maillon suivant precedent devient le maillon que l'on vient de creer
            iter->suivant = elem;
            l->nbElem++;
        }
    }
}

