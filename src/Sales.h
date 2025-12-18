#ifndef SALES_H_INCLUDED
#define SALES_H_INCLUDED

#include <iostream>
#include <string>
using namespace std;

struct Sales {
    string id;
    string nama;
    int jumlahTerjual;
    string golongan;
};

typedef struct Sales infotypeSales;
typedef struct elmSales *adrSales;

struct elmSales {
    infotypeSales info;
    adrSales next;
    adrSales prev;
};

struct ListSales {
    adrSales first;
    adrSales last;
};

void createListSales(ListSales &L);
adrSales alokasiSales(infotypeSales S);
string cekGolongan(int jumlah);
void insertFirstSales(ListSales &L, adrSales P);
void insertLastSales(ListSales &L, adrSales P);
void insertAfterSales(ListSales &L, adrSales Prec, adrSales P);
void deleteFirstSales(ListSales &L, adrSales &P);
void deleteLastSales(ListSales &L, adrSales &P);
void deleteAfterSales(ListSales &L, adrSales Prec, adrSales &P);
adrSales findSales(ListSales L, string id);
void showAllSales(ListSales L);

#endif

