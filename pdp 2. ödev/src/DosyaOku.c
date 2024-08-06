#include "DosyaOku.h"

char* DosyaOkuYaz(char* dosyaAdi) {
    char* icerik = NULL;
    int uzunluk = 0;
    
    FILE* dosya;
    dosya=fopen(dosyaAdi, "r");

    if (!dosya) {
        return "HATA";
    }

    fseek(dosya, 0, SEEK_END);
    uzunluk = ftell(dosya); 
    rewind(dosya);

    icerik = (char*)malloc(sizeof(char) * (uzunluk + 1));

    if (!icerik) {
        fclose(dosya);
        return NULL;
    }

    uzunluk = fread(icerik, 1, uzunluk, dosya); 
    icerik[uzunluk] = '\0';

    fclose(dosya);
    return icerik;
}



