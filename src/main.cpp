#include <iostream>
#include "Sales.h"
#include "Mobil.h"
#include "Relation.h"

using namespace std;

void menuAdmin(ListSales &LS, ListMobil &LM, ListRelasi &LR, long long &totalPendapatan);
void menuUser(ListSales LS, ListMobil LM, ListRelasi LR, long long totalPendapatan);

int main()
{
    ListSales LS;
    ListMobil LM;
    ListRelasi LR;

    createListSales(LS);
    createListMobil(LM);
    createListRelasi(LR);

    long long totalPendapatan = 0;
    dataDummy(LS, LM);
    int peran;
    do
    {
        cout << "\n=== DEALER SYSTEM ===" << endl;
        cout << "1. Admin" << endl;
        cout << "2. User" << endl;
        cout << "0. Exit" << endl;
        cout << "Pilih: ";
        cin >> peran;

        if (peran == 1)
        {
            menuAdmin(LS, LM, LR, totalPendapatan);
        }
        else if (peran == 2)
        {
            menuUser(LS, LM, LR, totalPendapatan);
        }
    } while (peran != 0);

    return 0;
}
