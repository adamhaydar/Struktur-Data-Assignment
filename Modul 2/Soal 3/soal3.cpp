#include <iostream>
using namespace std;

int cariMaks(int a[], int n) {
    int maks = a[0];
    for (int i = 1; i < n; i++)
        if (a[i] > maks) maks = a[i];
    return maks;
}

int cariMin(int a[], int n) {
    int min = a[0];
    for (int i = 1; i < n; i++)
        if (a[i] < min) min = a[i];
    return min;
}

void rataRata(int a[], int n) {
    float total = 0;
    for (int i = 0; i < n; i++)
        total += a[i];
    cout << "Rata-rata: " << total / n << endl;
}

int main() {
    int arr[] = {11, 8, 5, 7, 12, 26, 3, 54, 33, 55};
    int n = sizeof(arr) / sizeof(arr[0]);
    int pilih;

    do {
        cout << "\n--- Menu Array ---\n";
        cout << "1. Tampilkan array\n";
        cout << "2. Nilai maksimum\n";
        cout << "3. Nilai minimum\n";
        cout << "4. Nilai rata-rata\n";
        cout << "5. Keluar\n";
        cout << "Pilih: ";
        cin >> pilih;

        switch (pilih) {
            case 1:
                for (int i = 0; i < n; i++) cout << arr[i] << " ";
                cout << endl;   
                break;
            case 2:
                cout << "Maksimum: " << cariMaks(arr, n) << endl;
                break;
            case 3:
                cout << "Minimum: " << cariMin(arr, n) << endl;
                break;
            case 4:
                rataRata(arr, n);
                break;
            case 5:
                cout << "Selesai.\n";
                break;
            default:
                cout << "Pilihan salah!\n";
        }
    } while (pilih != 5);
}
