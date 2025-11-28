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

void createListMobil(ListMobil &Lm);
adrMobil allocateMobil(infotype x);
void insertFirstMobil(ListMobil &Lm, adrMobil p);
void inserLastMobil(ListMobil &Lm, adrMobil p);
void insertafterMobil(ListMobil &Lm,adrMobil prec, adrMobil p);
void deleteFirstMobil(ListMobil &Lm, adrMobil &p);
void deleteLastMobil(ListMobil &Lm, adrMobil &p);
void deleteAfterMobil(ListMobil &Lm, adrMobil prec, adrMobil &p);
adrMobil findMobil(ListMobil Lm, string IDmobil);
void showAllMobil(ListMobil Lm);
#endif

