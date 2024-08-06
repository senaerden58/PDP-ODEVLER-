#ifndef BITKI_H
#define BITKI_H

#include "Canli.h"

struct BITKI
{
    Canli super; // canlidan kalitim almistir.
    void (*yoket)(struct BITKI *);
    char *(*toString)(struct BITKI *);
};
typedef struct BITKI *Bitki;

Bitki BitkiBul();
char *BitkiToString(const Bitki);
void BitkiYokEt(const Bitki);

#endif