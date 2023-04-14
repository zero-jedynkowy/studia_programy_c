#ifndef __STDIO__H
#include <stdio.h>
#endif

#ifndef __WIELOMIANY__H
#include "wielomiany.h"
#endif

int main(int argc, char **argv)
{
    if(argc == 1)
    {
        printf("\n\nBRAK JAKICHKOLWIEK DANYCH WEJSCIOWYCH!\n\n\n");
        return 0;
    }
    int liczbaWspolczynnikow = argc - 1;
    int * wspolczynniki = konwerterWspolczynnikow(argv, liczbaWspolczynnikow);
    int liczbaDzielnikowAN = 0;
    float * dzielnikiAN = kreatorWszystkichDzielnikow(wspolczynniki[0], &liczbaDzielnikowAN);
    int najmniejszaPotega = szukanieNajmniejszejPotegi(wspolczynniki, liczbaWspolczynnikow);
    int liczbaDzielnikowA0 = 0;
    float * dzielnikiA0 = kreatorWszystkichDzielnikow(najmniejszaPotega, &liczbaDzielnikowA0);
    infoWielomian(wspolczynniki, liczbaWspolczynnikow);
    int liczbaPierwiastkow = 0;
    float * pierwiastki = szukaniePierwiastkow(&liczbaPierwiastkow, wspolczynniki, liczbaWspolczynnikow, dzielnikiA0, liczbaDzielnikowA0, dzielnikiAN, liczbaDzielnikowAN);
    wyswietleniePierwiastkow(pierwiastki, liczbaPierwiastkow);
    free(dzielnikiA0);
    free(dzielnikiAN);
    free(pierwiastki);
    free(wspolczynniki);
    return 0;
}
