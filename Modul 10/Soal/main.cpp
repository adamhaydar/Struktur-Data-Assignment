#include <iostream>
#include "bstree.h"
using namespace std;

int main() {
    cout << "Hello world!" << endl;

    address root = Nil;

    int data[] = {1, 2, 6, 4, 5, 3, 6, 7};
    int n = 8;

    for (int i = 0; i < n; i++) {
        insertNode(root, data[i]);
    }

    printInOrderStrip(root);
    cout << endl;

    cout << "kedalaman : " << hitungKedalaman(root) << endl;
    cout << "jumlah node : " << hitungJumlahNode(root) << endl;
    cout << "total : " << hitungTotalInfo(root) << endl;

    return 0;
}
