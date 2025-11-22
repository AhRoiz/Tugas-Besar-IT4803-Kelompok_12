#ifndef CHILD_H
#define CHILD_H

#include <iostream>
#include <string>
using namespace std;

// Definisi Infotype Mobil
struct Mobil {
    string idMobil;
    string Merek;
    string Model
    int harga;
    int tahunProduksi;
    string status;
};

typedef struct Mobil infotype:

typedef struct elmMobil *address;

struct elmMobil {
    infotype info;
    address next;
};

struct ListMobil {
    address first;
};

// Primitif
void createListMobil(ListMobil &L);
address allocate(infotype x);
void createListMobil(ListMobil &L);
address allocate(infotype x);
void insertFirst(ListMobil &L, address p);
void inserLast(ListMobil &L, address p);
void insertafter(ListMobil &L,address prec, address &p);
void deleteFirst(ListMobil &L, address p);
void deleteLast(ListMobil &L, address p);
void deleteAfter(ListMobil &L, address prec, address &p);
void printInfo(ListMobil L);
void findMobil(ListMobil L);
void showAllMobil(ListMobil L);
#endif

