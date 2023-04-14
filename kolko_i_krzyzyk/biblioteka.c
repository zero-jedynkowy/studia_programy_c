#ifndef _STDIO_H
#include <stdio.h>
#endif

#ifndef _STDBOOL_H
#include <stdbool.h>
#endif

#ifndef _STDLIB_H
#include <stdlib.h>
#endif

#ifndef _BIBLIOTEKA_H
#include "biblioteka.h"
#endif

void inicjalizacjaPlanszy(char ** adresPlanszy, int rozmiarPlanszy)
{
    for(int i=0; i<rozmiarPlanszy; i++)
    {
        adresPlanszy[i] = (char *)malloc(sizeof(char) * rozmiarPlanszy); 
    }
    for(int i=0; i<rozmiarPlanszy; i++)
    {
        for(int j=0; j<rozmiarPlanszy; j++)
        {
            adresPlanszy[i][j] = 'O';
        }
    }
}

void tworzeniePlanszy(char ** adresPlanszy, int rozmiarPlanszy, int liczbaRund)
{
    char oddzielenie[23];
    char gornaLinia[] = "|*#|1|2|3|4|5|6|7|8|9|";
    for(int i=0; i<22; i++) oddzielenie[i] = '-'; 
    oddzielenie[22] = '\0';
    printf("Liczba ruchow: %d\n", liczbaRund);
    printf("%s\n%s\n%s\n", oddzielenie, gornaLinia, oddzielenie);
    for(int i=0; i<rozmiarPlanszy; i++)
    {
        printf("|%d#", i + 1);
        for(int j=0; j<rozmiarPlanszy; j++) printf("|%c", adresPlanszy[i][j]);
        printf("|\n%s\n", oddzielenie);
    }
}

// Funkcja sprawdza czy zakończono grę
bool czyGraJestWygrana(char ** adresPlanszy, int rozmiarPlanszy)
{
    for(int i=0; i<rozmiarPlanszy; i++) for(int j=0; j<rozmiarPlanszy; j++) if(adresPlanszy[i][j] == 'O') return false;
    return true;
}

// Funkcja czyszcząca w konsolii
void czyszczenieKonsoli()
{
    printf("\n\n\n\n\n");
}

// //Funkcja pobierająca informacje o wierszu i kolumnie od użytkownika z klawiatury
void pobranieWartosciOdUzytkownika(int * adresWiersza, int * adresKolumny, int * adresLicznika)
{
    int indeksWiersz = 0;
    int indeksKolumna = 0;
    while(true)
    {
        printf("Wybierz wiersz: ");
        scanf("%d", &indeksWiersz);
        getchar(); 
        printf("\bWybierz kolumne: ");
        scanf("%d", &indeksKolumna);
        getchar(); 
        if(czyPktIstnieje(indeksWiersz, indeksKolumna)) break;
        else printf("Wprowadzono bledne dane!\n");
    }
    *adresLicznika += 1;
    *adresWiersza = indeksWiersz;
    *adresKolumny = indeksKolumna;
}

//Sprawdza czy punkt jest na planszy
bool czyPktIstnieje(int nowyWiersz, int nowaKolumna)
{
    if((nowaKolumna >= 1) && (nowaKolumna <= 9) && (nowyWiersz >= 1) && (nowyWiersz <= 9)) return true;
    return false;
}

void zmianaPlanszy(char ** adresPlanszy, int * adresWiersza, int * adresKolumny)
{
    int tablicaWartosciSprawdzanych[5][2] = {{*adresWiersza, *adresKolumny}, {*adresWiersza - 1, *adresKolumny}, {*adresWiersza + 1, *adresKolumny}, {*adresWiersza, *adresKolumny - 1}, {*adresWiersza, *adresKolumny + 1}};
    for(int i=0; i<5; i++)
    {
        if(czyPktIstnieje(tablicaWartosciSprawdzanych[i][0], tablicaWartosciSprawdzanych[i][1]))
        {
            if(adresPlanszy[tablicaWartosciSprawdzanych[i][0] - 1][tablicaWartosciSprawdzanych[i][1] - 1] == 'X') adresPlanszy[tablicaWartosciSprawdzanych[i][0] - 1][tablicaWartosciSprawdzanych[i][1] - 1] = 'O';
            else adresPlanszy[tablicaWartosciSprawdzanych[i][0] - 1][tablicaWartosciSprawdzanych[i][1] - 1] = 'X';
        }
    }
}

void czyPlikIstnieje()
{
    FILE * plik;
    plik = fopen("wspolrzedne.txt", "r");
    if(plik != NULL)
    {
        fclose(plik);
        FILE * plik2 = fopen("wspolrzedne.txt", "a");
        fprintf(plik2, "%s", "\n\nKOLEJNA GRA TUTAJ:\n");
        fclose(plik2);
    }
    else
    {
        FILE * plik2 = fopen("wspolrzedne.txt", "a");
        fprintf(plik2, "%s", "KOLEJNA GRA TUTAJ:\n");
        fclose(plik2);
    }
}

void zapisDanych(int wiersz, int kolumna, int runda)
{
    FILE * plik;
    plik = fopen("wspolrzedne.txt", "a");
    if(plik == NULL) fprintf(stderr, "ERROR!\n");
    else
    {
        fprintf(plik, "%s", "W rundzie ");
        fprintf(plik, "%d", runda - 1);
        fprintf(plik, "%s", " zapisano wpolrzedne: wiersz nr. ");
        fprintf(plik, "%d", wiersz);
        fprintf(plik, "%s", ", kolumna ");
        fprintf(plik, "%d", kolumna);
        fprintf(plik, "%s", ".\n");
    }
    fclose(plik);
}