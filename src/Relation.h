#ifndef RELATION_H_INCLUDED
#define RELATION_H_INCLUDED

#include "Sales.h"
#include "Mobil.h"

typedef struct elmRelasi *adrRelasi;

struct elmRelasi {
    adrSales parent;
    adrMobil child;
    adrRelasi next;
};

struct ListRelasi {
    adrRelasi first;
};

void createListRelasi(ListRelasi &L);
adrRelasi alokasiRelasi(adrSales P, adrMobil C);

void insertFirstRelasi(ListRelasi &L, adrRelasi R);
void insertLastRelasi(ListRelasi &L, adrRelasi R);
void insertAfterRelasi(ListRelasi &L, adrRelasi Prec, adrRelasi R);

void deleteFirstRelasi(ListRelasi &L, adrRelasi &R);
void deleteLastRelasi(ListRelasi &L, adrRelasi &R);
void deleteAfterRelasi(ListRelasi &L, adrRelasi Prec, adrRelasi &R);

void deleteRelasiSpecific(ListRelasi &L, adrSales P, adrMobil C, adrRelasi &R);
adrRelasi findRelasi(ListRelasi L, adrSales P, adrMobil C);

void deleteRelasiByParent(ListRelasi &L, adrSales P);
void deleteRelasiByChild(ListRelasi &L, adrMobil C);


#endif
