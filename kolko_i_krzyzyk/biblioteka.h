#ifndef _STDIO_H
#include <stdio.h>
#endif

#ifndef _STDBOOL_H
#include <stdbool.h>
#endif

#ifndef _STDLIB_H
#include <stdlib.h>
#endif

void inicjalizacjaPlanszy(char **adresPlanszy, int rozmiarPlanszy);
bool czyGraJestWygrana(char ** adresPlanszy, int rozmiarPlanszy);
void czyszczenieKonsoli();
void tworzeniePlanszy(char ** adresPlanszy, int rozmiarPlanszy, int liczbaRund);
void pobranieWartosciOdUzytkownika(int * adresWiersza, int * adresKolumny, int * adresLicznika);
bool czyPktIstnieje(int nowyWiersz, int nowaKolumna);
void zmianaPlanszy(char ** adresPlanszy, int * adresWiersza, int * adresKolumny);
void zapisDanych(int wiersz, int kolumna, int runda);
void czyPlikIstnieje();