# <h1 align="center">ABSTRACT DATA TYPE (ADT)</h1>
<p align="center">Adam Haydar</p>

## Dasar Teori
ADT adalah tipe data yang dilengkapi dengan kumpulan operasi dasar atau primitif yang dapat dilakukan terhadapnya. Dalam ADT yang lengkap, terdapat pula penjelasan mengenai invarian tipe serta aksioma yang menentukan perilaku data tersebut. ADT pada dasarnya bersifat sebagai definisi statis.

## Guided 

### 1. [Nama Topik]

```C++
#include <iostream>
using namespace std;

struct mahasiswa{ 
char nim[10]; 
int nilai1,nilai2;
};
void inputMhs(mahasiswa &m); 
float rata2(mahasiswa m);

int main() 
{ 
mahasiswa mhs; 
inputMhs(mhs); 
cout << “rata-rata = “ << rata2(mhs); 
return 0; 
}


void inputMhs(mahasiswa &m){ 
cout << “input nama = “; 
cin >> m.nim; 
cout << “input nilai = “; 
cin >> m.nilai1; 
cout << “input nilai2 = “;
cin >> m.nilai2; 
} 
float rata2(mahasiswa m){ 
return float(m.nilai1+m.nilai2)/2; 
}

mahasiswa.h
#ifndef MAHASISWA_H_INCLUDED 
#define MAHASISWA_H_INCLUDED 
struct mahasiswa{ 
char nim[10]; 
int nilai1, nilai2; 
};
void inputMhs(mahasiswa &m); 
float rata2(mahasiswa m); 
#endif // MAHASISWA_H_INCLUDED

mahasiswa.cpp
#include “mahasiswa.h” 
void inputMhs(mahasiswa &m){ 
cout << “input nama = “; 
cin >> (m).nim; 
cout << “input nilai = “; 
cin >> (m).nilai1; 
cout << “input nilai2 = “; 
cin >> (m).nilai2;
} 
 
float rata2(mahasiswa m){ 
  return float(m.nilai1+m.nilai2)/2; 
}

main.cpp
#include <iostream> 
#include “mahasiswa.h” 
 
using namespace std; 
 
int main() 
{ 
  mahasiswa mhs; 
  inputMhs(mhs); 
  cout << “rata-rata = “ << rata2(mhs); 
  return 0; 
} 
```
Program ini digunakan untuk menginput data mahasiswa berupa NIM dan dua nilai, lalu menghitung nilai rata-ratanya. Pada versi awal, semua kode ditulis dalam satu file. Sedangkan pada versi berikutnya, program dipisah menjadi file header dan source supaya lebih rapi dan terstruktur. Dengan pemisahan ini, program jadi lebih mudah dibaca, dikelola, dan dikembangkan ke depannya.

## Unguided 

### 1. [Soal]
**Soal 1.cpp**
```C++
#include <iostream>
using namespace std;

struct Mahasiswa {
    string nama;
    string nim;
    float uts, uas, tugas, nilaiAkhir;
};

float hitungNilaiAkhir(float uts, float uas, float tugas) {
    return 0.3 * uts + 0.4 * uas + 0.3 * tugas;
}

int main() {
    Mahasiswa mhs[10];
    int n;

    cout << "Masukkan jumlah mahasiswa (maks 10): ";
    cin >> n;

    for (int i = 0; i < n; i++) {
        cout << "\nData mahasiswa ke-" << i + 1 << endl;
        cin.ignore();
        cout << "Nama  : ";
        getline(cin, mhs[i].nama);
        cout << "NIM   : ";
        cin >> mhs[i].nim;
        cout << "UTS   : ";
        cin >> mhs[i].uts;
        cout << "UAS   : ";
        cin >> mhs[i].uas;
        cout << "Tugas : ";
        cin >> mhs[i].tugas;

        mhs[i].nilaiAkhir = hitungNilaiAkhir(mhs[i].uts, mhs[i].uas, mhs[i].tugas);
    }

    cout << "\n=== Daftar Nilai Mahasiswa ===\n";
    for (int i = 0; i < n; i++) {
        cout << "\nNama        : " << mhs[i].nama;
        cout << "\nNIM         : " << mhs[i].nim;
        cout << "\nNilai Akhir : " << mhs[i].nilaiAkhir << endl;
    }

    return 0;
}
```
#### Output:
<img width="579" height="626" alt="image" src="https://github.com/user-attachments/assets/65d1dab9-3978-4af9-a65f-a3cfca0445aa" />

Kode tersebut berfungsi untuk menyimpan dan menampilkan data hingga maksimal 10 mahasiswa. Program ini memanfaatkan struct Mahasiswa sebagai wadah penyimpanan data, seperti nama, NIM, nilai UTS, UAS, dan tugas.

### 2. [Soal]
**pelajaran.h**
```C++
#ifndef PELAJARAN_H
#define PELAJARAN_H

#include <string>
using namespace std;

struct Pelajaran {
    string namaMapel;
    string kodeMapel;
};

Pelajaran createPelajaran(string nama, string kode);

void tampilPelajaran(Pelajaran p);

#endif
```
**pejalaran.cpp**
```C++
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
```
**main.cpp**
```C++
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
```
#### Output:
<img width="492" height="116" alt="image" src="https://github.com/user-attachments/assets/c2011a8b-14ee-44c0-8229-b06f1839ca0a" />

Kode tersebut digunakan untuk membuat dan menampilkan data mata pelajaran. Data berupa nama dan kode mata pelajaran disimpan dalam struktur Pelajaran, kemudian ditampilkan ke layar melalui fungsi tampilPelajaran().

### 3. [Soal]

```C++
#include <iostream>
using namespace std;

int main() {
    int A[3][3] = {{1,2,3},{4,5,6},{7,8,9}};
    int B[3][3] = {{9,8,7},{6,5,4},{3,2,1}};

    cout << "Array A sebelum ditukar:" << endl;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cout << A[i][j] << " ";
        }
        cout << endl;
    }

    cout << "\nArray B sebelum ditukar:" << endl;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cout << B[i][j] << " ";
        }
        cout << endl;
    }

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            int temp = A[i][j];
            A[i][j] = B[i][j];
            B[i][j] = temp;
        }
    }

    cout << "\nSetelah menukar seluruh isi array:" << endl;

    cout << "Array A:" << endl;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cout << A[i][j] << " ";
        }
        cout << endl;
    }

    cout << "\nArray B:" << endl;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cout << B[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
```
#### Output:
<img width="450" height="519" alt="image" src="https://github.com/user-attachments/assets/8c4a232a-f7bb-4d93-91e5-fccd1baae2cf" />


Kode tersebut digunakan untuk menampilkan dua array dua dimensi, yaitu A dan B, lalu menukar seluruh isi kedua array tersebut. Setelah proses pertukaran selesai, program menampilkan kembali masing-masing array untuk menunjukkan perubahan nilai yang terjadi.

#### Full code Screenshot:
**Soal 1 :**
<img width="758" height="987" alt="image" src="https://github.com/user-attachments/assets/11859516-e129-4f9a-9633-278d5bd649fb" />
**Soal 2 :**
<img width="556" height="491" alt="image" src="https://github.com/user-attachments/assets/552e8264-845b-4006-97a6-f647636f9cc3" />
<img width="550" height="447" alt="image" src="https://github.com/user-attachments/assets/c927e226-f9f9-450e-9664-df9f92a2b081" />
<img width="475" height="401" alt="image" src="https://github.com/user-attachments/assets/400fbbbf-6cb2-433c-b589-df8370008ba8" />
**Soal 3 :**
<img width="468" height="897" alt="image" src="https://github.com/user-attachments/assets/fd73f50d-810d-483e-a748-18eb13f44d80" />

## Kesimpulan
Praktikum ini menunjukkan bahwa bahasa C++ dapat digunakan untuk mengelola data secara terstruktur dengan memanfaatkan variabel, fungsi, struct, array, dan pointer. Selain itu, pembagian program ke dalam beberapa bagian membuat kode lebih rapi, terorganisir, dan mudah dipahami.

## Referensi
[1] Rachman, D. A. Perkenalan Abstrak Data Type.
[2] Teman sekelas
[3] AI
