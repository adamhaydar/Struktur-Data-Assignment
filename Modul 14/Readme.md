# <h1 align="center">Graph</h1>
<p align="center">Adam Haydar</p>

## Dasar Teori

Teori graph mempelajari hubungan antar simpul dalam bentuk graf, di mana penelusurannya dapat dilakukan menggunakan algoritma DFS yang menelusuri simpul secara mendalam dan BFS yang menelusuri simpul berdasarkan level.

## Guided 
### 1. [Nama Topik]
**graph.h**
```C++
#ifndef GRAPH_H_INCLUDED
#define GRAPH_H_INCLUDED

#include <iostream>
using namespace std;

typedef char infoGraph;
typedef struct ElmNode *adrNode;
typedef struct ElmEdge *adrEdge;

struct ElmEdge {
    adrNode Node;
    adrEdge Next;
};

struct ElmNode {
    infoGraph info;
    int visited;
    adrEdge firstEdge;
    adrNode Next;
};

struct Graph {
    adrNode first;
};

/* PRIMITIF */
void CreateGraph(Graph &G);
adrNode AllocateNode(infoGraph X);
adrEdge AllocateEdge(adrNode N);

void InsertNode(Graph &G, infoGraph X);
void ConnectNode(adrNode N1, adrNode N2);
adrNode FindNode(Graph G, infoGraph X);

void PrintInfoGraph(Graph G);

#endif
```
**graph.cpp**
```C++
#include "graph.h"
#include <iostream>
#include <queue> //library queue untuk BFS
#include <stack> //library stack untuk DFS

using namespace std;

//prosedur untuk mengeset first dari graph sebagai NULL
void CreateGraph(Graph &G) {
    G.First = NULL;
}

//alokasi Node baru
adrNode AlokasiNode(infoGraph data) {
    adrNode nodeBaru = new ElmNode;
    nodeBaru->info = data;
    nodeBaru->visited = 0; //isinya 0/1
    nodeBaru->firstEdge = NULL;
    nodeBaru->Next = NULL;
    return nodeBaru;
}

//alokasi Edge baru
adrEdge AlokasiEdge(adrNode nodeTujuan) {
    adrEdge edgeBaru = new ElmEdge;
    edgeBaru->Node = nodeTujuan;
    edgeBaru->Next = NULL;
    return edgeBaru;
}

//Menambahkan Node ke dalam Graph
void InsertNode(Graph &G, infoGraph data) {
    adrNode nodeBaru = AlokasiNode(data);
    if (G.First == NULL) {
        G.First = nodeBaru;
    } else {
        //konsepnya insert last
        adrNode nodeBantu = G.First;
        while (nodeBantu->Next != NULL) {
            nodeBantu = nodeBantu->Next;
        }
        nodeBantu->Next = nodeBaru;
    }
}

//function untuk mencari alamat Node berdasarkan infonya
adrNode FindNode(Graph G, infoGraph data) {
    adrNode nodeBantu = G.First;
    while (nodeBantu != NULL) {
        if (nodeBantu->info == data) {
            return nodeBantu;
        }
        nodeBantu = nodeBantu->Next;
    }
    return NULL;
}

//prosedur untuk menghubungkan dua Node (Undirected Graph)
void ConnectNode(Graph &G, infoGraph info1, infoGraph info2) {
    adrNode node1 = FindNode(G, info1);
    adrNode node2 = FindNode(G, info2);

    if (node1 != NULL && node2 != NULL) {
        //Hubungkan node1 ke node2
        adrEdge Edge1 = AlokasiEdge(node2);
        Edge1->Next = node1->firstEdge; // Insert First pada list edge
        node1->firstEdge = Edge1;

        //Hubungkan node2 ke node1 (Karena Undirected/Bolak-balik)
        adrEdge Edge2 = AlokasiEdge(node1);
        Edge2->Next = node2->firstEdge;
        node2->firstEdge = Edge2;
    } else {
        cout << "Node tidak ditemukan!" << endl;
    }
}

//prosedur untuk memutuskan hubungan dua node
void DisconnectNode(adrNode node1, adrNode node2) {
    if (node1 != NULL && node2 != NULL) {
        adrEdge edgeBantu = node1->firstEdge;
        adrEdge PrevE = NULL;

        //Cari edge yang mengarah ke node2 di dalam list milik node1
        while (edgeBantu != NULL && edgeBantu->Node != node2) {
            PrevE = edgeBantu;
            edgeBantu = edgeBantu->Next;
        }

        if (edgeBantu != NULL) { //jika Edge ditemukan
            if (PrevE == NULL) {
                //Hapus edge pertama
                node1->firstEdge = edgeBantu->Next;
            } else {
                //Hapus edge di tengah/akhir
                PrevE->Next = edgeBantu->Next;
            }
            delete edgeBantu;
        }
    }
}

//prosedur untuk menghapus Node X beserta semua edge yang berhubungan dengannya
void DeleteNode(Graph &G, infoGraph X) {
    //1. Cari Node yang akan dihapus (nodeHapus)
    adrNode nodeHapus = FindNode(G, X);
    if (nodeHapus == NULL) {
        cout << "Node tidak ditemukan." << endl;
        return;
    }

    //2. Hapus semua Edge yang MENGARAH ke nodeHapus (Incoming Edges)
    //cek setiap node di graph, apakah punya edge ke nodeHapus
    adrNode nodeLainnya = G.First;
    while (nodeLainnya != NULL) {
        DisconnectNode(nodeLainnya, nodeHapus); //putus hubungan nodeLainnya ke nodeHapus
        nodeLainnya = nodeLainnya->Next;
    }

    //3. Hapus semua Edge yang KELUAR dari nodeHapus (Outgoing Edges)
    //Deallokasi list edge milik nodeHapus
    adrEdge edgeBantu = nodeHapus->firstEdge;
    while (edgeBantu != NULL) {
        adrEdge tempE = edgeBantu;
        edgeBantu = edgeBantu->Next;
        delete tempE;
    }
    nodeHapus->firstEdge = NULL;

    //4. Hapus nodeHapus dari List Utama Graph
    if (G.First == nodeHapus) {
        //jika nodeHapus di awal
        G.First = nodeHapus->Next;
    } else {
        //jika nodeHapus di tengah/akhir
        adrNode nodeBantu = G.First;
        while (nodeBantu->Next != nodeHapus) {
            nodeBantu = nodeBantu->Next;
        }
        nodeBantu->Next = nodeHapus->Next;
    }

    //5. delete nodeHapus
    delete nodeHapus;
}

//Menampilkan isi Graph (Adjacency List) 
void PrintInfoGraph(Graph G) {
    adrNode nodeBantu = G.First;
    while (nodeBantu != NULL) {
        cout << "Node " << nodeBantu->info << " terhubung ke: ";
        adrEdge edgeBantu = nodeBantu->firstEdge;
        while (edgeBantu != NULL) {
            cout << edgeBantu->Node->info << " "; //Akses info dari node tujuan
            edgeBantu = edgeBantu->Next;
        }
        cout << endl;
        nodeBantu = nodeBantu->Next;
    }
}

//Reset status visited sebelum traversal
void ResetVisited(Graph &G) {
    adrNode nodeReset = G.First;
    while (nodeReset != NULL) {
        nodeReset->visited = 0;
        nodeReset = nodeReset->Next;
    }
}

//traversal Breadth First Search / BFS (Menggunakan Queue)
void PrintBFS(Graph G, infoGraph StartInfo) {
    ResetVisited(G);
    adrNode StartNode = FindNode(G, StartInfo);
    
    if (StartNode == NULL) return;

    queue<adrNode> Qyu;
    
    //Enqueue start
    Qyu.push(StartNode);
    StartNode->visited = 1;

    cout << "BFS Traversal: ";
    while (!Qyu.empty()) {
        adrNode nodeBantu = Qyu.front();
        Qyu.pop();
        cout << nodeBantu->info << " - ";

        //Cek semua tetangga atau edge nya
        adrEdge edgeBantu = nodeBantu->firstEdge;
        while (edgeBantu != NULL) {
            if (edgeBantu->Node->visited == 0) {
                edgeBantu->Node->visited = 1;
                Qyu.push(edgeBantu->Node);
            }
            edgeBantu = edgeBantu->Next;
        }
    }
    cout << endl;
}

//Traversal Depth First Search / DFS (Menggunakan Stack)
void PrintDFS(Graph G, infoGraph StartInfo) {
    ResetVisited(G);
    adrNode StartNode = FindNode(G, StartInfo);
    
    if (StartNode == NULL) return;

    stack<adrNode> Stak;
    
    Stak.push(StartNode);

    cout << "DFS Traversal: ";
    while (!Stak.empty()) {
        adrNode nodeBantu = Stak.top();
        Stak.pop();

        if (nodeBantu->visited == 0) {
            nodeBantu->visited = 1;
            cout << nodeBantu->info << " - ";

            //masukkan tetangga ke stack
            adrEdge edgeBantu = nodeBantu->firstEdge;
            while (edgeBantu != NULL) {
                if (edgeBantu->Node->visited == 0) {
                    Stak.push(edgeBantu->Node);
                }
                edgeBantu = edgeBantu->Next;
            }
        }
    }
    cout << endl;
}
```
Program ini digunakan untuk membuat dan mengelola struktur data graph. Di dalamnya kita bisa menambah node, menghubungkan node satu dengan yang lain, menghapus node beserta hubungannya, dan menampilkan isi graph. Selain itu, program ini juga bisa menelusuri graph dengan dua cara, yaitu BFS (menelusuri dari dekat dulu pakai queue) dan DFS (menelusuri sampai dalam pakai stack). Jadi, secara keseluruhan kode ini menunjukkan cara kerja graph beserta proses pencarian jalurnya dengan jelas dan terstruktur.

## Unguided 

### 1. [Soal]
**graph.h**
```C++
#ifndef GRAPH_H
#define GRAPH_H

#include <iostream>
using namespace std;

typedef char infoGraph;
typedef struct ElmNode *adrNode;
typedef struct ElmEdge *adrEdge;

struct ElmEdge {
    adrNode node;
    adrEdge next;
};

struct ElmNode {
    infoGraph info;
    int visited;
    adrEdge firstEdge;
    adrNode next;
};

struct Graph {
    adrNode first;
};

void CreateGraph(Graph &G);
void InsertNode(Graph &G, infoGraph X);
void ConnectNode(adrNode N1, adrNode N2);
adrNode FindNode(Graph G, infoGraph X);
void PrintInfoGraph(Graph G);
void PrintDFS(Graph G, adrNode N);
void PrintBFS(Graph G, adrNode N);

#endif
```
**graph.cpp**
```C++
#include "graph.h"

void CreateGraph(Graph &G) {
    G.first = NULL;
}

adrNode FindNode(Graph G, infoGraph X) {
    adrNode P = G.first;
    while (P != NULL) {
        if (P->info == X) return P;
        P = P->next;
    }
    return NULL;
}

void InsertNode(Graph &G, infoGraph X) {
    adrNode N = new ElmNode{X,0,NULL,NULL};
    if (G.first == NULL) G.first = N;
    else {
        adrNode P = G.first;
        while (P->next != NULL) P = P->next;
        P->next = N;
    }
}

void ConnectNode(adrNode N1, adrNode N2) {
    adrEdge E1 = new ElmEdge{N2, NULL};
    if (N1->firstEdge == NULL)
        N1->firstEdge = E1;
    else {
        adrEdge P = N1->firstEdge;
        while (P->next != NULL) P = P->next;
        P->next = E1;
    }

    adrEdge E2 = new ElmEdge{N1, NULL};
    if (N2->firstEdge == NULL)
        N2->firstEdge = E2;
    else {
        adrEdge P = N2->firstEdge;
        while (P->next != NULL) P = P->next;
        P->next = E2;
    }
}

void PrintInfoGraph(Graph G) {
    adrNode P = G.first;
    while (P != NULL) {
        cout << P->info << " : ";
        adrEdge E = P->firstEdge;
        while (E != NULL) {
            cout << E->node->info << " ";
            E = E->next;
        }
        cout << endl;
        P = P->next;
    }
}

void PrintDFS(Graph G, adrNode N) {
    if (N == NULL || N->visited) return;
    cout << N->info << " ";
    N->visited = 1;
    for (adrEdge E = N->firstEdge; E != NULL; E = E->next)
        PrintDFS(G, E->node);
}

void PrintBFS(Graph G, adrNode N) {
    adrNode Q[50];
    int f=0, r=0;
    Q[r++] = N;
    N->visited = 1;

    while (f < r) {
        adrNode P = Q[f++];
        cout << P->info << " ";
        for (adrEdge E = P->firstEdge; E != NULL; E = E->next)
            if (!E->node->visited) {
                E->node->visited = 1;
                Q[r++] = E->node;
            }
    }
}
```
**main.cpp**
```C++
#include "graph.h"

int main() {
    Graph G;
    CreateGraph(G);

    char node[] = {'A','B','C','D','E','F','G','H'};
    for (char c : node) InsertNode(G,c);

    ConnectNode(FindNode(G,'A'), FindNode(G,'B'));
    ConnectNode(FindNode(G,'A'), FindNode(G,'C'));
    ConnectNode(FindNode(G,'B'), FindNode(G,'D'));
    ConnectNode(FindNode(G,'B'), FindNode(G,'E'));
    ConnectNode(FindNode(G,'C'), FindNode(G,'F'));
    ConnectNode(FindNode(G,'C'), FindNode(G,'G'));
    ConnectNode(FindNode(G,'D'), FindNode(G,'H'));
    ConnectNode(FindNode(G,'E'), FindNode(G,'H'));
    ConnectNode(FindNode(G,'F'), FindNode(G,'H'));
    ConnectNode(FindNode(G,'G'), FindNode(G,'H'));

    cout << "DFS: ";
    PrintDFS(G, FindNode(G,'A'));

    adrNode P = G.first;
    while (P) { P->visited = 0; P = P->next; }

    cout << "\nBFS: ";
    PrintBFS(G, FindNode(G,'A'));

    return 0;
}
```
#### Output:
<img width="515" height="124" alt="image" src="https://github.com/user-attachments/assets/a353d892-2822-46d7-a300-4cf5bad567d5" />

Pada materi ini, membahas beberapa fungsi pada graph seperti insertNode, connectNode, serta penelusuran graph menggunakan DFS dan BFS. DFS melakukan penelusuran dengan bantuan stack, sedangkan BFS menggunakan queue. Meskipun tanpa fungsi alokasi, findNode, dan resetVisited, proses tetap dapat berjalan dengan memodifikasi fungsi insertNode dan menginisialisasi nilai visited = 0 pada awal proses DFS dan BFS.

#### Full code Screenshot:
![240309_10h21m35s_screenshot](https://github.com/suxeno/Struktur-Data-Assignment/assets/111122086/41e9641c-ad4e-4e50-9ca4-a0215e336b04)


## Kesimpulan
Dari praktikum ini dapat disimpulkan bahwa struktur data graph digunakan untuk merepresentasikan hubungan antar node. Program yang dibuat mampu menambahkan node, menghubungkan node secara dua arah, serta menampilkan isi graph. Selain itu, penelusuran graph dapat dilakukan dengan dua metode, yaitu DFS yang menelusuri node secara mendalam dan BFS yang menelusuri node berdasarkan urutan level. Melalui praktikum ini, konsep graph serta cara kerja DFS dan BFS dapat dipahami dan diterapkan dengan baik dalam program.

## Referensi
[1] Anggara, F. D. (2009). Studi dan Implementasi Struktur Data Graf. Jurnal Sekolah Teknik Elektro dan Informatika Institut Teknologi Bandung, Bandung.
[2] Teman
[3] ai
