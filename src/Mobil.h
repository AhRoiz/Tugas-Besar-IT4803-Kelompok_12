#ifndef CHILD_H
#define CHILD_H

#include <iostream>
#include <string>
using namespace std;

//Parent 
// Definisi Infotype Mobil
struct Mobil {
    string idMobil;
    string Merek;
    string Model;
    int harga;
    int tahunProduksi;
    string status;
};

typedef struct Mobil infotype;

typedef struct elmMobil *adrMobil;

struct elmMobil {
    infotype info;
    adrMobil next;
};

struct ListMobil {
    adrMobil first;
};

// Primitif
void createListMobil(ListMobil &L);
adrMobil allocate(infotype x);
void createListMobil(ListMobil &L);
adrMobil allocate(infotype x);
void insertFirst(ListMobil &L, adrMobil p);
void inserLast(ListMobil &L, adrMobil p);
void insertafter(ListMobil &L,adrMobil prec, adrMobil &p);
void deleteFirst(ListMobil &L, adrMobil p);
void deleteLast(ListMobil &L, adrMobil p);
void deleteAfter(ListMobil &L, adrMobil prec, adrMobil &p);
void printInfo(ListMobil L);
void findMobil(ListMobil L);
void showAllMobil(ListMobil L);
#endif

