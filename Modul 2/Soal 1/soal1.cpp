#include <iostream>
using namespace std;

int main() {
    int A[3][3], B[3][3], C[3][3], p;

    cout << "Masukkan elemen matriks A:\n";
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            cin >> A[i][j];

    cout << "Masukkan elemen matriks B:\n";
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            cin >> B[i][j];

    cout << "Pilih operasi (1=+, 2=-, 3=*): ";
    cin >> p;

    cout << "Hasil:\n";

    if (p == 1) { 
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++)
                cout << A[i][j] + B[i][j] << "\t";
            cout << endl;
        }
    } 
    else if (p == 2) { 
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++)
                cout << A[i][j] - B[i][j] << "\t";
            cout << endl;
        }
    } 
    else if (p == 3) { 
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                C[i][j] = 0;
                for (int k = 0; k < 3; k++)
                    C[i][j] += A[i][k] * B[k][j];
                cout << C[i][j] << "\t";
            }
            cout << endl;
        }
    } 
    else cout << "Pilihan tidak valid!\n";

    return 0;
}
