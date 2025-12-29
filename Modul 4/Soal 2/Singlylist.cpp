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
