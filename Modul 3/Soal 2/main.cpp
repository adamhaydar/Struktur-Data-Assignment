#include <iostream>
#include "pelajaran.h"
using namespace std;

int main() {
    string nama = "Struktur Data";
    string kode = "STD";

    Pelajaran pel = createPelajaran(nama, kode);

    tampilPelajaran(pel);

    return 0;
}
