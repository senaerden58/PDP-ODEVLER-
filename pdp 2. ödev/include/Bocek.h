#ifndef BOCEK_H
#define BOCEK_H

#include "Canli.h"

struct BOCEK
{
    Canli super;
    char bocekTuru;
    char *(*toString)(struct BOCEK *);
    void (*yoket)(struct BOCEK *);
};

typedef struct BOCEK *Bocek;
Bocek BocekBul();
char *BocekToString(const Bocek this);
void BocekYokEt(const Bocek);

#endif