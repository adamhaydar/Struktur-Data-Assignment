#include <iostream>
#include <queue>
using namespace std;

const int MAX_KOST = 5;

// ================= STRUCT =================
struct Pemilik {
    string namaPemilik;        // key BST (unik)
    string kontak;
    int jumlahKost;
    string namaKost[MAX_KOST]; // ARRAY (syarat BST)
    int hargaKost[MAX_KOST];
};

struct Node {
    Pemilik data;
    Node *left;
    Node *right;
};

// ================= CREATE NODE =================
Node* createNode(Pemilik p) {
    Node* newNode = new Node;
    newNode->data = p;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// ================= INSERT BST =================
Node* insertBST(Node* root, Pemilik p) {
    if (root == NULL)
        return createNode(p);

    if (p.namaPemilik < root->data.namaPemilik)
        root->left = insertBST(root->left, p);
    else if (p.namaPemilik > root->data.namaPemilik)
        root->right = insertBST(root->right, p);

    return root;
}

// ================= SEARCH =================
Node* searchBST(Node* root, string nama) {
    if (root == NULL || root->data.namaPemilik == nama)
        return root;

    if (nama < root->data.namaPemilik)
        return searchBST(root->left, nama);
    else
        return searchBST(root->right, nama);
}

// ================= DISPLAY =================
void tampilPemilik(Pemilik p) {
    cout << "\nNama Pemilik : " << p.namaPemilik << endl;
    cout << "Kontak       : " << p.kontak << endl;
    cout << "Daftar Kost  :\n";
    for (int i = 0; i < p.jumlahKost; i++) {
        cout << "  - " << p.namaKost[i]
             << " | Harga: " << p.hargaKost[i] << endl;
    }
}

// ================= TRAVERSAL =================
void inorder(Node* root) {
    if (root != NULL) {
        inorder(root->left);
        tampilPemilik(root->data);
        inorder(root->right);
    }
}

void preorder(Node* root) {
    if (root != NULL) {
        tampilPemilik(root->data);
        preorder(root->left);
        preorder(root->right);
    }
}

void postorder(Node* root) {
    if (root != NULL) {
        postorder(root->left);
        postorder(root->right);
        tampilPemilik(root->data);
    }
}

void levelOrder(Node* root) {
    if (root == NULL) return;
    queue<Node*> q;
    q.push(root);

    while (!q.empty()) {
        Node* curr = q.front();
        q.pop();
        tampilPemilik(curr->data);

        if (curr->left) q.push(curr->left);
        if (curr->right) q.push(curr->right);
    }
}

// ================= COUNT =================
int countPemilik(Node* root) {
    if (root == NULL) return 0;
    return 1 + countPemilik(root->left) + countPemilik(root->right);
}

// ================= MIN & MAX =================
Node* findMin(Node* root) {
    while (root->left != NULL)
        root = root->left;
    return root;
}

Node* findMax(Node* root) {
    while (root->right != NULL)
        root = root->right;
    return root;
}

// ================= DELETE BST =================
Node* deleteBST(Node* root, string nama) {
    if (root == NULL) return root;

    if (nama < root->data.namaPemilik)
        root->left = deleteBST(root->left, nama);
    else if (nama > root->data.namaPemilik)
        root->right = deleteBST(root->right, nama);
    else {
        if (root->left == NULL && root->right == NULL) {
            delete root;
            return NULL;
        }
        else if (root->left == NULL) {
            Node* temp = root->right;
            delete root;
            return temp;
        }
        else if (root->right == NULL) {
            Node* temp = root->left;
            delete root;
            return temp;
        }
        else {
            Node* temp = findMin(root->right);
            root->data = temp->data;
            root->right = deleteBST(root->right, temp->data.namaPemilik);
        }
    }
    return root;
}

// ================= DELETE KOST =================
void hapusKost(Node* root, string pemilik, string kost) {
    Node* p = searchBST(root, pemilik);
    if (p == NULL) {
        cout << "Pemilik tidak ditemukan.\n";
        return;
    }

    int idx = -1;
    for (int i = 0; i < p->data.jumlahKost; i++) {
        if (p->data.namaKost[i] == kost) {
            idx = i;
            break;
        }
    }

    if (idx == -1) {
        cout << "Kost tidak ditemukan.\n";
        return;
    }

    for (int i = idx; i < p->data.jumlahKost - 1; i++) {
        p->data.namaKost[i] = p->data.namaKost[i + 1];
        p->data.hargaKost[i] = p->data.hargaKost[i + 1];
    }

    p->data.jumlahKost--;
    cout << "Kost berhasil dihapus.\n";
}

// ================= DELETE HARGA =================
void hapusHarga(Node* root, string pemilik, string kost) {
    Node* p = searchBST(root, pemilik);
    if (p == NULL) {
        cout << "Pemilik tidak ditemukan.\n";
        return;
    }

    for (int i = 0; i < p->data.jumlahKost; i++) {
        if (p->data.namaKost[i] == kost) {
            p->data.hargaKost[i] = 0;
            cout << "Harga kost dihapus.\n";
            return;
        }
    }
    cout << "Kost tidak ditemukan.\n";
}

// ================= MAIN =================
int main() {
    Node* root = NULL;
    int pilih;

    do {
        cout << "\n=== MENU MANAJEMEN KOST ===\n";
        cout << "1. Tambah Pemilik\n";
        cout << "2. Cari Pemilik\n";
        cout << "3. Inorder\n";
        cout << "4. Preorder\n";
        cout << "5. Postorder\n";
        cout << "6. Level Order\n";
        cout << "7. Hitung Pemilik\n";
        cout << "8. Min & Max Nama Pemilik\n";
        cout << "9. Hapus Pemilik\n";
        cout << "10. Hapus Kost\n";
        cout << "11. Hapus Harga Kost\n";
        cout << "0. Keluar\n";
        cout << "Pilih: ";
        cin >> pilih;
        cin.ignore();

        if (pilih == 1) {
            Pemilik p;
            cout << "Nama Pemilik: ";
            getline(cin, p.namaPemilik);

            if (searchBST(root, p.namaPemilik) != NULL) {
                cout << "Pemilik sudah ada.\n";
                continue;
            }

            cout << "Kontak: ";
            getline(cin, p.kontak);

            cout << "Jumlah Kost (max " << MAX_KOST << "): ";
            cin >> p.jumlahKost;
            cin.ignore();

            for (int i = 0; i < p.jumlahKost; i++) {
                cout << "Nama Kost ke-" << i + 1 << ": ";
                getline(cin, p.namaKost[i]);
                cout << "Harga: ";
                cin >> p.hargaKost[i];
                cin.ignore();
            }

            root = insertBST(root, p);
            cout << "Pemilik berhasil ditambahkan.\n";
        }

        else if (pilih == 2) {
            string nama;
            cout << "Cari Nama Pemilik: ";
            getline(cin, nama);
            Node* hasil = searchBST(root, nama);
            if (hasil) tampilPemilik(hasil->data);
            else cout << "Data tidak ditemukan.\n";
        }

        else if (pilih == 3) inorder(root);
        else if (pilih == 4) preorder(root);
        else if (pilih == 5) postorder(root);
        else if (pilih == 6) levelOrder(root);
        else if (pilih == 7)
            cout << "Total Pemilik: " << countPemilik(root) << endl;

        else if (pilih == 8) {
            if (root) {
                tampilPemilik(findMin(root)->data);
                tampilPemilik(findMax(root)->data);
            }
        }

        else if (pilih == 9) {
            string nama;
            cout << "Nama Pemilik yang dihapus: ";
            getline(cin, nama);
            root = deleteBST(root, nama);
        }

        else if (pilih == 10) {
            string p, k;
            cout << "Nama Pemilik: ";
            getline(cin, p);
            cout << "Nama Kost: ";
            getline(cin, k);
            hapusKost(root, p, k);
        }

        else if (pilih == 11) {
            string p, k;
            cout << "Nama Pemilik: ";
            getline(cin, p);
            cout << "Nama Kost: ";
            getline(cin, k);
            hapusHarga(root, p, k);
        }

    } while (pilih != 0);

    return 0;
}
