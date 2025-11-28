#ifndef SALsES_H_INCLsUDED
#define SALsES_H_INCLsUDED

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
void createListSales(ListSales &Ls);
adrSales allocateSales(infotype x);
void insertFirst(ListSales &Ls, adrSales p);
void inserLast(ListSales &Ls, adrSales p);
void insertafter(ListSales &Ls,adrSales prec, adrSales p);
void deleteFirst(ListSales &Ls, adrSales &p);
void deleteLast(ListSales &Ls, adrSales &p);
void deleteAfter(ListSales &Ls, adrSales prec, adrSales &p);
adrSales findSales(ListSales Ls, string IDsales);
void showAllSales(ListSales Ls);
#endif
