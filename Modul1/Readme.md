# <h1 align="center">Laporan Praktikum Modul Pengenalan Bahasa C++ (1)</h1>
<p align="center">Adam Haydar</p>

## Dasar Teori

C++ merupakan bahasa pemrograman yang dikembangkan dari C dan mendukung pemrograman prosedural maupun berorientasi objek.

## Guided 

### 1. [Nama Topik]
**Modul Codeblocks IDE & Pengenalan Bahas C++ (1)**
```C++
#include <iostream>
using namespace std;

int main () {
    int a;
    int b;

    cout << "masukan angka: ";
    cin >> a;
    cout << "masukan angka: ";
    cin >> b;

    //operator aritmatika
    cout << "a + b = " << (a+b) << endl;
    cout << "a - b = " << (a-b) << endl;
    cout << "a * b = " << (a*b) << endl;
    cout << "a / b = " << (a/b) << endl;
    cout << "a % b = " << (a%b) << endl;

    //operator logika
    cout << "a < b = " << (a<b) << endl;
    cout << "a > b = " << (a>b) << endl;
    cout << "a <= b = " << (a<=b) << endl;
    cout << "a >= b = " << (a>=b) << endl;
    cout << "a == b = " << (a==b) << endl;
    cout << "a != b = " << (a!=b) << endl;
}
```
Program ini meminta pengguna memasukkan dua angka, lalu menampilkan hasil operasi aritmatika seperti tambah, kurang, kali, bagi, dan sisa bagi. Selain itu, program juga membandingkan kedua angka tersebut untuk melihat mana yang lebih besar, lebih kecil, sama, atau tidak sama, lalu hasilnya ditampilkan ke layar.

## Unguided 

### 1. [Soal]

```C++
#include <iostream>
using namespace std;

int main() {
    float a, b;

    cin >> a;
    cin >> b;

    cout << a + b << endl;
    cout << a - b << endl;
    cout << a * b << endl;
    cout << a / b << endl;

    return 0;
}
```
#### Output:
<img width="537" height="163" alt="image" src="https://github.com/user-attachments/assets/aa5136d4-065b-4137-a1bf-221f17549d77" />

Program ini menerima dua angka desimal dari user lalu menampilkan hasil penjumlahan, pengurangan, perkalian, dan pembagian dari kedua angka tersebut.

#### 2. [Soal]
```C++
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
```
#### Output:
<img width="480" height="69" alt="image" src="https://github.com/user-attachments/assets/3bef5998-c23b-4ae8-bcbc-e513c01cbd53" />

Program ini menerima sebuah angka bulat dari 0 sampai 100 lalu menampilkan angka tersebut dalam bentuk tulisan menggunakan percabangan if-else.

#### 3. [Soal]
```C++
#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "Masukkan angka: ";
    cin >> n;

    for (int i = n; i >= 1; i--) {
        for (int s = n; s > i; s--) {
            cout << "  "; 
        }
        for (int j = i; j >= 1; j--) {
            cout << j << " ";
        }
        cout << "* ";
        for (int j = 1; j <= i; j++) {
            cout << j << " ";
        }
        cout << endl;
    }
    for (int s = 0; s < n; s++) {
        cout << "  "; 
    }
    cout << "*\n";

    return 0;
}
```
#### Output:
<img width="509" height="175" alt="image" src="https://github.com/user-attachments/assets/17d27780-8e93-41dc-985e-e6efc5ac446b" />

Program ini menerima satu angka lalu menampilkan pola angka berbentuk mirror (angka menurun, tanda *, lalu angka menaik) menggunakan perulangan for.

#### Full code Screenshot:
#### Soal 1 :
<img width="424" height="464" alt="image" src="https://github.com/user-attachments/assets/bd62dce4-58c7-41a3-a8f2-84a1eabf658e" />

#### Soal 2 : 
<img width="828" height="839" alt="image" src="https://github.com/user-attachments/assets/801b8c4b-e743-4982-a2be-d5a6c786fe30" />

#### Soal 3 :
<img width="532" height="755" alt="image" src="https://github.com/user-attachments/assets/66245b41-e688-4f66-8ca8-0332a90fec0a" />


## Kesimpulan
Program ini membantu meningkatkan pemahaman mengenai penggunaan perulangan bersarang, pengaturan logika posisi spasi, serta pembentukan pola tampilan visual pada layar.

## Referensi
[1] Rachman, D. A. Perkenalan Abstrak Data Type.
[2] Teman 
[3] Ai
