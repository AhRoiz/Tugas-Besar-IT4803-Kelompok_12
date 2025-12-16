#include <iostream>
#include "Sales.h"
using namespace std;

void createListSales(ListSales &Ls)
{
    Ls.first = nullptr;
    Ls.last = nullptr;
}
string cekGolongan(int jumlah)
{
    if (jumlah <= 2)
    {
        return "Trainee";
    }
    else if (jumlah <= 5)
    {
        return "Junior";
    }
    else
    {
        return "Senior";
    }
}
adrSales allocateSales(infotypeSales x)
{
    adrSales p;
    p = new elmSales;
    p->info.id = x.id;
    p->info.nama = x.nama;
    p->info.jumlahTerjual = x.jumlahTerjual;
    p->info.golongan = cekGolongan(x.jumlahTerjual);
    p->next = nullptr;
    p->prev = nullptr;
    return p;
}
void insertFirstSales(ListSales &Ls, adrSales p)
{
    if (Ls.first == nullptr && Ls.last == nullptr)
    {
        Ls.first = p;
        Ls.last = p;
    }
    else
    {
        Ls.first->prev = p;
        p->next = Ls.first;
        Ls.first = p;
    }
}
void insertLastSales(ListSales &Ls, adrSales p)
{
    if (Ls.first == nullptr && Ls.last == nullptr)
    {
        Ls.first = p;
        Ls.last = p;
    }
    else
    {
        Ls.last->next = p;
        p->prev = Ls.last;
        Ls.last = p;
    }
}
void deleteAfterSales(ListSales &Ls, adrSales prec, adrSales &p)
{
    if (prec != nullptr && prec->next != nullptr)
    {
        p = prec->next;
        if (p == Ls.last)
        {
            deleteLastSales(Ls, p);
        }
        else
        {
            p->next = p->next;
            p->next->prev = prec;
            p->next = nullptr;
            p->prev = nullptr;
        }
    }
}
