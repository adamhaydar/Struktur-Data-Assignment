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
