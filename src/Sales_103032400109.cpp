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