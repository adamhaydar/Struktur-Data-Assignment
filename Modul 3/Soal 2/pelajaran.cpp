#include <iostream>
#include "pelajaran.h"
using namespace std;

Pelajaran createPelajaran(string nama, string kode) {
    Pelajaran p;
    p.namaMapel = nama;
    p.kodeMapel = kode;
    return p;
}

void tampilPelajaran(Pelajaran p) {
    cout << "nama pelajaran : " << p.namaMapel << endl;
    cout << "nilai : " << p.kodeMapel << endl;
}
