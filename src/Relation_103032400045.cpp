#include "Relation.h"
#include <iostream>

using namespace std;

void createListRelasi(ListRelasi &L) {
    L.first = nullptr;
    L.last = nullptr;
}

adrRelasi alokasiRelasi(adrSales P, adrMobil C) {
    adrRelasi R = new elmRelasi;
    R->parent = P;
    R->child = C;
    R->next = nullptr;
    R->prev = nullptr;

    return R;
}

void insertFirstRelasi(ListRelasi &L, adrRelasi R) {
    if (L.first == nullptr) {
        L.first = R;
        L.last = R; 
    } else {
        R->next = L.first;
        L.first->prev = R;
        L.first = R;
    }
}

void insertLastRelasi(ListRelasi &L, adrRelasi R) {
    if (L.first == nullptr) {
        L.first = R;
        L.last = R; 
    } else {
        L.last->next = R;
        R->prev = L.last;
        L.last = R;
    }
}

void insertAfterRelasi(ListRelasi &L, adrRelasi Prec, adrRelasi R) {
    
}

void deleteRelasiByParent(ListRelasi &L, adrSales P);
void deleteRelasiByChild(ListRelasi &L, adrMobil C);
void showParentWithChild(ListSales LS, ListRelasi LR);
int countParentNoChild(ListSales LS, ListRelasi LR);
void editRelasi(ListRelasi &LR, adrSales oldP, adrMobil oldC, adrSales newP, adrMobil newC);