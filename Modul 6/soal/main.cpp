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