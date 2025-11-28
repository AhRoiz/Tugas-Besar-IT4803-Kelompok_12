#include "Mobil.h"
#include <iostream>
using namespace std;

void createListMobil(ListMobil &L) {
    L.first = NULL;
}

adrMobil allocateMobil(infotypeMobil x) {
    adrMobil p;
    
    p = new elmMobil;
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

void deleteAfterMobil(ListMobil &L, adrMobil prec, adrMobil &p) {
    if (prec != NULL && prec->next != NULL) {
        p = prec->next;
        prec->next = p->next;
        p->next = NULL;
    }
}