#ifndef CHILD_H
#define CHILD_H

#include <iostream>
#include <string>
using namespace std;

// Definisi Infotype Sales
struct Mobil {
    string idMobil;
    string Merek;
    string Model
    int harga;
    int tahunProduksi;
    string status;
};

typedef struct Mobil infotype:

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

#endif

