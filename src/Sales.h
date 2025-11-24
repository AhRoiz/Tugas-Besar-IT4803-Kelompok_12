#ifndef PARENT_H
#define PARENT_H

#include <iostream>
#include <string>
using namespace std;

//Child 
struct Sales {
    string idSales;
    string nama;
    float rating;
    int targetPenjualan;
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
adrSales allocate(infotype x);
void insertFirst(ListSales &L, adrSales p);
void inserLast(ListSales &L, adrSales p);
void insertafter(ListSales &L,adrSales prec, adrSales &p);
void deleteFirst(ListSales &L, adrSales p);
void deleteLast(ListSales &L, adrSales p);
void deleteAfter(ListSales &L, adrSales prec, adrSales &p);
void printInfo(ListSales L);
void findSales(ListSales L);
void showAllSales(ListSales L);
//halo
#endif
