#include <iostream>
#include "Sales.h"
using namespace std;

void createListSales(ListSales &L){
    L.first = nullptr;
    L.last = nullptr;
}
adrSales allocateSales(infotype x){
    adrSales p;
    p = new elmSales;
    p->info.idSales = x.idSales;
    p->info.nama = x.nama;
    p->next = nullptr;
    p->prev = nullptr;
    return p;
}
void insertFirst(ListSales &L, adrSales p){
    if (L.first == nullptr && L.last == nullptr){
        L.first = p;
        L.last = p;
    }else{
        L.first->prev = p;
        p->next = L.first;
        L.first = p;
    }
}
void inserLast(ListSales &L, adrSales p){
    if (L.first == nullptr && L.last == nullptr){
        L.first = p;
        L.last = p;
    }else{
        L.last->next = p;
        p->prev = L.last;
        L.last = p;
    }
}
void deleteAfter(ListSales &L, adrSales prec, adrSales &p){
    if (prec != nullptr && prec->next != nullptr) {
        p = prec->next;
        if (p == L.last) {
            deleteLast(L, p);
        } else {
            p->next = p->next;
            p->next->prev = prec;
            p->next = nullptr;
            p->prev = nullptr;
        }
    }
}
