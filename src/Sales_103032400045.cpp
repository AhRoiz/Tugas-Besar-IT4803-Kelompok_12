#include <iostream>
#include "Sales.h"
using namespace std;

void insertAfterSales(ListSales &L, adrSales prec, adrSales p) {
    if (prec != NULL) {
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
    if (L.first != NULL) {
        p = L.first;
        if (L.first == L.last) {
            L.first = NULL;
            L.last = NULL;
        } else {
            L.first = p->next;
            L.first->prev = NULL;
            p->next = NULL;
        }
    }
}