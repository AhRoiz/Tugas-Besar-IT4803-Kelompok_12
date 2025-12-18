
#include "Sales.h"
#include "Mobil.h"
#include "Relation.h"
#include <iostream>
using namespace std;
// Parameter ditambah: long long totalPendapatan
void menuUser(ListSales LS, ListMobil LM, ListRelasi LR, long long totalPendapatan)
{
    int pilihan, jumlah;
    string idS, idM;
    adrMobil PM;
    adrSales PS;
    do
    {
        cout << "\n=== MENU USER ===" << endl;
        cout << "1. Show All Sales (Parent)" << endl;
        cout << "2. Show All Mobil (Child)" << endl;
        cout << "3. Show Sales dengan Mobil jualannya" << endl;
        cout << "4. Show Mobil dengan Salesnya" << endl;
        cout << "5. Show Mobil dengan Sales Tertentu" << endl;
        cout << "6. Show Sales dengan Mobil Tertentu" << endl;
        cout << "7. Jumlah Mobil dari Sales Tertentu" << endl;
        cout << "8. Jumlah Sales dari Mobil Tertentu" << endl;
        cout << "9. Jumlah Sales Tanpa Mobil" << endl;
        cout << "10. Jumlah Mobil Tanpa Sales" << endl;
        cout << "11. Laporan Showroom Lengkap (Data + Pendapatan)" << endl;
        cout << "0. Kembali ke Menu Utama" << endl;
        cout << "Pilih: ";
        cin >> pilihan;

        switch (pilihan)
        {
        case 1:
            showAllSales(LS);
            break;
        case 2:
            showAllMobil(LM);
            break;
        case 3:
            showParentWithChild(LS, LR);
            break;
        case 4:
            showChildWithParent(LM, LR);
            break;
        case 5:
            cout << "Masukkan ID Sales: ";
            cin >> idS;
            PS = findSales(LS, idS);
            showChildParentTertentu(LR, PS);
            break;
        case 6:
            cout << "Masukkan ID Mobil: ";
            cin >> idM;
            PM = findMobil(LM, idM);
            showParentChildTertentu(LR, PM);
            break;
        case 7:
            cout << "Masukkan ID Sales: ";
            cin >> idS;
            PS = findSales(LS, idS);
            jumlah = countChildParentTertentu(LR, PS);
            cout << "Sales " << PS->info.nama << " akan menjual " << jumlah << " mobil" << endl;
            break;
        case 8:
            cout << "Masukkan ID Mobil: ";
            cin >> idM;
            PM = findMobil(LM, idM);
            jumlah = countParentsChildTertentu(LR, PM);
            cout << "Mobil " << PM->info.merk << " " << PM->info.model << " akan dijual oleh " << jumlah << " sales" << endl;
            break;
        case 9:
            countParentTanpaChild(LR, LS);
            break;
        case 10:
            countChildTanpaParent(LR, LM);
            break;
        case 11:
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
