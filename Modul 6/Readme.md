# <h1 align="center">DOUBLYLINKEDLIST(BAGIANPERTAMA)</h1>
<p align="center">Adam Haydar</p>

## Dasar Teori

Doubly Linked List adalah struktur data yang setiap nodenya dilengkapi dua pointer, yaitu pointer ke node sebelumnya (prev) dan pointer ke node selanjutnya (next).

## Guided 

### 1. [Nama Topik]

```C++
#include <iostream>
#define Nil NULL
using namespace std;

typedef int infotype; // Definisikan tipe data infotype sebagai integer untuk menyimpan informasi elemen
typedef struct elmlist *address; // Definisikan tipe address sebagai pointer ke struct elmlist

struct elmlist {
    infotype info; // Deklarasikan field info untuk menyimpan data elemen
    address next;
    address prev;
};

struct List { 
    address first; 
    address last; 
}; 

void insertFirst(List &L, address P) { 
    P->next = L.first; // Set pointer next dari P ke elemen pertama saat ini
    P->prev = Nil; // Set pointer prev dari P ke Nil karena menjadi elemen pertama
    if (L.first != Nil) L.first->prev = P; // Jika list tidak kosong, set prev elemen pertama lama ke P
    else L.last = P; // Jika list kosong, set last juga ke P
    L.first = P; // Update first list menjadi P
} 

void insertLast(List &L, address P) { 
    P->prev = L.last; // Set pointer prev dari P ke elemen terakhir saat ini
    P->next = Nil; // Set pointer next dari P ke Nil karena menjadi elemen terakhir
    if (L.last != Nil) L.last->next = P; // Jika list tidak kosong, set next elemen terakhir lama ke P
    else L.first = P; // Jika list kosong, set first juga ke P
    L.last = P; // Update last list menjadi P
} 

void insertAfter(List &L, address P, address R) { // Definisikan fungsi insertAfter untuk menyisipkan elemen setelah R
    P->next = R->next; // Set pointer next dari P ke elemen setelah R
    P->prev = R; // Set pointer prev dari P ke R
    if (R->next != Nil) R->next->prev = P; // Jika ada elemen setelah R, set prev elemen tersebut ke P
    else L.last = P; // Jika R adalah terakhir, update last menjadi P
    R->next = P; // Set next dari R ke P
}

address alokasi(infotype x) { // Definisikan fungsi alokasi untuk membuat elemen baru
    address P = new elmlist; // Alokasikan memori baru untuk elemen
    P->info = x; // Set info elemen dengan nilai x
    P->next = Nil; // Set next elemen ke Nil
    P->prev = Nil; // Set prev elemen ke Nil
    return P; 
} 

void printInfo(List L) { // Definisikan fungsi printInfo untuk mencetak isi list
    address P = L.first; // Set P ke elemen pertama list
    while (P != Nil) { // Loop selama P tidak Nil
        cout << P->info << " "; // Cetak info dari P 
        P = P->next; // Pindah ke elemen berikutnya
    } 
    cout << endl; 
}

int main() { 
    List L; 
    L.first = Nil; 
    L.last = Nil;
    address P1 = alokasi(1); 
    insertFirst(L, P1); 
    address P2 = alokasi(2); 
    insertLast(L, P2); 
    address P3 = alokasi(3); 
    insertAfter(L, P3, P1); 
    printInfo(L); 
    return 0; 
}
```
Program ini menampilkan proses pembuatan dan pengelolaan struktur data doubly linked list dengan menyisipkan tiga nilai, yaitu 1, 2, dan 3, pada posisi tertentu sehingga urutan data akhir yang terbentuk adalah 1, 3, dan 2.

## Unguided 

### 1. [Soal]
**Doublylist.h**
```C++
#ifndef DOUBLYLIST_H
#define DOUBLYLIST_H

#include <iostream>
#include <string>
using namespace std;

struct Kendaraan {
    string nopol;
    string warna;
    int tahun;
};

typedef struct Node* address;

struct Node {
    Kendaraan data;
    address next;
    address prev;
};

struct List {
    address first;
    address last;
};

void createList(List &L);
address newNode(Kendaraan x);
void printList(List L);
void insertLast(List &L, address P);
address find(List L, string nopol);

void deleteByNopol(List &L, string nopol);

#endif
```
**Doublylist.cpp**
```C++
#include "DoublyList.h"
using namespace std;

void createList(List &L) {
    L.first = NULL;
    L.last = NULL;
}

address newNode(Kendaraan x) {
    address P = new Node;
    P->data = x;
    P->next = NULL;
    P->prev = NULL;
    return P;
}

void printList(List L) {
    cout << "DATA LIST 1\n\n";
    address P = L.last;
    while (P != NULL) {
        cout << "no polisi : " << P->data.nopol << endl;
        cout << "warna     : " << P->data.warna << endl;
        cout << "tahun     : " << P->data.tahun << endl;
        if (P->prev != NULL) cout << endl;
        P = P->prev;
    }
}

void insertLast(List &L, address P) {
    if (L.first == NULL) {
        L.first = L.last = P;
    } else {
        L.last->next = P;
        P->prev = L.last;
        L.last = P;
    }
}

address find(List L, string nopol) {
    address P = L.first;
    while (P != NULL) {
        if (P->data.nopol == nopol) return P;
        P = P->next;
    }
    return NULL;
}

void deleteByNopol(List &L, string nopol) {
    address P = find(L, nopol);
    if (P == NULL) {
        cout << "Data tidak ditemukan\n";
        return;
    }

    if (P == L.first && P == L.last) {
        L.first = L.last = NULL;
    } 
    else if (P == L.first) {
        L.first = P->next;
        L.first->prev = NULL;
    } 
    else if (P == L.last) {
        L.last = P->prev;
        L.last->next = NULL;
    } 
    else {
        P->prev->next = P->next;
        P->next->prev = P->prev;
    }

    cout << "Data dengan nomor polisi " << nopol << " berhasil dihapus.\n\n";
    delete P;
}
```
**main.cpp**
```C++
#include <iostream>
#include "DoublyList.h"
using namespace std;

int main() {
    List L;
    createList(L);

    Kendaraan x;
    string nopol;

    cout << "masukkan nomor polisi: ";
    cin >> x.nopol;
    cout << "masukkan warna kendaraan: ";
    cin >> x.warna;
    cout << "masukkan tahun kendaraan: ";
    cin >> x.tahun;
    insertLast(L, newNode(x));
    cout << endl;

    cout << "masukkan nomor polisi: ";
    cin >> x.nopol;
    cout << "masukkan warna kendaraan: ";
    cin >> x.warna;
    cout << "masukkan tahun kendaraan: ";
    cin >> x.tahun;
    insertLast(L, newNode(x));
    cout << endl;

    cout << "masukkan nomor polisi: ";
    cin >> nopol;
    if (find(L, nopol) != NULL) {
        cout << "nomor polisi sudah terdaftar\n\n";
    }

    cout << "masukkan nomor polisi: ";
    cin >> x.nopol;
    cout << "masukkan warna kendaraan: ";
    cin >> x.warna;
    cout << "masukkan tahun kendaraan: ";
    cin >> x.tahun;
    insertLast(L, newNode(x));
    cout << endl;

    printList(L);
    cout << endl;

    cout << "Masukkan Nomor Polisi yang dicari  : ";
    cin >> nopol;

    address P = find(L, nopol);
    if (P != NULL) {
        cout << "\nNomor Polisi : " << P->data.nopol << endl;
        cout << "Warna        : " << P->data.warna << endl;
        cout << "Tahun        : " << P->data.tahun << endl;
    }
    cout << endl;

    cout << "Masukkan Nomor Polisi yang akan dihapus  : ";
    cin >> nopol;
    deleteByNopol(L, nopol);

    printList(L);

    return 0;
}
```
#### Output:
![240302_00h00m06s_screenshot](https://github.com/suxeno/Struktur-Data-Assignment/assets/111122086/6d1727a8-fb77-4ecf-81ff-5de9386686b7)

Jika dibandingkan dengan singly linked list, doubly linked list memiliki keunggulan karena dapat ditelusuri dari dua arah. Hal ini membuat proses penyisipan dan penghapusan data menjadi lebih efisien, terutama pada operasi yang membutuhkan akses ke node sebelumnya.2

#### Full code Screenshot:
<img width="543" height="928" alt="image" src="https://github.com/user-attachments/assets/b15c5bb6-0b10-49d5-9cfe-2f29a8a127a3" />
<img width="515" height="1114" alt="image" src="https://github.com/user-attachments/assets/cef3953e-ed29-4b97-980c-f060c0cdd200" />
<img width="438" height="978" alt="image" src="https://github.com/user-attachments/assets/81717d68-09a0-4c20-9200-c0b3fa3913f8" />

## Kesimpulan
Doubly Linked List memberikan kemampuan yang lebih baik dibandingkan Singly Linked List ketika dibutuhkan penelusuran data dari dua arah, meskipun penggunaan memorinya lebih besar karena adanya pointer tambahan. Struktur data ini cocok diterapkan pada aplikasi yang sering melakukan operasi penyisipan dan penghapusan elemen di berbagai posisi dalam list.

## Referensi
[1] Ginting, S. H. N., Effendi, H., Kumar, S., Marsisno, W., Sitanggang, Y. R. U., Anwar, K., ... & Smrti, N. N. E. (2024). Pengantar struktur data. Penerbit Mifandi Mandiri Digital, 1(01).
[2] Ai
[3] Teman
