#include <iostream>
#include "Sales.h"
using namespace std;

void insertAfterSales(ListSales &Ls, adrSales prec, adrSales p) {
    if (prec != nullptr) {
        if (prec == Ls.last) {
            insertLastSales(Ls, p);
        } else {
            p->next = prec->next;
            p->prev = prec;
            prec->next->prev = p;
            prec->next = p;
        }
    }
}

void deleteFirstSales(ListSales &Ls, adrSales &p) {
    if (Ls.first != nullptr) {
        p = Ls.first;
        if (Ls.first == Ls.last) {
            Ls.first = nullptr;
            Ls.last = nullptr;
        } else {
            Ls.first = p->next;
            Ls.first->prev = nullptr;
            p->next = nullptr;
        }
    }
}

void deleteLastSales(ListSales &Ls, adrSales &p) {
    if (Ls.first == nullptr) {
        p = nullptr;
    } else if (Ls.first == Ls.last) {
        p = Ls.first;
        Ls.first = nullptr;
        Ls.last = nullptr;
    } else {
        p = Ls.last;
        Ls.last = p->prev;
        Ls.last->next = nullptr;
        p->prev = nullptr;
    }
} 

adrSales findSales(ListSales Ls, string idSales) {
    adrSales p = Ls.first;
    while (p != nullptr) {
        if (p->info.idSales == idSales) {
            return p;
        }
        p = p->next;
    }
    return nullptr;
}

void showAllSales(ListSales Ls) {
    cout << "=== DATA SALES (Parent - DLL) ===" << endl;
    adrSales P = Ls.first;
    while (P != nullptr) {
        cout << "ID: " << P->info.idSales << " | Nama: " << P->info.nama << endl;
        P = P->next;
    }
    cout << endl;
}