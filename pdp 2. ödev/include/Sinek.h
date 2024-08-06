#ifndef SINEK_H
#define SINEK_H
#include "Bocek.h"

struct SINEK
{
    Bocek doubleSuper; // bocekten kalıtım almıştır.
    char *(*toString)(struct SINEK *);
    void (*yoket)(struct SINEK *);
};

typedef struct SINEK *Sinek;
Sinek SinekBul();
char *SinekToString(const Sinek);
void SinekYokEt(const Sinek);

#endif