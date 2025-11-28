#include "Mobil.h"

void createListMobil(ListMobil &L) {
    L.first = NULL;
}

adrMobil allocateMobil(infotypeMobil x) {
    adrMobil p = new elmMobil;
    p->info.id = x.id;
    p->info.merk = x.merk;
    p->info.model = x.model;
    p->info.harga = x.harga;
    p->info.tahunProduksi = x.tahunProduksi;
    p->next = nullptr;

    return p;
}

void insertFirstMobil(ListMobil &L, adrMobil p) {
    p->next = L.first;
    L.first = p;
}

void insertLastMobil(ListMobil &L, adrMobil p) {
    if (L.first == NULL) {
        insertFirstMobil(L, p);
    } else {
        adrMobil Q = L.first;
        while (Q->next != NULL) {
            Q = Q->next;
        }
        Q->next = p;
    }
}

void deleteAfterMobil(ListMobil &L, adrMobil Prec, adrMobil &p) {
    if (Prec != NULL && Prec->next != NULL) {
        p = Prec->next;
        Prec->next = p->next;
        p->next = NULL;
    }
}