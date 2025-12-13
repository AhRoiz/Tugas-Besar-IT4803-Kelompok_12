#include <iostream>
#include "Sales.h"
#include "Mobil.h"
#include "Relation.h"

using namespace std;

// Update Prototype fungsi agar menerima parameter totalPendapatan
void menuAdmin(ListSales &LS, ListMobil &LM, ListRelasi &LR, long long &totalPendapatan);
void menuUser(ListSales LS, ListMobil LM, ListRelasi LR, long long totalPendapatan);

int main() {
    ListSales LS;
    ListMobil LM;
    ListRelasi LR;

    createListSales(LS);
    createListMobil(LM);
    createListRelasi(LR);

    // Variabel Penampung Pendapatan (Shared Variable)
    long long totalPendapatan = 0;

    int peran;
    do {
        cout << "\n=== DEALER SYSTEM ===" << endl;
        cout << "1. Admin" << endl;
        cout << "2. User" << endl;
        cout << "0. Exit" << endl;
        cout << "Pilih: "; cin >> peran;

        if (peran == 1) {
            // Admin bisa mengubah totalPendapatan (pass by reference)
            menuAdmin(LS, LM, LR, totalPendapatan);
        } else if (peran == 2) {
            // User hanya melihat (pass by value)
            menuUser(LS, LM, LR, totalPendapatan);
        }
    } while (peran != 0);

    return 0;
}
