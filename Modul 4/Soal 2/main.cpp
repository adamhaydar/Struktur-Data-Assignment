#include "Singlylist.h"

int main() {
    List L;
    Node *P, *hapus;

    createList(L);

    insertFirst(L, createNode(2));
    insertFirst(L, createNode(0));
    insertFirst(L, createNode(8));
    insertFirst(L, createNode(12));
    insertFirst(L, createNode(9));

    deleteFirst(L, hapus);
    deleteNode(hapus);

    deleteLast(L, hapus);
    deleteNode(hapus);

    Node* prec = L.head;
    deleteAfter(prec, hapus);
    deleteNode(hapus);

    printList(L);
    cout << "Jumlah node : " << countList(L) << endl;

    deleteAll(L);
    cout << "\n- List Berhasil Terhapus -" << endl;
    cout << "Jumlah node : " << countList(L) << endl;

    return 0;
}
