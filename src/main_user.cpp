
#include "Sales.h"
#include "Mobil.h"
#include "Relation.h"

// Parameter ditambah: long long totalPendapatan
void menuUser(ListSales LS, ListMobil LM, ListRelasi LR, long long totalPendapatan) {
    int pilihan;
    do {
        cout << "\n=== MENU USER ===" << endl;
        cout << "1. Show All Sales (Parent)" << endl;
        cout << "2. Show All Mobil (Child)" << endl;
        cout << "3. Show Sales dengan Mobil jualannya" << endl;
        cout << "4. Show Mobil dengan Salesnya" << endl;
        // Menu Baru
        cout << "5. Laporan Showroom Lengkap (Data + Pendapatan)" << endl;
        cout << "0. Kembali ke Menu Utama" << endl;
        cout << "Pilih: "; cin >> pilihan;

        switch(pilihan) {
            case 1: showAllSales(LS); break;
            case 2: showAllMobil(LM); break;
            case 3: showParentWithChild(LS, LR); break;
            case 4: showChildWithParent(LM, LR); break;

            // CASE 5: Pindahan dari Admin Case 8
            case 5:
                cout << "\n=== LAPORAN SHOWROOM LENGKAP ===" << endl;
                showParentWithChild(LS, LR);
                cout << "--------------------" << endl;
                showChildWithParent(LM, LR);
                cout << "--------------------" << endl;
                cout << "TOTAL PENDAPATAN DARI MOBIL TERJUAL: Rp " << totalPendapatan << endl;
                cout << "====================" << endl;
                break;
        }
    } while (pilihan != 0);
}
