#include <iostream>
#include "Mobil.h"
using namespace std;

void insertafterMobil(ListMobil &Lm,adrMobil prec, adrMobil p){
    if (Lm.first == nullptr){
        Lm.first = p;
    }else{
        p->next = prec->next;
        prec->next = p;
    }
}
void deleteFirstMobil(ListMobil &Lm, adrMobil &p){
    if (Lm.first == nullptr){
        cout << "List kosong" << endl;
        p = nullptr; 
    }else{
        p = Lm.first;
        Lm.first = p->next;
        p->next = nullptr;
    }
}
void deleteLastMobil(ListMobil &Lm, adrMobil &p){
    if (Lm.first == nullptr){
        cout << "List kosong" << endl;
        p = nullptr; 
    }else{
        adrMobil q;
        q = Lm.first;
        while (q->next->next != nullptr){
            q = q->next; 
        }
        p = q->next;
        q->next = nullptr;
    }
}
adrMobil findMobil(ListMobil Lm, string IDmobil){
    adrMobil p;
    p = Lm.first;
    while (p != nullptr){
        if (p->info.idMobil == IDmobil){
            return p;
        }
        p = p->next;
    }
    return nullptr;
}
void showAllMobil(ListMobil Lm){
    cout << "===== List Mobil ======" << endl;
    adrMobil p;
    p = Lm.first;
    while (p != nullptr){
        cout << "ID Mobil : " << p->info.idMobil << endl;
        p = p->next;
    }
    cout << endl;
}