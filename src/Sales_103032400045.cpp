#include <iostream>
#include "Sales.h"
using namespace std;

void insertAfterSales(ListSales &L, adrSales prec, adrSales p) {
    if (prec != nullptr) {
        if (prec == L.last) {
            insertLastSales(L, p);
        } else {
            p->next = prec->next;
            p->prev = prec;
            prec->next->prev = p;
            prec->next = p;
        }
    }
}

void deleteFirstSales(ListSales &L, adrSales &p) {
    if (L.first != nullptr) {
        p = L.first;
        if (L.first == L.last) {
            L.first = nullptr;
            L.last = nullptr;
        } else {
            L.first = p->next;
            L.first->prev = nullptr;
            p->next = nullptr;
        }
    }
}

void deleteLastSales(ListSales &L, adrSales &p) {
    if (L.first == nullptr) {
        p = nullptr;
    } else if (L.first == L.last) {
        p = L.first;
        L.first = nullptr;
        L.last = nullptr;
    } else {
        p = L.last;
        L.last = p->prev;
        L.last->next = nullptr;
        p->prev = nullptr;
    }
} 