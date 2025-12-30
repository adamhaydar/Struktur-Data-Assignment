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

Kode tersebut berfungsi untuk menyimpan dan menampilkan data hingga maksimal 10 mahasiswa. Program ini memanfaatkan struct Mahasiswa sebagai wadah penyimpanan data, seperti nama, NIM, nilai UTS, UAS, dan tugas.

### 2. [Soal]

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

Kode tersebut digunakan untuk membuat dan menampilkan data mata pelajaran. Data berupa nama dan kode mata pelajaran disimpan dalam struktur Pelajaran, kemudian ditampilkan ke layar melalui fungsi tampilPelajaran().

### 3. [Soal]

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

Kode tersebut digunakan untuk menampilkan dua array dua dimensi, yaitu A dan B, lalu menukar seluruh isi kedua array tersebut. Setelah proses pertukaran selesai, program menampilkan kembali masing-masing array untuk menunjukkan perubahan nilai yang terjadi.

#### Full code Screenshot:
![240309_10h21m35s_screenshot](https://github.com/suxeno/Struktur-Data-Assignment/assets/111122086/41e9641c-ad4e-4e50-9ca4-a0215e336b04)

## Kesimpulan
Sebagai penutup, praktikum ini menunjukkan bahwa bahasa C++ dapat digunakan untuk mengelola data secara terstruktur dengan memanfaatkan variabel, fungsi, struct, array, dan pointer. Selain itu, pembagian program ke dalam beberapa bagian membuat kode lebih rapi, terorganisir, dan mudah dipahami.

## Referensi
[1] I. Holm, Narrator, and J. Fullerton-Smith, Producer, How to Build a Human [DVD]. London: BBC; 2002.
