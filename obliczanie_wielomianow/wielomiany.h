#ifndef __STDIO__H
#include <stdio.h>
#endif

#ifndef __STDIO__H
#include <stdlib.h>
#endif

#ifndef __STDBOOL__H
#include <stdbool.h>
#endif

int * konwerterWspolczynnikow(char ** adresArgv, int liczbaWspolczynnikow);
float * kreatorWszystkichDzielnikow(int liczba, int * liczbaDzielnikow);
int szukanieNajmniejszejPotegi(int * adresWspoczynnikow, int liczbaWspolczynnikow);
void infoWielomian(int * adresWspo, int liczbaWspolczynnikow);
float * szukaniePierwiastkow(int * adresLiczbyPierwiastkow, int * adresWspolczynnikow, int liczbaWspolczynnikow, float * adresDzielnikowA0, int liczbaDzielnikowA0, float * adresDzielnikowAN, int liczbaDzielnikowAN);
bool szukanieDuplikatu(float szukanaWartosc, float * adresTablicy, int rozmiarTablicy);
void wyswietleniePierwiastkow(float * adresPierwiastkow, int liczbaPierwiastkow);