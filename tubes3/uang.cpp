#include "uang.h"

// CREATE BST
void createBST(NodeBST* &root) { root = NULL; }

// CREATE NODE
NodeBST* createNode(string nama, string jenis) {
    NodeBST *P = new NodeBST;
    P->namaKategori = nama;
    P->jenis = jenis;
    P->firstTrx = NULL;
    P->left = NULL;
    P->right = NULL;
    return P;
}

// KEY UNIK
string getKey(NodeBST *node) { return node->namaKategori + "_" + node->jenis; }
string getKey(string nama, string jenis) { return nama + "_" + jenis; }

// INSERT BST

void insertBST(NodeBST* &root, string nama, string jenis) {
    string key = getKey(nama, jenis);
    if (root == NULL) { root = createNode(nama, jenis); return; }

    string rootKey = getKey(root);
    if (key < rootKey) insertBST(root->left, nama, jenis);
    else if (key > rootKey) insertBST(root->right, nama, jenis);
}

// SEARCH BST
NodeBST* searchBST(NodeBST *root, string nama, string jenis) {
    if (!root) return NULL;
    string key = getKey(nama, jenis);
    string rootKey = getKey(root);
    if (key == rootKey) return root;
    else if (key < rootKey) return searchBST(root->left, nama, jenis);
    else return searchBST(root->right, nama, jenis);
}

// DELETE NODE BST
NodeBST* findMin(NodeBST *root) { while (root->left) root=root->left; return root; }

NodeBST* deleteBST(NodeBST *root, string nama, string jenis) {
    if (!root) return NULL;
    string key = getKey(nama, jenis);
    string rootKey = getKey(root);

    if (key < rootKey) root->left = deleteBST(root->left, nama, jenis);
    else if (key > rootKey) root->right = deleteBST(root->right, nama, jenis);
    else {
        // delete transaksi
        Transaksi *T = root->firstTrx;
        while(T){ Transaksi *temp=T; T=T->next; delete temp; }
        // delete node
        if(!root->left){ NodeBST *temp=root->right; delete root; return temp; }
        else if(!root->right){ NodeBST *temp=root->left; delete root; return temp; } 
        else{
            NodeBST *temp=findMin(root->right);
            root->namaKategori=temp->namaKategori;
            root->jenis=temp->jenis;
            root->firstTrx=temp->firstTrx;
            root->right=deleteBST(root->right,temp->namaKategori,temp->jenis); 
        }
    }
    return root;
}

// TAMBAH / HAPUS TRANSAKSI 
bool tambahTransaksi(NodeBST *kategori, int nominal){
    if(!kategori) return false;
    Transaksi *T=kategori->firstTrx;
    while(T){ if(T->nominal==nominal) return false; T=T->next; }
    Transaksi *newT=new Transaksi{nominal,kategori->firstTrx};
    kategori->firstTrx=newT; return true;
}

bool hapusTransaksi(NodeBST *kategori,int nominal){
    if(!kategori) return false;
    Transaksi *curr=kategori->firstTrx,*prev=NULL;
    while(curr){
        if(curr->nominal==nominal){
            if(!prev) kategori->firstTrx=curr->next;
            else prev->next=curr->next;
            delete curr; return true;
        }
        prev=curr; curr=curr->next;
    }
    return false;
}

// EDIT
bool editKategori(NodeBST* &root, string nama, string jenis, string newNama, string newJenis){
    NodeBST* k = searchBST(root,nama,jenis);
    if(!k) return false;
    Transaksi* tempTrx = k->firstTrx;
    root = deleteBST(root,nama,jenis);
    insertBST(root,newNama,newJenis);
    NodeBST* newNode=searchBST(root,newNama,newJenis);
    newNode->firstTrx=tempTrx;
    return true;
}

bool editTransaksi(NodeBST *kategori,int oldNom,int newNom){
    if(!kategori) return false;
    Transaksi *T=kategori->firstTrx;
    while(T){
        if(T->nominal==oldNom){ T->nominal=newNom; return true; }
        T=T->next;
    }
    return false;
}

// TOTAL / MIN / MAX / AVG
int totalTransaksi(NodeBST *kategori){
    int total=0; Transaksi*T=kategori->firstTrx;
    while(T){ total+=T->nominal; T=T->next; } return total;
}
int minTransaksi(NodeBST *kategori){
    if(!kategori->firstTrx) return 0;
    int minVal=kategori->firstTrx->nominal;
    Transaksi*T=kategori->firstTrx->next;
    while(T){ if(T->nominal<minVal) minVal=T->nominal; T=T->next; } return minVal;
}
int maxTransaksi(NodeBST *kategori){
    if(!kategori->firstTrx) return 0;
    int maxVal=kategori->firstTrx->nominal;
    Transaksi*T=kategori->firstTrx->next;
    while(T){ if(T->nominal>maxVal) maxVal=T->nominal; T=T->next; } return maxVal;
}
double avgTransaksi(NodeBST *kategori){
    if(!kategori->firstTrx) return 0;
    int total=0,count=0; Transaksi*T=kategori->firstTrx;
    while(T){ total+=T->nominal; count++; T=T->next; } return (double)total/count;
}

// SALDO & COUNT

int hitungSaldo(NodeBST *root){
    if(!root) return 0;
    int total=totalTransaksi(root);
    if(root->jenis=="Expense") total=-total;
    return total+hitungSaldo(root->left)+hitungSaldo(root->right);
}

int countKategori(NodeBST *root){ if(!root) return 0; return 1+countKategori(root->left)+countKategori(root->right); }

// TRAVERSAL KATEGORI
void inorderKategori(NodeBST *root){
    if(root){
        inorderKategori(root->left);
        cout<<"Kategori : "<<root->namaKategori<<" | Jenis : "<<root->jenis
            <<" | Total : "<<totalTransaksi(root)<<endl;
        inorderKategori(root->right);
    }
}
void preorderKategori(NodeBST *root){
    if(root){
        cout<<"Kategori : "<<root->namaKategori<<" | Jenis : "<<root->jenis
            <<" | Total : "<<totalTransaksi(root)<<endl;
        preorderKategori(root->left);
        preorderKategori(root->right);
    }
}
void postorderKategori(NodeBST *root){
    if(root){
        postorderKategori(root->left);
        postorderKategori(root->right);
        cout<<"Kategori : "<<root->namaKategori<<" | Jenis : "<<root->jenis
            <<" | Total : "<<totalTransaksi(root)<<endl;
    }
}

// TRAVERSAL TRANSAKSI 
void inorderTransaksi(NodeBST *root){
    if(root){
        inorderTransaksi(root->left);
        cout<<"Kategori : "<<root->namaKategori<<" | Jenis : "<<root->jenis
            <<" | Total : "<<totalTransaksi(root)<<endl;
        Transaksi* T=root->firstTrx;
        if(T){ cout<<"Transaksi: "; while(T){ cout<<T->nominal<<" "; T=T->next; } cout<<endl; }
        inorderTransaksi(root->right);
    }
}
void preorderTransaksi(NodeBST *root){
    if(root){
        cout<<"Kategori : "<<root->namaKategori<<" | Jenis : "<<root->jenis
            <<" | Total : "<<totalTransaksi(root)<<endl;
        Transaksi* T=root->firstTrx;
        if(T){ cout<<"Transaksi: "; while(T){ cout<<T->nominal<<" "; T=T->next; } cout<<endl; }
        preorderTransaksi(root->left);
        preorderTransaksi(root->right);
    }
}
void postorderTransaksi(NodeBST *root){
    if(root){
        postorderTransaksi(root->left);
        postorderTransaksi(root->right);
        cout<<"Kategori : "<<root->namaKategori<<" | Jenis : "<<root->jenis
            <<" | Total : "<<totalTransaksi(root)<<endl;
        Transaksi* T=root->firstTrx;
        if(T){ cout<<"Transaksi: "; while(T){ cout<<T->nominal<<" "; T=T->next; } cout<<endl; }
    }
}

