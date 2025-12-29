#include <iostream>
using namespace std;

int main() {
    float x, y;

    cout << "Masukkan angka pertama : ";
    cin >> x;
    cout << "Masukkan angka kedua   : ";
    cin >> y;

    cout << endl;
    cout << "Penjumlahan = " << (x + y) << endl;
    cout << "Pengurangan = " << (x - y) << endl;
    cout << "Perkalian   = " << (x * y) << endl;

    if(y != 0){
        cout << "Pembagian   = " << (x / y) << endl;
    } else {
        cout << "Pembagian   = tidak bisa (pembagi nol)" << endl;
    }

    return 0;
}
