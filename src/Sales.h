#ifndef PARENT_H
#define PARENT_H

#include <iostream>
#include <string>
using namespace std;

struct Sales {
    string idSales;
    string nama;
    float rating;
    int targetPenjualan;
};

typedef Sales infotype;

typedef struct elmSales *address;

struct elmSales {
    infotype info;
    address next;
    address prev;
};

struct ListSales {
    address first;
    address last;
};

// Primitif
void createListSales(ListSales &L);
address allocate(infotype x);
void insertFirst(ListSales &L, address p);
void inserLast(ListSales &L, address p);
void insertafter(ListSales &L,address prec, address &p);
void deleteFirst(ListSales &L, address p);
void deleteLast(ListSales &L, address p);
void deleteAfter(ListSales &L, address prec, address &p);
void printInfo(ListSales L);
void findSales(ListSales L);
void showAllSales(ListSales L);
//halo
#endif
