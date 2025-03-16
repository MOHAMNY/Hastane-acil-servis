#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Hasta {
    int id;
    char ad[50];
    int yas;
    char tani[100];
    int oncelik;
    int receteNo;
    struct Hasta* sonraki;
} Hasta;

Hasta* bas = NULL;
int hastaSayaci = 1;
int receteSayaci = 1000;

void hastaEkle(char ad[], int yas, char tani[], int oncelik) {
    Hasta* yeniHasta = (Hasta*)malloc(sizeof(Hasta));
    yeniHasta->id = hastaSayaci++;
    strcpy(yeniHasta->ad, ad);
    yeniHasta->yas = yas;
    strcpy(yeniHasta->tani, tani);
    yeniHasta->oncelik = oncelik;
    yeniHasta->receteNo = receteSayaci++;
    yeniHasta->sonraki = NULL;

    if (bas == NULL || oncelik < bas->oncelik) {
        yeniHasta->sonraki = bas;
        bas = yeniHasta;
    } else {

        Hasta* mevcut = bas;
        while (mevcut->sonraki != NULL && mevcut->sonraki->oncelik <= oncelik) {
            mevcut = mevcut->sonraki;
        }
        yeniHasta->sonraki = mevcut->sonraki;
        mevcut->sonraki = yeniHasta;
    }
    printf("Hasta eklendi: %s (ID: %d, Oncelik: %d, Recete No: %d)\n", ad, yeniHasta->id, yeniHasta->oncelik, yeniHasta->receteNo);
}

void hastaListele() {
    if (bas == NULL) {
        printf("Acil serviste bekleyen hasta yok.\n");
        return;
    }
    printf("\n--- Acil Servis Bekleyen Hastalar ---\n");
    Hasta* gecici = bas;
    while (gecici != NULL) {
        printf("ID: %d, Ad: %s, Yas: %d, Tani: %s, Oncelik: %d, Recete No: %d\n", 
            gecici->id, gecici->ad, gecici->yas, gecici->tani, gecici->oncelik, gecici->receteNo);
        gecici = gecici->sonraki;
    }
}

void hastaIsle() {
    if (bas == NULL) {
        printf("Bekleyen hasta yok.\n");
        return;
    }
    Hasta* silinecek = bas;
    printf("Hasta isleme alindi: %s (ID: %d, Recete No: %d)\n", silinecek->ad, silinecek->id, silinecek->receteNo);
    bas = bas->sonraki;
    free(silinecek);
}

int main() {
    int secim;
    char ad[50];
    int yas, oncelik;
    char tani[100];

    while (1) {
        printf("\n--- Acil Servis Sistemi ---\n");
        printf("1. Yeni Hasta Ekle\n");
        printf("2. Hasta Listesini Goruntule\n");
        printf("3. Hastayi Isleme Al\n");
        printf("4. Cikis\n");
        printf("Seciminizi yapin: ");
        scanf("%d", &secim);
        getchar();

        switch (secim) {
            case 1:
                printf("Hasta adi: ");
                fgets(ad, sizeof(ad), stdin);
                ad[strcspn(ad, "\n")] = 0; 
                printf("Yas: ");
                scanf("%d", &yas);
                getchar();
                printf("Tani: ");
                fgets(tani, sizeof(tani), stdin);
                tani[strcspn(tani, "\n")] = 0;
                printf("Oncelik (1: Kritik, 2: Orta, 3: Hafif): ");
                scanf("%d", &oncelik);
                hastaEkle(ad, yas, tani, oncelik);
                break;
            case 2:
                hastaListele();
                break;
            case 3:
                hastaIsle();
                break;
            case 4:
                printf("Sistemden cikiliyor...\n");
                return 0;
            default:
                printf("Gecersiz secim, tekrar deneyin.\n");
        }
    }
    return 0;
}