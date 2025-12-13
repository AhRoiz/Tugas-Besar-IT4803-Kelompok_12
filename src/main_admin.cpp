
#include "Sales.h"
#include "Mobil.h"
#include "Relation.h"
#include <iostream>
using namespace std;
void menuAdmin(ListSales &LS, ListMobil &LM, ListRelasi &LR, long long &totalPendapatan) {
    int pilihan, subPilihan;
    infotypeSales S;
    infotypeMobil M;
    string idS, namaS;
    int jumlahAwal;
    string idM, merkM, modelM;
    int hargaM, tahunM;
    string idPrec;

    // Variabel untuk Edit Relasi
    string idSLama, idMLama, idSBaru, idMBaru;

    adrSales PS, PrecSales;
    adrMobil PM;
    adrRelasi PR;

    do {
        cout << "\n=== MENU ADMIN ===" << endl;
        cout << "1. Insert Sales" << endl;
        cout << "2. Insert Mobil" << endl;
        cout << "3. Insert Relasi Manual (Tanpa Update Stats)" << endl;
        cout << "4. Delete Sales" << endl;
        cout << "5. Delete Mobil" << endl;
        cout << "6. Delete Relasi" << endl;
        cout << "7. Search / Find Data" << endl;
        cout << "8. Transaksi Mobil Terjual (Jual & Hapus Data)" << endl;
        cout << "9. Edit Relasi (Ubah Pemilik/Mobil)" << endl;
        cout << "0. Kembali" << endl;
        cout << "Pilih: "; cin >> pilihan;

        switch(pilihan) {
            case 1:
                cout << "\n--- Tambah Data Sales ---" << endl;
                cout << "Masukkan ID: "; cin >> S.id;
                cout << "Masukkan Nama: "; cin >> S.nama;
                cout << "Jumlah mobil yg SUDAH terjual: "; cin >> S.jumlahTerjual;
                PS = alokasiSales(S);
                cout << "1.First 2.Last 3.After: "; cin >> subPilihan;
                if (subPilihan == 1) insertFirstSales(LS, PS);
                else if (subPilihan == 2) insertLastSales(LS, PS);
                else {
                    cout << "ID Sales sebelumnya: "; cin >> idPrec;
                    PrecSales = findSales(LS, idPrec);
                    if(PrecSales) insertAfterSales(LS, PrecSales, PS);
                    else { cout << "ID tidak ditemukan!" << endl; delete PS; }
                }
                break;

            case 2:
                cout << "ID: "; cin >> M.idMobil; cout << "Merk: "; cin >> M.merk;
                cout << "Model: "; cin >> M.model; cout << "Harga: "; cin >> M.harga;
                cout << "Tahun: "; cin >> M.tahunProduksi;
                insertLastMobil(LM, allocateMobil(M));
                break;

            case 3:
                cout << "ID Sales: "; cin >> idS; cout << "ID Mobil: "; cin >> idM;
                PS = findSales(LS, idS); PM = findMobil(LM, idM);
                if (PS && PM) {
                    insertFirstRelasi(LR, alokasiRelasi(PS, PM));
                    cout << "Relasi dibuat." << endl;
                } else cout << "Data tidak ada." << endl;
                break;

            case 4:
                cout << "Hapus ID Sales: "; cin >> idS;
                PS = findSales(LS, idS);
                if (PS) {
                    deleteRelasiByParent(LR, PS);
                    if (PS == LS.first) deleteFirstSales(LS, PS);
                    else if (PS == LS.last) deleteLastSales(LS, PS);
                    else { adrSales temp = PS->prev; deleteAfterSales(LS, temp, PS); }
                    delete PS;
                    cout << "Sales dihapus." << endl;
                } else cout << "Sales tidak ditemukan." << endl;
                break;

            case 5:
                cout << "Hapus ID Mobil: "; cin >> idM;
                PM = findMobil(LM, idM);
                if (PM) {
                    deleteRelasiByChild(LR, PM);
                    if (PM == LM.first) deleteFirstMobil(LM, PM);
                    else if (PM->next == NULL) deleteLastMobil(LM, PM);
                    else {
                        adrMobil temp = LM.first;
                        while(temp->next != PM) temp = temp->next;
                        deleteAfterMobil(LM, temp, PM);
                    }
                    delete PM;
                    cout << "Mobil dihapus." << endl;
                } else cout << "Mobil tidak ditemukan." << endl;
                break;

            case 6:
                cout << "ID Sales: "; cin >> idS; cout << "ID Mobil: "; cin >> idM;
                PS = findSales(LS, idS); PM = findMobil(LM, idM);
                if(PS && PM) {
                    deleteRelasiSpecific(LR, PS, PM, PR);
                    if(PR) { delete PR; cout << "Relasi putus." << endl; }
                    else cout << "Relasi tidak ada." << endl;
                }
                break;

            case 7:
                cout << "1.Sales 2.Mobil: "; cin >> subPilihan;
                if(subPilihan==1){
                    cout<<"ID Sales: "; cin>>idS; PS=findSales(LS, idS);
                    if(PS) cout<<"Ketemu: "<<PS->info.nama<<endl; else cout<<"404 Not Found"<<endl;
                } else {
                    cout<<"ID Mobil: "; cin>>idM; PM=findMobil(LM, idM);
                    if(PM) cout<<"Ketemu: "<<PM->info.model<<endl; else cout<<"404 Not Found"<<endl;
                }
                break;

            // --- CASE 8: TRANSAKSI JUAL (FIXED LOGIC) ---
            case 8:
                cout << "\n=== TRANSAKSI MOBIL TERJUAL ===" << endl;
                cout << "Masukkan ID Mobil yang terjual: "; cin >> idM;
                cout << "Masukkan ID Sales yang menjual: "; cin >> idS;

                PM = findMobil(LM, idM);
                PS = findSales(LS, idS);

                if (PS != NULL && PM != NULL) {
                    adrRelasi cekRelasi = findRelasi(LR, PS, PM);
                    if (cekRelasi != NULL) {
                        // 1. Update Stats Sales
                        PS->info.jumlahTerjual++;
                        PS->info.golongan = cekGolongan(PS->info.jumlahTerjual);

                        // 2. Update Pendapatan
                        totalPendapatan = totalPendapatan + PM->info.harga;

                        cout << "\n>> BERHASIL TERJUAL!" << endl;
                        cout << ">> " << PM->info.merk << " " << PM->info.model << " terjual oleh " << PS->info.nama << endl;
                        cout << ">> Pendapatan bertambah: Rp " << PM->info.harga << endl;

                        // 3. Hapus Relasi
                        deleteRelasiByChild(LR, PM);

                        // 4. Hapus Mobil dari List (Logika SLL)
                        adrMobil hapusM;
                        if (PM == LM.first) deleteFirstMobil(LM, hapusM);
                        else if (PM->next == NULL) deleteLastMobil(LM, hapusM);
                        else {
                            adrMobil Prec = LM.first;
                            while (Prec->next != PM) Prec = Prec->next;
                            deleteAfterMobil(LM, Prec, hapusM);
                        }
                        delete hapusM;
                        cout << ">> Data mobil dihapus dari database." << endl;

                    } else {
                        cout << "\n>> GAGAL! Sales ini tidak memegang mobil tersebut." << endl;
                    }
                } else { cout << "Data tidak valid." << endl; }
                break;

            // --- CASE 9: EDIT RELASI (NEW) ---
            case 9:
                cout << "\n=== EDIT RELASI ===" << endl;
                cout << "--- Data Lama ---" << endl;
                cout << "ID Sales Lama: "; cin >> idSLama;
                cout << "ID Mobil Lama: "; cin >> idMLama;

                cout << "--- Data Baru ---" << endl;
                cout << "ID Sales Baru: "; cin >> idSBaru;
                cout << "ID Mobil Baru: "; cin >> idMBaru;

                updateRelasi(LR, LS, LM, idSLama, idMLama, idSBaru, idMBaru);
                break;
        }
            //case 10:
                //cout << menampilkan child dari parent tertentu: ";
                //PS = findSales(LS, idS);
                //if (PS != NULL && PM != NULL)
    } while (pilihan != 0);
}
