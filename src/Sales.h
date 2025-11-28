#ifndef SALES_H_INCLUDED
#define SALES_H_INCLUDED

#include <iostream>
#include <string>
using namespace std;

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
void createListSales(ListSales &Ls);
adrSales allocateSales(infotype x);
void insertFirstSales(ListSales &Ls, adrSales p);
void insertLastSales(ListSales &Ls, adrSales p);
void insertafterSales(ListSales &Ls,adrSales prec, adrSales p);
void deleteFirstSales(ListSales &Ls, adrSales &p);
void deleteLastSales(ListSales &Ls, adrSales &p);
void deleteAfterSales(ListSales &Ls, adrSales prec, adrSales &p);
adrSales findSales(ListSales Ls, string IDsales);
void showAllSales(ListSales Ls);
#endif
