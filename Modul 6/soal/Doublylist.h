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
