#include <iostream>
#include "stack.h"
using namespace std;

void createStack(Stack &S) {
    S.top = -1;
}

void push(Stack &S, int x) {
    if (S.top < MAX - 1) {
        S.top++;
        S.data[S.top] = x;
    }
}

int pop(Stack &S) {
    if (S.top >= 0) {
        int value = S.data[S.top];
        S.top--;
        return value;
    }
    return -1;
}

void printInfo(Stack S) {
    cout << "[TOP] ";
    for (int i = S.top; i >= 0; i--) {
        cout << S.data[i] << " ";
    }
    cout << endl;
}

void balikStack(Stack &S) {
    Stack temp;
    createStack(temp);

    while (S.top >= 0) {
        push(temp, pop(S));
    }

    S = temp;
}

void getInputStream(Stack &S) {
    string input = "4729601";  
    cout << input << endl;

    for (char ch : input) {
        push(S, ch - '0');
    }
}

