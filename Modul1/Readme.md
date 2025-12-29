# <h1 align="center">Laporan Praktikum Modul Pengenalan Bahasa C++ (1)</h1>
<p align="center">Adam Haydar</p>

## Dasar Teori

C++ merupakan bahasa pemrograman yang dikembangkan dari C dan mendukung pemrograman prosedural maupun berorientasi objek.

## Guided 

### 1. [Nama Topik]**
**Modul Codeblocks IDE & Pengenalan Bahas C++ (1)**
```C++
#include <iostream>

using namespace std;

int main () {
    // array 1 dimensi
    int arrID[5] = {10,20,30,40,50};
    cout << "Array 1 Dimensi" << endl;
    for (int i=0; i<5; i++) {
        cout << "arrID" << i << " = " << arrID[i] << endl; 
        
    }
    cout << endl;

    // array 2 dimensi baris & kolom
    int arr2D[2][3] = {
        {1,2,3},
        {4,5,6}
    };
    cout << "Array 2 Dimensi" << endl;
    for (int i=0; i<2; i++) {
        for (int j=0; j<3; j++) {
            cout << "arr2D[" << i << "}[" << j << "] = " << arr2D[i][j]
            << " ";
        }
        cout << endl;
    }
    cout << endl;
    
    //array multi dimensi (3D)
    int arr3D[2][2][3] = {
    { { 1, 2, 3 }, {4, 5, 6} },
    { { 7, 8, 9} , {10, 11, 12} }   
    };
    cout << "array 3 dimensi" << endl;
    for (int i=0; i<2; i++) {
        for (int j=0; j<2; j++) {
            for (int k=0; k<3; k++) {
                cout << "arr3D[" << i << "][" << j << "]["
                << k << "] = " << arr3D[i][j][k] << endl;
            }
        }
    }

    return 0;
}
```
Program tersebut berfungsi untuk menampilkan data pada array satu dimensi, dua dimensi, dan tiga dimensi ke layar. Proses penampilan setiap elemen dilakukan menggunakan perulangan for, lalu dicetak dengan cout sehingga hasilnya dapat dilihat pada layar.

## Unguided 

### 1. [Soal]

```C++
#include <iostream>
using namespace std;

int main() {
    cout << "ini adalah file code unguided praktikan" << endl;
    return 0;
}
```
#### Output:
![240302_00h00m06s_screenshot](https://github.com/suxeno/Struktur-Data-Assignment/assets/111122086/6d1727a8-fb77-4ecf-81ff-5de9386686b7)
Kode tersebut digunakan untuk menghitung operasi aritmatika dari dua bilangan yang dimasukkan oleh pengguna melalui cin, kemudian hasil perhitungannya ditampilkan ke layar menggunakan cout.

**2. [Soal]**
```C++
#include <iostream>
using namespace std;

int main() {
    cout << "ini adalah file code unguided praktikan" << endl;
    return 0;
}
```
#### Output:
![240302_00h00m06s_screenshot](https://github.com/suxeno/Struktur-Data-Assignment/assets/111122086/6d1727a8-fb77-4ecf-81ff-5de9386686b7)
Kode tersebut berfungsi untuk mengonversi angka yang diinput oleh pengguna menjadi bentuk tulisan dalam bahasa Indonesia menggunakan fungsi ubahTulisan(), kemudian hasilnya ditampilkan ke layar melalui cout.

**3. [Soal]**
```C++
#include <iostream>
using namespace std;

int main() {
    cout << "ini adalah file code unguided praktikan" << endl;
    return 0;
}
```
#### Output:
![240302_00h00m06s_screenshot](https://github.com/suxeno/Struktur-Data-Assignment/assets/111122086/6d1727a8-fb77-4ecf-81ff-5de9386686b7)
Kode ini digunakan untuk membentuk pola angka bercermin dengan simbol bintang sebagai pusatnya. Angka di sisi kiri disusun menurun, sedangkan sisi kanan tersusun menaik, sehingga menghasilkan tampilan yang simetris secara vertikal.

#### Full code Screenshot:
![240309_10h21m35s_screenshot](https://github.com/suxeno/Struktur-Data-Assignment/assets/111122086/41e9641c-ad4e-4e50-9ca4-a0215e336b04)


## Kesimpulan
Program ini membantu meningkatkan pemahaman mengenai penggunaan perulangan bersarang, pengaturan logika posisi spasi, serta pembentukan pola tampilan visual pada layar.

## Referensi
[1] I. Holm, Narrator, and J. Fullerton-Smith, Producer, How to Build a Human [DVD]. London: BBC; 2002.
