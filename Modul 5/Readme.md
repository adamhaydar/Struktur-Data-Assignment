# <h1 align="center">Laporan Praktikum Modul Singly Linked List (Bagian 2)</h1>
<p align="center">Adam Haydar</p>

## Dasar Teori

Searching pada linked list merupakan proses pencarian suatu nilai dengan menelusuri setiap node secara berurutan, dimulai dari node pertama (head) hingga node terakhir atau sampai nilai yang dicari ditemukan. Metode yang umum digunakan adalah linear search atau sequential search, yaitu dengan membandingkan nilai pada setiap node dengan nilai target. Proses pencarian akan berhenti ketika nilai ditemukan atau ketika seluruh node telah diperiksa tanpa hasil. Karena struktur linked list berupa rangkaian node yang saling terhubung, pencarian harus dilakukan dari awal hingga akhir secara berurutan. Kompleksitas waktu untuk operasi searching pada linked list adalah O(N), dengan N menyatakan jumlah node, karena pada kondisi terburuk seluruh node harus dilalui. Keberadaan operasi searching ini mempermudah proses lanjutan seperti insert after, delete after, dan update, karena posisi node yang dituju dapat diketahui terlebih dahulu.

## Guided 

### 1. [Nama Topik]

```C++
#include <iostream>
using namespace std;

int main() {
    cout << "ini adalah file code guided praktikan" << endl;
    return 0;
}
```
Kode di atas digunakan untuk mencetak teks "ini adalah file code guided praktikan" ke layar menggunakan function cout untuk mengeksekusi nya.

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

Kode tersebut merupakan program C++ yang digunakan untuk mengelola data buah dengan menerapkan struktur data Singly Linked List. Pada struktur ini, data disimpan secara dinamis di dalam node-node yang saling terhubung melalui pointer. Setiap node memuat tiga informasi utama, yaitu nama buah (tipe string), jumlah buah (tipe int), dan harga buah (tipe float), serta memiliki pointer next yang menunjuk ke node selanjutnya.

#### Full code Screenshot:
![240309_10h21m35s_screenshot](https://github.com/suxeno/Struktur-Data-Assignment/assets/111122086/41e9641c-ad4e-4e50-9ca4-a0215e336b04)


## Kesimpulan
Pada modul ini, mahasiswa mempelajari konsep dan mekanisme kerja Singly Linked List sebagai struktur data dinamis yang tersusun dari node-node berisi data dan pointer yang saling terhubung. Melalui kegiatan praktikum, mahasiswa memahami berbagai operasi dasar seperti pembuatan list, penambahan, penghapusan, pencarian, serta pembaruan data, sekaligus mempelajari pengelolaan memori menggunakan pointer. Modul ini menegaskan bahwa Singly Linked List merupakan konsep dasar yang penting dalam struktur data dinamis karena memungkinkan pengolahan data secara fleksibel dan efisien.

## Referensi
[1] I. Holm, Narrator, and J. Fullerton-Smith, Producer, How to Build a Human [DVD]. London: BBC; 2002.
