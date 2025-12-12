
#include "Relation.h"

void createListRelasi(ListRelasi &L) {
    L.first = NULL;
    L.last = NULL;
}

adrRelasi alokasiRelasi(adrSales P, adrMobil C) {
    adrRelasi R = new elmRelasi;
    R->parent = P;
    R->child = C;
    R->next = NULL;
    R->prev = NULL;
    return R;
}

void insertFirstRelasi(ListRelasi &L, adrRelasi R) {
    if (L.first == NULL) {
        L.first = R;
        L.last = R;
    } else {
        R->next = L.first;
        L.first->prev = R;
        L.first = R;
    }
}

void insertLastRelasi(ListRelasi &L, adrRelasi R) {
    if (L.first == NULL) {
        insertFirstRelasi(L, R);
    } else {
        R->prev = L.last;
        L.last->next = R;
        L.last = R;
    }
}

void insertAfterRelasi(ListRelasi &L, adrRelasi Prec, adrRelasi R) {
    if (Prec != NULL) {
        if (Prec == L.last) {
            insertLastRelasi(L, R);
        } else {
            R->next = Prec->next;
            R->prev = Prec;
            Prec->next->prev = R;
            Prec->next = R;
        }
    }
}

void deleteFirstRelasi(ListRelasi &L, adrRelasi &R) {
    if (L.first != NULL) {
        R = L.first;
        if (L.first == L.last) {
            L.first = NULL;
            L.last = NULL;
        } else {
            L.first = R->next;
            L.first->prev = NULL;
            R->next = NULL;
        }
    }
}

void deleteLastRelasi(ListRelasi &L, adrRelasi &R) {
    if (L.first != NULL) {
        R = L.last;
        if (L.first == L.last) {
            deleteFirstRelasi(L, R);
        } else {
            L.last = R->prev;
            L.last->next = NULL;
            R->prev = NULL;
        }
    }
}

void deleteAfterRelasi(ListRelasi &L, adrRelasi Prec, adrRelasi &R) {
    if (Prec != NULL && Prec->next != NULL) {
        R = Prec->next;
        if (R == L.last) {
            deleteLastRelasi(L, R);
        } else {
            Prec->next = R->next;
            R->next->prev = Prec;
            R->next = NULL;
            R->prev = NULL;
        }
    }
}

void deleteRelasiSpecific(ListRelasi &L, adrSales P, adrMobil C, adrRelasi &R) {
    R = findRelasi(L, P, C);
    if (R != NULL) {
        if (R == L.first) {
            deleteFirstRelasi(L, R);
        } else if (R == L.last) {
            deleteLastRelasi(L, R);
        } else {
            adrRelasi Prec = R->prev;
            deleteAfterRelasi(L, Prec, R);
        }
    }
}

adrRelasi findRelasi(ListRelasi L, adrSales P, adrMobil C) {
    adrRelasi R = L.first;
    while (R != NULL) {
        if (R->parent == P && R->child == C) return R;
        R = R->next;
    }
    return NULL;
}

void deleteRelasiByParent(ListRelasi &L, adrSales P) {
    adrRelasi R = L.first;
    while (R != NULL) {
        adrRelasi nextNode = R->next;
        if (R->parent == P) {
            adrRelasi temp;
            if (R == L.first) deleteFirstRelasi(L, temp);
            else if (R == L.last) deleteLastRelasi(L, temp);
            else {
                adrRelasi Prec = R->prev;
                deleteAfterRelasi(L, Prec, temp);
            }
            delete temp;
        }
        R = nextNode;
    }
}

void deleteRelasiByChild(ListRelasi &L, adrMobil C) {
    adrRelasi R = L.first;
    while (R != NULL) {
        adrRelasi nextNode = R->next;
        if (R->child == C) {
            adrRelasi temp;
            if (R == L.first) deleteFirstRelasi(L, temp);
            else if (R == L.last) deleteLastRelasi(L, temp);
            else {
                adrRelasi Prec = R->prev;
                deleteAfterRelasi(L, Prec, temp);
            }
            delete temp;
        }
        R = nextNode;
    }
}

void showParentWithChild(ListSales LS, ListRelasi LR) {
    adrSales P = LS.first;
    while (P != NULL) {
        cout << "Sales: " << P->info.nama << " (Gol: " << P->info.golongan << ")" << endl;
        cout << "  Mobil: ";
        adrRelasi R = LR.first;
        bool found = false;
        while (R != NULL) {
            if (R->parent == P) {
                cout << R->child->info.model << ", ";
                found = true;
            }
            R = R->next;
        }
        if (!found) cout << "-";
        cout << endl;
        P = P->next;
    }
}

void showChildWithParent(ListMobil LM, ListRelasi LR) {
    adrMobil C = LM.first;
    while (C != NULL) {
        cout << "Mobil: " << C->info.model << endl;
        cout << "  Sales: ";
        adrRelasi R = LR.first;
        bool found = false;
        while (R != NULL) {
            if (R->child == C) {
                cout << R->parent->info.nama << ", ";
                found = true;
            }
            R = R->next;
        }
        if (!found) cout << "-";
        cout << endl;
        C = C->next;
    }
}

// --- IMPLEMENTASI FITUR BARU EDIT RELASI ---
void updateRelasi(ListRelasi &LR, ListSales LS, ListMobil LM, string idSLama, string idMLama, string idSBaru, string idMBaru) {
    adrSales salesLama = findSales(LS, idSLama);
    adrMobil mobilLama = findMobil(LM, idMLama);

    adrSales salesBaru = findSales(LS, idSBaru);
    adrMobil mobilBaru = findMobil(LM, idMBaru);

    if (salesLama != NULL && mobilLama != NULL && salesBaru != NULL && mobilBaru != NULL) {
        adrRelasi R = findRelasi(LR, salesLama, mobilLama);
        if (R != NULL) {
            R->parent = salesBaru;
            R->child = mobilBaru;
            cout << ">> SUKSES: Relasi berhasil diubah!" << endl;
            cout << ">> Dari [" << salesLama->info.nama << " - " << mobilLama->info.model << "]";
            cout << " Menjadi [" << salesBaru->info.nama << " - " << mobilBaru->info.model << "]" << endl;
        } else {
            cout << ">> GAGAL: Relasi lama tidak ditemukan." << endl;
        }
    } else {
        cout << ">> GAGAL: ID Sales atau ID Mobil (Lama/Baru) tidak valid." << endl;
    }
}
