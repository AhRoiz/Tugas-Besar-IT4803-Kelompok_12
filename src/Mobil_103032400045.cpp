#include "Mobil.h"

void createListMobil(ListMobil &L) {
    L.first = NULL;
}

adrMobil allocateMobil(infotypeMobil x) {
    adrMobil P = new elmMobil;
    P->info.id = x.id;
    P->info.merk = x.merk;
    P->info.model = x.model;
    P->info.harga = x.harga;
    P->info.tahunProduksi = x.tahunProduksi;
    P->next = nullptr;

    return P;
}

void insertFirstMobil(ListMobil &L, adrMobil P) {
    P->next = L.first;
    L.first = P;
}

void insertLastMobil(ListMobil &L, adrMobil P) {
    if (L.first == NULL) {
        insertFirstMobil(L, P);
    } else {
        adrMobil Q = L.first;
        while (Q->next != NULL) {
            Q = Q->next;
        }
        Q->next = P;
    }
}

void deleteAfterMobil(ListMobil &L, adrMobil Prec, adrMobil &P) {
    if (Prec != NULL && Prec->next != NULL) {
        P = Prec->next;
        Prec->next = P->next;
        P->next = NULL;
    }
}