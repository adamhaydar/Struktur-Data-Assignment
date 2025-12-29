#ifndef STACK_H
#define STACK_H

const int MAX = 20;

struct Stack {
    int data[MAX];
    int top;
};

void createStack(Stack &S);
void push(Stack &S, int x);
int pop(Stack &S);
void printInfo(Stack S);
void balikStack(Stack &S);
void getInputStream(Stack &S);

#endif
