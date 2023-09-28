#include "liste.h"
#include <stdio.h>

int main(){
    lst liste = creerListe();
    printf("%d \n", liste->nbElem);
    ajouterEnTete(liste, 3);
    ajouterEnTete(liste, 6);
    ajouterEnTete(liste, 7);
    ajouterEnTete(liste, 98);
    afficherListe(liste);
    supprimerEnTete(liste);
    afficherListe(liste);
    //no
    return 0;
}