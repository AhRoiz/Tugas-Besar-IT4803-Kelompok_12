#include <iostream>
using namespace std;
#include "Relation.h"

void createListRelasi(ListRelasi &L)
{
    L.first = nullptr;
    L.last = nullptr;
}

adrRelasi alokasiRelasi(adrSales P, adrMobil C)
{
    adrRelasi R = new elmRelasi;
    R->parent = P;
    R->child = C;
    R->next = nullptr;
    R->prev = nullptr;
    return R;
}

void insertFirstRelasi(ListRelasi &L, adrRelasi R)
{
    if (L.first == nullptr)
    {
        L.first = R;
        L.last = R;
    }
    else
    {
        R->next = L.first;
        L.first->prev = R;
        L.first = R;
    }
}

void insertLastRelasi(ListRelasi &L, adrRelasi R)
{
    if (L.first == nullptr)
    {
        insertFirstRelasi(L, R);
    }
    else
    {
        R->prev = L.last;
        L.last->next = R;
        L.last = R;
    }
}

void insertAfterRelasi(ListRelasi &L, adrRelasi Prec, adrRelasi R)
{
    if (Prec != nullptr)
    {
        if (Prec == L.last)
        {
            insertLastRelasi(L, R);
        }
        else
        {
            R->next = Prec->next;
            R->prev = Prec;
            Prec->next->prev = R;
            Prec->next = R;
        }
    }
}

void deleteFirstRelasi(ListRelasi &L, adrRelasi &R)
{
    if (L.first != nullptr)
    {
        R = L.first;
        if (L.first == L.last)
        {
            L.first = nullptr;
            L.last = nullptr;
        }
        else
        {
            L.first = R->next;
            L.first->prev = nullptr;
            R->next = nullptr;
        }
    }
}

void deleteLastRelasi(ListRelasi &L, adrRelasi &R)
{
    if (L.first != nullptr)
    {
        R = L.last;
        if (L.first == L.last)
        {
            deleteFirstRelasi(L, R);
        }
        else
        {
            L.last = R->prev;
            L.last->next = nullptr;
            R->prev = nullptr;
        }
    }
}

void deleteAfterRelasi(ListRelasi &L, adrRelasi Prec, adrRelasi &R)
{
    if (Prec != nullptr && Prec->next != nullptr)
    {
        R = Prec->next;
        if (R == L.last)
        {
            deleteLastRelasi(L, R);
        }
        else
        {
            Prec->next = R->next;
            R->next->prev = Prec;
            R->next = nullptr;
            R->prev = nullptr;
        }
    }
}

void deleteRelasiSpecific(ListRelasi &L, adrSales P, adrMobil C, adrRelasi &R)
{
    R = findRelasi(L, P, C);
    if (R != nullptr)
    {
        if (R == L.first)
        {
            deleteFirstRelasi(L, R);
        }
        else if (R == L.last)
        {
            deleteLastRelasi(L, R);
        }
        else
        {
            adrRelasi Prec = R->prev;
            deleteAfterRelasi(L, Prec, R);
        }
    }
}

adrRelasi findRelasi(ListRelasi L, adrSales P, adrMobil C)
{
    adrRelasi R = L.first;
    while (R != nullptr)
    {
        if (R->parent == P && R->child == C)
            return R;
        R = R->next;
    }
    return nullptr;
}

void deleteRelasiByParent(ListRelasi &L, adrSales P)
{
    adrRelasi R = L.first;
    while (R != nullptr)
    {
        adrRelasi nextNode = R->next;
        if (R->parent == P)
        {
            adrRelasi temp;
            if (R == L.first)
                deleteFirstRelasi(L, temp);
            else if (R == L.last)
                deleteLastRelasi(L, temp);
            else
            {
                adrRelasi Prec = R->prev;
                deleteAfterRelasi(L, Prec, temp);
            }
            delete temp;
        }
        R = nextNode;
    }
}

void deleteRelasiByChild(ListRelasi &L, adrMobil C)
{
    adrRelasi R = L.first;
    while (R != nullptr)
    {
        adrRelasi nextNode = R->next;
        if (R->child == C)
        {
            adrRelasi temp;
            if (R == L.first)
                deleteFirstRelasi(L, temp);
            else if (R == L.last)
                deleteLastRelasi(L, temp);
            else
            {
                adrRelasi Prec = R->prev;
                deleteAfterRelasi(L, Prec, temp);
            }
            delete temp;
        }
        R = nextNode;
    }
}

void showParentWithChild(ListSales LS, ListRelasi LR)
{
    adrSales P = LS.first;
    while (P != nullptr)
    {
        cout << "Sales: " << P->info.nama << " (Gol: " << P->info.golongan << ")" << endl;
        cout << "  Mobil: ";
        adrRelasi R = LR.first;
        bool found = false;
        while (R != nullptr)
        {
            if (R->parent == P)
            {
                cout << R->child->info.model << ", ";
                found = true;
            }
            R = R->next;
        }
        if (!found)
            cout << "-";
        cout << endl;
        P = P->next;
    }
}

void showChildWithParent(ListMobil LM, ListRelasi LR)
{
    adrMobil C = LM.first;
    while (C != nullptr)
    {
        cout << "Mobil: " << C->info.model << endl;
        cout << "  Sales: ";
        adrRelasi R = LR.first;
        bool found = false;
        while (R != nullptr)
        {
            if (R->child == C)
            {
                cout << R->parent->info.nama << ", ";
                found = true;
            }
            R = R->next;
        }
        if (!found)
            cout << "-";
        cout << endl;
        C = C->next;
    }
}

void updateRelasi(ListRelasi &LR, ListSales LS, ListMobil LM, string idSLama, string idMLama, string idSBaru, string idMBaru)
{
    adrSales salesLama = findSales(LS, idSLama);
    adrMobil mobilLama = findMobil(LM, idMLama);

    adrSales salesBaru = findSales(LS, idSBaru);
    adrMobil mobilBaru = findMobil(LM, idMBaru);

    if (salesLama != nullptr && mobilLama != nullptr && salesBaru != nullptr && mobilBaru != nullptr)
    {
        adrRelasi R = findRelasi(LR, salesLama, mobilLama);
        if (R != nullptr)
        {
            R->parent = salesBaru;
            R->child = mobilBaru;
            cout << ">> SUKSES: Relasi berhasil diubah!" << endl;
            cout << ">> Dari [" << salesLama->info.nama << " - " << mobilLama->info.model << "]";
            cout << " Menjadi [" << salesBaru->info.nama << " - " << mobilBaru->info.model << "]" << endl;
        }
        else
        {
            cout << ">> GAGAL: Relasi lama tidak ditemukan." << endl;
        }
    }
    else
    {
        cout << ">> GAGAL: ID Sales atau ID Mobil (Lama/Baru) tidak valid." << endl;
    }
}
void showChildParentTertentu(ListRelasi LR, adrSales P)
{
    cout << "Mobil yang dijual oleh Sales " << P->info.nama << ":" << endl;
    adrRelasi R = LR.first;
    bool found = false;
    while (R != nullptr)
    {
        if (R->parent == P)
        {
            cout << "- " << R->child->info.model << endl;
            found = true;
        }
        R = R->next;
    }
    if (!found)
    {
        cout << "Tidak ada mobil yang dijual oleh sales ini." << endl;
    }
}

void showParentChildTertentu(ListRelasi LR, adrMobil c)
{
    cout << "Mobil " << c->info.merk << " " << c->info.model << ":" << endl;
    adrRelasi R = LR.first;
    bool found = false;
    while (R != nullptr)
    {
        if (R->child == c)
        {
            cout << "- " << R->parent->info.id << " " << R->parent->info.nama << endl;
            found = true;
        }
        R = R->next;
    }
    if (!found)
    {
        cout << "Tidak ada sales yang menjual mobil ini." << endl;
    }
}

int countChildParentTertentu(ListRelasi LR, adrSales P)
{
    int count = 0;
    adrRelasi R = LR.first;
    while (R != nullptr)
    {
        if (R->parent == P)
        {
            count++;
        }
        R = R->next;
    }
    return count;
}
int countParentsChildTertentu(ListRelasi LR, adrMobil C)
{
    int count = 0;
    adrRelasi R = LR.first;
    while (R != nullptr)
    {
        if (R->child == C)
        {
            count++;
        }
        R = R->next;
    }
    return count;
}
void countChildTanpaParent(ListRelasi LR, ListMobil LM)
{
    int count = 0;
    adrMobil m = LM.first;
    while (m != nullptr)
    {
        adrRelasi R = LR.first;
        bool hasParent = false;
        while (R != nullptr && hasParent == false)
        {
            if (R->child == m)
            {
                hasParent = true;
            }
            else
            {
                R = R->next;
            }
        }
        if (hasParent == false)
        {
            count++;
        }

        m = m->next;
    }

    cout << ">> Jumlah Mobil tanpa Sales: " << count << endl;
}

void countParentTanpaChild(ListRelasi LR, ListSales LS)
{
    int count = 0;
    adrSales s = LS.first;
    while (s != nullptr)
    {
        adrRelasi R = LR.first;
        bool hasChild = false;
        while (R != nullptr && hasChild == false)
        {
            if (R->parent == s)
            {
                hasChild = true;
            }
            else
            {
                R = R->next;
            }
        }
        if (hasChild == false)
        {
            count++;
        }

        s = s->next;
    }

    cout << ">> Jumlah Sales tanpa Mobil: " << count << endl;
}

void dataDummy(ListSales &LS, ListMobil &LM)
{
    infotypeSales s;
    infotypeMobil m;
    adrSales PS;
    adrMobil PM;
    s.id = "109";
    s.nama = "Ja'far";
    s.jumlahTerjual = 5;
    s.golongan = cekGolongan(s.jumlahTerjual);
    PS = alokasiSales(s);
    insertFirstSales(LS, PS);

    s.id = "45";
    s.nama = "Ahmad";
    s.jumlahTerjual = 9;
    s.golongan = cekGolongan(s.jumlahTerjual);
    PS = alokasiSales(s);
    insertFirstSales(LS, PS);

    s.id = "139";
    s.nama = "Aldi";
    s.jumlahTerjual = 3;
    s.golongan = cekGolongan(s.jumlahTerjual);
    PS = alokasiSales(s);
    insertFirstSales(LS, PS);

    s.id = "91";
    s.nama = "Nabil";
    s.jumlahTerjual = 0;
    s.golongan = cekGolongan(s.jumlahTerjual);
    PS = alokasiSales(s);
    insertFirstSales(LS, PS);

    m.idMobil = "911";
    m.merk = "Porsche";
    m.model = "911_GT3";
    m.harga = 63000000;
    m.tahunProduksi = 2020;
    PM = allocateMobil(m);
    insertFirstMobil(LM, PM);

    m.idMobil = "921";
    m.merk = "Lexus";
    m.model = "LFA";
    m.harga = 93000000;
    m.tahunProduksi = 2018;
    PM = allocateMobil(m);
    insertFirstMobil(LM, PM);

    m.idMobil = "931";
    m.merk = "Nissan";
    m.model = "GTR_R35";
    m.harga = 85000000;
    m.tahunProduksi = 2018;
    PM = allocateMobil(m);
    insertFirstMobil(LM, PM);

    m.idMobil = "941";
    m.merk = "Nissan";
    m.model = "Altima";
    m.harga = 2340000;
    m.tahunProduksi = 2017;
    PM = allocateMobil(m);
    insertFirstMobil(LM, PM);
}

