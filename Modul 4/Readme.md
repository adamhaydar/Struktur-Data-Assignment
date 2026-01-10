# <h1 align="center">Singly Linked List (Bagian Pertama)</h1>
<p align="center">Adam Haydar</p>

## Dasar Teori

Linked List merupakan struktur data linear yang elemen-elemennya tidak disimpan secara berurutan atau berdekatan di memori. Hubungan antara satu elemen dengan elemen selanjutnya dibentuk melalui pointer atau referensi yang tersimpan pada setiap elemen.

## Guided 

### 1. [Nama Topik]

```C++
1. [Singly Linked List (Bagian Pertama)]
list.h

//
//
#ifndef LIST_H
#define LIST_H
#define Nil NULL

#include <iostream>
using namespace std;

//deklarasi isi data struct mahasiswa
struct mahasiswa{
    string nama;
    string nim;
    int umur;
};

typedef mahasiswa dataMahasiswa; //Membiarkan nama alias dataMahasiswa untuk struct mahasiswa

typedef struct node *address; //Mendefinisikan alias address sbg pointer ke struct node

struct node{
    dataMahasiswa isidata;
    address next;
};

struct linkedlist{ //ini linked list nya
    address first;
};

//semua function & prosedur yang akan dipakai
bool isEmpty(linkedlist List);
void createList(linkedlist &List);
address alokasi(string nama, string nim, int umur);
void dealokasi(address &node);
void printList(linkedlist List);
void insertFirst(linkedlist &List, address nodeBaru);
void insertAfter(linkedlist &List, address nodeBaru, address Prev);
void insertLast(linkedlist &List, address nodeBaru);

#endif
list.cpp

#include "list.h"
#include <iostream>
using namespace std;

//I.S = Initial State / kondisi awal
//F.S = Final State / kondisi akhir

//fungsi untuk cek apakah list kosong atau tidak
bool isEmpty(linkedlist List) {
    if(List.first == Nil){
        return true; 
    } else {
        return false;
    }
}

//pembuatan linked list kosong
void createList(linkedlist &List) {
    /* I.S. sembarang
       F.S. terbentuk list kosong */
    List.first = Nil;
}

//pembuatan node baru dengan menerapkan manajemen memori
address alokasi(string nama, string nim, int umur) { 
    /* I.S. sembarang
       F.S. mengembalikan alamat node baru dengan isidata = sesuai parameter dan next = Nil */
    address nodeBaru = new node; 
    nodeBaru->isidata.nama = nama;
    nodeBaru->isidata.nim = nim; 
    nodeBaru->isidata.umur = umur;
    nodeBaru->next = Nil;
    return nodeBaru;
}

//penghapusan node dengan menerapkan manajemen memori
void dealokasi(address &node) {
    /* I.S. P terdefinisi
       F.S. memori yang digunakan node dikembalikan ke sistem */
    node->next = Nil;
    delete node;
}

//prosedur-prosedur untuk insert / menambahkan node baru kedalam list
void insertFirst(linkedlist &List, address nodeBaru) {
    /* I.S. sembarang, P sudah dialokasikan
       F.S. menempatkan elemen list (node) pada awal list */
    nodeBaru->next = List.first; 
    List.first = nodeBaru;
}

void insertAfter(linkedlist &List, address nodeBaru, address Prev) {
    /* I.S. sembarang, nodeBaru dan Prev alamat salah satu elemen list (node)
       F.S. menempatkan elemen (node) sesudah elemen node Prev */
    if (Prev != Nil) {
        nodeBaru->next = Prev->next;
        Prev->next = nodeBaru;
    } else {
        cout << "Node sebelumnya tidak valid!" << endl;
    }
}

void insertLast(linkedlist &List, address nodeBaru) {
    /* I.S. sembarang, nodeBaru sudah dialokasikan
       F.S. menempatkan elemen nodeBaru pada akhir list */
    if (isEmpty(List)) {
        List.first = nodeBaru;
    } else {
        address nodeBantu = List.first;
        while (nodeBantu->next != Nil) {
            nodeBantu = nodeBantu->next;
        }
        nodeBantu->next = nodeBaru;
    }
}

//prosedur-prosedur untuk delete / menghapus node yang ada didalam list
void delFirst(linkedlist &List){
    /* I.S. list tidak kosong
    F.S. node pertama di list terhapus*/
    address nodeHapus;
    if (isEmpty(List) == false) {
        nodeHapus = List.first;
        List.first = List.first->next;
        nodeHapus->next = Nil;
        dealokasi(nodeHapus);
    } else {
        cout << "List kosong!" << endl;
    }
}

void delLast(linkedlist &List){
    /* I.S. list tidak kosong
    F.S. node terakhir di list terhapus */
    address nodeHapus, nodePrev;
    if(isEmpty(List) == false){
        nodeHapus = List.first;
        if(nodeHapus->next == Nil){
            List.first->next = Nil;
            dealokasi(nodeHapus);
        } else { 
            while(nodeHapus->next != Nil){
                nodePrev = nodeHapus; 
                nodeHapus = nodeHapus->next;
            }
            nodePrev->next = Nil; 
            dealokasi(nodeHapus);
        }
    } else {
        cout << "list kosong" << endl;
    }
}

void delAfter(linkedlist &List, address nodeHapus, address nodePrev){
    /* I.S. list tidak kosng, Prev alamat salah satu elemen list
    F.S. nodeBantu adalah alamat dari Prev→next, menghapus Prev→next dari list */
    if(isEmpty(List) == true){
        cout << "List kosong!" << endl;
    } else { //jika list tidak kosong
        if (nodePrev != Nil && nodePrev->next != Nil) { 
            nodeHapus = nodePrev->next;       
            nodePrev->next = nodeHapus->next;  
            nodeHapus->next = Nil;         
            dealokasi(nodeHapus);
        } else {
            cout << "Node sebelumnya (prev) tidak valid!" << endl;
        }
    }
}

//prosedur untuk menampilkan isi list
void printList(linkedlist List) {
    /* I.S. list mungkin kosong
       F.S. jika list tidak kosong menampilkan semua info yang ada pada list */
    if (isEmpty(List)) {
        cout << "List kosong." << endl;
    } else {
        address nodeBantu = List.first;
        while (nodeBantu != Nil) { 
            cout << "Nama : " << nodeBantu->isidata.nama << ", NIM : " << nodeBantu->isidata.nim << ", Usia : " << nodeBantu->isidata.umur << endl;
            nodeBantu = nodeBantu->next;
        }
    }
}

//function untuk menampilkan jumlah node didalam list
int nbList(linkedlist List) {
    /* I.S. list sudah ada
       F.S. menampilkan jumlah node didalam list*/
    int count = 0;
    address nodeBantu = List.first;
    while (nodeBantu != Nil) {
        count++;
        nodeBantu = nodeBantu->next; 
    }
    return count;
}

//prosedur untuk menghapus list (menghapus semua node didalam list)
void deleteList(linkedlist &List){
    /* I.S. list sudah ada
       F.S. menghapus semua node didalam list*/
    address nodeBantu, nodeHapus;
    nodeBantu = List.first;
    while(nodeBantu != Nil){
        nodeHapus = nodeBantu;
        nodeBantu = nodeBantu->next;
        dealokasi(nodeHapus); 
    }
    List.first = Nil; 
    cout << "List sudah terhapus!" << endl;
}
main.cpp

#include "list.h"

#include<iostream>
using namespace std;

int main(){
    linkedlist List;
    address nodeA, nodeB, nodeC, nodeD, nodeE = Nil;
    createList(List);

    dataMahasiswa mhs;

    nodeA = alokasi("Dhimas", "2311102151", 20);
    nodeB = alokasi("Arvin", "2211110014", 21);
    nodeC = alokasi("Rizal", "2311110029", 20);
    nodeD = alokasi("Satrio", "2211102173", 21);
    nodeE = alokasi("Joshua", "2311102133", 21);

    insertFirst(List, nodeA);
    insertLast(List, nodeB);
    insertAfter(List, nodeC, nodeA);
    insertAfter(List, nodeD, nodeC);
    insertLast(List, nodeE);

    cout << "--- ISI LIST SETELAH DILAKUKAN INSERT ---" << endl;
    printList(List);

    return 0;
}
```

Program ini menggunakan Singly Linked List untuk menyimpan data mahasiswa. Setiap data disimpan dalam node yang saling terhubung satu arah, sehingga data bisa ditambahkan di awal, di tengah, atau di akhir list. Dari program ini terlihat bagaimana proses insert dan pengelolaan node dilakukan tanpa menggunakan array. Praktikum ini membantu memahami dasar kerja linked list serta cara mengatur data secara dinamis.
## Unguided 

### 1. [Soal]
**Singlyist.h**
```C++
#ifndef SINGLYLIST_H
#define SINGLYLIST_H

#include <iostream>
using namespace std;

typedef int infotype;

struct ElmList {
    infotype info;
    ElmList* next;
};

typedef ElmList* address;

struct List {
    address First;
};

void createList(List &L);
address alokasi(infotype x);
void dealokasi(address P);
void insertFirst(List &L, address P);
void printInfo(List L);

#endif
```
**Singlylist.cpp**
```C++
#include "Singlylist.h"

void createList(List &L) {
    L.First = nullptr;
}

address alokasi(infotype x) {
    address P = new ElmList;
    if (P != nullptr) {
        P->info = x;
        P->next = nullptr;
    }
    return P;
}

void dealokasi(address P) {
    delete P;
}

void insertFirst(List &L, address P) {
    if (P != nullptr) {
        P->next = L.First;
        L.First = P;
    }
}

void printInfo(List L) {
    address P = L.First;
    while (P != nullptr) {
        cout << P->info << " ";
        P = P->next;
    }
    cout << endl;
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

    return 0;
}
```
#### Output:
<img width="536" height="137" alt="image" src="https://github.com/user-attachments/assets/884a390b-eced-4c10-8290-b3310a470511" />

Program ini menunjukkan penggunaan singly linked list untuk menyimpan data bilangan bulat. Data dimasukkan ke dalam list menggunakan metode insert di awal, sehingga elemen terakhir yang dimasukkan akan berada di posisi paling depan. Dari hasil program, dapat dilihat bahwa linked list bekerja dengan menghubungkan data satu per satu menggunakan pointer, sehingga urutan data bisa berubah sesuai cara insert yang digunakan.

### 2. [Soal]
**SInglylist.h**
```C++
#ifndef SINGLYLIST_H
#define SINGLYLIST_H

#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

struct List {
    Node* head;
};

void createList(List &L);
Node* createNode(int nilai);
void deleteNode(Node* P);
void insertFirst(List &L, Node* P);
void printList(List L);

void deleteFirst(List &L, Node* &P);
void deleteLast(List &L, Node* &P);
void deleteAfter(Node* prec, Node* &P);
int countList(List L);
void deleteAll(List &L);

#endif
```
**Singlylist.cpp**
```C++
#include "Singlylist.h"

void createList(List &L) {
    L.head = nullptr;
}

Node* createNode(int nilai) {
    Node* P = new Node;
    P->data = nilai;
    P->next = nullptr;
    return P;
}

void deleteNode(Node* P) {
    delete P;
}

void insertFirst(List &L, Node* P) {
    if (P != nullptr) {
        P->next = L.head;
        L.head = P;
    }
}

void printList(List L) {
    Node* P = L.head;
    while (P != nullptr) {
        cout << P->data << " ";
        P = P->next;
    }
    cout << endl;
}

void deleteFirst(List &L, Node* &P) {
    if (L.head != nullptr) {
        P = L.head;
        L.head = P->next;
        P->next = nullptr;
    } else {
        P = nullptr;
    }
}

void deleteLast(List &L, Node* &P) {
    if (L.head == nullptr) {
        P = nullptr;
    } else if (L.head->next == nullptr) {
        P = L.head;
        L.head = nullptr;
    } else {
        Node* Q = L.head;
        while (Q->next->next != nullptr) {
            Q = Q->next;
        }
        P = Q->next;
        Q->next = nullptr;
    }
}

void deleteAfter(Node* prec, Node* &P) {
    if (prec != nullptr && prec->next != nullptr) {
        P = prec->next;
        prec->next = P->next;
        P->next = nullptr;
    } else {
        P = nullptr;
    }
}

int countList(List L) {
    int jumlah = 0;
    Node* P = L.head;
    while (P != nullptr) {
        jumlah++;
        P = P->next;
    }
    return jumlah;
}

void deleteAll(List &L) {
    Node* P;
    while (L.head != nullptr) {
        deleteFirst(L, P);
        deleteNode(P);
    }
}
```
**main.cpp**
```C++
#include "Singlylist.h"

int main() {
    List L;
    Node *P, *hapus;

    createList(L);

    insertFirst(L, createNode(2));
    insertFirst(L, createNode(0));
    insertFirst(L, createNode(8));
    insertFirst(L, createNode(12));
    insertFirst(L, createNode(9));

    deleteFirst(L, hapus);
    deleteNode(hapus);

    deleteLast(L, hapus);
    deleteNode(hapus);

    Node* prec = L.head;
    deleteAfter(prec, hapus);
    deleteNode(hapus);

    printList(L);
    cout << "Jumlah node : " << countList(L) << endl;

    deleteAll(L);
    cout << "\n- List Berhasil Terhapus -" << endl;
    cout << "Jumlah node : " << countList(L) << endl;

    return 0;
}
```
#### Output:
<img width="508" height="119" alt="image" src="https://github.com/user-attachments/assets/d94c780e-be9d-482d-8529-aa5da5753ac1" />

Versi ini merupakan lanjutan dari program sebelumnya. Kalau sebelumnya hanya bisa menambah dan menampilkan data, sekarang programnya sudah bisa menghapus data, menghitung jumlah node, dan mengosongkan list, jadi cara kerjanya lebih lengkap dan mirip penggunaan linked list di kondisi sebenarnya.

#### Full code Screenshot:
#### Soal 1 :
<img width="460" height="732" alt="image" src="https://github.com/user-attachments/assets/66d8305d-2225-43a0-9b78-b45358950f82" />
<img width="470" height="917" alt="image" src="https://github.com/user-attachments/assets/62e262e7-86f8-4531-bd8c-9cccbffaf1b4" />
<img width="436" height="761" alt="image" src="https://github.com/user-attachments/assets/278bb185-37db-4ca0-b831-745d7e3e5891" />

#### Soal 2 :
<img width="471" height="756" alt="image" src="https://github.com/user-attachments/assets/cc8a4c7e-c406-4101-9932-3f8200831e07" />
<img width="319" height="1055" alt="image" src="https://github.com/user-attachments/assets/f4ea0eea-45ae-4e93-8eee-ccdb680b189d" />
<img width="677" height="899" alt="image" src="https://github.com/user-attachments/assets/6e8dcafc-79d6-4823-807e-20031c7027b1" />


## Kesimpulan
Secara keseluruhan, modul dan praktikum Singly Linked List membahas pengelolaan data secara dinamis melalui penggunaan node-node yang saling terhubung. Materi ini menjelaskan cara menambah, menghapus, serta mengolah atau menghitung data dalam list secara teratur dan efisien.

## Referensi
[1] Sofianti, H. A., Manullang, Y. V., Tampubolon, N. A., Naibaho, L. H., & Gunawan, I. (2025). Implementasi Struktur Data Array Dan Linked List Dalam Pengelolaan Data Mahasiswa. Menulis: Jurnal Penelitian Nusantara, 1(6), 871-877.
[2] Nizar
[3] Nopal
[4] AI
