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