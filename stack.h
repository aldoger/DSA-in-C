#include <stdio.h>
#include <stdlib.h>
#define ROGUEVALUE -9999;
typedef struct node {
    int num;
    struct node *next;
}Node, *NodePtr;

typedef struct {
    NodePtr top;
}StackType, *Stack;

Stack initStack(){
    Stack sp = (Stack)malloc(sizeof(StackType));
    sp->top = NULL;
    return sp;
}

int empty(Stack S){
    return (S->top == NULL);
}

void push(Stack S, int n){
    NodePtr np = (NodePtr)malloc(sizeof(Node));
    np->num = n;
    np->next = S->top;
    S->top = np;
}

int pop(Stack S){
    if(empty(S)) return ROGUEVALUE;
    int num = S->top->num;
    NodePtr temp = S->top;
    S->top = S->top->next;
    free(temp);
    return num;
}
