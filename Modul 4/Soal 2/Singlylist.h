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
