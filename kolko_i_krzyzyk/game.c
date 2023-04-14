//Dyrektywy pre-procesora
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include "biblioteka.h"

//Funkcja główna
int main(void)
{
    int rozmiarPlanszy = 9;
    int wiersz = 0;
    int kolumna = 0;
    int licznikRund = 1;
    char ** plansza = (char **)malloc(sizeof(char *) * rozmiarPlanszy);
    inicjalizacjaPlanszy(plansza, rozmiarPlanszy);
    czyPlikIstnieje();
    while(true)
    {
        wiersz = 0;
        kolumna = 0;
        tworzeniePlanszy(plansza, rozmiarPlanszy, licznikRund);
        pobranieWartosciOdUzytkownika(&wiersz, &kolumna, &licznikRund);
        zapisDanych(wiersz, kolumna, licznikRund);
        czyszczenieKonsoli();
        zmianaPlanszy(plansza, &wiersz, &kolumna);
        if(czyGraJestWygrana(plansza, rozmiarPlanszy)) break;
    }
    printf("Gre zakonczono!\nLiczba rund: %d\n", licznikRund);
    for(int i=0; i<rozmiarPlanszy; i++) free(plansza[i]);
    free(plansza);
    return 0;
}