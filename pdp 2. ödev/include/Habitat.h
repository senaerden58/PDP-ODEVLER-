#ifndef HABITAT_H
#define HABITAT_H
#include "Canli.h"
#include "Bitki.h"
#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "Habitat.h"
#include "MatrisOlustur.h"
#include "conio.h"

struct HABITAT
{
    Canli **canlilar;
    Boyut boyut;
    void (*yokEt)(struct HABITAT *);
};
typedef struct HABITAT *Habitat;
Habitat HabitatOlustur();
Canli *KazananiBul(Canli **, Boyut *, int **);
void HabitatYokEt(const Habitat);

#endif