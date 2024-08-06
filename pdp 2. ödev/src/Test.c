#include "DosyaOku.h"
#include "MatrisOlustur.h"
#include "Canli.h"
#include "Bitki.h"
#include "stdio.h"
#include "stdlib.h"
#include "time.h"
#include "string.h"
#include "Habitat.h"

int main()
{
    char *dosya = DosyaOkuYaz("Veri.txt"); // Dosya içeriğini oku
    if (dosya == NULL)
    {
        printf("Dosya okunamadi.\n");
        return 1;
    }
    Boyut boyut;
    int **matris = MatrisOlustur("Veri.txt", &boyut); 
    if (matris == NULL)
    {
        printf("Matris olusturulamadi.\n");
        free(dosya); 
        return 1;
    }
    Canli **canlilar = CanliMatrisOlustur("Veri.txt", &boyut);
    CanliEsle(canlilar, matris, boyut.satir, boyut.sutun);
    CanliMatrisYazdir(canlilar, &boyut);
    printf("Lutfen bir tusa basiniz.");
    getch();
    KazananiBul(canlilar, &boyut, matris);
    CanliMatrisYoket(canlilar, &boyut);
    MatrisYoket(matris, &boyut);

    free(dosya);
    return 0;
}
