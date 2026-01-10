#include "uang.h"

// MENU FUNCTIONS

void menuUtama(){  //Menampilkan menu utama program yang berisi pilihan untuk mengelola data keuangan seperti 
                    //tambah, hapus, edit, tampilkan, analisis, pencarian kategori, dan keluar program.
    cout<<"\n=== MENU MANAJEMEN KEUANGAN ===\n";
    cout<<"1. Tambah Data\n";
    cout<<"2. Hapus Data\n";
    cout<<"3. Edit Data\n";
    cout<<"4. Tampilkan Data\n";
    cout<<"5. Analisis Data\n";
    cout<<"6. Cari Kategori\n";
    cout<<"0. Keluar\n";
    cout<<"Pilih: ";
}

void menuTambah(){  //Menampilkan menu untuk menambahkan data, yaitu menambah kategori baru atau menambah transaksi pada kategori tertentu.
    cout<<"\n--- TAMBAH DATA ---\n";
    cout<<"1. Tambah Kategori\n"; 
    cout<<"2. Tambah Transaksi\n"; 
    cout<<"0. Kembali\n";
    cout<<"Pilih: ";
}

void menuHapus(){  //Menampilkan menu untuk menghapus data, baik menghapus kategori beserta
                    // transaksinya maupun menghapus transaksi tertentu pada suatu kategori.
    cout<<"\n--- HAPUS DATA ---\n";
    cout<<"1. Hapus Kategori\n";
    cout<<"2. Hapus Transaksi\n";
    cout<<"0. Kembali\n";
    cout<<"Pilih: ";
}

void menuEdit(){  //Menampilkan menu untuk mengubah data yang sudah ada, yaitu mengedit nama/jenis kategori atau mengedit nominal transaksi.
    cout<<"\n--- EDIT DATA ---\n";
    cout<<"1. Edit Kategori\n";
    cout<<"2. Edit Transaksi\n";
    cout<<"0. Kembali\n";
    cout<<"Pilih: ";
}

void menuTampil(){  //Menampilkan menu untuk menampilkan data kategori atau transaksi menggunakan metode traversal pada struktur BST.
    cout<<"\n--- TAMPILKAN DATA ---\n";
    cout<<"1. Tampilkan Kategori (Traversal)\n";
    cout<<"2. Tampilkan Transaksi (Traversal)\n";
    cout<<"0. Kembali\n";
    cout<<"Pilih: ";
}

void menuAnalisis(){  //Menampilkan menu untuk melakukan analisis data keuangan seperti menghitung saldo total, 
                        //mencari nilai minimum, maksimum, dan rata-rata transaksi, serta menghitung jumlah kategori berdasarkan jenis.
    cout<<"\n--- ANALISIS DATA ---\n";
    cout<<"1. Hitung Saldo Total\n";
    cout<<"2. Min / Max / Avg Transaksi per Kategori\n";
    cout<<"3. Count Kategori / Per Jenis\n";
    cout<<"0. Kembali\n";
    cout<<"Pilih: ";
}

void menuTraversal(){  //Menampilkan pilihan metode traversal BST yang digunakan untuk 
                        //menampilkan data, yaitu inorder, preorder, dan postorder.
    cout<<"\n--- PILIH TRAVERSAL ---\n";
    cout<<"1. Inorder\n";
    cout<<"2. Preorder\n";
    cout<<"3. Postorder\n";
    cout<<"0. Kembali\n";
    cout<<"Pilih: ";
}

// MAIN PROGRAM
int main(){
    NodeBST *root;  //Inisialisasi BST Digunakan untuk membuat BST kosong sebagai tempat menyimpan kategori keuangan.
    createBST(root);

        // DATA DUMMY 
    insertBST(root, "Makan", "Expense");  //Bagian ini digunakan untuk mengisi data awal secara otomatis 
                                         //agar program bisa langsung diuji tanpa input manual.
    insertBST(root, "Transport", "Expense");
    insertBST(root, "Hiburan", "Expense");
    insertBST(root, "Bonus", "Income");

    tambahTransaksi(searchBST(root,"Makan","Expense"), 20000);
    tambahTransaksi(searchBST(root,"Makan","Expense"), 15000);
    tambahTransaksi(searchBST(root,"Makan","Expense"), 10000);

    tambahTransaksi(searchBST(root,"Transport","Expense"), 5000);
    tambahTransaksi(searchBST(root,"Transport","Expense"), 7000);

    tambahTransaksi(searchBST(root,"Hiburan","Expense"), 30000);
    tambahTransaksi(searchBST(root,"Hiburan","Expense"), 25000);

    tambahTransaksi(searchBST(root,"Bonus","Income"), 500000);


    int pilih;
    do{
        menuUtama();
        cin >> pilih;
        cin.ignore();

        // TAMBAH 
        if(pilih == 1){
            int p;
            do{
                menuTambah();
                cin >> p; cin.ignore();

                if(p == 1){
                    string nama, jenis;
                    cout<<"Nama Kategori: "; getline(cin,nama);
                    cout<<"Jenis (Income/Expense): "; getline(cin,jenis);
                    insertBST(root,nama,jenis);
                }
                else if(p == 2){
                    string nama, jenis;
                    int nominal;
                    cout<<"Nama Kategori: "; getline(cin,nama);
                    cout<<"Jenis Kategori: "; getline(cin,jenis);
                    NodeBST* k = searchBST(root,nama,jenis);
                    if(k){
                        cout<<"Nominal Transaksi: "; cin>>nominal; cin.ignore();
                        tambahTransaksi(k,nominal);
                    }
                    else cout<<"Kategori tidak ditemukan.\n";
                }
            }while(p != 0);
        }

        // HAPUS
        else if(pilih == 2){
            int p;
            do{
                menuHapus();
                cin >> p; cin.ignore();

                if(p == 1){
                    string nama, jenis;
                    cout<<"Nama Kategori: "; getline(cin,nama);
                    cout<<"Jenis Kategori: "; getline(cin,jenis);
                    root = deleteBST(root,nama,jenis);
                }
                else if(p == 2){
                    string nama, jenis;
                    int nominal;
                    cout<<"Nama Kategori: "; getline(cin,nama);
                    cout<<"Jenis Kategori: "; getline(cin,jenis);
                    NodeBST* k = searchBST(root,nama,jenis);
                    if(k){
                        cout<<"Nominal Transaksi: "; cin>>nominal; cin.ignore();
                        hapusTransaksi(k,nominal);
                    }
                    else cout<<"Kategori tidak ditemukan.\n";
                }
            }while(p != 0);
        }

        // EDIT
        else if(pilih == 3){
            int p;
            do{
                menuEdit();
                cin >> p; cin.ignore();

                if(p == 1){
                    string nama, jenis, newNama, newJenis;
                    cout<<"Nama Lama: "; getline(cin,nama);
                    cout<<"Jenis Lama: "; getline(cin,jenis);
                    cout<<"Nama Baru: "; getline(cin,newNama);
                    cout<<"Jenis Baru: "; getline(cin,newJenis);
                    editKategori(root,nama,jenis,newNama,newJenis);
                }
                else if(p == 2){
                    string nama, jenis;
                    int oldNom, newNom;
                    cout<<"Nama Kategori: "; getline(cin,nama);
                    cout<<"Jenis Kategori: "; getline(cin,jenis);
                    NodeBST* k = searchBST(root,nama,jenis);
                    if(k){
                        cout<<"Nominal Lama: "; cin>>oldNom;
                        cout<<"Nominal Baru: "; cin>>newNom; cin.ignore();
                        editTransaksi(k,oldNom,newNom);
                    }
                    else cout<<"Kategori tidak ditemukan.\n";
                }
            }while(p != 0);
        }

      // TAMPILKAN
else if(pilih == 4){
    int p;
    do{
        menuTampil();
        cin >> p; cin.ignore();

        if(p == 1){ // Kategori
            int t;
            do{
                menuTraversal();
                cin >> t; cin.ignore();

                if(t == 1) inorderKategori(root);
                else if(t == 2) preorderKategori(root);
                else if(t == 3) postorderKategori(root);
            }while(t != 0);
        }
        else if(p == 2){ // Transaksi
            int t;
            do{
                menuTraversal();
                cin >> t; cin.ignore();

                if(t == 1) inorderTransaksi(root);
                else if(t == 2) preorderTransaksi(root);
                else if(t == 3) postorderTransaksi(root);
            }while(t != 0);
        }
    }while(p != 0);
}


        // ANALISIS
        else if(pilih == 5){
            int p;
            do{
                menuAnalisis();
                cin >> p; cin.ignore();

                if(p == 1){
                    cout<<"Saldo Total: "<<hitungSaldo(root)<<endl;
                }
                else if(p == 2){
                    string nama, jenis;
                    cout<<"Nama Kategori: "; getline(cin,nama);
                    cout<<"Jenis Kategori: "; getline(cin,jenis);
                    NodeBST* k = searchBST(root,nama,jenis);
                    if(k)
                        cout<<"Min: "<<minTransaksi(k)
                            <<" | Max: "<<maxTransaksi(k)
                            <<" | Avg: "<<avgTransaksi(k)<<endl;
                    else cout<<"Kategori tidak ditemukan.\n";
                }
                else if(p == 3){
                    int income=0, expense=0;
                    NodeBST *stack[100];
                    int top=-1;
                    NodeBST* curr=root;
                    while(curr || top!=-1){
                        while(curr){ stack[++top]=curr; curr=curr->left; }
                        curr=stack[top--];
                        if(curr->jenis=="Income") income++;
                        else if(curr->jenis=="Expense") expense++;
                        curr=curr->right;
                    }
                    cout<<"Income: "<<income<<" | Expense: "<<expense<<endl;
                }
            }while(p != 0);
        }

        // CARI
       else if(pilih == 6){
    string nama, jenis;
    cout<<"Nama Kategori: "; getline(cin,nama);
    cout<<"Jenis Kategori: "; getline(cin,jenis);

    NodeBST* k = searchBST(root, nama, jenis);
    if(k){
        cout<<"Kategori ditemukan.\n";
        cout<<"Nama   : "<<k->namaKategori<<endl;
        cout<<"Jenis  : "<<k->jenis<<endl;
        cout<<"Total  : "<<totalTransaksi(k)<<endl;
    }
    else{
        cout<<"Kategori tidak ditemukan.\n";
    }
}

    }while(pilih != 0);

    cout<<"Program selesai.\n";
    return 0;
}
