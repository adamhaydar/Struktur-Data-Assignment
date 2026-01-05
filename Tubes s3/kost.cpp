#include <iostream>
using namespace std;

struct Kamar {
    int noKamar;
    int harga;
    string status; // Kosong / Terisi
    string jenis;  // Reguler / AC / VIP
    string penghuni[5];
    int jmlPenghuni;
    Kamar *left, *right;
};

// ================== BUAT NODE ==================
Kamar* buatKamar(int no, int harga, string status, string jenis) {
    Kamar* baru = new Kamar;
    baru->noKamar = no;
    baru->harga = harga;
    baru->status = status;
    baru->jenis = jenis;
    baru->jmlPenghuni = 0;
    baru->left = baru->right = NULL;
    return baru;
}

// ================== HITUNG TOTAL KAMAR ==================
int hitungKamar(Kamar* root) {
    if (root == NULL)
        return 0;
    return 1 + hitungKamar(root->left) + hitungKamar(root->right);
}

// ================== INSERT KAMAR (MAX 10) ==================
