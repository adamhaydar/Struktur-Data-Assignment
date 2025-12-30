# <h1 align="center">Laporan Praktikum Modul Pengenalan Bahasa C++ (2)</h1>
<p align="center">Adam Haydar</p>

## Dasar Teori

Bahasa C++ dikembangkan dari bahasa C dan mendukung konsep pemrograman prosedural serta berorientasi objek. Penulisan program dilakukan menggunakan Code::Blocks dengan struktur dasar yang terdiri dari header, fungsi main(), serta pemanfaatan cin dan cout untuk proses masukan dan keluaran.

## Guided 

### 1. [Nama Topik]

```C++
#include <iostream>
using namespace std;

void tukar(int *x, int *y) {
    int temp;
    temp = *x;
    *x = *y;
    *y = temp;
}

int main () {
    int a = 20, b = 30;
    int& ref = a;

    cout << "Nilai a : " << a << endl;
    cout << "Alamat a (&a) : " << &a << endl;
    cout << "Nilai ref (alias a): " << ref << endl;
    cout << "Alamat red (&ref): " << &ref << endl;


    //mengubah nilai a lewar refrence
    ref = 50;
    cout << "\nSetelah ref = 50: " << endl;
    cout << "Nilai a :" << a << endl;
    cout << "Nilai ref :" << ref << endl;

tukar(&a, &b);
cout << "After swapping, value of a : " << a << " and b=" << b << endl;

return 0;
}


#include <iostream>
using namespace std;

void tukar(int *x, int *y) {
    int temp;
    temp = *x;
    *x = *y;
    *y = temp;
}

main () {
    int a = 20, b = 30;
    int *ptr;

    ptr = &a;

    cout << "Value a : " << a << endl;
    cout << "Address a : " << &a << endl;
    cout << "Value stored in otr (address of a) : " << ptr << endl;
    cout << "Value pointed to by ptr: " << *ptr << endl;


tukar(&a, &b);
cout << "After swapping, value of a : " << a << " and b=" << b << endl;

return 0;
}

#include <iostream>
using namespace std;

void tulis (int x) {
    for (int i = 0; i < x; i++) {
        cout << "Baris ke -: " << i+1 << endl;
    }
}


int main() {
    int jum;
    cout << "Jumlah baris kata: ";
    cin >> jum;
    tulis(jum);
    return 0;
}

#include <iostream>
using namespace std;

int main() {
    // --- Array 1 Dimensi ---
    int arr[5] = {10, 20, 30, 40, 50};
    cout << "Array 1 Dimensi:" << endl;
    for (int i = 0; i < 5; i++) {
        cout << "Element ke-" << i << ": " << arr[i] << endl;
    }
    cout << endl;

    // --- Array 2 Dimensi ---
    int arr2D[2][3] = {
        {1, 2, 3},
        {4, 5, 6},
    };
    cout << "Array 2 Dimensi:" << endl;
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 3; j++) {
            cout << "arr2D[" << i << "][" << j << "]: " << arr2D[i][j]
            << " ";
        }
        cout << endl;
    }
    // --- Array Multi Dimensi (3D) ---
    int arr3D[2][2][3] = {
        { {1, 2, 3}, {4, 5, 6} },
        { {7, 8, 9}, {10, 11, 12} },
    };
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            for (int k = 0; k < 3; k++) {
                cout << "arr3D[" << i << "][" << j << "]["
                << k << "]: " << arr3D[i][j][k] << endl;
            }
        }
    }

    return 0;
}
```
Program ini memperlihatkan penggunaan pointer, reference, fungsi, dan array dalam C++. Dari contoh yang ada, bisa dipahami cara mengubah nilai variabel, menukar data, menggunakan fungsi, serta menyimpan data dalam array satu hingga tiga dimensi.

## Unguided 

### 1. [Soal]

```C++
#include <iostream>
using namespace std;

int main() {
    int A[3][3], B[3][3];
    int tambah[3][3], kurang[3][3], kali[3][3];

    cout << "Masukkan elemen matriks A (3x3):" << endl;
    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++) {
            cin >> A[i][j];
        }
    }

    cout << "\nMasukkan elemen matriks B (3x3):" << endl;
    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++) {
            cin >> B[i][j];
        }
    }

    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++) {
            tambah[i][j] = A[i][j] + B[i][j];
            kurang[i][j] = A[i][j] - B[i][j];
        }
    }

    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++) {
            kali[i][j] = 0;
            for(int k = 0; k < 3; k++) {
                kali[i][j] += A[i][k] * B[k][j];
            }
        }
    }

    cout << "\nHasil Penjumlahan Matriks:" << endl;
    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++) {
            cout << tambah[i][j] << " ";
        }
        cout << endl;
    }

    cout << "\nHasil Pengurangan Matriks:" << endl;
    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++) {
            cout << kurang[i][j] << " ";
        }
        cout << endl;
    }

    cout << "\nHasil Perkalian Matriks:" << endl;
    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++) {
            cout << kali[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
```
#### Output:
<img width="442" height="720" alt="image" src="https://github.com/user-attachments/assets/2eea3852-729f-46be-a406-cda84b4da8e2" />

Program ini berfungsi untuk mengolah dua matriks berukuran 3×3. Pengguna diminta memasukkan elemen matriks A dan B serta memilih jenis operasi yang akan dilakukan, seperti penjumlahan, pengurangan, atau perkalian. Setelah perhitungan selesai, hasilnya ditampilkan ke layar menggunakan cout.

### 2. [Soal]

```C++
#include <iostream>
using namespace std;

void tukarReference(int &a, int &b, int &c) {
    int temp = a;
    a = b;
    b = c;
    c = temp;
}

int main() {
    int x = 10, y = 20, z = 30;
    cout << "Sebelum: x=" << x << ", y=" << y << ", z=" << z << endl;
    tukarReference(x, y, z);
    cout << "Sesudah: x=" << x << ", y=" << y << ", z=" << z << endl;
}
```
#### Output:
<img width="510" height="250" alt="image" src="https://github.com/user-attachments/assets/c9c43750-dc7a-4ed9-85f8-bf0788c400ae" />

Program ini digunakan untuk menukar nilai tiga variabel secara berurutan dengan menerapkan konsep referensi. Nilai awal masing-masing variabel ditampilkan terlebih dahulu, kemudian fungsi tukarReference memindahkan nilai dari x ke y, y ke z, dan z kembali ke x, sebelum akhirnya hasil pertukaran ditampilkan ke layar.

### 3. [Soal]

```C++
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
```
#### Output:
<img width="347" height="802" alt="image" src="https://github.com/user-attachments/assets/717d0260-627b-40e8-9389-774dbe2de510" />


Kode ini menyajikan menu interaktif untuk mengelola sebuah array, seperti menampilkan data, mencari nilai maksimum dan minimum, serta menghitung rata-rata. Setiap proses dijalankan melalui fungsi yang terpisah, dan program akan terus berulang hingga pengguna memilih opsi keluar.

#### Full code Screenshot:
#### Soal 1 :
<img width="506" height="1050" alt="image" src="https://github.com/user-attachments/assets/7f3d3e3e-0945-47f7-baed-a3a25a23ecd8" />
#### Soal 2 :
<img width="793" height="550" alt="image" src="https://github.com/user-attachments/assets/0288556c-9800-4c2b-9012-004f66f1b718" />
#### Soal 3 :
<img width="443" height="891" alt="image" src="https://github.com/user-attachments/assets/039fc2e5-b507-4499-b764-f7d10e8babc7" />

## Kesimpulan
Program ini menampilkan menu interaktif yang memungkinkan pengguna mengelola sebuah array, seperti menampilkan data, menentukan nilai maksimum dan minimum, serta menghitung nilai rata-ratanya. Setiap pilihan diproses melalui fungsi yang berbeda, dan program akan terus berjalan hingga pengguna memilih opsi keluar.

## Referensi
[1] I. Holm, Narrator, and J. Fullerton-Smith, Producer, How to Build a Human [DVD]. London: BBC; 2002.
