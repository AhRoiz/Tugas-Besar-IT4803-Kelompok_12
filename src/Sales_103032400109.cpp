#include <iostream>
#include "Sales.h"
using namespace std;

void createListSales(ListSales &Ls){
    Ls.first = nullptr;
    Ls.last = nullptr;
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
void insertFirst(ListSales &Ls, adrSales p){
    if (Ls.first == nullptr && Ls.last == nullptr){
        Ls.first = p;
        Ls.last = p;
    }else{
        Ls.first->prev = p;
        p->next = Ls.first;
        Ls.first = p;
    }
}
void inserLast(ListSales &Ls, adrSales p){
    if (Ls.first == nullptr && Ls.last == nullptr){
        Ls.first = p;
        Ls.last = p;
    }else{
        Ls.last->next = p;
        p->prev = Ls.last;
        Ls.last = p;
    }
}
void deleteAfter(ListSales &Ls, adrSales prec, adrSales &p){
    if (prec != nullptr && prec->next != nullptr) {
        p = prec->next;
        if (p == Ls.last) {
            deleteLast(Ls, p);
        } else {
            p->next = p->next;
            p->next->prev = prec;
            p->next = nullptr;
            p->prev = nullptr;
        }
    }
}
