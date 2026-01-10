#include "bstree.h"

address alokasi(infotype x) {
    address P = new Node;
    if (P != Nil) {
        P->info = x;
        P->left = Nil;
        P->right = Nil;
    }
    return P;
}

void insertNode(address &root, infotype x) {
    if (root == Nil) {
        root = alokasi(x);
        return;
    }
    if (x < root->info) {
        insertNode(root->left, x);
    } else if (x > root->info) {
        insertNode(root->right, x);
    }
}

void printInOrderStrip(address root) {
    if (root == Nil) return;
    printInOrderStrip(root->left);
    cout << root->info << " - ";
    printInOrderStrip(root->right);
}

int hitungJumlahNode(address root) {
    if (root == Nil) return 0;
    return 1 + hitungJumlahNode(root->left) + hitungJumlahNode(root->right);
}

int hitungTotalInfo(address root) {
    if (root == Nil) return 0;
    return root->info + hitungTotalInfo(root->left) + hitungTotalInfo(root->right);
}

int hitungKedalaman(address root) {
    if (root == Nil) return 0;
    int kiri = hitungKedalaman(root->left);
    int kanan = hitungKedalaman(root->right);
    if (kiri > kanan) return kiri + 1;
    else return kanan + 1;
}