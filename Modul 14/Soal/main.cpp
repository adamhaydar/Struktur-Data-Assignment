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
