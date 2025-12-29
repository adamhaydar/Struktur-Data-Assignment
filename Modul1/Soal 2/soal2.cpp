#include <iostream>
using namespace std;

string ubahTulisan(int n) {
    string satuan[10] = {"", "satu", "dua", "tiga", "empat", "lima", 
                         "enam", "tujuh", "delapan", "sembilan"};
    string belasan[10] = {"sepuluh", "sebelas", "dua belas", "tiga belas", "empat belas",
                          "lima belas", "enam belas", "tujuh belas", "delapan belas", "sembilan belas"};
    string puluhan[10] = {"", "", "dua puluh", "tiga puluh", "empat puluh", 
                          "lima puluh", "enam puluh", "tujuh puluh", "delapan puluh", "sembilan puluh"};

    if (n == 0) return "nol";
    if (n == 100) return "seratus";
    if (n < 10) return satuan[n];
    if (n < 20) return belasan[n - 10];
    
    int p = n / 10;   
    int s = n % 10;   

    if (s == 0) {
        return puluhan[p];
    } else {
        return puluhan[p] + " " + satuan[s];
    }
}

int main() {
    int angka;
    cout << "Masukkan angka (0 - 100) : ";
    cin >> angka;

    if (angka < 0 || angka > 100) {
        cout << "Angka tidak valid!" << endl;
    } else {
        cout << angka << " : " << ubahTulisan(angka) << endl;
    }

    return 0;
}
