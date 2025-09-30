#include <stdio.h>
#include <stdlib.h>
#define MAXSTACK 5
#define ROGUEVALUE -9999

typedef struct {
    int top;
    int ST[MAXSTACK];
} StackType, *Stack;

Stack initStack(){
    Stack sp = (Stack)malloc(sizeof(StackType));
    sp->top = -1;
    return sp;
}

int empty(Stack S){
    return (S->top == -1);
}

void push(Stack S, int n) {
    if(S->top == MAXSTACK-1){
        printf("\nStack Overflow\n");
        exit(1);
    }
    ++(S->top);
    S->ST[S->top] = n;
}

int pop(Stack S){
    if(empty(S)) return ROGUEVALUE;
    int hold = S->ST[S->top];
    --(S->top);
    return hold;
}

int main(){
    int n;
    Stack S = initStack();
    scanf("%d", &n);
    while (n != 0)
    {
        push(S, n);
        scanf("%d", &n);
    }
    while(!empty(S)){
        printf("%d", pop(S));
    }
    printf("\n");
    
}