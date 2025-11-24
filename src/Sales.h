#ifndef SALES_H_INCLUDED
#define SALES_H_INCLUDED

#include <iostream>
#include <string>
using namespace std;

//Child 
struct Sales {
    string idSales;
    string nama;
};

typedef struct Sales infotype;

typedef struct elmSales *adrSales;

struct elmSales {
    infotype info;
    adrSales next;
    adrSales prev;
};

struct ListSales {
    adrSales first;
    adrSales last;
};

// Primitif
void createListSales(ListSales &L);
adrSales allocateSales(infotype x);
void insertFirst(ListSales &L, adrSales p);
void inserLast(ListSales &L, adrSales p);
void insertafter(ListSales &L,adrSales prec, adrSales &p);
void deleteFirst(ListSales &L, adrSales p);
void deleteLast(ListSales &L, adrSales p);
void deleteAfter(ListSales &L, adrSales prec, adrSales &p);
void findSales(ListSales L);
void showAllSales(ListSales L);
#endif
