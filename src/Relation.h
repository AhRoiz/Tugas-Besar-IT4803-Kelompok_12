#ifndef RELATION_H
#define RELATION_H

#include "Sales.h"
#include "Mobil.h"

typedef struct elmRelasi *adrRelasi;

struct elmRelasi
{
    adrSales parent;
    adrMobil child;
    adrRelasi next;
    adrRelasi prev;
};

struct ListRelasi
{
    adrRelasi first;
    adrRelasi last;
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

void showParentWithChild(ListSales LS, ListRelasi LR);
void showChildWithParent(ListMobil LM, ListRelasi LR);
void showChildParentTertentu(ListRelasi LR, adrSales P);
void showParentChildTertentu(ListRelasi LR, adrMobil C);
int countChildParentTertentu(ListRelasi LR, adrSales P);
int countParentsChildTertentu(ListRelasi LR, adrMobil C);
void countChildTanpaParent(ListRelasi LR, ListMobil LM);
void countParentTanpaChild(ListRelasi LR, ListSales LS);
// --- TAMBAHAN BARU ---
void updateRelasi(ListRelasi &LR, ListSales LS, ListMobil LM, string idSLama, string idMLama, string idSBaru, string idMBaru);

#endif
