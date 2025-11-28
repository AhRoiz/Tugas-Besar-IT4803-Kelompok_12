#ifndef MOBIL_H_INCLUDED
#define MOBIL_H_INCLUDED

#include <iostream>
#include <string>
using namespace std;

struct Mobil {
    string idMobil;
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
adrMobil allocateMobil(infotypeMobil x);
void insertFirstMobil(ListMobil &Lm, adrMobil p);
void inserLastMobil(ListMobil &Lm, adrMobil p);
void insertafterMobil(ListMobil &Lm,adrMobil prec, adrMobil p);
void deleteFirstMobil(ListMobil &Lm, adrMobil &p);
void deleteLastMobil(ListMobil &Lm, adrMobil &p);
void deleteAfterMobil(ListMobil &Lm, adrMobil prec, adrMobil &p);
adrMobil findMobil(ListMobil Lm, string idMobil);
void showAllMobil(ListMobil Lm);
#endif

