#ifndef MOBIL_H_INCLUDED
#define MOBIL_H_INCLUDED

#include <iostream>
#include <string>
using namespace std;

struct Mobil {
    string id;
    string merk;
    string model;
    int harga;
    int tahunProduksi;
};

typedef struct Mobil infotypeMobil;
typedef struct elmMobil *adrMobil;

struct elmMobil {
    infotypeMobil info;
    adrMobil next;
};

struct ListMobil {
    adrMobil first;
};


// Primitif

void createListMobil(ListMobil &Lm);
adrMobil allocateMobil(infotype x);
void insertFirstMobil(ListMobil &Lm, adrMobil p);
void inserLastMobil(ListMobil &Lm, adrMobil p);
void insertafterMobil(ListMobil &Lm,adrMobil prec, adrMobil p);
void deleteFirstMobil(ListMobil &Lm, adrMobil &p);
void deleteLastMobil(ListMobil &Lm, adrMobil &p);
void deleteAfterMobil(ListMobil &Lm, adrMobil prec, adrMobil &p);
void findMobil(ListMobil Lm);
void showAllMobil(ListMobil Lm);
#endif

