#include "Mobil.h"
#include <iostream>
using namespace std;

void createListMobil(ListMobil &Lm) {
    Lm.first = NULL;
}

adrMobil allocateMobil(infotypeMobil x) {
    adrMobil p;
    
    p = new elmMobil;
    p->info.idMobil = x.idMobil;
    p->info.merk = x.merk;
    p->info.model = x.model;
    p->info.harga = x.harga;
    p->info.tahunProduksi = x.tahunProduksi;
    p->next = nullptr;

    return p;
}

void insertFirstMobil(ListMobil &Lm, adrMobil p) {
    p->next = Lm.first;
    Lm.first = p;
}

void insertLastMobil(ListMobil &Lm, adrMobil p) {
    if (Lm.first == nullptr) {
        insertFirstMobil(Lm, p);
    } else {
        adrMobil Q = Lm.first;
        while (Q->next != nullptr) {
            Q = Q->next;
        }
        Q->next = p;
    }
}

void deleteAfterMobil(ListMobil &Lm, adrMobil prec, adrMobil &p) {
    if (prec != nullptr && prec->next != nullptr) {
        p = prec->next;
        prec->next = p->next;
        p->next = nullptr;
    }
}