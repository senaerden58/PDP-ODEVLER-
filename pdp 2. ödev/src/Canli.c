#include "Canli.h"
#include "Bitki.h"
#include "Bocek.h"
#include "Pire.h"
#include "Sinek.h"
#include <stdio.h>
#include <stdlib.h>

Canli CanliBul(char canliTuru) {
    Canli this;
    this = (Canli)malloc(sizeof(struct CANLI));
    this->toString = &toString;
    this->canliTuru = canliTuru;
    this->yoket = &CanliYokEt;
    return this;
}

void CanliEsle(Canli** matris, int** veriMatris, int satir, int sutun) {
    for (int i = 0; i < satir; i++) {
        for (int j = 0; j < sutun; j++) {
            int sayi = veriMatris[i][j];
            if (sayi >= 1 && sayi <= 9) {
                matris[i][j] = CanliBul('B'); // Bitki olustur
            } else if (sayi >= 10 && sayi <= 20) {
                matris[i][j] = CanliBul('C'); // Bocek olustur
            } else if (sayi >= 21 && sayi <= 50) {
                matris[i][j] = CanliBul('S'); // Sinek olustur
            } else if (sayi >= 51 && sayi <= 99) {
                matris[i][j] = CanliBul('P'); // Pire olustur
            } else {
                matris[i][j] = NULL;
            }
        }
    }
}

char* toString(const Canli this) {
    switch (this->canliTuru) {
        case 'B':
            return BitkiToString((Bitki)this);
        case 'C':
            return BocekToString((Bocek)this);
        case 'S':
            return SinekToString((Sinek)this);
        case 'P':
            return PireToString((Pire)this);
        case 'X':
            printf("X");
    }
}


void CanliYokEt(const Canli this) {
    if (this == NULL) return;
    free(this);
}
