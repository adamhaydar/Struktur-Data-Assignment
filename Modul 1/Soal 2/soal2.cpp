#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;

    if (n == 0) cout << "nol";
    else if (n == 10) cout << "sepuluh";
    else if (n == 11) cout << "sebelas";
    else if (n < 10) {
        string satuan[] = {"", "satu", "dua", "tiga", "empat", "lima",
                           "enam", "tujuh", "delapan", "sembilan"};
        cout << satuan[n];
    }
    else if (n < 20) {
        string satuan[] = {"", "satu", "dua's", "tiga", "empat", "lima",
                           "enam", "tujuh", "delapan", "sembilan"};
        cout << satuan[n % 10] << " belas";
    }
    else if (n < 100) {
        string satuan[] = {"", "satu", "dua", "tiga", "empat", "lima",
                           "enam", "tujuh", "delapan", "sembilan"};
        cout << satuan[n / 10] << " puluh " << satuan[n % 10];
    }
    else if (n == 100) {
        cout << "seratus";
    }

    return 0;
}
