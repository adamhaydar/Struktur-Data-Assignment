# <h1 align="center">SINGLY LINKED LIST (BAGIAN KEDUA) </h1>
<p align="center">Adam Haydar</p>

## Dasar Teori

Searching pada linked list merupakan proses pencarian suatu nilai dengan menelusuri setiap node secara berurutan, dimulai dari node pertama (head) hingga node terakhir atau sampai nilai yang dicari ditemukan. Metode yang umum digunakan adalah linear search atau sequential search, yaitu dengan membandingkan nilai pada setiap node dengan nilai target. Proses pencarian akan berhenti ketika nilai ditemukan atau ketika seluruh node telah diperiksa tanpa hasil. Karena struktur linked list berupa rangkaian node yang saling terhubung, pencarian harus dilakukan dari awal hingga akhir secara berurutan. Kompleksitas waktu untuk operasi searching pada linked list adalah O(N), dengan N menyatakan jumlah node, karena pada kondisi terburuk seluruh node harus dilalui. Keberadaan operasi searching ini mempermudah proses lanjutan seperti insert after, delete after, dan update, karena posisi node yang dituju dapat diketahui terlebih dahulu.

## Guided 

### 1. [Nama Topik]

```C++
//prosedur-prosedur untuk searching data
//prosedur untuk mencari node berdasarkan data
void FindNodeByData(linkedlist list, string data){
    if(isEmpty(list) == true){
        cout << "List kosong!" << endl;
    } else {
        address nodeBantu = list.first;
        int posisi = 0;
        bool found = false;
        while(nodeBantu != Nil){
            posisi++;
            if(nodeBantu->isidata.nama == data){
                cout << "Data " << data << " ditemukan pada posisi ke-" << posisi << "!" << endl;
                cout << "Nama Buah : " << nodeBantu->isidata.nama << ", Jumlah : " << nodeBantu->isidata.jumlah << ", Harga : " << nodeBantu->isidata.harga << endl;
                found = true;
                break;
            }
            nodeBantu = nodeBantu->next;
        }
        if(found == false){
            cout << "Node dengan data " << data << " tidak ditemukan!" << endl;
        }
    }
    cout << endl;
}

//prosedur untuk mencari node berdasarkan alamat node
void FindNodeByAddress(linkedlist list, address node) {
    if(isEmpty(list) == true) {
        cout << "List kosong!" << endl;
    } else {
        address nodeBantu = list.first;
        int posisi = 0;
        bool found = false;
        while (nodeBantu != Nil) {
            posisi++;
            if(nodeBantu == node) {
                cout << "Node ditemukan pada posisi ke-" << posisi << "!" << endl;
                cout << "Alamat node : " << nodeBantu << endl;
                cout << "Nama Buah : " << nodeBantu->isidata.nama << ", Jumlah : " << nodeBantu->isidata.jumlah << ", Harga : " << nodeBantu->isidata.harga << endl;
                found = true;
                break;
            }
            nodeBantu = nodeBantu->next;
        }
        if(found == false) {
            cout << "Node dengan alamat " << node << " tidak ditemukan dalam list!" << endl;
        }
    }
    cout << endl;
}

//prosedur untuk mencari node berdasarkan range data (range harga)
void FindNodeByRange(linkedlist list, float hargaAwal, float hargaAkhir) {
    if(isEmpty(list) == true) {
        cout << "List kosong!" << endl;
    } else {
        address nodeBantu = list.first;
        int posisi = 0;
        bool found = false;
        cout << "--- Buah dalam range harga " << hargaAwal << " - " << hargaAkhir << " ---" << endl;
        cout << "-------------------------------------------" << endl;
        while (nodeBantu != Nil) {
            posisi++;
            float harga = nodeBantu->isidata.harga;
            if(harga >= hargaAwal && harga <= hargaAkhir) {
                cout << "Data ditemukan pada posisi ke-" << posisi << " :" << endl;
                cout << "Nama Buah : " << nodeBantu->isidata.nama << ", Jumlah : " << nodeBantu->isidata.jumlah << ", Harga : " << nodeBantu->isidata.harga << endl;
                cout << "-------------------------------------------" << endl;
                found = true;
            }
            nodeBantu = nodeBantu->next;
        }
        if(found == false) {
            cout << "Tidak ada data buah dalam range harga tersebut!" << endl;
            cout << "-------------------------------------------" << endl;
        }
    }
    cout << endl;
}


*main.cpp*
C++
#include "listBuah.h"

#include<iostream>
using namespace std;

int main(){
    linkedlist List;
    address nodeA, nodeB, nodeC, nodeD, nodeE = Nil;
    createList(List);

    dataBuah dtBuah;

    nodeA = alokasi("Jeruk", 100, 3000);
    nodeB = alokasi("Apel", 75, 4000);
    nodeC = alokasi("Pir", 87, 5000);
    nodeD = alokasi("Semangka", 43, 11500);
    nodeE = alokasi("Durian", 15, 31450);

    insertFirst(List, nodeA);
    insertLast(List, nodeB);
    insertAfter(List, nodeC, nodeA);
    insertAfter(List, nodeD, nodeC);
    insertLast(List, nodeE);

    cout << "--- ISI LIST SETELAH DILAKUKAN INSERT ---" << endl;
    printList(List);
    cout << "Jumlah node : " << nbList(List) << endl;
    cout << endl;

   updateFirst(List);
   updateLast(List);
   updateAfter(List, nodeD);

    cout << "--- ISI LIST SETELAH DILAKUKAN UPDATE ---" << endl;
    printList(List);
    cout << "Jumlah node : " << nbList(List) << endl;
    cout << endl;

    FindNodeByData(List, "Kelapa");
    FindNodeByAddress(List, nodeC);
    FindNodeByRange(List, 5000, 10000);

    delFirst(List);
    delLast(List);
    delAfter(List, nodeD, nodeC);

    cout << "--- ISI LIST SETELAH DILAKUKAN DELETE ---" << endl;
    printList(List);
    cout << "jumlah node : " << nbList(List) << endl;
    cout << endl;

    deleteList(List);
    cout << "--- ISI LIST SETELAH DILAKUKAN HAPUS LIST ---" << endl;
    printList(List);
    cout << "jumlah node : " << nbList(List) << endl;
    cout << endl;

    return 0;
```
Program ini menunjukkan cara melakukan pencarian data pada linked list dengan beberapa metode, seperti mencari berdasarkan nama data, alamat node, dan rentang harga. Selain itu, program juga dilengkapi dengan proses insert, update, dan delete sehingga alur pengelolaan data bisa terlihat jelas dari awal sampai akhir. Dari percobaan ini, bisa dipahami bagaimana linked list bekerja untuk menyimpan dan menelusuri data secara berurutan tanpa harus menggunakan indeks seperti array.
## Unguided 

### 1. [Soal]
**Singlylist.h**
```C++
#ifndef SINGLYLIST_H
#define SINGLYLIST_H

#include <iostream>
using namespace std;

#define Nil NULL

typedef int infotype;
typedef struct elmList *address;

struct elmList {
    infotype info;
    address next;
};

struct List {
    address first;
};

void createList(List &L);
address alokasi(infotype x);
void dealokasi(address P);
void insertFirst(List &L, address P);
void printInfo(List L);
address findElm(List L, infotype x);
int totalInfo(List L);

#endif
```
**Singlylist.cpp**
```C++
#include "Singlylist.h"

void createList(List &L) {
    L.first = Nil;
}

address alokasi(infotype x) {
    address P;
    P = new elmList;
    if (P != Nil) {
        P->info = x;
        P->next = Nil;
    } else {
        cout << "Alokasi gagal" << endl;
    }
    return P;
}

void dealokasi(address P) {
    delete P;
}

void insertFirst(List &L, address P) {
    if (L.first == Nil) {
        L.first = P;
    } else {
        P->next = L.first;
        L.first = P;
    }
}

void printInfo(List L) {
    address P = L.first;
    if (P == Nil) {
        cout << "List kosong" << endl;
    } else {
        while (P != Nil) {
            cout << P->info << " ";
            P = P->next;
        }
        cout << endl;
    }
}

address findElm(List L, infotype x) {
    address P = L.first;
    while (P != Nil) {
        if (P->info == x) {
            return P;
        }
        P = P->next;
    }
    return Nil;
}

int totalInfo(List L) {
    int total = 0;
    address P = L.first;

    while (P != Nil) {
        total += P->info;
        P = P->next;
    }

    return total;
}
```
**main.cpp**
```C++
#include "Singlylist.h"

int main() {
    List L;
    address P1, P2, P3, P4, P5;

    createList(L);

    P1 = alokasi(2);
    insertFirst(L, P1);

    P2 = alokasi(0);
    insertFirst(L, P2);

    P3 = alokasi(8);
    insertFirst(L, P3);

    P4 = alokasi(12);
    insertFirst(L, P4);

    P5 = alokasi(9);
    insertFirst(L, P5);

    printInfo(L);

    address hasil = findElm(L, 8);
    if (hasil != Nil) {
        cout << "8 ditemukan dalam list" << endl;
    } else {
        cout << "8 tidak ditemukan" << endl;
    }

    int jumlah = totalInfo(L);
    cout << "Total info dari kelima elemen adalah " << jumlah << endl;

    return 0;
}
```
#### Output:
<img width="528" height="287" alt="image" src="https://github.com/user-attachments/assets/321ebe2e-c4b4-45db-9db8-e38d928cdd50" />


Kode tersebut merupakan program yang digunakan untuk mengelola data buah dengan menerapkan struktur data Singly Linked List. Pada struktur ini, data disimpan secara dinamis di dalam node-node yang saling terhubung melalui pointer. Setiap node memuat tiga informasi utama, yaitu nama buah (tipe string), jumlah buah (tipe int), dan harga buah (tipe float), serta memiliki pointer next yang menunjuk ke node selanjutnya.

#### Full code Screenshot:
<img width="474" height="841" alt="image" src="https://github.com/user-attachments/assets/bb464579-82dd-46bc-8746-0a358536ddad" />
<img width="655" height="833" alt="image" src="https://github.com/user-attachments/assets/713c38d3-e6e0-46fb-95cd-bb7c3b6109c5" />
<img width="636" height="830" alt="image" src="https://github.com/user-attachments/assets/0b7bea22-7fe5-4f42-ab1d-a6f1e6366940" />

## Kesimpulan
Pada modul ini, mempelajari konsep dan mekanisme kerja Singly Linked List sebagai struktur data dinamis yang tersusun dari node-node berisi data dan pointer yang saling terhubung. Melalui kegiatan praktikum, mahasiswa memahami berbagai operasi dasar seperti pembuatan list, penambahan, penghapusan, pencarian, serta pembaruan data, sekaligus mempelajari pengelolaan memori menggunakan pointer. Modul ini menegaskan bahwa Singly Linked List merupakan konsep dasar yang penting dalam struktur data dinamis karena memungkinkan pengolahan data secara fleksibel dan efisien.

## Referensi
[1] [I. Holm, Narrator, and J. Fullerton-Smith, Producer, How to Build a Human [DVD]. London: BBC; 2002.](https://github.com/adamhaydar/Struktur-Data-Assignment/edit/main/Modul%205/Readme.md)
[2] Ai
[3] Teman
