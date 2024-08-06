#ifndef CANLI_H
#define CANLI_H

struct CANLI
{
    char *(*toString)(struct CANLI *); // Sekilden alttaki kalıtımı almali
    char canliTuru;
    void (*yoket)(struct CANLI *);
};

typedef struct CANLI *Canli;
Canli CanliBul(char);
void CanliYokEt(const Canli);
char *toString(const Canli);
void CanliEsle(Canli **, int **, int, int);

#endif
