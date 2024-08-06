#include "Habitat.h"
#include "stdio.h"
#include "stdlib.h"
#include <time.h> // nanosleep için
#include <unistd.h>
#include "conio.h"
#include "MatrisOlustur.h"
Habitat HabitatOlustur()
{
    Habitat this;
    this = (Habitat)malloc(sizeof(struct HABITAT));
    if (this == NULL)
    {
        printf("Habitat oluşturulamadı. Bellek yetersiz.");
        return NULL;
    }
    this->yokEt = &HabitatYokEt;
    return this;
}

Canli *KazananiBul(Canli **canlilar, Boyut *boyut, int **matris)
{
    Canli *kazanan = NULL;
    int satir_kazanan = 0;
    int sutun_kazanan = 0;

    struct timespec bekleme_suresi;
    bekleme_suresi.tv_sec = 1;
    bekleme_suresi.tv_nsec = 0;

    for (int i = 0; i < boyut->satir; i++)
    {
        for (int j = 0; j < boyut->sutun; j++)
        {
            if (kazanan == NULL) //kazanan ilk olarak Null'dir. İlk buraya girer.
            {
                kazanan = &canlilar[0][0]; //0,0 konumuna atanır.
                satir_kazanan = i; //satir ve sutunun nerede oldugunu tutmaya arar. 
                sutun_kazanan = j;
            }
            if ((j + 1) < boyut->sutun) 
            { //yeme kurallarına gore ilerler.
                if (((*kazanan)->canliTuru == 'C' && canlilar[i][j + 1]->canliTuru == 'B') ||
                    ((*kazanan)->canliTuru == 'B' && canlilar[i][j + 1]->canliTuru == 'P') ||
                    ((*kazanan)->canliTuru == 'S' && canlilar[i][j + 1]->canliTuru == 'P') ||
                    ((*kazanan)->canliTuru == 'B' && canlilar[i][j + 1]->canliTuru == 'S') ||
                    ((*kazanan)->canliTuru == 'S' && canlilar[i][j + 1]->canliTuru == 'C') ||
                    ((*kazanan)->canliTuru == 'C' && canlilar[i][j + 1]->canliTuru == 'P'))
                {
                    canlilar[i][j + 1]->canliTuru = 'X'; //kazanan aynıdır. O yuzden kazanan degeri degistirilmemistir.
                }
                else if (((*kazanan)->canliTuru == 'B' && canlilar[i][j + 1]->canliTuru == 'C') ||
                         ((*kazanan)->canliTuru == 'P' && canlilar[i][j + 1]->canliTuru == 'B') ||
                         ((*kazanan)->canliTuru == 'P' && canlilar[i][j + 1]->canliTuru == 'S') ||
                         ((*kazanan)->canliTuru == 'S' && canlilar[i][j + 1]->canliTuru == 'B') ||
                         ((*kazanan)->canliTuru == 'C' && canlilar[i][j + 1]->canliTuru == 'S') ||
                         ((*kazanan)->canliTuru == 'P' && canlilar[i][j + 1]->canliTuru == 'C'))
                {//bu tam tersi geldiginde kazananın değişmesi için oluşturulmuştur.
                    (*kazanan)->canliTuru = 'X';   // tam tersi oldugu için kazanan değisti.
                    kazanan = &canlilar[i][j + 1]; // kazanana yeni deger atandı.
                    satir_kazanan = i;             // Satır güncellendi
                    sutun_kazanan = j + 1;         // Sütun güncellendi
                }
                else if (((*kazanan)->canliTuru == 'B' && canlilar[i][j + 1]->canliTuru == 'B') ||
                         ((*kazanan)->canliTuru == 'C' && canlilar[i][j + 1]->canliTuru == 'C') ||
                         ((*kazanan)->canliTuru == 'S' && canlilar[i][j + 1]->canliTuru == 'S') ||
                         ((*kazanan)->canliTuru == 'P' && canlilar[i][j + 1]->canliTuru == 'P'))
                {// aynı gelen harfler için koşul eklenmiştir.
                    if (matris[satir_kazanan][sutun_kazanan] > matris[i][j + 1])
                    {  //sayı degeri buyuk olan kazanmıştır.
                        canlilar[i][j + 1]->canliTuru = 'X';
                        kazanan = &canlilar[satir_kazanan][sutun_kazanan];
                        satir_kazanan = satir_kazanan; // Satırı güncelle
                        sutun_kazanan = sutun_kazanan; // Sütunu güncelle
                    }
                    else if (matris[i][j + 1] > matris[satir_kazanan][sutun_kazanan])
                    {
                        canlilar[satir_kazanan][sutun_kazanan]->canliTuru = 'X';
                        kazanan = &canlilar[i][j + 1];
                        satir_kazanan = i;     // Satırı güncelle
                        sutun_kazanan = j + 1; // Sütunu güncelle
                    }
                    else if (matris[satir_kazanan][sutun_kazanan] == matris[i][j + 1])
                    {//sayı degeri eşit ise uzaklıklara bakılmıştır.
                        // Kazanacak olanı belirlemek için matris değerlerine göre uzaklık hesaplanıyor
                        int uzaklik1 = ((boyut->sutun - 1) - sutun_kazanan) + (((boyut->satir - 1) - satir_kazanan) * boyut->sutun);
                        int uzaklik2 = ((boyut->sutun - 1) - (j + 1)) + (((boyut->satir - 1) - i) * boyut->sutun);

                        if (uzaklik1 < uzaklik2) // Uzaklık 1 daha yakınsa
                        {
                            canlilar[satir_kazanan][sutun_kazanan]->canliTuru = 'X'; // Uzaklığı büyük olan kaybeder
                            kazanan = &canlilar[i][j + 1];                           // Yeni kazanan bu olur
                            satir_kazanan = i;                                       // Satırı güncelle
                            sutun_kazanan = j + 1;                                   // Sütunu güncelle
                        }
                        else // Uzaklık 2 daha yakınsa
                        {
                            canlilar[i][j + 1]->canliTuru = 'X';               // Uzaklığı büyük olan kaybeder
                            kazanan = &canlilar[satir_kazanan][sutun_kazanan]; // Yeni kazanan bu olur
                            satir_kazanan = satir_kazanan;                     // Satırı güncelle
                            sutun_kazanan = sutun_kazanan;                     // Sütunu güncelle
                        }
                    }
                }
                system("cls");
                CanliMatrisYazdir(canlilar, boyut);
                nanosleep(&bekleme_suresi, NULL);
            }
            //üst satırda kazanan harfin alt satır ile kıyaslanması için ayrı koşul eklenmiştir.
            else if ((j + 1) == boyut->sutun && (i + 1) < boyut->satir)
            {
                if (((*kazanan)->canliTuru == 'C' && canlilar[i + 1][0]->canliTuru == 'B') ||
                    ((*kazanan)->canliTuru == 'B' && canlilar[i + 1][0]->canliTuru == 'P') ||
                    ((*kazanan)->canliTuru == 'S' && canlilar[i + 1][0]->canliTuru == 'P') ||
                    ((*kazanan)->canliTuru == 'B' && canlilar[i + 1][0]->canliTuru == 'S') ||
                    ((*kazanan)->canliTuru == 'S' && canlilar[i + 1][0]->canliTuru == 'C') ||
                    ((*kazanan)->canliTuru == 'C' && canlilar[i + 1][0]->canliTuru == 'P'))
                {
                    canlilar[i + 1][0]->canliTuru = 'X'; // kazanan değismedi
                }
                else if (((*kazanan)->canliTuru == 'B' && canlilar[i + 1][0]->canliTuru == 'C') ||
                         ((*kazanan)->canliTuru == 'P' && canlilar[i + 1][0]->canliTuru == 'B') ||
                         ((*kazanan)->canliTuru == 'P' && canlilar[i + 1][0]->canliTuru == 'S') ||
                         ((*kazanan)->canliTuru == 'S' && canlilar[i + 1][0]->canliTuru == 'B') ||
                         ((*kazanan)->canliTuru == 'C' && canlilar[i + 1][0]->canliTuru == 'S') ||
                         ((*kazanan)->canliTuru == 'P' && canlilar[i + 1][0]->canliTuru == 'C'))
                {
                    (*kazanan)->canliTuru = 'X';
                    kazanan = &canlilar[i + 1][0];
                    satir_kazanan = i + 1; // Satırı güncelle
                    sutun_kazanan = 0;     // Sütunu güncelle
                }
                else if (((*kazanan)->canliTuru == 'B' && canlilar[i + 1][0]->canliTuru == 'B') ||
                         ((*kazanan)->canliTuru == 'C' && canlilar[i + 1][0]->canliTuru == 'C') ||
                         ((*kazanan)->canliTuru == 'S' && canlilar[i + 1][0]->canliTuru == 'S') ||
                         ((*kazanan)->canliTuru == 'P' && canlilar[i + 1][0]->canliTuru == 'P'))
                {
                    if (matris[satir_kazanan][sutun_kazanan] > matris[i + 1][0])
                    {
                        canlilar[i + 1][0]->canliTuru = 'X';
                        kazanan = &canlilar[satir_kazanan][sutun_kazanan];
                        satir_kazanan = satir_kazanan; // Satırı güncelle
                        sutun_kazanan = sutun_kazanan; // Sütunu güncelle
                    }
                    else if (matris[i + 1][0] > matris[satir_kazanan][sutun_kazanan])
                    {
                        canlilar[satir_kazanan][sutun_kazanan]->canliTuru = 'X';
                        kazanan = &canlilar[i + 1][0];
                        satir_kazanan = i + 1; // Satırı güncelle
                        sutun_kazanan = 0;     // Sütunu güncelle
                    }

                    else if (matris[satir_kazanan][sutun_kazanan] == matris[i + 1][0])
                    {

                        canlilar[i + 1][0]->canliTuru = 'X';
                        kazanan = &canlilar[satir_kazanan][sutun_kazanan];
                        satir_kazanan = satir_kazanan; // Satırı güncelle
                        sutun_kazanan = sutun_kazanan; // Sütunu güncelle
                    }
                }
                system("cls");
                CanliMatrisYazdir(canlilar, boyut);
                nanosleep(&bekleme_suresi, NULL);
            }
            else if ((i + 1) == boyut->satir && (j + 1) == boyut->sutun)
            {
                break;
            }
        }
    }
    // Sonucu ekrana yazdır
    if (kazanan != NULL)
    {
        printf("Kazanan: %c : (%d, %d)\n",(*kazanan)->canliTuru, satir_kazanan, sutun_kazanan);
        return kazanan;
    }
    return NULL;
}

void HabitatYokEt(const Habitat this)
{
    if (this == NULL)
        return;
    free(this); // Habitat yapısını tutan belleği serbest bırak
}
