#ifndef PIRE_H
#define PIRE_H
#include "Bocek.h"

struct PIRE
{
    Bocek doubleSuper;
    char *(*toString)(struct PIRE *);
    void (*yoket)(struct PIRE *);
};

typedef struct PIRE *Pire;
Pire PireBul();
void PireYokEt(const Pire);
char *PireToString(const Pire);

#endif