#ifndef DOSYAOKU_H
#define DOSYAOKU_H

#include "stdio.h"
#include "stdlib.h"
#include "time.h"
#include "string.h"

struct DOSYAOKU
{
   char *icerik;
   char *(*DosyaOkuYaz)(char *);
};

typedef struct DOSYAOKU *DosyaOku;
char *DosyaOkuYaz(char *);

#endif