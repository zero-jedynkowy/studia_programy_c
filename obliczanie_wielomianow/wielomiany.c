#ifndef __STDIO__H
#include <stdio.h>
#endif

#ifndef __STDIO__H
#include <stdlib.h>
#endif

#ifndef __STDBOOL__H
#include <stdbool.h>
#endif

#ifndef __FLOAT__H
#include <float.h>
#endif

#ifndef __MATH__H
#include <math.h>
#endif

#include "wielomiany.h"

int * konwerterWspolczynnikow(char ** adresArgv, int liczbaWspolczynnikow)
{
    int licznik = 1;
    int * wspolczynniki = (int *)calloc(liczbaWspolczynnikow, sizeof(int));
    for(int i=0; i<liczbaWspolczynnikow; i++)
    {
        wspolczynniki[i] = atoi(*(adresArgv + licznik));
        licznik += 1;
    }
    return wspolczynniki;
}

float * kreatorWszystkichDzielnikow(int liczba, int * liczbaDzielnikow)
{
    int rozmiarDzielnikow = 2;
    float * tablica = (float *)calloc(rozmiarDzielnikow, sizeof(float));
    float * ptr;
    tablica[0] = 1;
    tablica[1] = -1;
    for(int i = 2; i <= abs(liczba); i++)
    {
        if((liczba % i) == 0)
        {
            rozmiarDzielnikow += 2;
            ptr = (float *)realloc(tablica, rozmiarDzielnikow * sizeof(float));
            tablica = ptr;
            tablica[rozmiarDzielnikow - 2] = (float)i;
            tablica[rozmiarDzielnikow - 1] = -1 * (float)i;
        }
    }
    ptr = NULL;
    *liczbaDzielnikow = rozmiarDzielnikow;
    return tablica;
}

int szukanieNajmniejszejPotegi(int * adresWspoczynnikow, int liczbaWspolczynnikow)
{
    for(int i=liczbaWspolczynnikow - 1; i>=0; i--)
    {
        if(*(adresWspoczynnikow + i) != 0) return (*(adresWspoczynnikow + i));
    }
}

void infoWielomian(int * adresWspo, int liczbaWspolczynnikow)
{
    int najmniejszaPotega = 0;
    int licznikPoteg = liczbaWspolczynnikow - 1;
    najmniejszaPotega = szukanieNajmniejszejPotegi(adresWspo, liczbaWspolczynnikow);
    printf("Rzad wielomianu: %d.\n", liczbaWspolczynnikow - 1);
    printf("Wspolczynnik najwiekszej potegi: %d.\n", *adresWspo);
    printf("Wspolczynnik najmniejszej (o niezerowym wspolczynniku) potegi: %d.\n\n", najmniejszaPotega);
    printf("Wielomian:\n\n\t");
    for(int i=0; i<liczbaWspolczynnikow; i++)
    {
        if(*(adresWspo + i) != 0)
        {
            if(i == (liczbaWspolczynnikow - 1))
            {
                if(*(adresWspo + i) < 0) printf(" - %d", abs(*(adresWspo + i)));
                else printf(" + %d", *(adresWspo + i));
            }
            else
            {
                if(*(adresWspo + i) < 0) printf(" - %dx^%d", abs(*(adresWspo + i)), licznikPoteg);
                else printf(" + %dx^%d", *(adresWspo + i), licznikPoteg);
            }
        }
        licznikPoteg -= 1;
    }
    printf("\n\n\n");
}

bool porownanieLiczb(float a, float b)
{
    if(fabs(a - b) < FLT_EPSILON) return true;
    return false;
}

float obliczenieFunkcjiDlaPkt(float x, int * adresWspolczynnikow, int liczbaWspolczynnikow)
{
    float wynik = 0;
    int potega = liczbaWspolczynnikow - 1;
    for(int i=0; i<liczbaWspolczynnikow - 1; i++)
    {
        wynik += pow(x, potega) * (*(adresWspolczynnikow + i));
        potega -= 1;
    }
    wynik += *(adresWspolczynnikow + liczbaWspolczynnikow - 1);
    return wynik;
}

float * szukaniePierwiastkow(int * adresLiczbyPierwiastkow, int * adresWspolczynnikow, int liczbaWspolczynnikow, float * adresDzielnikowA0, int liczbaDzielnikowA0, float * adresDzielnikowAN, int liczbaDzielnikowAN)
{
    int rozmiarTablicy = 0;
    float * tablica = NULL;
    float wynik = 0;
    float y = 0;
    float * ptr = NULL;
    for(int i=0; i<liczbaDzielnikowA0; i++)
    {
        for(int j=0; j<liczbaDzielnikowAN; j++)
        {
            wynik = (adresDzielnikowA0[i])/(adresDzielnikowAN[j]);
            y = obliczenieFunkcjiDlaPkt(wynik, adresWspolczynnikow, liczbaWspolczynnikow);
            if(porownanieLiczb(y, 0))
            {
                if(tablica == NULL)
                {
                    rozmiarTablicy = 1;
                    tablica = (float *)calloc(rozmiarTablicy, sizeof(float));
                    tablica[0] = wynik;
                }
                else
                {
                    if(!szukanieDuplikatu(wynik, tablica, rozmiarTablicy))
                    {
                        rozmiarTablicy += 1;
                        ptr = (float *)realloc(tablica, rozmiarTablicy* sizeof(float));
                        tablica = ptr;
                        tablica[rozmiarTablicy - 1] = wynik;
                    }
                }
            }
        }
    }
    if(porownanieLiczb(*(adresWspolczynnikow + liczbaWspolczynnikow - 1), 0))
    {
        rozmiarTablicy += 1;
        ptr = (float *)realloc(tablica, rozmiarTablicy* sizeof(float));
        tablica = ptr;
        tablica[rozmiarTablicy - 1] = 0;
    }
    *adresLiczbyPierwiastkow = rozmiarTablicy;
    return tablica;
}

bool szukanieDuplikatu(float szukanaWartosc, float * adresTablicy, int rozmiarTablicy)
{
    for(int i=0; i<rozmiarTablicy; i++)
    {
        if(porownanieLiczb(adresTablicy[i], szukanaWartosc)) return true;   
    }
    return false;
}

void wyswietleniePierwiastkow(float * adresPierwiastkow, int liczbaPierwiastkow)
{
    if(liczbaPierwiastkow != 0)
    {
        printf("Liczba znalezionych pierwiastkow: %d.\n\n", liczbaPierwiastkow);
        for(int i=0; i<liczbaPierwiastkow; i++) printf("\tPierwiastek nr. %d: %f.\n", i + 1, *(adresPierwiastkow + i));
        printf("\nKONIEC!\n");
    }
    else printf("NIE ZNALEZIONO PIERWIATKOW!\n");
}