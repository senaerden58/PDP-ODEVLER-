#include "MatrisOlustur.h"

Boyut MatrisBoyutuBelirle(char *dosyaAdi)
{
    DosyaOku dosya = (DosyaOku)malloc(sizeof(struct DOSYAOKU));
    dosya->DosyaOkuYaz = &DosyaOkuYaz;
    dosya->icerik = dosya->DosyaOkuYaz(dosyaAdi);

    Boyut boyut;
    boyut.satir = 0;
    boyut.sutun = 0;

    if (dosya->icerik == NULL || strcmp(dosya->icerik, "HATA") == 0)
    {
        free(dosya->icerik);
        free(dosya);
        return boyut;
    }

    int satirSayisi = 0;
    int sutunSayisi = 0;
    char *temp = dosya->icerik;
    while (*temp != '\0')
    {
        if (*temp == '\n')
        {
            satirSayisi++;
        }
        else if (*temp == ' ' && satirSayisi == 0)
        {
            sutunSayisi++;
        }
        temp++;
    }
    sutunSayisi++;
    satirSayisi++;

    boyut.satir = satirSayisi;
    boyut.sutun = sutunSayisi;
    free(dosya->icerik);
    free(dosya);
    return boyut;
}

int **MatrisOlustur(char *dosyaAdi, Boyut *boyut)
{
    *boyut = MatrisBoyutuBelirle(dosyaAdi);
    if (boyut->satir == -1)
    {
        printf("Matris boyutu belirlenemedi!\n");
        return NULL;
    }

    printf("Satir sayisi: %d\n", boyut->satir);
    printf("Sutun sayisi: %d\n", boyut->sutun);

    // Matris oluştur
    int **matris = (int **)malloc(boyut->satir * sizeof(int *));
    char *dosyaIcerik = DosyaOkuYaz(dosyaAdi);
    int index = 0;
    for (int i = 0; i < boyut->satir; i++)
    {
        matris[i] = (int *)malloc(boyut->sutun * sizeof(int));
        if (!matris[i])
        {
            for (int j = 0; j < i; j++)
            {
                free(matris[j]);
            }
            free(matris);
            printf("Matris olusturulamadi!\n");
            return NULL;
        }
        for (int j = 0; j < boyut->sutun; j++)
        {
            // Dosyadan okunan veriyi diziye aktar
            char *temp;
            matris[i][j] = strtol(&dosyaIcerik[index], &temp, 10);
            index = temp - dosyaIcerik;
        }
    }

    free(dosyaIcerik);

    return matris;
}

Canli **CanliMatrisOlustur(char *dosyaAdi, Boyut *boyut)
{
    // Matris boyutunu al
    *boyut = MatrisBoyutuBelirle(dosyaAdi);
    // Boyut belirlenemediyse
    if (boyut->satir == -1)
    {
        printf("Matris boyutu belirlenemedi!\n");
        return NULL;
    }

    // Canli matrisi oluştur
    Canli **canliMatris = (Canli **)malloc(boyut->satir * sizeof(Canli *));
    if (!canliMatris)
    {
        printf("Canli matris olusturulamadi!\n");
        return NULL;
    }

    char *dosyaIcerik = DosyaOkuYaz(dosyaAdi);
    if (!dosyaIcerik)
    {
        printf("Dosya okunamadi!\n");
        free(canliMatris);
        return NULL;
    }

    // Dosya içeriğini kullanarak canli matrisini oluştur
    int index = 0;
    for (int i = 0; i < boyut->satir; i++)
    {
        canliMatris[i] = (Canli *)malloc(boyut->sutun * sizeof(Canli));
        if (!canliMatris[i])
        {
            for (int j = 0; j < i; j++)
            {
                free(canliMatris[j]);
            }
            free(canliMatris);
            printf("Canli matris olusturulamadi!\n");
            free(dosyaIcerik);
            return NULL;
        }
        for (int j = 0; j < boyut->sutun; j++)
        {
            // Dosyadan okunan veriyi diziye aktar
            char *temp;
            int canliTur = strtol(&dosyaIcerik[index], &temp, 10);
            index = temp - dosyaIcerik;

            Canli canli = CanliBul(canliTur); // canliTur, dosyadan okunan canli türü
            canliMatris[i][j] = canli;        // Canli yapısının adresini kullanarak değeri atar
        }
    }

    free(dosyaIcerik);

    return canliMatris;
}

void MatrisYazdir(int **matris, Boyut *boyut)
{
    for (int i = 0; i < boyut->satir; i++)
    {
        for (int j = 0; j < boyut->sutun; j++)
        {
            printf(" | ");
            printf("%d ", matris[i][j]);
        }
        printf("| \n");
    }
}

void MatrisYoket(int **matris, Boyut *boyut)
{
    for (int i = 0; i < boyut->satir; i++)
    {
        free(matris[i]);
    }
    free(matris);
}

void CanliMatrisYazdir(Canli **canlilar, Boyut *boyut)
{
    for (int i = 0; i < boyut->satir; i++)
    {
        for (int j = 0; j < boyut->sutun; j++)
        {
            printf(" | %c ", canlilar[i][j]->canliTuru);
        }
        printf("|\n");
    }
}

void CanliMatrisYoket(Canli **matris, Boyut *boyut)
{
    for (int i = 0; i < boyut->satir; i++)
    {
        for (int j = 0; j < boyut->sutun; j++)
        {
            matris[i][j]->yoket(matris[i][j]);
        }
        free(matris[i]);
    }
    free(matris);
}
