#ifndef UANG_H
#define UANG_H

#include <iostream>
#include <string>
#include <queue>
using namespace std;  

// CHILD (MLL - TIPE DASAR)
struct Transaksi {
    int nominal;
    Transaksi *next;
};

// PARENT (BST NODE)
struct NodeBST {
    string namaKategori; // nama kategori (misal: Makan, Bonus)   
    string jenis; // Jenis kategori (Income / Expense)

    int dummyArray[5]; // array tipe dasar               //NodeBST menyimpan kategori keuangan dalam BST dan terhubung ke linked list transaksi (MLL) melalui pointer firstTrx.

    Transaksi *firstTrx; // pointer ke linked list transaksi
    NodeBST *left; // anak kiri BST
    NodeBST *right; // anak kanan BST
};



// PROTOTYPE FUNCTIONS
void createBST(NodeBST* &root);
NodeBST* createNode(string nama, string jenis);
string getKey(NodeBST *node);
string getKey(string nama, string jenis);
void insertBST(NodeBST* &root, string nama, string jenis);
NodeBST* searchBST(NodeBST *root, string nama, string jenis);
NodeBST* deleteBST(NodeBST *root, string nama, string jenis);
bool tambahTransaksi(NodeBST *kategori, int nominal);
bool hapusTransaksi(NodeBST *kategori,int nominal);
bool editKategori(NodeBST* &root, string nama, string jenis, string newNama, string newJenis);
bool editTransaksi(NodeBST *kategori,int oldNom,int newNom);
int totalTransaksi(NodeBST *kategori);
int minTransaksi(NodeBST *kategori);
int maxTransaksi(NodeBST *kategori);
double avgTransaksi(NodeBST *kategori);
int hitungSaldo(NodeBST *root);
int countKategori(NodeBST *root);
void inorderKategori(NodeBST *root);
void preorderKategori(NodeBST *root);
void postorderKategori(NodeBST *root);
void inorderTransaksi(NodeBST *root);
void preorderTransaksi(NodeBST *root);
void postorderTransaksi(NodeBST *root);

#endif