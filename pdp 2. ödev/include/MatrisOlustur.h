#ifndef MATRISOLUSTUR_H
#define MATRISOLUSTUR_H

#include "DosyaOku.h"
#include "Canli.h"
#include <stdio.h>

struct BOYUT
{
     int satir;
     int sutun;
};

typedef struct BOYUT Boyut;
Boyut MatrisBoyutuBelirle(char *);
int **MatrisOlustur(char *, Boyut *);
Canli **CanliMatrisOlustur(char *, Boyut *);
void MatrisYazdir(int **, Boyut *);
void MatrisYoket(int **, Boyut *);
void CanliMatrisYazdir(Canli **matris, Boyut *boyut);
void CanliMatrisYoket(Canli **matris, Boyut *boyut);

#endif