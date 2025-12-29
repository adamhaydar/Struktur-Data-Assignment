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