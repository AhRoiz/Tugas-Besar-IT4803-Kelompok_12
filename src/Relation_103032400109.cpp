#include "Relation.h"
#include <iostream>

using namespace std;

void deleteFirstRelasi(ListRelasi &L, adrRelasi &R){
    if (L.first != nullptr) {
        R = L.first;
        if (L.first == L.last) { // Only one element
            L.first = nullptr;
            L.last = nullptr;
        } else {
            L.first = L.first->next;
            L.first->prev = nullptr;
        }
        R->next = nullptr;
        R->prev = nullptr;
    } else {
        cout << "List kosong" << endl;
        R = nullptr; // List is empty
    }
} //semua delete jafar
void deleteLastRelasi(ListRelasi &L, adrRelasi &R){
    if (L.last != nullptr) {
        R = L.last;
        if (L.first == L.last) { // Only one element
            L.first = nullptr;
            L.last = nullptr;
        } else {
            L.last = L.last->prev;
            L.last->next = nullptr;
        }
        R->next = nullptr;
        R->prev = nullptr;
    } else {
        cout << "List kosong" << endl;
        R = nullptr; // List is empty
    }
}
void deleteAfterRelasi(ListRelasi &L, adrRelasi Prec, adrRelasi &R){
    if (Prec != nullptr && Prec->next != nullptr) {
        R = Prec->next;
        Prec->next = R->next;
        if (R->next != nullptr) {
            R->next->prev = Prec;
        } else {
            L.last = Prec; // Update last if we deleted the last element
        }
        R->next = nullptr;
        R->prev = nullptr;
    } else {
        R = nullptr; // No element to delete after Prec
    }
}

void deleteRelasiSpecific(ListRelasi &L, adrSales P, adrMobil C, adrRelasi &R){
    adrRelasi current = L.first;
    while (current != nullptr) {
        if (current->parent == P && current->child == C) {
            R = current;
            if (current == L.first) {
                deleteFirstRelasi(L, R);
            } else if (current == L.last) {
                deleteLastRelasi(L, R);
            } else {
                deleteAfterRelasi(L, current->prev, R);
            }
            return;
        }
        current = current->next;
    }
    R = nullptr; // Relation not found
} //dua ini jafar
adrRelasi findRelasi(ListRelasi L, adrSales P, adrMobil C){
    adrRelasi current = L.first;
    while (current != nullptr) {
        if (current->parent == P && current->child == C) {
            return current; // Relation found
        }
        current = current->next;
    }
    return nullptr; // Relation not found
}

void showChildWithParent(ListMobil LM, ListRelasi LR);//jafar
int countChildNoParent(ListMobil LM, ListRelasi LR);//jafar